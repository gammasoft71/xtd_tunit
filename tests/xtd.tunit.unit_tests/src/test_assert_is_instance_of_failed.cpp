#include "assert_unit_tests.h"
#include <tunit/tunit>
#include <stdexcept>

namespace unit_tests {
  class test_class_(test_assert_is_instance_of_failed) {
  public:
    void test_method_(test_case_failed) {
      std::invalid_argument e("invalid argument");;
      tunit::assert::is_instance_of<std::bad_cast>(e);
    }
  };
}

void test_(test_assert_is_instance_of_failed, test_output) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_is_instance_of_failed.*");
  std::stringstream ss;
  tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  test_assert_is_instance_of_failed.test_case_failed\n"
                "    Expected: instance of <std::bad_cast>\n"
                "    But was:  <std::invalid_argument>\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_instance_of_failed, test_result) {
  tunit::settings::default_settings().exit_status(0);
  tunit::settings::default_settings().filter_tests("test_assert_is_instance_of_failed.*");
  std::stringstream ss;
  assert_value_(1, tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
