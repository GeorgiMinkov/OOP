#include "stdafx.h"
#include "Card.h"

Card::Card()
{
	this->attack = 0;

	this->life = 0;

	this->neededEnergy = 0;

	this->startingLife = 0;
}

Card::Card(size_t attack, size_t life)
{
	this->attack = attack;

	this->life = life;

	this->neededEnergy = life / 100 + attack / 20;

	this->startingLife = life;
}

Card::Card(const Card & other)
{
	this->attack = other.attack;

	this->life = other.life;

	this->neededEnergy = other.neededEnergy;

	this->startingLife = other.startingLife;
}

Card & Card::operator=(const Card & other)
{
	// TODO: Predefine operator =
	if (this != &other)
	{
		this->attack = other.attack;
		
		this->life = other.life;

		this->neededEnergy = other.neededEnergy;

		this->startingLife = other.startingLife;
	}

	return *this;
}

Card::~Card()
{
}

void Card::setAttack(const size_t & attack)
{
	this->attack = attack;
}

void Card::setLife(const size_t & life)
{
	this->life = life;
}

void Card::calculateNeededEnergy()
{
	this->neededEnergy = this->life / 100 + this->attack / 20;
}

size_t Card::getAttack() const
{
	return this->attack;
}

size_t Card::getLife() const
{
	return this->life;
}

size_t Card::getNeededEnergy() const
{
	return this->neededEnergy;
}

size_t Card::getStartingLife() const
{
	return this->startingLife;
}

bool Card::operator==(const Card & other) const
{
	return this->attack == other.attack && this->life == other.life; // не е необходимо да се проверява по необходима енергия, тъй като тя зависи пряко от атаката и живота
}

bool Card::operator!=(const Card & other) const
{
	return !(*this == other); // Провери дали ще даде правилен резултат
}

Card & Card::operator+=(const size_t & number)
{
	// TODO: insert return statement here
	if (this->life + number <= this->startingLife) this->life += number;

	return *this;
}

Card & Card::operator-=(const size_t & number)
{
	// TODO: insert return statement here
	if (this->life - number > 0) this->life -= number;

	return *this;
}

std::ostream & operator<<(std::ostream &out, const Card & source)
{
	// TODO: insert return statement here
	out << "Attack: " << source.attack << "\nLife: " << source.life << "\nNeeded Energy: " << source.neededEnergy;

	return out;
}

std::istream & operator >> (std::istream &in, Card & source)
{
	// TODO: insert return statement here
	in >> source.attack;
	in >> source.life;

	source.calculateNeededEnergy();

	return in;
}
