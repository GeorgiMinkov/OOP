#pragma once

#include"Filter.h"

class FilterChain
{
protected:
	Filter *filterChain;
	size_t numberOfFilters;

	void copyFilters(const Filter *filterChain, const size_t &numberOfFilters);
	void resize(size_t newSize); // да пренапиша ли логиката, така че да имам контейнер (sizeContent, currentSize)
public:
	FilterChain();
	FilterChain(const FilterChain &other);
	FilterChain(const Filter *filterChain, const size_t &numberOfFilters);
	~FilterChain();

	// предефинирани оператори
	FilterChain &operator=(const FilterChain &other);

	bool operator==(const FilterChain &other) const;
	bool operator!=(const FilterChain &other) const;

	FilterChain &operator+=(const Filter &newFilter);
	FilterChain &operator-=(const char *text);

	friend FilterChain operator|(const FilterChain &left, const Filter &right);
	friend FilterChain operator+(const FilterChain &left, const FilterChain &right);
	 
	Filter &operator[](const int &index) const; // провери дали с или без &
	Filter &operator[](const char *text) const;
};