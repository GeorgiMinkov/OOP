#pragma once
#include"Filter.h"
#include<sstream>

class EncodeFilter : public Filter
{
protected:
	std::string latinAlphabet;
	std::string morseAlphabet[29];

	std::string convertToMorse(std::string text, const std::string  morseAlphabet[], const std::string latin);
public:
	EncodeFilter();
	EncodeFilter(std::string text, std::string inputFileName, std::string outputFileName);
	EncodeFilter &operator=(const EncodeFilter &other);

	void morseEncoding();
};