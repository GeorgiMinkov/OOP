#include "stdafx.h"
#include "FilterChain.h"

void FilterChain::copyFilters(const Filter * filterChain, const size_t &numberOfFilters)
{
	this->numberOfFilters = numberOfFilters;

	this->filterChain = new Filter[numberOfFilters];

	for (size_t i = 0; i < numberOfFilters; i++)
		this->filterChain[i] = filterChain[i];
}

void FilterChain::resize(size_t newSize)
{
	Filter *buffer = new Filter[newSize];

	for (size_t i = 0; i < this->numberOfFilters; i++)
		buffer[i] = this->filterChain[i];

	delete[] this->filterChain;

	this->filterChain = buffer;

	this->numberOfFilters = newSize;
}

FilterChain::FilterChain()
{
	this->filterChain = nullptr;

	this->numberOfFilters = 0;
}

FilterChain::FilterChain(const FilterChain & other)
{
	copyFilters(other.filterChain, other.numberOfFilters);
}

FilterChain::FilterChain(const Filter * filterChain, const size_t & numberOfFilters)
{
	copyFilters(filterChain, numberOfFilters);
}

FilterChain::~FilterChain()
{
	delete[] this->filterChain;
}

FilterChain & FilterChain::operator=(const FilterChain & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		if (this->filterChain != nullptr) delete[] this->filterChain;

		copyFilters(other.filterChain, other.numberOfFilters);
	}

	return *this;
}

bool FilterChain::operator==(const FilterChain & other) const
{
	int size = (this->numberOfFilters == other.numberOfFilters) ? this->numberOfFilters : -1;

	if (size != -1)
	{
		bool *checkArray = new bool[size], fastCheck = false;
		std::fill(checkArray, checkArray + size, false); // Запълвам динамично зададения масив с начална стойност false

		for (size_t i = 0, index = 0; i < size; i++, index++)
		{
			for (size_t j = 0; j < size && !checkArray[index]; j++)
			{
				if (this->filterChain[i] == other.filterChain[j])
				{
					checkArray[index] = true;
				}
			}
		}

		return std::all_of(checkArray, checkArray + size, [](bool i) { return i; }); // Проверяв дали всички елементи от масива са true
	}
	else
	{
		return false;
	}
}

bool FilterChain::operator!=(const FilterChain & other) const
{
	return !(*this == other);
}

FilterChain & FilterChain::operator+=(const Filter & newFilter)
{
	// TODO: insert return statement here
	resize(this->numberOfFilters + 1);

	this->filterChain[this->numberOfFilters - 1] = newFilter;

	return *this;
}

FilterChain & FilterChain::operator-=(const char * text)
{
	// TODO: delete all filters with text equal to entered text
	for (size_t i = 0; i < this->numberOfFilters; i++)
	{
		if (this->filterChain[i].getText() == (std::string)text)
		{
			this->filterChain[i] = this->filterChain[i + 1];
			--i;

			this->numberOfFilters--;
		}
	}

	return *this;
}

Filter & FilterChain::operator[](const int & index) const
{
	// TODO: get filter in index position
	if (index < 0 || index >= this->numberOfFilters)
	{
		std::cout << "\nEntered illegal index\n";
	}

	return this->filterChain[index];
}

Filter & FilterChain::operator[](const char * text) const
{
	// TODO: 
	for (size_t i = 0; i < this->numberOfFilters; i++)
	{
		if (this->filterChain[i].getText() == (std::string)text)
			return this->filterChain[i];
	}

	return Filter();
}

FilterChain operator|(const FilterChain & left, const Filter & right)
{
	FilterChain tmp(left);

	tmp.resize(tmp.numberOfFilters + 1);

	tmp.filterChain[tmp.numberOfFilters - 1] = right;

	return tmp;
}

FilterChain operator+(const FilterChain & left, const FilterChain & right)
{
	FilterChain tmp(left);
	size_t tmpSize = left.numberOfFilters + right.numberOfFilters;
	tmp.resize(tmpSize);

	for (size_t i = left.numberOfFilters, j = 0; i < tmpSize; i++, j++)
		tmp.filterChain[i] = right.filterChain[j];

	return tmp;
}
