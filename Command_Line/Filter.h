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
	// ������������
	Filter();
	Filter(const Filter &other);
	Filter(std::string text, std::string inputFileName, std::string outputFileName); // ���������
	~Filter();
	void creatFileForWrite();
	void creatFileForRead();

	void setTextToAllFields(const std::string text, const std::string fileName); // ������� ������ � �������� �� �����

	std::string getText() const;

	void inputFromCommandLine(const std::string fileName); // ���� ���� cmd � ��������� ��� setTextToAllFields
	void openFiles(); // ������ ����� ������
	void closeOpenFiles(); // ������� ���������
	// ������������� ���������

	Filter &operator=(const Filter &other);

	// ������ ���������

	bool operator==(const Filter &other) const;
	bool operator!=(const Filter &other) const;

	// ��������� �� ������ � �����
	friend std::ostream &operator<<(std::ostream &out, const Filter &source);
	friend std::istream &operator >> (std::istream &in, Filter &source); // ����� ������ �� ������������ ���� ���, ����� ��������� �� enterFromCommandLine ��?

	Filter &operator+=(char chararcter);
	Filter &operator+=(char *str);	

	// 5-�� ��������� �� ����������
	void findWordLine(std::string word);
	void smallToUpper();
	void upperToSmall();
	void colorSpecificSymbols(std::string word) const;
	void countEachWord() const;
};