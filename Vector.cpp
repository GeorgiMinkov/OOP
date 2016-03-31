#include "stdafx.h"
#include "Vector.h"
#include<iostream>

int main()
{
	return 0;
}

void Vector::resize(size_t newCapacity)
{
	int *buffer = new int[newCapacity];
	
	for (size_t i = 0; i < this->size; ++i)
	{
		buffer[i] = this->container[i];
	}

	delete[] this->container;
	this->container = buffer;
	this->capacity = newCapacity
}

Vector::Vector()
{
	this->capacity = initialCapacity;
	this->container = new int[this->capacity];
	this->size = 0;
}

Vector::Vector(size_t capacity, size_t size)
{
	this->capacity = capacity;
	this->container = new int[this->capacity];
	this->size = size;
	for (size_t i = 0; i < this->size; ++i)
	{
		this->container[i] = 0;
	}
	//this->container = { 0 };
}

Vector::Vector(const Vector & otherVector)
{
	this->capacity = otherVector.capacity;
	this->size = otherVector.size;
	this->container = new int[this->capacity];
	for (size_t i = 0; i < this->size; ++i)
		this->container[i] = otherVector.container[i];
}

Vector::~Vector()
{
	delete[] this->container;
}

bool Vector::SetAt(int value, size_t index)
{
	if (index >= this->capacity)
	{
		std::cout << "Error memory missmatch" << std::endl;
		return false;
	}
	
	this->container[index] = value;
	return true;
}

int Vector::GetAt(size_t index) const
{
	if (this->size < index)
	{
		std::cout << "Error memory missmatch" << std::endl;
		return -1;
	}
	else return this->container[index];
	
}

void Vector::PushBack(int element)
{
	if (this->size == this->capacity)
	{
		resize(this->capacity * 2);
		this->container[this->size] = element;
	}
	else this->container[this->size] = element;
}

void Vector::InsertAt(int element, size_t index)
{
	if (index > this->size);//направи отделните случаи
}
