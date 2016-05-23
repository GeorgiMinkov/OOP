#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

class Filter
{
	std::string text;

	std::string inputFileName;
	std::ifstream inputFile;
	std::string outputFileName;
	std::ofstream outputFile;

	void copyElemets(const Filter &other);

public:
	// Конструктури
	Filter();
	Filter(const Filter &other);
	Filter(std::string text, std::string inputFileName, std::string outputFileName, std::ifstream inputFile, std::ostream outputFile); // Параметри
	~Filter();

	void setText(const std::string text); // Въвежда текста в полетата на класа

	void inputFromCommandLine(); // вход чрез cmd и свързване със setText
	void openFiles(); // Отваря двата потока
	void closeOpenFiles(); // Затваря файловете
	// Предефенирани оператори
	/*
	operator=  -стандартен
		operator== -сравнява два филтъра по стринга който филтрират
		operator!= -обратното на ==
		operator<< -записва низът за филтриране в поток(низ за филтриране - това което се филтрира от текста)
		operator >> -чете си низът за филтриране от поток(низ за филтриране - това което се филтрира от текста)
		operator+= -десен аргумент char добавя аргумента към края на низът за филтриране
		operator+= -десен аргумент char* добавя дадения низ към края на низът за филтриране
		operator|  -два аргумента Filter връща FilterChain съставен от аргументите си*/

	Filter &operator=(const Filter &other);

	// Булеви оператори

	bool operator==(const Filter &other) const;
	bool operator!=(const Filter &other) const;

	// Оператори за четене и изход
	friend std::ostream &operator<<(std::ostream &out, const Filter &source);
	friend std::istream &operator >> (std::istream &in, Filter &source); // Какво трябва да представлява това тук, както функцията ми enterFromCommandLine ли?

	Filter &operator+=(char chararcter);
	Filter &operator+=(char *str);

	//FilterChain &operator|(const Filter &right); Как трябва да изглежда	

	// 5-те оператора за филтриране
	void findWordLine(std::string word);
	void smallToUpper();
	void upperToSmall();
	void colorSpecificWord(std::string word);
	void countEachWord() const;
};