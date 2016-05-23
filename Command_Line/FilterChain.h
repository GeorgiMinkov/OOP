#pragma once

#include"Filter.h"

class FilterChain
{
protected:
	Filter *filterChain;
	size_t numberOfFilters;

public:

	// предефинирани оператори
	FilterChain &operator=(const FilterChain &other);

	bool operator==(const FilterChain &other) const;
	bool operator!=(const FilterChain &other) const;

	FilterChain &operator+=(const Filter &newFilter);
	FilterChain &operator-=(const char *text);

	friend FilterChain operator|(const FilterChain &left, const Filter &right);
	friend FilterChain operator+(const FilterChain &left, const FilterChain &right);
	 
	FilterChain &operator[](const int &index) const; // провери дали с или без &
	FilterChain &operator[](const char *text) const;
};