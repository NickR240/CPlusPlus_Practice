#include "dynamic_array.h"

template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
	if (size_ == capacity_)
	{
		reserver(capacity_ == 0 ? 1 : capacity_ * 2);
	}
	data_[size_++] = value;
}

template <typename T>
void DynamicArray<T>::reserve(std::size_t new_capacity)
{
	if (new_capacity > capacity_)
	{
		T* new_data = new T[new_capacity];
		for (std::size_t i = 0; i < size_; ++i)
		{
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
		capacity_ = new_capacity;
	}
}
