#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<sstream>

class Filter
{
protected:
	std::string text; // Save all text

	std::string inputFileName;
	std::ifstream inputFile; // read from file

	std::string outputFileName; 
	std::ofstream outputFile; // save to file

	void copyElemets(const Filter &other);
	
	

public:
	// Конструктури
	Filter();
	Filter(const Filter &other);
	Filter(std::string text, std::string inputFileName, std::string outputFileName); // Параметри
	~Filter();
	void creatFileForWrite();
	void creatFileForRead();

	void setTextToAllFields(const std::string text, const std::string fileName); // Въвежда текста в полетата на класа

	std::string getText() const;

	void inputFromCommandLine(const std::string fileName); // вход чрез cmd и свързване със setTextToAllFields
	void openFiles(); // Отваря двата потока
	void closeOpenFiles(); // Затваря файловете
	// Предефенирани оператори

	Filter &operator=(const Filter &other);

	// Булеви оператори

	bool operator==(const Filter &other) const;
	bool operator!=(const Filter &other) const;

	// Оператори за четене и изход
	friend std::ostream &operator<<(std::ostream &out, const Filter &source);
	friend std::istream &operator >> (std::istream &in, Filter &source); // Какво трябва да представлява това тук, както функцията ми enterFromCommandLine ли?

	Filter &operator+=(char chararcter);
	Filter &operator+=(char *str);	

	// 5-те оператора за филтриране
	void findWordLine(std::string word);
	void smallToUpper();
	void upperToSmall();
	void colorSpecificSymbols(std::string word) const;
	void countEachWord() const;
};