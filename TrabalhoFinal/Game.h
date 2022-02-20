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
		// GamePlayer é apenas uma string para guardar o nome do jogador, 
		// mas futuramente será uma class com mais informção e funcionalidades 
		int GameScore;
		int GuessWords;
		// GameScore é um inteiro para guardar a pontuação do jogo,  
		// mas futuramente será uma class com mais informção e funcionalidades 
		// para iniciar e terminar a contagem de tempo e calcular a pontuaçãpo final

};

