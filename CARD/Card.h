#pragma once
#include<iostream>

class Card
{
	size_t attack;
	size_t life; // �� ���� �� � �����������, ��� ���� ���� � ������� �� �������, � �� �� ������
	size_t neededEnergy;
	// ������������ �� �� ������ � ���� ������, � �� ��� ��� �� ��� ����� �� ��� ������

	size_t startingLife;
public:
	Card();
	Card(size_t attack, size_t life);
	Card(const Card &other);
	Card & operator=(const Card &other);
	~Card();
	
	// Setters
	void setAttack(const size_t &attack);
	void setLife(const size_t &life);
	void calculateNeededEnergy();

	// Getters
	size_t getAttack() const;
	size_t getLife() const;
	size_t getNeededEnergy() const;
	size_t getStartingLife() const;

	bool operator==(const Card &other) const;
	bool operator!=(const Card &other) const ;
	
	friend std::ostream& operator<<(std::ostream &out, const Card &source);
	friend std::istream& operator >> (std::istream &in, Card &source);

	Card & operator+=(const size_t &number);
	Card & operator-=(const size_t &number);

};