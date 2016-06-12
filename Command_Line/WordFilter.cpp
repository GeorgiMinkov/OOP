#include"stdafx.h"
#include"WordFilter.h"

void WordFilter::printWordLine(std::string word)
{
	// Filter::findWordLine(word); защо не мога да ги използвам така
	this->findWordLine(word);
}