
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

//функция заполнения массива рандомными числами
void random(double random_arr[], int size){
    
    int lower_limit, upper_limit;
    
    std::cout << "Enter the range of random: ";
    
    if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit){
        std::cout << "Incorrect input!\n";
        std::exit(1);
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_real_distribution<> distrib(lower_limit, upper_limit);
    
    for (int i = 0; i < size; i++){
        random_arr[i] = distrib(gen);
    }
    
}

//функция заполнения массива вручную
void hand(double hand_arr[], int size){
    
    std::cout << "Enter the elements of array: ";
    
    for (int i = 0; i < size; i++){
        if (!(std::cin >> hand_arr[i])){
            std::cout << "Incorrect Input!\n";
            std::exit(1);
        }
    }
    
}

void transform(double new_arr[], int size, int P){
    
    int start = 0;
    for (int i = 0; i < size; i++) {
        if (new_arr[i] < P) {
            double temp = new_arr[i];
            for (int j = i; j > start; j--) {
                new_arr[j] = new_arr[j-1];
            }
            new_arr[start] = temp;
            start++;
        }
    }
}

int main(){
    const int max_size = 100;
    double arr[max_size], p;
    int n, count = 0, sum = 0;
    char option;
    
    std::cout << "Enter size of array <= 100: ";
    if (!(std::cin >> n) || n <= 0 || n > max_size){
        std::cout << "Incorrect input!\n";
        std::exit(1);
    }
    
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
            std::cout << "Incorrect option input!\n";
            std::exit(1);
    }
    
    //задание 1 (сравнение с P)
    std::cout << "Enter the P: ";
    if (!(std::cin >> p)){
        std::cout << "Incorrect Input!";
        std::exit(1);
    }
    
    std::cout << "Number of elements that are less than P: ";
    for (int i = 0; i < n; i++){
        if (arr[i] < p){
            count++;
        }
    }
    
    std::cout << count << "\n";
    
    //задание 2 (сумма целых частей)
    //считается, что при отсутствии отрицательных чисел берется сумма целых частей всех элементов массива, так как в условии про обработку такого случая ничего не сказано
    for (int i = 0; i < n; i++){
        sum += static_cast<int>(arr[i]);
        if (arr[i] < 0){
            sum = 0;
        }
    }
    std::cout << "Integer sum of all elemnets after the last negative: " << sum << "\n";
    
    //преобразовние массива
    std::cout << "Array before tranformation:\n";
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    
    transform(arr, n, p);
    
    std::cout << "\nArray after tranformation:\n";
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\n";
    
    return 0;
}
