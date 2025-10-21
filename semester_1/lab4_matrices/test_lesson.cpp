//
//  mat_sort.cpp
//  labs
//
//  Created by Taras Zaporozhets on 21.10.25.
//
#include <iostream>
#include <random>

void allocate_matrix(int**& matrix, int n_rows, int n_cols){
    matrix = new int* [n_rows];
    
    for (int i = 0; i < n_rows; i++){
        matrix[i] = new int [n_cols];
    }
}

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

void print_matrix(int** matrix, int n_rows, int n_cols){
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
}

void print_array(int* arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

void bubble_sort(int* arr, int size, bool (*comp)(int, int)){
    
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (comp(arr[i], arr[j])){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

void quick_sort(int* arr, int left, int right, bool (*comp)(int, int)) {
    if (left >= right) return;
    
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (comp(arr[i], pivot)) i++;
        while (comp(pivot, arr[j])) j--;
        
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    quick_sort(arr, left, j, comp);
    quick_sort(arr, i, right, comp);
}

void merge(int *a, int left, int mid, int right, int* temp, bool (*comp)(int, int))
{
    int i = left;
    int j = mid;
    int k = left;

    while(i < mid && j < right)
    {
        if(comp(a[i], a[j]))
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i < mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j < right)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int t = left; t < right; t++)
        a[t] = temp[t];

}

void merge_sort(int* a, int left, int right, int* temp, bool (*comp)(int, int))
{
    if(right - left <= 1) return;

    int mid = (left + right) / 2;

    merge_sort(a, left, mid, temp, comp);
    merge_sort(a, mid, right, temp, comp);

    merge(a, left, mid, right, temp, comp);
}

void insertionSort(int* arr, int n, bool (*comp)(int, int)) {
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
    return a < b;
}

bool descending(int a, int b){
    return a > b;
}

int main(){
    int rows = 0, cols = 0;
    int** mat = nullptr;
    
    std::cout << "Enter the num of rows and columns: ";
        if (!(std::cin >> rows) || rows <= 0 || !(std::cin >> cols) || cols <= 0){
            std::cout << "Incorrect value! Must be integer > 0!\n";
            std::exit(1);
        }
        
    allocate_matrix(mat, rows, cols);
    random(mat, rows, cols);
    
    std::cout << "Before sort:\n";
    print_matrix(mat, rows, cols);
    
    char option;
    std::cout << "Choose your sort:\n1. Bubble Sort (b)\n2. Quick Sort (q)\n3. Merge Sort (m)\n4. Insert Sort (i)\n";
    std::cin >> option;
    
    char order;
    std::cout << "Choose your order (a/d): ";
    std::cin >> order;
    
    switch (option) {
        case 'b':
            
            break;
        case 'q':
            break;
        case 'm':
            break;
        case 'i':
            break;
            
        default:
            std::cout << "Incorrect option input!\n";
            delete_arr(mat, rows);
            std::exit(1);
    }
    
    
}
