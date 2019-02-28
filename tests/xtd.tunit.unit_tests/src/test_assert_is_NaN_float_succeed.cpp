#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <limits>

namespace unit_tests {
  class test_class_(test_assert_is_NaN_float_succeed) {
  public:
    void test_method_(test_case_succeed) {
      float f = std::numeric_limits<float>::quiet_NaN();
      xtd::tunit::assert::is_NaN(f, xtd::tunit::line_info {"test_assert_is_NaN_float_succeed.cpp", 10});
    }
  };
}

void test_(test_assert_is_NaN_float_succeed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_NaN_float_succeed.*");
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  SUCCEED test_assert_is_NaN_float_succeed.test_case_succeed\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_NaN_float_succeed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_NaN_float_succeed.*");
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
