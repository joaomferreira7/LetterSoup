#pragma once

#include <iostream>

using namespace std;

class Char
{
public:
	Char();
	Char(char );
	~Char();

	void Rand(void);
	void View();

	void Set_Ch(char c) { Ch = c; }
	char Get_Ch() { return Ch; }

private:
	char Ch;

};

