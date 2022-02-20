#pragma once
#include <iostream>
#include <string>
using namespace std;


class player{

private:
	std:: string Pl_Name;


public:
	player(void);
	~player();
	void Setname (void);
	string Getname(void);
};