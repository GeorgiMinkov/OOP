#include "stdafx.h"
//#include "Deck.h"
#include "Functions.h"

Deck::Deck()
{
	this->cards = nullptr;

	this->numberOfCards = 0;
}

Deck::Deck(const Deck & other)
{
	this->numberOfCards = other.numberOfCards;

	this->cards = new Card[other.numberOfCards];

	copy(this->cards, other.numberOfCards, other.cards);
}

Deck::Deck(const Card * cards, size_t numberOfCards)
{
	this->numberOfCards = numberOfCards;

	this->cards = new Card[numberOfCards];

	copy(this->cards, numberOfCards, cards);
}

Deck & Deck::operator=(const Deck & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		if (this->cards != nullptr) delete[] this->cards;

		this->cards = new Card[other.numberOfCards];

		copy(this->cards, other.numberOfCards, other.cards);

		this->numberOfCards = other.numberOfCards;
	}

	return *this;
}

Deck::~Deck()
{
	delete[] this->cards;
}

void Deck::resize(const size_t newSize)
{
	assert(("Reached maximum amount of cards", newSize >= 0 && newSize <= 10));

	Card *buffer = new Card[newSize];
	assert(buffer);

	for (size_t i = 0; i < this->numberOfCards; i++)
		buffer[i] = this->cards[i];

	delete[] this->cards;

	this->cards = buffer;
	this->numberOfCards = newSize;
}

bool Deck::checkLegitimacy() const
{
	return this->numberOfCards >= 5;
}

void Deck::addNewCard(const Card & other)
{
	resize(this->numberOfCards + 1);

	this->cards[this->numberOfCards - 1] = other;
	
}

void Deck::deleteCard(const size_t & index)
{
	assert(("llegal index", index >= 0 && index < this->numberOfCards));
	
	for (size_t i = index; i < this->numberOfCards; i++)
		this->cards[i] = this->cards[i + 1];

	this->numberOfCards--;
}

void Deck::changeCard(const size_t & index, const Card &other)
{
	assert(("llegal index", index >= 0 && index < this->numberOfCards));

	this->cards[index] = other;
}

bool Deck::operator==(const Deck & other) const
{
	return true;
}

bool Deck::operator!=(const Deck & other) const
{
	return !(*this == other);
}

bool Deck::operator<(const Deck & other) const
{
	return sum(this->cards, this->numberOfCards) < sum(other.cards, other.numberOfCards);
}

bool Deck::operator>(const Deck & other) const
{
	return sum(this->cards, this->numberOfCards) > sum(other.cards, other.numberOfCards);
}

bool Deck::operator<=(const Deck & other) const
{
	return sum(this->cards, this->numberOfCards) <= sum(other.cards, other.numberOfCards);
}

bool Deck::operator>=(const Deck & other) const
{
	return sum(this->cards, this->numberOfCards) >= sum(other.cards, other.numberOfCards);
}

Deck & Deck::operator+=(const Card & other)
{
	// TODO: add card from the end of deck
	this->addNewCard(other);

	return *this;
}

Deck & Deck::operator+=(const Deck & other)
{
	// TODO: add deck to deck
	if (this != &other)
	{
		const size_t oldSize = this->numberOfCards;
		resize(oldSize + other.numberOfCards);
			
		for (size_t i = oldSize, j = 0; j < other.numberOfCards; i++, j++)
			this->cards[i] = other.cards[j];
	}
	else
	{
		Deck tmp = other;
		const size_t oldSize = this->numberOfCards;
		resize(oldSize + tmp.numberOfCards);

		for (size_t i = oldSize, j = 0; j < tmp.numberOfCards; i++, j++)
			this->cards[i] = tmp.cards[j];
	}
	return *this;
}

Card * Deck::operator[](size_t index)
{
	assert(("Illegal index", index >= 0 && index < this->numberOfCards));

	return &(this->cards[index]);
}

std::ostream & operator<<(std::ostream & out, const Deck & source)
{
	// TODO: cout predefenition
	for (size_t i = 0; i < source.numberOfCards; i++)
		out << source.cards[i] << std::endl;

	return out;
}

Deck operator+(const Card & left, const Deck & right)
{
	Deck tmp(right);

	tmp.resize(right.numberOfCards + 1);

	tmp.cards[right.numberOfCards - 1] = left;

	//tmp.numberOfCards++;

	return tmp;
}

Deck operator+(const Deck & left, const Card & right)
{
	Deck tmp(left);

	tmp.resize(left.numberOfCards + 1);

	tmp.cards[left.numberOfCards - 1] = right;

	return tmp;
}

Deck operator+(const Deck & left, const Deck & right)
{
	Deck tmp(left);
//добави проверка за макс размер
	tmp.resize(left.numberOfCards + right.numberOfCards);

	for (size_t i = left.numberOfCards, j = 0; j < right.numberOfCards; i++, j++)
		tmp.cards[i] = right.cards[j];

	return tmp;
}
