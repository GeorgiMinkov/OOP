// Command_Line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Filter.h"

int main()
{
	Filter other("asdasda\nsda\nsd ", "newFile.txt", "newFile.txt");  //���� �������, �� �� �� � ������� ������ �� �����

	Filter fil(other);

	fil.inputFromCommandLine("TestFile.txt");

	// fil.countEachWord(); ������� ���� �� ��� ���������� ����

	fil.findWordLine("sda");

	std::cout << fil << std::endl;


    return 0;
}

