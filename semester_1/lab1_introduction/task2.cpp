//
//  task2.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>


int main() {
    int n;
    int sumEven = 0;
    int productOdd = 1;
    
    std::cout << "Enter n: ";
    
    if (!(std::cin >> n) || (n <= 0)) {
        std::cout << "Error!\n" << std::endl;
        std::exit(1);
    }
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sumEven += i;
        }
        else {
            productOdd *= i;
        }
    }
    

    std::cout << "Sum of even from 1 to " << n << ": " << sumEven << std::endl;
    std::cout << "Product of odd from 1 to " << n << ": " << productOdd << std::endl;
    
    return 0;
}

