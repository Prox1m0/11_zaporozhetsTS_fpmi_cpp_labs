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
    
    std::cout << "Enter the lenght of sequence: ";
    if(!(std::cin >> num) || (num <= 0)){
        std::cout << "Error!\n";
        std::exit(1);
    }
    
    float arr[num];
    float min, max;
    
    for (int i = 0; i < num; i++){
        std::cout << i + 1<< ". ";
        
        if(!(std::cin >> arr[i])){
            std::cout << "Error!";
            std::exit(1);
        }
    }
    for (int i = 0; i <= num; i++){
        sum += arr[i];
    }
    
    mid = float (sum / num);
    
    std::sort(arr, arr + num);
    min = arr[0];
    max = arr[num-1];
    
    std::cout << "Arithmetic mean: " << mid << "\n";
    std::cout << "Max: " << min << "\n";
    std::cout << "Min: " << max << "\n";
}
