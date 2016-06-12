#include "stdafx.h"
#include "EncodeFilter.h"

std::string EncodeFilter::convertToMorse(std::string text, const std::string morseAlphabet[], const std::string latin)
{
	std::string morsePhrase = "";

	for (size_t i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ')
		{
			morsePhrase += " ";
			continue;
		}
		if (text[i] == '\n')
		{
			morsePhrase += '\n';
			continue;
		}
		for (size_t index = 0; index < 29; index++)
		{
			if (text.at(i) == latin[index])
			{
				morsePhrase += morseAlphabet[index] + " ";
				break;
			}
		}
	}

	return morsePhrase.substr(0, morsePhrase.size() - 1); // за да премахна последното " "
}

EncodeFilter::EncodeFilter()
{
	this->latinAlphabet = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ.," };

	
	std::string _morseAlphabet[29] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
	for (size_t i = 0; i < 29; i++)
		this->morseAlphabet[i] = _morseAlphabet[i];
}

EncodeFilter::EncodeFilter(std::string text, std::string inputFileName, std::string outputFileName) :
	Filter(text, inputFileName, outputFileName)
{
	this->latinAlphabet = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ.," };


	std::string _morseAlphabet[29] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
	for (size_t i = 0; i < 29; i++)
		this->morseAlphabet[i] = _morseAlphabet[i];

}

EncodeFilter & EncodeFilter::operator=(const EncodeFilter & other)
{
	// TODO: =
	if (this != &other)
	{
		Filter::operator=(other);
		this->latinAlphabet = other.latinAlphabet;

		for (size_t i = 0; i < 29; i++)
			this->morseAlphabet[i] = other.morseAlphabet[i];
	}
	
	return *this;
}

void EncodeFilter::morseEncoding()
{
	this->smallToUpper();

	this->text = this->convertToMorse(this->text, this->morseAlphabet, this->latinAlphabet);

	this->setTextToAllFields(this->text, this->outputFileName);
}
