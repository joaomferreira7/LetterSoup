//#include "pch.h"
#include "Word.h"

Word::Word(void)
{
	Set_Letters("");
}

Word::Word(string w)
{
	Set_Letters(w);
}

Word::Word(string s, Point p)
{
	Set_Letters(s);
	Set_Position(p);
}

Word::~Word()
{
}


void Word::Set_Position(Point p)
{
	Position = p;
}

Point Word::Get_Position(void)
{
	return Position;
}

void Word::Set_Letters(string w)
{
	Letters = w;
}

string Word::Get_Letters(void) {
	
	return Letters;

}