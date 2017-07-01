#include "test_fixture.h"
#include "gmock/gmock.h"
#include "test_driver.h"
#include "test_matrix.h"
#include "keyboard.h"
#include "action.h"
#include "action_tapping.h"

extern "C" {
    void set_time(uint32_t t);
    void advance_time(uint32_t ms);
}

using testing::_;
using testing::AnyNumber;
using testing::Return;
using testing::Between;

void TestFixture::SetUpTestCase() {
    TestDriver driver;
    EXPECT_CALL(driver, send_keyboard_mock(_));
    keyboard_init();
}

void TestFixture::TearDownTestCase() {
}

TestFixture::TestFixture() {
}

TestFixture::~TestFixture() {
    TestDriver driver;
    clear_all_keys();
    // Run for a while to make sure all keys are completely released
    EXPECT_CALL(driver, send_keyboard_mock(_)).Times(AnyNumber());
    idle_for(TAPPING_TERM + 10);
    testing::Mock::VerifyAndClearExpectations(&driver); 
    // Verify that the matrix really is cleared
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport())).Times(Between(0, 1));
}

void TestFixture::run_one_scan_loop() {
    keyboard_task();
    advance_time(1);
}

void TestFixture::idle_for(uint time) {
    for (uint i=0; i<time; i++) {
        run_one_scan_loop();
    }
}