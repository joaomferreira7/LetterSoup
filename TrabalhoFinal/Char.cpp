#include "Char.h"


Char::Char(){
	Set_Ch('\0');
}

Char::Char(char c){
	Set_Ch(c);
}

Char::~Char() {
	Set_Ch('\0');
}

void Char::Rand(){
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	Set_Ch(letters[rand() % 26]);
	//cout << letters;
}

void Char::View(void){
	cout << Get_Ch();
}

