//
//  task9_matrices.cpp
//  labs
//
//  Created by Taras Zaporozhets on 30.09.25.
//
#include <iostream>
#include <random>

//функция выделения памяти и создания матрицы
void allocate_matrix(int**& matrix, int n_rows, int n_cols){
    matrix = new int* [n_rows];

    for (int i = 0; i < n_rows; i++){
        matrix[i] = new int [n_cols];
    }
}

//функция удаления динамической матрицы
void delete_arr(int** arr, int n_rows){
    if (arr == nullptr){
        std::cout << "Pointer is NULL!\n";
        std::exit(1);
    }
    
    for (int i = 0; i < n_rows; i++){
        delete [] arr[i];
    }
    delete [] arr;
}

//функция ручного ввода элементов матрицы
void hand(int** matrix, int n_rows, int n_cols){
    std::cout << "Enter the elements of matrix: ";
    
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            if (!(std::cin >> matrix[i][j])){
                std::cout << "Incorrect input! Elements must be integer!\n";
                
                delete_arr(matrix, n_rows);
                std::exit(1);
            }
        }
    }
}

//функция заполнения элементов матрицы рандомными числами
void random(int** matrix, int n_rows, int n_cols){
    int lower_limit, upper_limit;
    
    std::cout << "Enter the range of random: ";
    
    if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit){
        std::cout << "Incorrect input! 1st integer must be lower than 2nd.\n";
        
        delete_arr(matrix, n_rows);
        std::exit(1);
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);
    
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            matrix[i][j] = distrib(gen);
        }
    }
}

//функция вывода матрицы
void print_matrix(int** matrix, int n_rows, int n_cols){
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
}

//функция подсчета столбцов без 0
int counter_of_no_zeroes(int** matrix, int n_rows, int n_cols){
    int count = 0;
    
    for (int j = 0; j < n_cols; j++){
        bool zero = false;
        
        for (int i = 0; i < n_rows; i++){
            if (matrix[i][j] == 0){
                zero = true;
                break;
            }
        }
        if (!zero){
            count++;
        }
    }
    
    return count;
}

//функция поиска строки с самой длинной возрастающей последовательностью
int row_with_longest_increasing_sequence(int** matrix, int n_rows, int n_cols) {
    int index = -1;
    int max_length = 0;
    
    for (int i = 0; i < n_rows; i++) {
        int current = 1;
        int max_current = 1;
        

        for (int j = 1; j < n_cols; j++) {
            if (matrix[i][j] > matrix[i][j - 1]) {
                current++;
                
                if (current > max_current) {
                    max_current = current;
                }
            }
            else {
                current = 1;
            }
        }
        if (max_current > max_length) {
            max_length = max_current;
            index = i;
        }
    }
    
    return index;
}


int main(){
    int rows = 0, cols = 0;
    char option;
    
    int** mat = nullptr;

    std::cout << "Enter the num of rows: ";
    if (!(std::cin >> rows) || rows <= 0){
        std::cout << "Incorrect value! Must be integer > 0!\n";
        std::exit(1);
    }
    
    std::cout << "Enter the num of columns: ";
    if (!(std::cin >> cols) || cols <= 0){
        std::cout << "Incorrect value! Must integer be > 0!\n";
        std::exit(1);
    }
    
    allocate_matrix(mat, rows, cols);

    std::cout << "Choose Hand Input or Random Input (h/r): ";
    std::cin >> option;
    
    std::cin.ignore();

    switch(option){
        case 'h':
            hand(mat, rows, cols);
            break;
        case 'r':
            random(mat, rows, cols);
            break;
        default:
            std::cout << "Incorrect option input!\n";
            
            delete_arr(mat, rows);
            std::exit(1);
            
    }
    
    print_matrix(mat, rows, cols);
    
    std::cout << "Count of columns with no zeroes: " << counter_of_no_zeroes(mat, rows, cols) << "\n";
    std::cout << "Number of the row with the longest increasing sequence: " << row_with_longest_increasing_sequence(mat, rows, cols) << "\n";
    
    delete_arr(mat, rows);
    
    return 0;
}