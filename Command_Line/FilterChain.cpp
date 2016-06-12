#include "stdafx.h"
#include "FilterChain.h"

void FilterChain::copyFilters(const Filter * filterChain, const size_t & currentNumberOfFilters, const size_t & capacity)
{
	this->currentNumberOfFilters = currentNumberOfFilters;
	this->capacity = capacity;

	this->filterChain = new Filter[capacity];

	for (size_t i = 0; i < currentNumberOfFilters; i++)
	{
		this->filterChain[i] = filterChain[i];
	}
}

void FilterChain::resize()
{
	size_t newSize = this->capacity * 1.7 + 1;
	Filter *buffer = new Filter[newSize];

	for (size_t i = 0; i < this->currentNumberOfFilters; i++)
		buffer[i] = this->filterChain[i];

	delete[] this->filterChain;

	this->filterChain = buffer;
	this->capacity = newSize;
}

bool FilterChain::isFull() const
{
	return this->currentNumberOfFilters == this->capacity;
}

FilterChain::FilterChain()
{
	this->filterChain = nullptr;

	this->currentNumberOfFilters = 0;

	this->capacity = 0;
}

FilterChain::FilterChain(const FilterChain & other)
{
	copyFilters(other.filterChain, other.currentNumberOfFilters, other.capacity);
}

FilterChain::FilterChain(const Filter * filterChain, const size_t & currentNumberOfFilters, const size_t & capacity)
{
	copyFilters(filterChain, currentNumberOfFilters, capacity);
}

FilterChain::~FilterChain()
{
	delete[] this->filterChain;
}

FilterChain & FilterChain::operator=(const FilterChain & other)
{
	// TODO: =
	if (this != &other)
	{
		if (this->filterChain != nullptr) delete[] this->filterChain;

		copyFilters(other.filterChain, other.currentNumberOfFilters, other.capacity);
	}

	return *this;
}

bool FilterChain::operator==(const FilterChain & other) const
{
	int size = (this->currentNumberOfFilters == other.currentNumberOfFilters) ? this->currentNumberOfFilters : -1;

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
	if (this->isFull())
	{
		this->resize();

		this->filterChain[this->currentNumberOfFilters] = newFilter;
		this->currentNumberOfFilters++;
	}
	else
	{
		this->filterChain[this->currentNumberOfFilters] = newFilter;
		this->currentNumberOfFilters++;

	}

	return *this;
}

FilterChain & FilterChain::operator-=(const char * text)
{
	// TODO: delete all filters with text equal to entered text
	for (size_t i = 0; i < this->currentNumberOfFilters; i++)
	{
		if (this->filterChain[i].getText() == (std::string)text)
		{
			this->filterChain[i] = this->filterChain[i + 1];
			--i;

			this->currentNumberOfFilters--;
		}
	}

	return *this;
}

Filter & FilterChain::operator[](const int & index) const
{
	// TODO: get filter in index position
	if (index < 0 || index >= this->currentNumberOfFilters)
	{
		std::cout << "\nEntered illegal index, will return default filter\n";
		return Filter();
	}

	return this->filterChain[index];
}

Filter & FilterChain::operator[](const char * text) const
{
	// TODO: 
	for (size_t i = 0; i < this->currentNumberOfFilters; i++)
	{
		if (this->filterChain[i].getText() == (std::string)text)
			return this->filterChain[i];
	}

	return Filter();
}

FilterChain operator|(const FilterChain & left, const Filter & right)
{
	FilterChain tmp(left);

	if (tmp.capacity == tmp.currentNumberOfFilters)
	{
		tmp.resize();

		tmp.filterChain[tmp.currentNumberOfFilters] = right;

		tmp.currentNumberOfFilters++;
	}
	else
	{
		tmp.filterChain[tmp.currentNumberOfFilters] = right;

		tmp.currentNumberOfFilters++;
	}

	return tmp;
}

FilterChain operator+(const FilterChain & left, const FilterChain & right)
{
	FilterChain tmp(left);
	size_t tmpSize = left.currentNumberOfFilters + right.currentNumberOfFilters;
	
	while (tmpSize > tmp.capacity)
	{
		tmp.resize();
	}


	bool check = false;
	for (size_t i = left.currentNumberOfFilters, j = 0; j < left.currentNumberOfFilters; i++, j++)
	{
		for (size_t k = 0; k < left.currentNumberOfFilters && !check; k++)
		{
			if (tmp.filterChain[k] == right.filterChain[j])
			{
				check = true;
			}
		}
		if (!check)
		{
			tmp.filterChain[i] = right.filterChain[j];
		}
	}

	return tmp;
}
