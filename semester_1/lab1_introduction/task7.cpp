//
//  task7.cpp
//  labs
//
//  Created by Taras Zaporozhets on 4.09.25.
//
#include <iostream>
#include <algorithm>

int main(){
    int num;
    float sum, mid;
    sum = 0;
    
    std::cout << "Введите количество чисел последовательности: ";
    std::cin >> num;
    
    float arr[num];
    float min, max;
    
    for (int i = 0; i < num; i++){
        std::cout << i + 1<< ". ";
        std::cin >> arr[i];
    }
    for (int i = 0; i <= num; i++){
        sum += arr[i];
    }
    
    mid = float (sum / num);
    
    std::sort(arr, arr + num);
    min = arr[0];
    max = arr[num-1];
    
    std::cout << "Среднее арифметическое: " << mid << "\n";
    std::cout << "Минимальное значение: " << min << "\n";
    std::cout << "Максимальное значение: " << max << "\n";
}
