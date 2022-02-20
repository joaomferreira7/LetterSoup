#pragma once
#include <iostream>
#include <string>

#include "Point.h"


using namespace std;

class Word
{
public:
	Word(void);
	Word(string);
	Word(string, Point);
	~Word();

	void Set_Position(Point);
	Point Get_Position(void);
	string Get_Letters(void);
	void Set_Letters(string);
	void Set_Size(int s) { size = s; };

private:
	int size;
	string Letters;
	Point Position;
};

