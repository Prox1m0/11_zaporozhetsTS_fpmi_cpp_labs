#include "palindrome.h"

bool is_palindrome(int x){

    if (x < 0){
        return false;
    }

    int original = x;
    int reversed_x = 0;

    while (x > 0){
        reversed_x = reversed_x * 10 + x % 10;
        x /= 10;
    }
    
    return original == reversed_x;
}