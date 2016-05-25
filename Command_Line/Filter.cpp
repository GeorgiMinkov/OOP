#include "stdafx.h"
#include "Filter.h"

void Filter::copyElemets(const Filter & other)
{
	this->text = other.text;

	this->inputFileName = other.inputFileName;

	this->outputFileName = other.outputFileName;

	this->inputFile.open(this->inputFileName);

	this->outputFile.open(this->outputFileName);
}

Filter::Filter()
{
	this->text = "";

	this->inputFileName = "";

	this->outputFileName = "";
}

Filter::Filter(const Filter & other)
{
	this->copyElemets(other);
}

Filter::Filter(std::string text, std::string inputFileName, std::string outputFileName)
{
	this->text = text;

	//this->setTextToAllFields(text, outputFileName);

	this->inputFileName = inputFileName;
	// ��� ������������� ����� ������ �� �� ������ ifstream-�� ��� ofstream-��
	this->inputFile.open(inputFileName);

	this->outputFileName = outputFileName;
	// ��� ������������� ����� ������ �� �� ������ ifstream-�� ��� ofstream-��
	this->outputFile.open(outputFileName);

	// this->copyElemets(); ��������� ����, ��� ������ ������ �� �� ������
	this->setTextToAllFields(text, outputFileName);
}

Filter::~Filter()
{
	this->closeOpenFiles();
}

void Filter::setTextToAllFields(const std::string text, const std::string fileName)
{
	this->text = text;

	this->inputFileName = fileName;

	this->outputFileName = fileName;

	this->openFiles();

	if (this->outputFile.good())
	{
		this->outputFile << text;
	}
	else
	{
		std::cout << "File for write is not open.\n";
	}
}

std::string Filter::getText() const
{
	return this->text;
}

void Filter::inputFromCommandLine(const std::string fileName)
{
	std::string str;
	std::string strText;

	while (getline(std::cin, str))
	{
		strText += str + "\n";
	}

	this->setTextToAllFields(strText, fileName);
}

void Filter::openFiles()
{
	this->inputFile.open(this->inputFileName);

	this->outputFile.open(this->outputFileName);
}

// 5-�� ���� ������
void Filter::findWordLine(std::string word) // 1
{
	std::string thisLine;
	bool check = false;
	
	if (this->inputFile.good())
	{
		while (getline(this->inputFile, thisLine).good())
		{
			if (thisLine == word)
			{
				check = true;
				std::cout << thisLine;
			}
		}
	}
	else
	{
		std::cout << "File is not open\n";
	}

	if (!check)
	{
		std::cout << "No match for: " << word << std::endl;
	}
}

void Filter::smallToUpper() // 2
{
	if (this->outputFile.good())
	{
		for (size_t i = 0; i < this->text.length(); i++)
		{
			if (this->text[i] >= 'a' && this->text[i] <= 'z')
			{
				this->text[i] -= 'a';
			}
		}
	}
	else
	{
		std::cout << "No file is open to write\n";
	}
}

void Filter::upperToSmall() // 3
{
	if (this->outputFile.good())
	{
		for (size_t i = 0; i < this->text.length(); i++)
		{
			if (this->text[i] >= 'a' && this->text[i] <= 'z')
			{
				this->text[i] += 'a';
			}
		}
	}
	else
	{
		std::cout << "No file is open to write\n";
	}
}

void Filter::colorSpecificWord(std::string word) // 4
{
	std::string oneWord;
	bool check = false;

	if (this->outputFile.good())
	{
		// ��� ���� �� �� ������ ���������� ����, ���� �� ��������� �����?
	}
	else
	{
		std::cout << "No file is open.\n";
	}
}

void Filter::countEachWord() const // 5
{
	std::string word;
	std::vector<std::string> wordHolder;

	for (size_t i = 0; i < this->text.length(); i++)
	{
		if (this->text[i] != ' ')
		{
			if (this->text[i] != '\n')
			{
				word += text[i];
			}
			else
			{
				wordHolder.push_back(word);

				word = "";
			}
		}
		else
		{
			wordHolder.push_back(word);

			word = "";
		}
	}

	sort(wordHolder.begin(), wordHolder.end());

	size_t countWord = 0;
	word = wordHolder[0];

	for (size_t i = 0; i < wordHolder.size(); i++)
	{
		if (word != wordHolder[i])
		{
			std::cout << "Word " << word << " appear " << countWord << " times\n";
			
			word = wordHolder[i];

			countWord = 0;
		}

		countWord++;
	}

	std::cout << "Word " << word << " appear " << countWord << " times\n";
}

void Filter::closeOpenFiles()
{
	this->inputFile.close();

	this->outputFile.close();
}

// ������������� ���������
Filter & Filter::operator=(const Filter & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		this->closeOpenFiles();
		
		this->copyElemets(other);
	}

	return *this;
}

bool Filter::operator==(const Filter & other) const
{
	return this->text == other.text;
}

bool Filter::operator!=(const Filter & other) const
{
	return !(*this == other);
}

Filter & Filter::operator+=(char chararcter)
{
	// TODO: insert return statement here

	this->setTextToAllFields(this->text + std::to_string(chararcter), this->outputFileName);

	return *this;
}

Filter & Filter::operator+=(char * str)
{
	// TODO: insert return statement here
	if (str != nullptr)
	{
		this->setTextToAllFields(this->text + (std::string)str, this->outputFileName);
	}

	return *this;
}

std::ostream & operator<<(std::ostream &out, const Filter & source)
{
	// TODO: insert return statement here
	out << source.text;

	return out;
}

std::istream & operator >> (std::istream &in, Filter & source)
{
	// TODO: insert return statement here
	std::string str;
	std::string strText;

	while (getline(in, str))
	{
		strText += str + "\n";
	}

	std::cout << "Enter file name: "; 
	in >> str; // ���� �� ��������

	source.setTextToAllFields(strText, str);
	return in;
}
