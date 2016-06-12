#include "stdafx.h"
#include "Filter.h"

void Filter::copyElemets(const Filter & other)
{
	this->text = other.text;

	this->inputFileName = other.inputFileName;

	this->outputFileName = other.outputFileName;
}

void Filter::creatFileForWrite()
{
	this->outputFile.open(this->outputFileName);
	this->outputFile.close();
}

void Filter::creatFileForRead()
{
	this->inputFile.open(this->inputFileName);
	this->inputFile.close();
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

	this->outputFile.open(this->outputFileName);

	if (this->outputFile.is_open())
	{
		this->outputFile << text;
	}
	else
	{
		// отвори и запиши
		this->outputFile.open(outputFileName);
		this->outputFile << text;
	}
	this->outputFile.close();
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

// Delete
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
	this->inputFile.open(this->inputFileName);

	if (this->inputFile.good())
	{
		std::istringstream f(this->text);
		std::string line;
		while (std::getline(f, line)) 
		{
			if (line.find(word) != -1)
			{
				std::cout << line << std::endl;
				check = true;
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
	this->outputFile.open(this->outputFileName, std::fstream::out | std::fstream::trunc); // За да изтрие текущото съдържание на файла

	if (this->outputFile.good())
	{
		for (size_t i = 0; i < this->text.length(); i++) 
		{
			if (this->text[i] >= 'a' && this->text[i] <= 'z')
			{
				this->text[i] = toupper(this->text[i]);
			}
		}

		this->outputFile << this->text;
		this->outputFile.close();
	}
	else
	{
		std::cout << "No file is open to write. Will load exist document.\n";
		this->outputFile.open(this->outputFileName, std::fstream::out | std::fstream::trunc);

		for (size_t i = 0; i < this->text.length(); i++)
		{
			if (this->text[i] >= 'a' && this->text[i] <= 'z')
			{
				this->text[i] = toupper(this->text[i]);
			}
		}

		this->outputFile << this->text;
		this->outputFile.close();
	}
}

void Filter::upperToSmall() // 3
{
	this->outputFile.open(this->outputFileName, std::fstream::out | std::fstream::trunc);

	if (this->outputFile.good())
	{
		std::transform(this->text.begin(), this->text.end(), this->text.begin(), ::tolower);

		this->outputFile << this->text;
		this->outputFile.close();
	}
	else
	{
		std::cout << "No file is open to write\n";
		this->outputFile.open(this->outputFileName, std::fstream::out | std::fstream::trunc);

		std::transform(this->text.begin(), this->text.end(), this->text.begin(), ::tolower);

		this->outputFile << this->text;
		this->outputFile.close();
	}
}

void Filter::colorSpecificSymbols(std::string word) const // 4 Тъй като NotePad няма оцветяване на текст той ще бъде само визуализиран оцветен
{
	HANDLE hConsole;
	int k = 0;
			
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool checkIT = false;
	for (size_t i = 0; i < this->text.length(); i++)
	{
		while (this->text[i] == word[k] && k < word.length())
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << this->text[i];
			i++;
			k++;
			checkIT = true;
		}
		k = 0;
		if (checkIT)
		{
			i--;
			checkIT = false;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << this->text[i];
		}
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

// Предефинирани оператори
Filter & Filter::operator=(const Filter & other)
{
	// TODO: =
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
	// TODO: +=
	std::stringstream ss;
	std::string s;
	ss << chararcter;
	ss >> s;
	this->setTextToAllFields(this->text + s, this->outputFileName);

	return *this;
}

Filter & Filter::operator+=(char * str)
{
	// TODO: +=
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
	std::string fileName;
	std::cout << "Enter file name: "; 
	in >> fileName; // Подаване на име на файла

	source.inputFromCommandLine(fileName + ".txt");

	return in;
}
