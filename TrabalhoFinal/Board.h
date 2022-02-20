#pragma once
#include <iostream>
#include "Char.h"
#include "Word.h"



class Board
{
public:
	Word* Words;
	Board(void);
	void Init(int sx , int sy );
	void Init2(int sx , int sy, int num);
	void View(Board x, string y);	
	~Board();
	

	inline void Set_BoardWidth(int bw) { BoardWidth = bw; }
	inline void Set_BoardHeight(int bh) { BoardHeight = bh; };

	int get_BoardWidth() { return BoardWidth; }
	int get_BoardHeight() { return BoardHeight; };

	char getChar(int y, int x) { return Chars[y][x].Get_Ch(); };
	int getChar2(int y, int x) { return Chars2[y][x]; };

	void setChar(int y, int x, char a) { Chars[y][x].Set_Ch(a); };
	void setChar2(int y, int x, int a) { Chars2[y][x] = a; };

	int getNumWords() { return NumWords; };
	void setNumWords(int a) { NumWords = a; };

private:
	int BoardWidth;
	int BoardHeight;
	Char** Chars;
	int NumWords;
	int Chars2[50][50];
	int numWords;
	

};
