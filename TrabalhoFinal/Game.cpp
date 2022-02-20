//#include "pch.h"
#include "Game.h"
#include "Board.h"
#include "player.h"


Game::Game() {

}


Game::Game(int w, int h, player Pl_Name){
	int GameScore;
	int GuessWords;
		/*cout << "------------------------------------------------------" << endl << endl;
		cout << "Chamada ao construtor da classe Game " << endl;
		cout << "O que deve fazer: " << endl;
		cout << "\t- Constroi e inicializa a GameBoard" << endl<<endl;*/
		GameScore = 0;
		GuessWords = 0;
		GamePlayer = Pl_Name.Getname();
		PlayBoard.Init(w,h);
}
	
void Game::Run(){
		/*cout << "------------------------------------------------------" << endl << endl;
		cout << "Chamada a Run da classe Game para iniciar (correr) o jogo" << endl;
		cout << "O que deve fazer: " << endl;
		cout << "\t- Executa um ciclo que chama Play enquanto houver palavras por descobrir;" << endl;
		cout << "\t- Play devolve o numero de palavras por descobrir." << endl << endl;

		cout << "Running 2 calls for testing" << endl << endl;*/

		//int a = 2;
		//while(a > 0)
		//{
			//cout << a-- << "  -----------------" << endl << endl;
		while (GameScore < 10)
		{
			Play();
			system("CLS");
		}
		if (GameScore == 10) {
			system("CLS");
			cout << "Parabens!!!! ganhaste :))" << endl;
		}
			
		//}
}

void Game::load() {
	int i, b, h, w, k;
	char a;
	string c;
	ifstream ficheiro;
	ficheiro.open("saveGame.txt");
	if (!ficheiro) {

		cout << "Impossivel abrir o ficheiro, nenhum jogo guardado encontrado" << endl;
		_getch();
		return;
	}
	ficheiro >> GamePlayer >> GameScore >> GuessWords >> b >> h >> w;
	PlayBoard.setNumWords(b);
	PlayBoard.Init2(w, h, b);
	for (i = 0; i < b; i++) {
		ficheiro >> c;
		PlayBoard.Words[i].Set_Letters(c);
	}
	for (i = 0; i < h; i++) {
		for (k = 0; k < w; k++) {
			ficheiro >> a >> b;
			PlayBoard.setChar(i, k, a);
			PlayBoard.setChar2(i, k, b);
		}
	}
	for (i = 0; i < GameScore; i++) {
		ficheiro >> c;
		acertadas[i] = c;
	}
}

void Game::save() {
	int i, a;
	ofstream ficheiro;
	int h = PlayBoard.get_BoardHeight();
	int w = PlayBoard.get_BoardWidth();

	ficheiro.open("saveGame.txt");
	ficheiro << GamePlayer << endl << GameScore << endl << GuessWords << endl << PlayBoard.getNumWords() << endl << h << endl << w << endl;
	for (i = 0; i < PlayBoard.getNumWords(); i++) {
		ficheiro << PlayBoard.Words[i].Get_Letters() << endl;
	}
	for (i = 0; i < h; i++) {
		for (a = 0; a < w; a++) {
			ficheiro << PlayBoard.getChar(i, a) << endl << PlayBoard.getChar2(i, a) << endl;
		}
	}
	for (i = 0; i < GameScore; i++) {
		ficheiro << acertadas[i] << endl;
	}
}


int Game::Play(void){

		/*cout << "------------------------------------------------------" << endl << endl;
		cout << "Chamada a Play da classe Game para efetuar uma jogada completa" << endl;
		cout << "O que deve fazer: " << endl;
		cout << "\t- Executa uma jogada completa, incluindo:" << endl;

		cout << "\t\tPede uma palavra ao jogador" << endl;
		cout << "\t\tVerifica se a palavra existe, evocando um metodo Find da GameBoard;" << endl;
		cout << "\t\tSe existe, assinala a palavra como descoberta, decrementa no número de palavras por descobrir;" << endl;
		cout << "\t\tSe não existe existe, avisa que não existe;" << endl;
		cout << "\t- Imprime a nova board" << endl;
		cout << "\t- Devolve o valor de palavras por descobrir" << endl << endl;*/
		int i;
		string guess;
		string temp;

		PlayBoard.View(PlayBoard, GamePlayer);
		cout << "\n\n\nPalavras adivinhadas  || " << GameScore << ": ";

		
		for (i = 0; i < GameScore; i++) {
			cout << acertadas[i] << " || ";
		}

		GuessWords = 10 - GameScore;
		cout << "\n\n\nPalavras que faltam: " << GuessWords;
		
		cout << "\n1 - Salvar Jogo";
		cout << "\n2 - Sair";
		cout << "\nAdivinhe uma palavra: ";
		cin >> guess;
		//salvar
		if (guess == "1") {
			save();
			return 0;
		}
		//sair
		else if (guess == "2") {
			GameScore = 11;
			return 0;
		}

		for (i = 0; i < 10; i++) {
			temp = PlayBoard.Words[i].Get_Letters();
			if (guess == temp && temp != "NULL") {
				acertadas[GameScore] = temp;
				PlayBoard.Words[i].Set_Letters("NULL");
				GameScore++;
				cout << "Esta certa!";
				_getch();
				break;
			}
		}

		if (i == 10) {
			cout << "Esta errada!";
			_getch();
		}
		return 0;
		
}
