#define BOOST_TEST_MODULE boost_tests
#include <boost/test/included/unit_test.hpp>
#include "palindrome.h"

BOOST_AUTO_TEST_CASE(negative_numbers){
    BOOST_CHECK(!is_palindrome(-1));
    BOOST_CHECK(!is_palindrome(-116));
    BOOST_CHECK(!is_palindrome(-373));
    BOOST_CHECK(!is_palindrome(-4554));
}

BOOST_AUTO_TEST_CASE(single_digit){
    BOOST_CHECK(is_palindrome(0));
    BOOST_CHECK(is_palindrome(1));
    BOOST_CHECK(is_palindrome(9));
}

BOOST_AUTO_TEST_CASE(valid_palindromes) {
    BOOST_CHECK(is_palindrome(11));
    BOOST_CHECK(is_palindrome(121));
    BOOST_CHECK(is_palindrome(1221));
    BOOST_CHECK(is_palindrome(1001));
}

BOOST_AUTO_TEST_CASE(non_palindromes) {
    BOOST_CHECK(!is_palindrome(10));
    BOOST_CHECK(!is_palindrome(12));
    BOOST_CHECK(!is_palindrome(123));
    BOOST_CHECK(!is_palindrome(122));
}

BOOST_AUTO_TEST_CASE(big_numbers) {
    BOOST_CHECK(is_palindrome(1000001));
    BOOST_CHECK(!is_palindrome(1234322));
}