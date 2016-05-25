// Command_Line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Filter.h"

int main()
{
	Filter other("asdasda\nsda\nsd ", "newFile.txt", "newFile.txt");  //Защо показва, че не се е отворил файлът за запис

	Filter fil(other);

	fil.inputFromCommandLine("TestFile.txt");

	// fil.countEachWord(); Провери дали ще яде последната дума

	fil.findWordLine("sda");

	std::cout << fil << std::endl;


    return 0;
}

