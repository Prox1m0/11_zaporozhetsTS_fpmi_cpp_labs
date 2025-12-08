#include <iostream>
#include "palindrome.h"


int main(){

    int a,b;

    std::cout << "Enter a, b: ";
    if(!(std::cin >> a >> b)){     
        std::cout << "Error!";
        std::exit(1);
    }

     if (a > b) {
        std::cout << "Error: a should be less or equal to b";
        std::exit(1);
    }

    for (int i = a; i <= b; i++){
        if (is_palindrome(i)){
            std::cout << i << ' ';
        }

    }

}
