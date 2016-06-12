#include "stdafx.h"
#include "CapitalizeFilter.h"

void CapitalizeFilter::doIT()
{
	const char GAP = 'A' - 'a';

	for (size_t i = 0; i < this->text.length(); i++)
	{
		if (i == 0 && this->text[i] != ' ')
		{
			this->text[i] += GAP;
		}

		if (this->text[i] == ' ' && this->text[i + 1] != ' ')
		{
			this->text[i + 1] += GAP;
		}
	}
}
