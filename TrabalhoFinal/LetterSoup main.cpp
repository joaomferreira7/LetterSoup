// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <conio.h>
#include "Game.h"
#include "player.h"

//#define PLAYER_NAME "Ronaldo"


using namespace std;

int main() {
	int bw, bh, op;
	player Pl_Name;

	setlocale(LC_ALL, "Portuguese");

	do {
		cout << "A - NOVO JOGO" << endl << "B - CARREGAR JOGO SALVO" << endl << "C - SAIR" << endl << "Selecione uma opção: ";

		op = _getch();

		switch (op) {
		case 'a':
		case 'A':
		{
			system("cls");
			cout << "Insira o seu nome: " << endl;
			Pl_Name.Setname();
			cout << "Bom dia " << Pl_Name.Getname() << "!" << endl;
			do {
				cout << "Altura da grelha (15 a 50): ";
				cin >> bh;
			} while (bh < 15 || bh > 50);
			do {
				cout << "Largura da grelha (15 a 50): ";
				cin >> bw;
			} while (bw < 15 || bw > 50);
			system("CLS");

			Game MyGame(bw, bh, Pl_Name);

			MyGame.Run();
			break;
		}
		case 'b':
		case 'B':
		{
			Game MyGame;
			MyGame.load();
			system("cls");
			MyGame.Run();
			break;
		}
		case 'c':
		case 'C':
			break;
		default:
			printf("INVALIDO");
			_getch();
			break;
		}

		system("cls");

	} while (op != 67 && op != 99);

	system("pause");
}

