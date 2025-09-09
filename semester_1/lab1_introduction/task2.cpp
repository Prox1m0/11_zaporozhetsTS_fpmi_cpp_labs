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
    
    std::cout << "Введите значение n: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "n должно быть положительным числом!" << std::endl;
        return 1;
    }
    
    // Обработка чисел от 1 до n
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sumEven += i;
        }
        else {
            productOdd *= i;
        }
    }
    

    std::cout << "Сумма всех четных чисел от 1 до " << n << ": " << sumEven << std::endl;
    std::cout << "Произведение всех нечетных чисел от 1 до " << n << ": " << productOdd << std::endl;
    
    return 0;
}

