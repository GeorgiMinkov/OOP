#pragma once

#include"Filter.h"

class FilterChain
{
protected:
	Filter *filterChain;
	size_t currentNumberOfFilters;
	size_t capacity;

	void copyFilters(const Filter *filterChain, const size_t &currentNumberOfFilters, const size_t &capacity);
	void resize(); // да пренапиша ли логиката, така че да имам контейнер (sizeContent, currentSize)

	bool isFull() const;
public:
	FilterChain();
	FilterChain(const FilterChain &other);
	FilterChain(const Filter *filterChain, const size_t &currentNumberOfFilters, const size_t &capacity);
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