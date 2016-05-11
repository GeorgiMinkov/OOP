#pragma once
#include "Card.h"
#include<cassert>

class Deck
{
	Card *cards;
	size_t numberOfCards;

public:
	Deck();
	Deck(const Deck &other);
	Deck(const Card *cards, size_t numberOfCards);
	Deck & operator=(const Deck &other);
	~Deck();

	void resize(const size_t newSize);
	bool checkLegitimacy() const;

	void addNewCard(const Card &other);
	void deleteCard(const size_t &index);
	void changeCard(const size_t &index, const Card &other);

	/*operator= - пристояване на дек
operator== - проверява дали два дека имат еднакви карти (без значение подредбата)
operator!= - проверява дали в два дека има поне 1 различна карата или различен брой карти
оperator < > <= >= - сравнява сборът от атака и живота на картите в двата дека
operator<< - оператор за изход в поток
оператор+ - приема карта и дек и връша дек с картите от дека и новата карта(независимо дали отляво седи картата или дека)
оператор+ - приема два дека и връща нов дек с картите от двата
operator+= - приема десен аргумент карта и я прибавя в дека
operator+= - приема десен аргумент дек и прибавя всички карти от него в дека от ляво
opertaor[] - приема аргумент цяло число n и въща указател към n-тата карта в дека
*/
	bool operator==(const Deck &other) const;
	bool operator!=(const Deck &other) const;
	bool operator<(const Deck &other) const;
	bool operator>(const Deck &other) const;
	bool operator<=(const Deck &other) const;
	bool operator>=(const Deck &other) const;

	friend std::ostream & operator<<(std::ostream &out, const Deck &source);
//	friend std::istream & operator<<(std::istream in, Deck &source);

	friend Deck operator+(const Card &left, const Deck &right);
	friend Deck operator+(const Deck &left, const Card &right);
	friend Deck operator+(const Deck &left, const Deck &right);

	Deck & operator+=(const Card &other);
	Deck & operator+=(const Deck &other);

	Card * operator[](size_t index);

};