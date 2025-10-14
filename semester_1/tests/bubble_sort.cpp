//
//  sort.cpp
//  labs
//
//  Created by Taras Zaporozhets on 14.10.25.
//

#include <iostream>
#include <cmath>

void bubble_sort(int* arr, int size){
    
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (abs(arr[j]) < abs(arr[i])){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

void print_array(int* arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}


int main(){
    const int max_length = 100;
    int n;
    int arr[max_length];
    
    std::cout << "Enter the length <= 100: ";
    if(!(std::cin >> n) || n <= 0 || n > 100){
        std::cout << "Error!\n";
        std::exit(1);
    }

    std::cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++){
        if(!(std::cin >> arr[i])){
            std::cout << "Error!\n";
            std::exit(1);
        }
    }
    
    std::cout << "Before sort: ";
    print_array(arr, n);
    
    bubble_sort(arr, n);
    
    std::cout << "\nAfter sort: ";
    print_array(arr, n);
    
}