//
//  task1.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>

int main(){

    int a,b,d;
    std::cout << "Введите a,b,d через пробел: ";
    std::cin >> a >> b >> d;
    
    for (int i = a; i <= b; i += d){
        if (i % 3 == 0){
            std::cout << i << ' ';
        }
    }
    
    return 0;
}

