#include "vector_impl.h"

Vector::Vector() {}

Vector::Vector(size_t size) : size_(size), capacity_(size), arr_(new int [size_]) {
    for (size_t i = 0; i < size_; i++) {
        arr_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> list) : size_(list.size()), capacity_(size_), arr_(new int [size_]){
    for (size_t i = 0; i < size_; i++) {
        arr_[i] = *(list.begin() + i);
    }
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_), arr_(new int [size_]) {
    for (size_t i = 0; i < size_; i++) {
        arr_[i] = other.arr_[i];
    }
    //std::copy(other.arr_, other.arr_ + size, arr_);
}

Vector::~Vector() {
    delete [] arr_;
}

void Vector::Swap(Vector& other) {
    if(this != &other){
        std::swap(arr_, other.arr_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }
}

void Vector::PushBack(int value){
    if (size_ == capacity_){
        size_t new_capacity;
        if (capacity_ == 0){
            new_capacity = 1;
        } else {
            new_capacity = capacity_ * 2;
        }
        int* new_arr = new int [new_capacity];
        for (size_t i = 0; i < size_; i++) {
            new_arr[i] = arr_[i];
        }
        //std::copy(arr_, arr_ + size_, new_arr);
        delete [] arr_;
        arr_ = new_arr;
        capacity_ = new_capacity;
    }
    arr_[size_++] = value;
}

void Vector::PopBack(){
    if (size_== 0){
        throw std::out_of_range("Vector is empty!");
    }
    size_--;
}

void Vector::Clear(){
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity){
    if (new_capacity > capacity_){
        int* new_arr = new int [new_capacity];
        for (size_t i = 0; i < size_; i++) {
            new_arr[i] = arr_[i];
        }
        delete [] arr_;
        arr_ = new_arr;
        capacity_ = new_capacity;
    }
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

int& Vector::At(size_t index){
    if (index >= size_){
        throw std::out_of_range("List index out of range!");
    }
    return arr_[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_){
        throw std::out_of_range("List index out of range!");
    }
    return arr_[index];
}

Vector& Vector::operator=(const Vector& other){
        if (this == &other){
            return *this;
        }
        size_ = other.size_;
        capacity_ = other.capacity_;
        delete [] arr_;
        arr_ = new int[size_];
        for (size_t i = 0; i < size_; i++) {
            arr_[i] = other.arr_[i];
        }
        //std::copy(other.arr_, other.arr_ + size_, arr_);
        return *this;
}

int& Vector::operator[](size_t index){
    return arr_[index];
}

const int& Vector::operator[](size_t index) const {
    return arr_[index];
}

std::ostream& operator<<(std::ostream& out, const Vector& vector){
    out << '[';
    for (size_t i = 0; i < vector.Size(); i++) {
        out << vector[i];
        if (i < vector.Size() - 1){
            out << ", ";
        }
    }
    out << ']';
    return out;
}