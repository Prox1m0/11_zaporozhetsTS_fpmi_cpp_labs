//
//  task7.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int num;
    double sum, mid;
    sum = 0;
    
    cout << "Введите количество чисел последовательности: ";
    cin >> num;
    
    double arr[num];
    double min, max;
    
    for (int i = 0; i < num; i++){
        cout << i + 1<< ". ";
        cin >> arr[i];
    }
    for (int i = 0; i <= num; i++){
        sum += arr[i];
    }
    
    mid = double (sum / num);
    
    sort(arr, arr + num);
    min = arr[0];
    max = arr[num-1];
    
    cout << "Среднее арифметическое: " << mid << "\n";
    cout << "Минимальное значение: " << min << "\n";
    cout << "Максимальное значение: " << max << "\n";
}
