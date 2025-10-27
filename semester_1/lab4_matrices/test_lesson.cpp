//
//  test_lesson.cpp
//  labs
//
//  Created by Taras Zaporozhets on 21.10.25.
//
#include <iostream>
#include <random>
#include <exception>

int read_int(){
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Expected integer value");
    }
    return value;
}


void allocate_matrix(int**& matrix, int n_rows, int n_cols){
    matrix = new int* [n_rows];

    for (size_t i = 0; i < n_rows; i++){
        matrix[i] = new int [n_cols];
    }
}

int read_matrix_size() {
    int size = read_int(); 
    
    if (size <= 0) {
        throw std::out_of_range("Size must be > 0");
    }
    
    return size;
}

void delete_mat(int** matrix, int n_rows){
    if (matrix == nullptr){
        return;
    }
    
    for (size_t i = 0; i < n_rows; i++){
        if (matrix[i] != nullptr){
            delete [] matrix[i];
            matrix[i] = nullptr;
        } 
    }
    delete [] matrix;
}

std::pair<int, int> read_random_limits(){    
   
    std::cout << "Enter the range of random: ";
    int lower_limit = read_int();
    int upper_limit = read_int();

    if (lower_limit > upper_limit){
        std::swap(lower_limit, upper_limit);
    }

    return {lower_limit, upper_limit};
}

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

void fill_manual(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_manual");
    }
    std::cout << "Enter the elements of matrix: ";
    for (size_t i = 0; i < n_rows; i++){
        for (size_t j = 0; j < n_cols; j++){
            matrix[i][j] = read_int();
        }
    }
}

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

void print_matrix(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to print_matrix");
    }
    
    for (size_t i = 0; i < n_rows; i++){
        for (size_t j = 0; j < n_cols; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
}

void bubble_sort(int* arr, int size, bool (*comp)(int, int)){
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (comp(arr[j], arr[j + 1])){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sort_selection(int* arr, int size, bool (*comp)(int, int))
{
    for(int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(comp(arr[min_index], arr[j]))
                min_index = j;
        }
        std::swap(arr[i], arr[min_index]);
    }
}

void merge(int *a, int left, int mid, int right, int* temp, bool (*comp)(int, int)){
    int i = left;
    int j = mid;
    int k = left;

    while(i < mid && j < right){
        if(comp(a[j], a[i])) { 
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i < mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j < right){
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int t = left; t < right; t++)
        a[t] = temp[t];
}

void merge_sort(int* a, int left, int right, int* temp, bool (*comp)(int, int)){
    if(right - left <= 1) return;

    int mid = (left + right) / 2;
    merge_sort(a, left, mid, temp, comp);
    merge_sort(a, mid, right, temp, comp);
    merge(a, left, mid, right, temp, comp);
}

void insertion_sort(int* arr, int n, bool (*comp)(int, int)) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && comp(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

bool ascending(int a, int b){
    return a > b;
}

bool descending(int a, int b){
    return a < b;
}

void order_choice(bool (*&comp)(int, int)){
    int order;
    std::cout << "Choose order of sorting (1 - ascending, 2 - descending): ";
    order = read_int();

    switch (order) {
        case 1:
            comp = ascending;
            break;
        case 2:
            comp = descending;
            break;
        default:
            throw std::invalid_argument("Invalid option. 1 or 2 only");
    }
    
}

void sort_choice(int** mat, int n_rows, int n_cols, bool (*comp)(int, int)){
    if (mat == nullptr) {
        throw std::invalid_argument("Null pointer passed to sort_choice");
    }  
    if (comp == nullptr) {
        throw std::invalid_argument("Comparison function not set");
    }

    int option;
    std::cout << "Choose your sort: 1 - Bubble, 2 - Selection, 3 - Merge, 4 - Insertion : ";
    option = read_int();
    
    for (size_t i = 0; i < n_rows; i++){
        switch (option){
            case 1:
                bubble_sort(mat[i], n_cols, comp);
                break;
            case 2:
                sort_selection(mat[i], n_cols, comp);
                break;
            case 3:
                {
                int* temp = nullptr;
                try {
                    temp = new int[n_cols];
                    merge_sort(mat[i], 0, n_cols, temp, comp);
                }
                catch(...){
                    delete [] temp;
                    throw;
                }
                delete [] temp;
                break;
                }
            case 4:
                insertion_sort(mat[i], n_cols, comp);
                break;
            default:
                throw std::invalid_argument("Invalid option. From 1 to 4 only");
        }
    }

}

int main(){
    int rows = 0, cols = 0;
    char option;
        
    bool (*comp)(int, int) = nullptr;
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
        
        std::cout << "Before sort:\n";
        print_matrix(mat, rows, cols);
        
        order_choice(comp);
        sort_choice(mat, rows, cols, comp);
        print_matrix(mat, rows, cols);

        delete_mat(mat, rows);
        
    }
  catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        delete_mat(mat, rows);
        return 1;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
        delete_mat(mat, rows);
        return 1;
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
        delete_mat(mat, rows);
        return 1;
    }
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
        delete_mat(mat, rows);
        return 1;
    }  
    return 0;
}