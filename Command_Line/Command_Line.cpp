// Command_Line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Filter.h"

int main()
{
	Filter fil;
	fil.closeOpenFiles();

	fil.inputFromCommandLine();

	std::cout << fil;
    return 0;
}

