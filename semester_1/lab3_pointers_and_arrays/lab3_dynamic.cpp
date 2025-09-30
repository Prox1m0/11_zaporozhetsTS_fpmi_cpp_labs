
// solve task with usage of
// dymanic arrays
//
//  task27_dynamic.cpp
//  labs
//
//  Created by Taras Zaporozhets on 29.09.25.
//

#include <iostream>
#include <random>

//функция заполнения массива рандомными числами
void random(int* random_arr, int size){
    
    int lower_limit, upper_limit;
    
    std::cout << "Enter the range of random: ";
    
    if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit){
        std::cout << "Incorrect input! 1st integer must be lower than 2nd.\n";
        
        delete [] random_arr;
        std::exit(1);
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);
    
    for (int i = 0; i < size; i++){
        random_arr[i] = distrib(gen);
    }
    
}

//функция заполнения массива вручную
void hand(int* hand_arr, int size){
    
    std::cout << "Enter the integer elements of array: ";
    
    for (int i = 0; i < size; i++){
        if (!(std::cin >> hand_arr[i])){
            std::cout << "Incorrect Input! Elements must be integer!\n";
            
            delete [] hand_arr;
            std::exit(1);
        }
    }
    
}

//функция преобразования массива
void transform(int* new_arr, int size){
    
    int start = 0;
    for (int i = 0; i < size; i++){
        if (new_arr[i] % 2 == 0){
            if (start != i){
                 
                int temp = new_arr[i];
                
                for (int j = i; j > start; j--){
                    new_arr[j] = new_arr[j-1];
                }
                new_arr[start] = temp;
            }
            start++;
        }
    }
}

//функция вывода массива
void print_array(int* p_arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << p_arr[i] << " ";
    }
}

int main(){
    
    int n = 0, sum = 0;
    char option;
    
    std::cout << "Enter the size of array: ";
    if(!(std::cin >> n) || n <= 0){
        std::cout << "Incorrect Input! Size must be > 0!\n";
        std::exit(1);
    }
    
    int* arr = new int [n];
    
    std::cout << "Choose Hand Input or Random Input (h/r): ";
    std::cin >> option;
    
    //обработка выбора ввода
    switch (option) {
        case 'h':
            hand(arr, n);
            break;
        case 'r':
            random(arr, n);
            break;
        default:
            std::cout << "Incorrect option input! (Only h/r).\n";
            
            delete [] arr;
            std::exit(1);
    }
    
    //задание 1 с минимальным по модулю элементом
    int min = std::abs(arr[0]);
    int value = arr[0];
    
    for (int i = 1; i < n; i++){
        if (std::abs(arr[i]) < min){
            min = std::abs(arr[i]);
            value = arr[i];
        }
    }
    
    std::cout << "Element with minimal absolute value: " << value  << " (abs = " << min << ")\n";
    
    //задание 2 с суммой всех элементов после последнего нулевого
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (arr[i] == 0){
            sum = 0;
        }
    }
    std::cout << "Sum of all elements after the last 0:  " << sum;
    
    //преобразование массива
    std::cout << "\nArray before transformation: ";
    
    print_array(arr, n);
    
    transform(arr, n);
    
    std::cout << "\nArray after trnsformation: ";
    
    print_array(arr, n);
    
    std::cout << "\n";
    
    delete []  arr;
    
    return 0;
}

