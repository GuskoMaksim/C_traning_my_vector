#pragma once
#include <iostream>

using namespace std;

template <class T>
class My_cont_vector
{
	T* data;
	int size;
	int max_size;
	void new_el_more_size();
public:
	My_cont_vector() noexcept;
	My_cont_vector(int n_size) noexcept;
	My_cont_vector(My_cont_vector<T>& arr) noexcept;

	void del_el(int index);
	void puch_back(const T& el);
	void clear();
	void new_size(int n_size);
	int getSize()
	{
		return size;
	}

	T& operator[](int ind)
	{
		if (ind > max_size)
			throw exception("index more than max");
		if (ind < 0)
			throw exception("index less than 0");
		return data[ind];
	}

	~My_cont_vector()
	{
		delete[] data;
	}
};


template <class T>
My_cont_vector<T>::My_cont_vector() noexcept
{
	max_size = 10;
	data = new T[max_size];
	size = 0;
}

template <class T>
My_cont_vector<T>::My_cont_vector(int n_size) noexcept
{
	this->max_size = 2 * n_size;
	this->size = n_size;
	data = new T[max_size];
	for (int i = 0; i < max_size; i++)
	{
		data[i] = 0;
	}
}

template <class T>
My_cont_vector<T>::My_cont_vector(My_cont_vector<T>& arr) noexcept
{
	max_size = arr.max_size;
	size = arr.size;
	data = new T[max_size];
	for (int i = 0; i < size; i++)
	{
		data[i] = arr.data[i];
	}
	data = arr;
}

template <class T>
void My_cont_vector<T>::new_el_more_size()
{
	max_size = size * 2;
	T* t_arr = new T[max_size];
	for (int i = 0; i < size; i++)
	{
		t_arr[i] = data[i];
	}
	delete[] data;
	data = t_arr;
}

template <class T>
void My_cont_vector<T>::puch_back(const T& el)
{
	if (size + 1 > max_size)
	{
		new_el_more_size();
	}
	data[size] = el;
	size++;
}

template <class T>
void My_cont_vector<T>::clear()
{
	delete[] data;
	size = 0;
	max_size = 10;
	data = new T[max_size];
}

template <class T>
void My_cont_vector<T>::new_size(int n_size)
{
	if (n_size > max_size)
	{
		int old_size = size;
		size = new_size;
		new_el_more_size();
	}
	else
	{
		T* t_data;
		t_data = new T[n_size];
		for (int i = 0; i < n_size; i++)
		{
			t_data[i] = data[i];
		}
		delete[] data;
		data = t_data;
	}
}

template <class T>
void My_cont_vector<T>::del_el(int index)
{
	T* t_data;
	t_data = new T[max_size];
	for (int i = 0, k = 0; i < size; i++, k++)
	{
		if (k == index)
			k++;
		t_data[i] = data[k];
	}
	delete[] data;
	data = t_data;
}