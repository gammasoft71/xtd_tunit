/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "__demangle.hpp"
#include "__join__items.hpp"
#include "abort_error.hpp"
#include "assert_error.hpp"
#include "default_insert_basic_ostream_operator.hpp"
#include "ignore_error.hpp"
#include "line_info.hpp"
#include <algorithm>
#include <cmath>
#include <exception>
#include <functional>
#include <iterator>
#include <memory>
#include <string>

/// @cond
#ifdef assert
#undef assert
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The assert class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class assert final {
    public:
      /// @cond
      assert() = delete;
      /// @endcond
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort() {abort("", line_info());}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const xtd::tunit::line_info& line_info) {abort("", line_info);}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const std::string& message) {abort(message, line_info());}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const std::string& message, const xtd::tunit::line_info& line_info);
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore() {ignore("", line_info());}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const xtd::tunit::line_info& line_info) {ignore("", line_info);}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const std::string& message) {ignore(message, line_info());}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const std::string& message, const xtd::tunit::line_info& line_info);

      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), line_info_); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (actual == expected)
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }
      
      /// @cond
      static void are_equal(float expected, float actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(actual) && std::isnan(expected))
          succeed(message, line_info);
        else if (actual == expected)
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }

      static void are_equal(double expected, double actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(actual) && std::isnan(expected))
          succeed(message, line_info);
        else if (actual == expected)
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }

      static void are_equal(long double expected, long double actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(actual) && std::isnan(expected))
          succeed(message, line_info);
        else if (actual == expected)
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }
      /// @endcond
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance) {are_equal(expected, actual, tolerance, "", line_info_);}

      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f, line_info_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, tolerance, "", line_info);}

      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f, "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float& actual, float tolerance, const std::string& message) {are_equal(expected, actual, tolerance, message, line_info());}

      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (fabsf(expected - actual) <= fabsf(tolerance))
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance) {are_equal(expected, actual, tolerance, "", line_info_);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001, line_info_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, tolerance, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001, "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const std::string& message) {are_equal(expected, actual, tolerance, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (fabs(expected - actual) <= fabs(tolerance))
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance) {are_equal(expected, actual, tolerance, "", line_info_);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l, line_info_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, tolerance, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l, "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const std::string& message) {are_equal(expected, actual, tolerance, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolelerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (fabsl(expected - actual) <= fabsl(tolerance))
          succeed(message, line_info);
        else
          fail(to_string(expected), to_string(actual), message, line_info);
      }

      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), line_info_); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (actual != expected)
          succeed(message, line_info);
        else
          fail("not " + to_string(expected), to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual) {are_not_same(expected, actual, "", line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, line_info_); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, line_info); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, "User message...", line_info); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (&actual != &expected)
          succeed(message, line_info);
        else
          fail("not same as " + to_string(expected), to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a); // test ok.
      /// xtd::tunit::assert::are_same(c, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual) {are_same(expected, actual, "", line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, line_info_); // test ok.
      /// xtd::tunit::assert::are_same(c, a, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::assert::are_same(c, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_same(c, a, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (&actual == &expected)
          succeed(message, line_info);
        else
          fail("same as " + to_string(expected), to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1); // test ok.
      /// xtd::tunit::assert::contains(4, v1); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection) {contains(item, collection, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, line_info_); // test ok.
      /// xtd::tunit::assert::contains(4, v1, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const xtd::tunit::line_info& line_info) {contains(item, collection, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::assert::contains(4, v1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message) {contains(item, collection, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::contains(4, v1, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(collection.begin(), collection.end(), item);
        if (result != collection.end())
          succeed(message, line_info);
        else
          fail("collection containing " + to_string(item), "< " + __join__items(collection) + " >", message, line_info);
      }
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement) {does_not_throw(statement, "", line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, line_info_); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {does_not_throw(statement, "", line_info);}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const std::string& message) {does_not_throw(statement, message, line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          succeed(message, line_info);
        } catch (const std::exception& e) {
          fail("No Exception to be thrown", "<" + __demangle(typeid(e).name()) + ">", message, line_info);
        } catch (...) {
          fail("No Exception to be thrown", "<exception>", message, line_info);
        }
      }
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail() {fail("Failed", line_info());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const xtd::tunit::line_info& line_info) {fail("Failed", line_info);}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message) {fail(message, line_info());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message, const xtd::tunit::line_info& line_info) {
        fail("", "", message, line_info);
      }
      
      /// @brief Asserts that collection or traits contains an item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1); // test ok.
      /// xtd::tunit::assert::is_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value) {is_empty(value, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value, const xtd::tunit::line_info& line_info) {is_empty(value, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value, const std::string& message) {is_empty(value, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::empty(value))
          succeed(message, line_info);
        else
          fail("collection <empty>", "< " + __join__items(value) + " >", message, line_info);
      }

      /// @brief Asserts that ta condition is false.
      /// @param condition The condition to check is false.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition) {is_false(condition, "", line_info());}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::tunit::line_info& line_info) {is_false(condition, "", line_info);}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const std::string& message) {is_false(condition, message, line_info());}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (condition == false)
          succeed(message, line_info);
        else
          fail("false", "true", message, line_info);
      }
 
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater(const TValue1& val1, const TValue2& val2) {is_greater(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12, line_info_); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {is_greater(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater(const TValue1& val1, const TValue2& val2, const std::string& message) {is_greater(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 > val2)
          succeed(message, line_info);
        else
          fail("greater than " + to_string(val2), to_string(val1), message, line_info);
      }
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater_or_equal(const TValue1& val1, const TValue2& val2) {is_greater_or_equal(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12, line_info_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24, line_info_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater_or_equal(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {is_greater_or_equal(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message) {is_greater_or_equal(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_greater_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 >= val2)
          succeed(message, line_info);
        else
          fail("greater than or equal to " + to_string(val2), to_string(val1), message, line_info);
      }

      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value) {is_instance_of<Type>(value, "", line_info());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, line_info_); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value, const xtd::tunit::line_info& line_info) {is_instance_of<Type>(value, "", line_info);}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value, const std::string& message) {is_instance_of<Type>(value, message, line_info());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (dynamic_cast<const Type*>(&value) != nullptr)
          succeed(message, line_info);
        else
          fail("instance of <" + __demangle(typeid(Type).name()) + ">", "<" + __demangle(typeid(value).name()) + ">", message, line_info);
      }
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48); // test ok.
      /// xtd::tunit::assert::is_less(24, 12); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less(const TValue1& val1, const TValue2& val2) {is_less(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48, line_info_); // test ok.
      /// xtd::tunit::assert::is_less(24, 12, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {is_less(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assert::is_less(24, 12, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less(const TValue1& val1, const TValue2& val2, const std::string& message) {is_less(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_less(24, 12, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 < val2)
          succeed(message, line_info);
        else {
          fail("less than " + to_string(val2), to_string(val1), message, line_info);
        }
      }
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less_or_equal(const TValue1& val1, const TValue2& val2) {is_less_or_equal(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48, line_info_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24, line_info_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less_or_equal(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {is_less_or_equal(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message) {is_less_or_equal(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void is_less_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 <= val2)
          succeed(message, line_info);
        else
          fail("less than or equal to " + to_string(val2), to_string(val1), message, line_info);
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const std::string& message) {is_NaN(value, message, line_info());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(value))
          succeed(message, line_info);
        else
          fail("NaN", to_string(value), message, line_info);
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value, const std::string& message) {is_NaN(value, message, line_info());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(value))
          succeed(message, line_info);
        else
          fail("NaN", to_string(value), message, line_info);
      }

      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const std::string& message) {is_NaN(value, message, line_info());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(value))
          succeed(message, line_info);
        else
          fail("NaN", to_string(value), message, line_info);
      }
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1); // test ok.
      /// xtd::tunit::assert::is_negative(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_negative(const TValue& value) {is_negative(value, "", line_info());}
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1, line_info_); // test ok.
      /// xtd::tunit::assert::is_negative(i2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_negative(const TValue& value, const xtd::tunit::line_info& line_info) {is_negative(value, "", line_info);}
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_negative(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_negative(const TValue& value, const std::string& message) {is_negative(value, message, line_info());}
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_negative(i2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_negative(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (value < 0)
          succeed(message, line_info);
        else
          fail("negative", to_string(value), message, line_info);
      }

      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value) {is_not_empty(value, "", line_info());}
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value, const xtd::tunit::line_info& line_info) {is_not_empty(value, "", line_info);}
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value, const std::string& message) {is_not_empty(value, message, line_info());}
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (!std::empty(value))
          succeed(message, line_info);
        else
          fail("collection not <empty>", "<empty>", message, line_info);
      }
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value) {is_not_instance_of<Type>(value, "", line_info());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value, const xtd::tunit::line_info& line_info) {is_not_instance_of<Type>(value, "", line_info);}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value, const std::string& message) {is_not_instance_of<Type>(value, message, line_info());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (dynamic_cast<const Type*>(&value) == nullptr)
          succeed(message, line_info);
        else
          fail("not instance of <" + __demangle(typeid(Type).name()) + ">", "<" + __demangle(typeid(value).name()) + ">", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer != nullptr)
          succeed(message, line_info);
        else
          fail("not null", "null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer != nullptr)
          succeed(message, line_info);
        else
          fail("not null", "null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer != nullptr)
          succeed(message, line_info);
        else
          fail("not null", "null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {succeed(message, line_info);}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer) {is_not_null(pointer, "", line_info());}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const std::string& message) {is_not_null(pointer, message, line_info());}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const std::string& message, const xtd::tunit::line_info& line_info) {fail("not null", "null", message, line_info);}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_zero(const TValue& value) {is_not_zero(value, "", line_info());}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_zero(const TValue& value, const xtd::tunit::line_info& line_info) {is_not_zero(value, "", line_info);}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_zero(const TValue& value, const std::string& message) {is_not_zero(value, message, line_info());}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_zero(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (value != 0)
          succeed(message, line_info);
        else
          fail("not zero", "0", message, line_info);
      }

      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer == nullptr)
          succeed(message, line_info);
        else
          fail("null", "not null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer == nullptr)
          succeed(message, line_info);
        else
          fail("null", "not null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer == nullptr)
          succeed(message, line_info);
        else
          fail("null", "not null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, line_info_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {fail("null", "not null", message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, line_info_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, "User message..."); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, "User message...", line_info_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const std::string& message, const xtd::tunit::line_info& line_info) {succeed(message, line_info);}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1); // test ok.
      /// xtd::tunit::assert::is_positive(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_positive(const TValue& value) {is_positive(value, "", line_info());}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1, line_info_); // test ok.
      /// xtd::tunit::assert::is_positive(i2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_positive(const TValue& value, const xtd::tunit::line_info& line_info) {is_positive(value, "", line_info);}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_positive(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_positive(const TValue& value, const std::string& message) {is_positive(value, message, line_info());}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_positive(i2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_positive(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (value > 0)
          succeed(message, line_info);
        else
          fail("positive", to_string(value), message, line_info);
      }

      /// @brief Asserts that ta condition is true.
      /// @param condition The condition to check is true.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition) {is_true(condition, "", line_info());}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::tunit::line_info& line_info) {is_true(condition, "", line_info);}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const std::string& message) {is_true(condition, message, line_info());}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (condition == true)
          succeed(message, line_info);
        else
          fail("true", "false", message, line_info);
      }
 
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1); // test ok.
      /// xtd::tunit::assert::is_zero(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_zero(const TValue& value) {is_zero(value, "", line_info());}
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1, line_info_); // test ok.
      /// xtd::tunit::assert::is_zero(i2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_zero(const TValue& value, const xtd::tunit::line_info& line_info) {is_zero(value, "", line_info);}
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_zero(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_zero(const TValue& value, const std::string& message) {is_zero(value, message, line_info());}
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_zero(i2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_zero(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (value == 0)
          succeed(message, line_info);
        else
          fail("zero", to_string(value), message, line_info);
      }
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(); // test ok.
      /// @endcode
      static void succeed() {succeed("", line_info_);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(line_info_); // test ok.
      /// @endcode
      static void succeed(const xtd::tunit::line_info& line_info) {succeed("", line_info);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message..."); // test ok.
      /// @endcode
      static void succeed(const std::string& message) {succeed(message, line_info_);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message...", line_info_); // test ok.
      /// @endcode
      static void succeed(const std::string& message, const xtd::tunit::line_info& line_info);

      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement) {throws<TException>(statement, "", line_info());}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, line_info_); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {throws<TException>(statement, "", line_info);}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement, const std::string& message) {throws<TException>(statement, message, line_info());}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          fail("<"  + __demangle(typeid(TException).name()) + ">", "<nothing>", message, line_info);
        } catch (const TException&) {
          succeed(message, line_info);
        } catch (const xtd::tunit::assert_error&) {
          throw;
        } catch (const std::exception& e) {
          fail("<"  + __demangle(typeid(TException).name()) + ">", "<" + __demangle(typeid(e).name()) + ">", message, line_info);
        } catch (...) {
          fail("<"  + __demangle(typeid(TException).name()) + ">", "<exception>", message, line_info);
        }
      }
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement) {throws_any(statement, "", line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, line_info_); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {throws_any(statement, "", line_info);}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const std::string& message) {throws_any(statement, message, line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          fail("<exception>", "<nothing>", message, line_info);
        } catch (const xtd::tunit::assert_error&) {
          throw;
        } catch (...) {
          succeed(message, line_info);
        }
      }
      
    private:
      static void fail(const std::string& actual, const std::string& expected, const std::string& message, const xtd::tunit::line_info& line_info);

      template <typename TValue>
      static std::string to_string(const TValue& value) {
        std::stringstream ss;
        __value_printer<char, std::char_traits<char>, TValue>::print(ss, value);
        return ss.str();
      }
    };
  }
}

/// @cond
#define __CMD_ASSERT_0_ARGS__(cmd) cmd(line_info_)
#define __CMD_ASSERT_1_ARGS__(cmd, arg1) cmd(arg1, line_info_)
#define __CMD_ASSERT_2_ARGS__(cmd, arg1, arg2) cmd(arg1, arg2, line_info_)
#define __CMD_ASSERT_3_ARGS__(cmd, arg1, arg2, arg3) cmd(arg1, arg2, arg3, line_info_)
#define __CMD_ASSERT_4_ARGS__(cmd, arg1, arg2, arg3, arg4) cmd(arg1, arg2, arg3, arg4)
#define __GET_LAST_ARG(arg1, arg2, arg3, arg4, arg5, ...) arg5
#define __CMD_ASSERT_MACRO_CHOOSER(cmd, ...) __GET_LAST_ARG(__VA_ARGS__, __CMD_ASSERT_4_ARGS__, __CMD_ASSERT_3_ARGS__, __CMD_ASSERT_2_ARGS__, __CMD_ASSERT_1_ARGS__, __CMD_ASSERT_0_ARGS__, )
#define __CMD_ASSERT_ARGS(cmd, ...) __CMD_ASSERT_MACRO_CHOOSER(cmd, __VA_ARGS__)(cmd, __VA_ARGS__)
/// @endcond

#define abort_() abort(line_info_)

#define are_equal_(...) __CMD_ASSERT_ARGS(are_equal, __VA_ARGS__)

#define are_not_equal_(...) __CMD_ASSERT_ARGS(are_not_equal, __VA_ARGS__)

#define are_not_same_(...) __CMD_ASSERT_ARGS(are_not_same, __VA_ARGS__)

#define are_same_(...) __CMD_ASSERT_ARGS(are_same, __VA_ARGS__)

#define contains_(...) __CMD_ASSERT_ARGS(contains, __VA_ARGS__)

#define does_not_throw_(...) __CMD_ASSERT_ARGS(does_not_throw, __VA_ARGS__)

#define fail_() fail(line_info_)

#define ignore_() ignore(line_info_)

#define is_empty_(...) __CMD_ASSERT_ARGS(is_empty, __VA_ARGS__)

#define is_false_(...) __CMD_ASSERT_ARGS(is_false, __VA_ARGS__)

#define is_greater_(...) __CMD_ASSERT_ARGS(is_greater, __VA_ARGS__)

#define is_greater_or_equal_(...) __CMD_ASSERT_ARGS(is_greater_or_equal, __VA_ARGS__)

#define is_instance_of_(Type, ...) __CMD_ASSERT_ARGS(is_instance_of<Type>, __VA_ARGS__)

#define is_less_(...) __CMD_ASSERT_ARGS(is_less, __VA_ARGS__)

#define is_less_or_equal_(...) __CMD_ASSERT_ARGS(is_less_or_equal, __VA_ARGS__)

#define is_NaN_(...) __CMD_ASSERT_ARGS(is_NaN, __VA_ARGS__)

#define is_negative_(...) __CMD_ASSERT_ARGS(is_negative, __VA_ARGS__)

#define is_not_empty_(...) __CMD_ASSERT_ARGS(is_not_empty, __VA_ARGS__)

#define is_not_instance_of_(Type, ...) __CMD_ASSERT_ARGS(is_not_instance_of<Type>, __VA_ARGS__)

#define is_not_null_(...) __CMD_ASSERT_ARGS(is_not_null, __VA_ARGS__)

#define is_not_zero_(...) __CMD_ASSERT_ARGS(is_not_zero, __VA_ARGS__)

#define is_null_(...) __CMD_ASSERT_ARGS(is_null, __VA_ARGS__)

#define is_positive_(...) __CMD_ASSERT_ARGS(is_positive, __VA_ARGS__)

#define is_true_(...) __CMD_ASSERT_ARGS(is_true, __VA_ARGS__)

#define is_zero_(...) __CMD_ASSERT_ARGS(is_zero, __VA_ARGS__)

#define succeed_() succeed(line_info_)

#define throws_(TException, ...) __CMD_ASSERT_ARGS(throws<TException>, __VA_ARGS__)

#define throws_any_(...) __CMD_ASSERT_ARGS(throws_any, __VA_ARGS__)
