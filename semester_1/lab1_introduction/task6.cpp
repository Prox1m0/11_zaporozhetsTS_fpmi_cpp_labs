//
//  task6.cpp
//  labs
//
//  Created by Taras Zaporozhets on 6.09.25.
//
#include <iostream>

int main(){
    int n, start, sum;
    start = 1;
    sum = 0;
    
    std::cout << "Введите n: ";
    std::cin >> n;
    
    for (int i = 0; i < n; i++){
        sum += start;
        start += 2;
    }
    std::cout << "Сумма первых n нечетных чисел равна: " << sum << '\n';
}
