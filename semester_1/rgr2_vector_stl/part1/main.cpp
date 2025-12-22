#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <stdexcept>
#include <string>
#include <cmath>
#include <cstdlib>

int sum(const std::vector<int>& vector){
    int sum = 0;
    for (size_t i = 0; i < vector.size(); ++i) {
        sum += vector[i];
    }
    return sum;
}

size_t get_length(const std::vector<int>& vector){
    return vector.size();
}

int get_equals_to(const std::vector<int>& vector, int target){
    int count = 0;
    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i] == target){
            count++;
        }
    }
    return count;
}

int get_by_condition(const std::vector<int>& vector, int n){
    int count = 0;
    for (size_t i = 0; i < vector.size(); ++i){

        if (vector[i] >= n){
            count++;
        }
    }
    return count;
}

void change_zeroes(std::vector<int>& vector){
    if (vector.empty()) return;
    int avg = sum(vector) / get_length(vector);
    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i] == 0){
            vector[i] = avg;
        }
    }
}

void add_sum(std::vector<int>& vector, int start, int end){
    if (start < 0 || end >= vector.size() || start >= vector.size() || end < 0){
        throw std::out_of_range("Invalid range");
    }
    if (start > end){
        std::swap(start, end);
    }
    int sum = 0;
    for (size_t i = start; i <= end; ++i) {
        sum += vector[i];
    }
    for (size_t i = 0; i < vector.size(); ++i) {
        vector[i] += sum;
    }
}

std::pair<int, int> get_min_max(const std::vector<int>& vector){
    if (vector.empty()) {
        throw std::invalid_argument("Vector is empty");
    }
    int max = vector[0];
    int min = vector[0];

    for (size_t i = 1; i < vector.size(); ++i) {
        if (vector[i] < min){
            min = vector[i];
        }
        if (vector[i] > max){
            max = vector[i];
        }
    }
    return {min, max};
}

bool is_abs_even(int number){
    return abs(number) % 2 == 0;
}

void change_evens(std::vector<int>& vector){
    int diff = 0;
    std::pair<int, int> min_max = get_min_max(vector);
    diff = min_max.second - min_max.first;

    for (size_t i = 0; i < vector.size(); ++i) {
        if (is_abs_even(vector[i])){
            vector[i] = diff;
        }
    }
}

void delete_similars(std::vector<int>& vector){
    std::set<int> seen{};
    for (auto it = vector.begin(); it != vector.end(); ) {
        int abs_value = std::abs(*it);
        if (seen.find(abs_value) != seen.end()) {
            it = vector.erase(it); 
        } else {
            seen.insert(abs_value);
            ++it;
        }
    }
}

void fill_vector(std::vector<int>& vector){
    std::string line;
    std::cout << "Enter vector elements: ";
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int num;
    while (stream >> num){
        vector.push_back(num);
    }
}

void print_vector(const std::vector<int>& vector){
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i];
        if (i < vector.size() - 1){
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}

void print_results(std::vector<int>& vector, int target, int n, int start, int end){
    std::cout << "Original vector: ";
    print_vector(vector);
    std::cout << "Sum: " << sum(vector) << '\n';
    std::cout << "Length: " << get_length(vector) << '\n';
    std::cout << "Equals to target: " << get_equals_to(vector, target) << '\n';
    std::cout << "By condition (>= n (n = " << n << ")): " << get_by_condition(vector, n) << '\n';
    
    {   
        std::vector<int> copy = vector;
        std::cout << "All zeroes -> average: ";
        change_zeroes(copy);
        print_vector(copy);
    }

    {   
        std::vector<int> copy = vector;
        std::cout << "Range sum to all: ";
        add_sum(copy, start, end);
        print_vector(copy);
    }
    
    {   
        std::vector<int> copy = vector;
        std::cout << "All even abs -> max - min: ";
        change_evens(copy);
        print_vector(copy);
    }

    {   
        std::vector<int> copy = vector;
        std::cout << "Deleting similars abs: ";
        delete_similars(copy);
        print_vector(copy);  
    }
}

int main() {
    std::vector<int> vector{};
    int target = 2, n = 0, start = 3, end = 6;
    try{
        fill_vector(vector);
        print_results(vector, target, n, start, end);
    }
    catch (const std::exception& e){
        std::cout << e.what() << '\n';
        return 1;
    }
    return 0;
}