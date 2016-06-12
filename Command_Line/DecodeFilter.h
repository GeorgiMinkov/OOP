#pragma once
#include"EncodeFilter.h"

class DecodeFilter : public EncodeFilter
{
	std::string fileToSave;

	std::string convertToLatin(std::string morse, const std::string morseCode[]);

public:
	DecodeFilter();
	DecodeFilter(std::string text, std::string inputFileName, std::string outputFileName, std::string fileToSave);
	void Decode();
	std::string getText() const;
};