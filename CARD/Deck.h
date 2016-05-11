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

	/*operator= - ����������� �� ���
operator== - ��������� ���� ��� ���� ���� ������� ����� (��� �������� ����������)
operator!= - ��������� ���� � ��� ���� ��� ���� 1 �������� ������ ��� �������� ���� �����
�perator < > <= >= - �������� ������ �� ����� � ������ �� ������� � ����� ����
operator<< - �������� �� ����� � �����
��������+ - ������ ����� � ��� � ����� ��� � ������� �� ���� � ������ �����(���������� ���� ������ ���� ������� ��� ����)
��������+ - ������ ��� ���� � ����� ��� ��� � ������� �� �����
operator+= - ������ ����� �������� ����� � � ������� � ����
operator+= - ������ ����� �������� ��� � ������� ������ ����� �� ���� � ���� �� ����
opertaor[] - ������ �������� ���� ����� n � ���� �������� ��� n-���� ����� � ����
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