//
//  task10.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>
using namespace std;

int main(){
    int n, sum1, sum2, half;
    sum1 = 0;
    sum2 = 0;
    cout << "Введите 6-значное число: ";
    cin >> n;
    while (to_string(n).length() != 6){
        cout << "Введите 6-значное число: ";
        cin >> n;
    }
    half = n / 1000;
    for (int i = 0; i < 3; i++){
        sum1 += half % 10;
        sum2 += n % 10;
        
        half  /= 10;
        n /= 10;
    }
    if (sum1 == sum2){
        cout << "Счастливое число" << "\n";
    }
    else{
        cout << "Несчастливое число" << "\n";
    }
}

