
// solve task with usage of
// static arrays
//
//  task9_static.cpp
//  labs
//
//  Created by Taras Zaporozhets on 25.09.25.
//

#include <iostream>
#include <random>
#include <exception>

//проверка вещественных данных
double read_double(){
    double value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Expected double value");
    }
    return value;
}

//проверка размера массива
int read_array_size(int max_size) {
    int size = read_double(); 
    
    if (size <= 0 || size > max_size) {
        throw std::out_of_range("Size must be in range [1;" + std::to_string(max_size) + "]");
    }
    
    return size;
}

//запрос границ рандома
std::pair<double, double> read_random_limits() {
    std::cout << "Enter the range of random (lower upper): ";
    
    double lower_limit = read_double();
    double upper_limit = read_double();

    if (lower_limit > upper_limit) {
        std::swap(lower_limit, upper_limit);
    }

    return {lower_limit, upper_limit};
}


//функция заполнения массива рандомными числами
void fill_random(double* array, int size) {
    if (array == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_random");
    }
    
    auto limits = read_random_limits();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(limits.first, limits.second);  
    
    for (int i = 0; i < size; i++) {
        array[i] = distrib(gen);
    }
}

//функция заполнения массива вручную
void fill_manual(double* array, int size) {
    if (array == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_manual");
    }
    
    std::cout << "Enter " << size << " elements of array: ";
    for (int i = 0; i < size; i++) {
        array[i] = read_double();
    }
}

//выбор заполнения
void fill_array(char option, double* array, int size) {
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

//задание 1 сравнение с P
int number_of_elems_less_than_p(double* arr, int size, int p){
    if (arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to count_elements_less_than_p");
    }
    int count = 0;
    for (size_t i = 0; i < size; i++){
        if (arr[i] < p){
            count++;
        }
    }
    
    return count;
}

//задание 2 (сумма целых частей)
int sum_of_integers(double* arr, int size){
    if (arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to sum_integer_parts_after_last_negative");
    }
    int last_negative_index = -1;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            last_negative_index = i;
        }
    }
    
    if (last_negative_index == -1) {
        throw std::runtime_error("No negative elements found in array");
    }

    if (last_negative_index == size - 1) {
        throw std::runtime_error("Last negative element is at the end of array");
    }
    
    int sum = 0;
    for (int i = last_negative_index + 1; i < size; i++) {
        sum += static_cast<int>(std::floor(arr[i]));
    }
    
    return sum;
}

//функция преобразования массива
void transform(double* new_arr, int size, int P){
    if (new_arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to transform_array");
    }
    int start = 0;
    for (size_t i = 0; i < size; i++) {
        if (new_arr[i] < P) {
            double temp = new_arr[i];
            for (size_t j = i; j > start; j--) {
                new_arr[j] = new_arr[j-1];
            }
            new_arr[start] = temp;
            start++;
        }
    }
}

//функция вывода массива
void print_array(double* p_arr, int size){
    if (p_arr == nullptr) {
        throw std::invalid_argument("Null pointer passed to print_array");
    }
    for (size_t i = 0; i < size; i++){
        std::cout << p_arr[i] << " ";
    }
    std::cout << '\n';
}

int main(){
    const int max_size = 100;
    
    try {
        double arr[max_size], p;
        int n;
        char option;
        
        std::cout << "Enter size of array <= 100: ";
        n = read_array_size(max_size);
        
        std::cout << "Choose Hand Input or Random Input (h/r): ";
        std::cin >> option; 
        std::cin.ignore();

        fill_array(option, arr, n);
        
        std::cout << "Enter the P: ";
        p = read_double();

        std::cout << "Number of elements that are less than P: " << number_of_elems_less_than_p(arr, n, p) << "\n";    
        
        try{
            std::cout << "Sum of all integer parts of elemnets after the last negative: " << sum_of_integers(arr, n) << "\n";
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "Array before transformation:\n";
        print_array(arr ,n);

        transform(arr, n, p);
        
        std::cout << "Array after transformation:";
        print_array(arr, n);
    }

    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
        return 1;
    }
    return 0;
}
