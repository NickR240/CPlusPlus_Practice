#pragma once

#include <cstddef>

template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();

    void push_back(const T& value);
    void pop_back();

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    std::size_t size() const;
    std::size_t capacity() const;
    bool empty() const;

    void clear();
    void reserve(std::size_t new_capacity);

private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;
};


// Constructor
template <typename T>
DynamicArray<T>::DynamicArray()
    : data_(nullptr),
    size_(0),
    capacity_(0)
{
}


// Destructor
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data_;
}


// Add a value to the end
template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    if (size_ == capacity_)
    {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }

    data_[size_] = value;
    ++size_;
}


// Remove the last value
template <typename T>
void DynamicArray<T>::pop_back()
{
    if (size_ > 0)
    {
        --size_;
    }
}


// Access a value
template <typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{
    return data_[index];
}


// Access a value from a const array
template <typename T>
const T& DynamicArray<T>::operator[](std::size_t index) const
{
    return data_[index];
}


// Return number of stored values
template <typename T>
std::size_t DynamicArray<T>::size() const
{
    return size_;
}


// Return current allocated capacity
template <typename T>
std::size_t DynamicArray<T>::capacity() const
{
    return capacity_;
}


// Check whether the array is empty
template <typename T>
bool DynamicArray<T>::empty() const
{
    return size_ == 0;
}


// Remove all values without releasing memory
template <typename T>
void DynamicArray<T>::clear()
{
    size_ = 0;
}


// Allocate more space
template <typename T>
void DynamicArray<T>::reserve(std::size_t new_capacity)
{
    if (new_capacity <= capacity_)
    {
        return;
    }

    T* new_data = new T[new_capacity];

    for (std::size_t i = 0; i < size_; ++i)
    {
        new_data[i] = data_[i];
    }

    delete[] data_;

    data_ = new_data;
    capacity_ = new_capacity;
}
