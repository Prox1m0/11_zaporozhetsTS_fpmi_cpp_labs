
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
#include <cmath>
#include <exception>

//создание массива
void create_array(int*& arr, int size){
    arr = new int [size];
}

//проверка целочисленных данных
int read_int(){
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        throw std::invalid_argument("Expected integer value");
    }
    return value;
}

//проверка размера массива
int read_array_size() {
    int size = read_int(); 
    
    if (size <= 0) {
        throw std::out_of_range("Size must be >0");
    }
    
    return size;
}

//запрос границ рандома
std::pair<int, int> read_random_limits(){    
   
    std::cout << "Enter the range of random: ";
    int lower_limit = read_int();
    int upper_limit = read_int();

    if (lower_limit > upper_limit){
        std::swap(lower_limit, upper_limit);
    }

    return {lower_limit, upper_limit};
}

//функция заполнения массива рандомными числами
void fill_random(int* array, int size) {
    if (array == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_random");
    }
    
    auto limits = read_random_limits();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(limits.first, limits.second);  
    
    for (int i = 0; i < size; i++) {
        array[i] = distrib(gen);
    }
}


//функция заполнения массива вручную
void fill_manual(int* array, int size) {
    if (array == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_manual");
    }
    
    std::cout << "Enter " << size << " elements of array: ";
    for (int i = 0; i < size; i++) {
        array[i] = read_int();
    }
}

//выбор заполнения
void fill_array(char option, int* array, int size) {
    if (array == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_array");
    }
    
    switch (option) {
        case 'h':
        case 'H':
            fill_manual(array, size);
            break;
        case 'r':
        case 'R':
            fill_random(array, size);
            break;
        default:
            throw std::invalid_argument("Invalid option. Use 'h' for manual or 'r' for random input");
    }
}

//функция преобразования массива
void transform(int* new_arr, int size){
    if (new_arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to transform");
    }
    int start = 0;
    for (size_t i = 0; i < size; i++){
        if (new_arr[i] % 2 == 0){
            if (start != i){
                 
                int temp = new_arr[i];
                
                for (size_t j = i; j > start; j--){
                    new_arr[j] = new_arr[j-1];
                }
                new_arr[start] = temp;
            }
            start++;
        }
    }
}

//задание 1 с минимальным по модулю элементом
int minimal_absolute_value(int* arr, int size){
    if (arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to minimal_absolute_value");
    }
    int min = std::abs(arr[0]);
    int value = arr[0];
    
    for (size_t i = 1; i < size; i++){
        if (std::abs(arr[i]) < min){
            min = std::abs(arr[i]);
            value = arr[i];
        }
    }

    return value;
}

//задание 2 с суммой элементов после последнего 0
int sum_after_last_zero(int* arr, int size){
    if (arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to sum_after_last_zero");
    }
    int last_zero_index = -1;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            last_zero_index = i;
        }
    }

    if (last_zero_index == - 1){
            throw std::runtime_error("No zeroes found in array");
    }
    if (last_zero_index == size - 1) {
        throw std::runtime_error("Last zero is at the end of array");
    }

    int sum = 0;
    for (int i = last_zero_index + 1; i < size; i++) {
        sum += arr[i];
    }
    
    return sum;
}

//функция вывода массива
void print_array(int* arr, int size){
    if (arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to print_array");
    }
    for (size_t i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main(){
    
    int n = 0;
    char option;
    int* arr = nullptr;
    
    try{
        std::cout << "Enter the size of array: ";
        n = read_array_size();

        create_array(arr, n);
        
        std::cout << "Choose Hand Input or Random Input (h/r): ";
        std::cin >> option;
        std::cin.ignore();

        fill_array(option, arr, n);
        
        std::cout << "Element with minimal absolute value: " << minimal_absolute_value(arr, n) << "\n";
        
        try{
            std::cout << "Sum of all elements after the last 0:  " << sum_after_last_zero(arr, n);
        }
        catch(const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Array before transformation: ";
        print_array(arr, n);
        
        transform(arr, n);
        
        std::cout << "Array after transformation: "; 
        print_array(arr, n); 
        std::cout << "\n";
        
        delete []  arr;
        return 0;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        delete []  arr;
        return 1;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        delete []  arr;
        return 1;
    }
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
        delete []  arr;
        return 1;
    }  

}

