#include "stdafx.h"
#include "DecodeFilter.h"

std::string DecodeFilter::convertToLatin(std::string morse, const std::string morseCode[])
{
	std::string morseWord, phrase = "";
	bool check = false;

	for (size_t i = 0; i < morse.length(); i++)
	{
		while (morse[i] != ' ' && i < morse.length())
		{
			morseWord += morse[i];
			i++;
			check = true;
		}
		if (check)
		{
			--i;
			check = false;
			for (size_t index = 0; index < 29; index++)
			{
				if (morseWord == morseCode[index])
				{
					phrase += 'A' + index;
					if (i + 2 < morse.length() && morse[i + 2] == ' ') // за да види дали ни трябва space
					{
						phrase += " ";
					}
					morseWord = "";
					break;
				}
			}
		}
	}

	return phrase;
}

DecodeFilter::DecodeFilter() : EncodeFilter()
{
	this->fileToSave = "";
}

DecodeFilter::DecodeFilter(std::string text, std::string inputFileName, std::string outputFileName, std::string fileToSave) : 
	EncodeFilter(text, inputFileName, outputFileName)
{
	this->fileToSave = fileToSave;
}

void DecodeFilter::Decode()
{
	this->text = convertToLatin(this->text, this->morseAlphabet);
	this->setTextToAllFields(text, this->fileToSave);
}

std::string DecodeFilter::getText() const
{
	return this->text;
}
