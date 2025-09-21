//
//  task.cpp
//  labs
//
//  Created by Taras Zaporozhets on 16.09.25.
//
#include <iostream>

void TryRead(int& number){
    if (!(std::cin >> number)){
        std::cout << "Fail on reading the number\n";
        exit(0);
    }
}

bool IsNotNegative(int number){
    return abs(number) == number;
}

int main(){
    int number;
    
    std::cout << "Enter the number: ";
    TryRead(number);
    
    bool std_non_negative_check = (number >= 0);
    
    if (IsNotNegative(number) == std_non_negative_check){
        std::cout << "Try again....\n";
        
    } else {
        std::cout << "You broke my program\n";
        exit(1);
    }
    
    return 0;
}


/*
 1. Если "Try again...." является сигналом того, что число неотрицательное, как следствие равенства 2 способов проверки,
то при вводе отрицательного числа функция и оператор сравнения передадут значение False, соответсвтенно будут равны, а значит
 и программа выведет "Try again....", что выводится при неотрицательности числа.
 2. Если ввести минимально возможное значение int (-2147483648), то в функции IsNotNegative() абсолютное значение будет превышать
 максимально возможное значение int (2147483647) и программа завершится с кодом 1. Для проверки чила на неотрицательность будет достаточно
 1 проверки. Проверка с модулем избыточна.
 3. При вводе 2 любых чисел через пробел выводится "Try again...." и программа завершается с кодом 0.
 */
