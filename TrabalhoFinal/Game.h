#pragma once
#include <iostream>
#include "Board.h"
#include "player.h"
#include <fstream>
#include <conio.h>

class Game
{
	public:
		Game();
		Game(int, int, player);

		int Play();
		void Run();
		void load();
		void save();
		
	private:
		Board PlayBoard;
		string GamePlayer; 
		string acertadas[10] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
		// GamePlayer � apenas uma string para guardar o nome do jogador, 
		// mas futuramente ser� uma class com mais inform��o e funcionalidades 
		int GameScore;
		int GuessWords;
		// GameScore � um inteiro para guardar a pontua��o do jogo,  
		// mas futuramente ser� uma class com mais inform��o e funcionalidades 
		// para iniciar e terminar a contagem de tempo e calcular a pontua��po final

};

