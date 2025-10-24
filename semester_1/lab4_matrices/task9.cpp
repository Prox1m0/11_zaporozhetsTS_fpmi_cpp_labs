//
//  task9_matrices.cpp
//  labs
//
//  Created by Taras Zaporozhets on 30.09.25.
//
#include <iostream>
#include <random>
#include <exception>

//проверка целочисленных данных
int read_int(){
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        throw std::invalid_argument("Expected integer value");
    }
    return value;
}

//проверка размера матрицы
int read_matrix_size() {
    int size = read_int(); 
    
    if (size <= 0) {
        throw std::out_of_range("Size must be > 0");
    }
    
    return size;
}

//функция выделения памяти и создания матрицы
void allocate_matrix(int**& matrix, int n_rows, int n_cols){
    matrix = new int* [n_rows];

    for (size_t i = 0; i < n_rows; i++){
        matrix[i] = new int [n_cols];
    }
}

//функция удаления динамической матрицы
void delete_arr(int** matrix, int n_rows){
    if (matrix == nullptr){
        throw std::invalid_argument("Null pointer is given to delete_arr");
    }
    
    for (size_t i = 0; i < n_rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

//функция ручного ввода элементов матрицы
void fill_manual(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_manual");
    }
    for (size_t i = 0; i < n_rows; i++){
        for (size_t j = 0; j < n_cols; j++){
            matrix[i][j] = read_int();
        }
    }
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

//функция заполнения элементов матрицы рандомными числами
void fill_random(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_random");
    }
    
    auto limits = read_random_limits();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(limits.first, limits.second);  
    
    for (size_t i = 0; i < n_rows; i++) {
        for (size_t j = 0; j < n_cols; j++){
            matrix[i][j] = distrib(gen);
        }
    }
}

//выбор заполнения
void fill_matrix(char option, int** matrix, int n_rows, int n_cols) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_matrix");
    }
    
    switch (option) {
        case 'h':
        case 'H':
            fill_manual(matrix, n_rows, n_cols);
            break;
        case 'r':
        case 'R':
            fill_random(matrix, n_rows, n_cols);
            break;
        default:
            throw std::invalid_argument("Invalid option. Use 'h' for manual or 'r' for random input");
    }
}

//функция вывода матрицы
void print_matrix(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to print_array");
    }
    
    for (size_t i = 0; i < n_rows; i++){
        for (size_t j = 0; j < n_cols; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
}

//функция подсчета столбцов без 0
int counter_of_no_zeroes(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr){
        throw std::invalid_argument("Null pointer passed to counter_of_no_zeroes");
    }
    
    int count = 0;
    
    for (size_t j = 0; j < n_cols; j++){
        bool zero = false;
        
        for (size_t i = 0; i < n_rows; i++){
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
    if (matrix == nullptr){
        throw std::invalid_argument("Null pointer passed to row_with_longest_increasing_sequence");
    }
    
    int index = -1;
    int max_length = 0;
    
    for (size_t i = 0; i < n_rows; i++) {
        int current = 1;
        int max_current = 1;

        for (size_t j = 1; j < n_cols; j++) {
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

    try{
        std::cout << "Enter the num of rows and columns: ";
        rows = read_matrix_size();
        cols = read_matrix_size();
        
        allocate_matrix(mat, rows, cols);

        std::cout << "Choose Hand Input or Random Input (h/r): ";
        std::cin >> option;
        std::cin.ignore();

        fill_matrix(option, mat, rows, cols);
        
        print_matrix(mat, rows, cols);
        
        std::cout << "Count of columns with no zeroes: " << counter_of_no_zeroes(mat, rows, cols) << "\n";
        std::cout << "Number of the row with the longest increasing sequence: " << row_with_longest_increasing_sequence(mat, rows, cols) << "\n";
        
        delete_arr(mat, rows);
    
        return 0;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        delete_arr(mat, rows);
        return 1;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        delete_arr(mat, rows);
        return 1;
    }
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
        delete_arr(mat, rows);
        return 1;
    } 
}