#include <cassert>
#include <iostream>
#include "palindrome.h"

void test_negative_numbers() {
    assert(is_palindrome(-1) == false);
    assert(is_palindrome(-121) == false);
    assert(is_palindrome(-10) == false);
    std::cout << "test_negative_numbers passed\n";
}

void test_single_digit_numbers() {
    for (int x = 0; x <= 9; ++x) {
        assert(is_palindrome(x) == true);
    }
    std::cout << "test_single_digit_numbers passed\n";
}

void test_palindromes() {
    assert(is_palindrome(11)  == true);
    assert(is_palindrome(121) == true);
    assert(is_palindrome(1221) == true);
    assert(is_palindrome(1001) == true);
    std::cout << "test_palindromes passed\n";
}

void test_non_palindromes() {
    assert(is_palindrome(10) == false);
    assert(is_palindrome(12) == false);
    assert(is_palindrome(123) == false);
    assert(is_palindrome(122) == false);
    std::cout << "test_non_palindromes passed\n";
}

void test_big_numbers() {
    assert(is_palindrome(1000001) == true);
    assert(is_palindrome(1234322) == false);
    std::cout << "test_big_numbers passed\n";
}

int main() {
    test_negative_numbers();
    test_single_digit_numbers();
    test_palindromes();
    test_non_palindromes();
    test_big_numbers();

    std::cout << "All tests passed!\n";
    return 0;
}
