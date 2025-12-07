#pragma once
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Vector {
    private:
        size_t size_ = 0;
        size_t capacity_ = 0;
        int* arr_ = nullptr;
    public:
        Vector();
        Vector(size_t);
        Vector(std::initializer_list<int>);
        Vector(const Vector&);
        ~Vector();
        void Swap(Vector&);
        void PushBack(int value);
        void PopBack();
        void Clear();
        void Reserve(size_t);
        size_t Size() const;
        size_t Capacity() const;
        int& At(size_t);
        const int& At(size_t) const;
        Vector& operator=(const Vector&);
        int& operator[](size_t);
        const int& operator[](size_t) const;
};

std::ostream& operator<<(std::ostream&, const Vector&);