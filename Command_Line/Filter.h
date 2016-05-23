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
	// ������������
	Filter();
	Filter(const Filter &other);
	Filter(std::string text, std::string inputFileName, std::string outputFileName, std::ifstream inputFile, std::ostream outputFile); // ���������
	~Filter();

	void setText(const std::string text); // ������� ������ � �������� �� �����

	void inputFromCommandLine(); // ���� ���� cmd � ��������� ��� setText
	void openFiles(); // ������ ����� ������
	void closeOpenFiles(); // ������� ���������
	// ������������� ���������
	/*
	operator=  -����������
		operator== -�������� ��� ������� �� ������� ����� ���������
		operator!= -��������� �� ==
		operator<< -������� ����� �� ���������� � �����(��� �� ���������� - ���� ����� �� �������� �� ������)
		operator >> -���� �� ����� �� ���������� �� �����(��� �� ���������� - ���� ����� �� �������� �� ������)
		operator+= -����� �������� char ������ ��������� ��� ���� �� ����� �� ����������
		operator+= -����� �������� char* ������ ������� ��� ��� ���� �� ����� �� ����������
		operator|  -��� ��������� Filter ����� FilterChain �������� �� ����������� ��*/

	Filter &operator=(const Filter &other);

	// ������ ���������

	bool operator==(const Filter &other) const;
	bool operator!=(const Filter &other) const;

	// ��������� �� ������ � �����
	friend std::ostream &operator<<(std::ostream &out, const Filter &source);
	friend std::istream &operator >> (std::istream &in, Filter &source); // ����� ������ �� ������������ ���� ���, ����� ��������� �� enterFromCommandLine ��?

	Filter &operator+=(char chararcter);
	Filter &operator+=(char *str);

	//FilterChain &operator|(const Filter &right); ��� ������ �� ��������	

	// 5-�� ��������� �� ����������
	void findWordLine(std::string word);
	void smallToUpper();
	void upperToSmall();
	void colorSpecificWord(std::string word);
	void countEachWord() const;
};