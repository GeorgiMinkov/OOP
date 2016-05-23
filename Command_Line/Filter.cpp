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

Filter::Filter(std::string text, std::string inputFileName, std::string outputFileName, std::ifstream inputFile, std::ostream outputFile)
{
	this->text = text;

	this->inputFileName = inputFileName;
	// При конструктурът какво трябва да се отваря ifstream-ът или ofstream-ът
	this->inputFile.open(inputFileName);

	this->outputFileName = outputFileName;
	// При конструктурът какво трябва да се отваря ifstream-ът или ofstream-ът
	this->outputFile.open(outputFileName);

	// this->copyElemets(); Използвай това, ако всичко трябва да се отвори
}

Filter::~Filter()
{
	this->closeOpenFiles();
}

void Filter::setText(const std::string text)
{
	this->text = text;

	if (this->outputFile.good())
	{
		this->outputFile << text;
	}
	else
	{
		std::cout << "File for write is not open.\n";
	}
}

void Filter::inputFromCommandLine()
{
	std::string str;
	std::string strText;

	while (getline(std::cin, str))
	{
		strText += str + "\n";
	}

	this->setText(strText);
}

void Filter::openFiles()
{
	this->inputFile.open(this->inputFileName);

	this->outputFile.open(this->outputFileName);
}

// 5-те вида филтри
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
		// Как може да се оцвети специфична площ, като се анализира текст?
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

	size_t countWord = 1;
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

// Предефинирани оператори
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

	this->setText(this->text + std::to_string(chararcter));

	return *this;
}

Filter & Filter::operator+=(char * str)
{
	// TODO: insert return statement here
	if (str != nullptr)
	{
		this->setText(this->text + (std::string)str);
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

	while (getline(std::cin, str))
	{
		strText += str + "\n";
	}

	source.setText(strText);
	// Тук трябва ли да посоча файлове за отваряне?
	return in;
}
