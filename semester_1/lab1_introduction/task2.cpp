//
//  task2.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    int sumEven = 0;
    long productOdd = 1;
    
    cout << "Введите значение n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "n должно быть положительным числом!" << endl;
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
    

    cout << "Сумма всех четных чисел от 1 до " << n << ": " << sumEven << endl;
    cout << "Произведение всех нечетных чисел от 1 до " << n << ": " << productOdd << endl;
    
    return 0;
}

