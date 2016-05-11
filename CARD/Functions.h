#pragma once
#include "Deck.h"

void copy(Card *& finish, size_t size, const Card * source)
{
	for (size_t i = 0; i < size; i++)
		finish[i] = source[i];
}

size_t sum(const Card *source, const size_t size)
{
	size_t sum = 0;
	for (size_t i = 0; i < size; i++)
		sum += source[i].getAttack() + source[i].getLife(); // <- тук началната стойност на life ли трябва да е или при текущото състояние

	return sum;
}