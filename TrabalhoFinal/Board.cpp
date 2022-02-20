//#include "pch.h"
#include "Board.h"
#include "char.h"
#include "Word.h"
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

void Board::View(Board x, string y) {
	/*cout << "------------------------------------------------------" << endl << endl;
	cout << "Chamada a View da Board" << endl;
	cout << "O que deve fazer: " << endl;
	cout << "\t- Percorre a matriz Chars e imprime cada Char. NB: Cada Char imprimem-se a si próprio, eg, Char::View()" << endl << endl;*/

	int k, j;

	cout << "Jogador: " << y << endl;
	cout << "Board = " << x.get_BoardWidth() << " Largura " << x.get_BoardHeight() << " Altura" << endl;
	for (k = 0; k < BoardHeight; k++) {
		for (j = 0; j < BoardWidth; j++) {
			cout << Chars[k][j].Get_Ch() << ' ';
		}
		cout << "\n";
	}
}

Board::~Board() {
	/*cout << "------------------------------------------------------" << endl << endl;
	cout << "Chamada a Destruidor da Board" << endl;
	cout << "O que deve fazer: " << endl;
	cout << "\t- Liberta a memória da matriz Chars (os objetos da classe Char)" << endl << endl;*/
}

Board::Board(void){
		/*cout << "------------------------------------------------------" << endl << endl;
		cout << "Chamada ao construtor da classe Board " << endl;
		cout << "O que deve fazer: " << endl;
		cout << "\t- Inicializa as propriedades da Board, ie, BoarWidth e BoardHeight" << endl;*/

		Set_BoardWidth(30);	
		Set_BoardHeight(20);
		Chars = NULL;
		NumWords = 10;
}

void Board::Init2(int Sx, int Sy, int num) {
	int i;

	Set_BoardWidth(Sx);
	Set_BoardHeight(Sy);
	Words = new Word[num];

	Chars = new Char * [Sx];

	for (i = 0; i < Sx; i++) {
		Chars[i] = new Char[Sy];
	}
}

 void Board::Init(int Sx, int Sy){
	 int i;
	 int k, j;  
	 numWords = 10;

	 Set_BoardWidth(Sx);
	 Set_BoardHeight(Sy);
		/*cout << "------------------------------------------------------" << endl << endl;
		cout << "Chamada a Init da Board para preparar a Board para jogar" << endl;
		cout << "O que deve fazer: " << endl;
		-----------cout << "\t- Alocar a matriz Chars (de Char *), com dimensoes Sx Sy" << endl;
		-----------cout << "\t- Alocar a matriz Chars (de Char *), com dimensoes Sx Sy" << endl;
		cout << "\t- Preenche a matriz Chars, criando os Char e atribuindo-os aos ponteiros da matriz Chars" << endl;
		cout << "\t- Carrega as palavras de um ficheiro e coloca-as na matriz"<<endl;
		*/

	 
		Chars = new Char * [Sx];          //---------- - cout << "\t- Alocar a matriz Chars (de Char *), com dimensoes Sx Sy" << endl;
		for (i = 0; i < Sx; i++) {
		 Chars[i] = new Char[Sy];
		}

		

		for (k = 0; k < Sy; k++){         //-----------cout << "\t- Alocar a matriz Chars (de Char *), com dimensoes Sx Sy" << endl;
			for (j = 0; j < Sx; j++){     
				Chars[k][j].Rand();
				Chars2[k][j] = 0;
			}
		}
		 
		ifstream ficheiro;	           //criçao e abertura do ficheiro 

		string LerPalavras;
		Point aux;
		bool valid = 1;
		int tamanhoPalavra;
		Word PalavrasFicheiro[50];
		




		ficheiro.open("Palavras.txt");
		if (!ficheiro) {
			
			cout << "Impossivel abrir o ficheiro, verifique se tem o documento palavras na pasta" << endl;

		}

		for (i = 0; i < 50; i++) {
			getline(ficheiro, LerPalavras);
			tamanhoPalavra = LerPalavras.length();
			PalavrasFicheiro[i].Set_Size(tamanhoPalavra);
			PalavrasFicheiro[i].Set_Letters(LerPalavras);
		}

		Words = new Word[10];
		srand(time(NULL));


		//vai selecionar as palavras aleatoriamente, 10 delas
		for (i = 0; i < 10; i++) {
			int aux = 0;
			aux = rand() % 50;
			if (PalavrasFicheiro[aux].Get_Letters() == "NULL") {
				i--;
				break;
				}
			Words[i] = PalavrasFicheiro[aux];
			PalavrasFicheiro[aux].Get_Letters() = "NULL";

		}

		//inserir palavras na matriz
		int h;
		i = 0;
		while (i < 10) {
			string palavra = Words[i].Get_Letters();
			int a = 0;
			do {
				int dir = rand() % 3;

				//palavra na vertical
				if (dir == 0) { 
					j = (rand() % (BoardHeight - palavra.length()));
					k = rand() % BoardWidth;
					int j2 = j;
					int k2 = k;
					if (rand() % 3 > 1) {
						reverse(palavra.begin(), palavra.end());
					}
					//testar se palavra interseta corretamente
					for (h = 0; h < palavra.length(); h++) {
						if ((Chars2[j2][k2] == 1) && Chars[j2][k2].Get_Ch() == palavra.at(h)) {
							j2++;
							if (h == palavra.length() - 1) {
								a++;
								break;
							}
						}
						else if (Chars2[j2][k2] == 0) {
							j2++;
							if (h == palavra.length() - 1) {
								a++;
								break;
							}
						}
						else {
							break;
						}
					}
					//colocar palavra na matriz
					if (a != 0) {
						for (h = 0; h < palavra.length(); h++) {
							Chars[j][k] = toupper(palavra.at(h));
							Chars2[j][k] = 1;
							j++;
						}
						i++;
						break;
					}
				}
				//palavra na horizontal
				else if (dir == 1) { 
					j = (rand() % (BoardWidth - palavra.length()));
					k = rand() % BoardHeight;
					int j2 = j;
					int k2 = k;
					if (rand() % 3 > 1) {
						reverse(palavra.begin(), palavra.end());
					}
					//testar se palavra interseta corretamente
					for (h = 0; h < palavra.length(); h++) {
						if (Chars2[k2][j2] == 1 && Chars[j2][k2].Get_Ch() == palavra.at(h)) {
							j2++;
							if (h == palavra.length() - 1) {
								a++;
								break;
							}
						}
						else if (Chars2[k2][j2] == 0) {
							j2++;
							if (h == palavra.length() - 1) {
								a++;
								break;
							}
						}
						else {
							break;
						}
					}
					//colocar palavra na matriz
					if (a != 0) {
						for (h = 0; h < palavra.length(); h++) {
							Chars[k][j] = toupper(palavra.at(h));
							Chars2[k][j] = 1;
							j++;
						}
						i++;
						break;
					}
				}
				//palavras na diagonal
				else { 
					//palavras da direita
					if (rand() % 2 == 0) { 
						j = (rand() % (BoardHeight - palavra.length()));
						k = (rand() % (BoardWidth - palavra.length()));
						int j2 = j;
						int k2 = k;
						if (rand() % 3 > 1) {
							reverse(palavra.begin(), palavra.end());
						}
						//testar se palavra interseta corretamente
						for (h = 0; h < palavra.length(); h++) {
							if (Chars2[k2][j2] == 1 && Chars[j2][k2].Get_Ch() == palavra.at(h)) {
								j2++;
								k2++;
								if (h == palavra.length() - 1) {
									a++;
									break;
								}
							}
							else if (Chars2[k2][j2] == 0) {
								j2++;
								k2++;
								if (h == palavra.length() - 1) {
									a++;
									break;
								}
							}
							else {
								break;
							}
						}
						//colocar palavra na matriz
						if (a != 0) {
							for (h = 0; h < palavra.length(); h++) {
								Chars[k][j] = toupper(palavra.at(h));
								Chars2[k][j] = 1;
								j++;
								k++;
							}
							i++;
							break;
						}
					}
					//palavras da esquerda
					else { 
						j = (palavra.length() + rand() % (BoardWidth - palavra.length()));
						k = (rand() % (BoardHeight - palavra.length()));
						int j2 = j;
						int k2 = k;
						if (rand() % 3 > 1) {
							reverse(palavra.begin(), palavra.end());
						}
						//testar se palavra interseta corretamente
						for (h = 0; h < palavra.length(); h++) {
							if (Chars2[k2][j2] == 1 && Chars[j2][k2].Get_Ch() == palavra.at(h)) {
								j2--;
								k2++;
								if (h == palavra.length() - 1) {
									a++;
									break;
								}
							}
							else if (Chars2[k2][j2] == 0) {
								j2--;
								k2++;
								if (h == palavra.length() - 1) {
									a++;
									break;
								}
							}
							else {
								break;
							}
						}
						//colocar palavra na matriz
						if (a != 0) {
							for (h = 0; h < palavra.length(); h++) {
								Chars[k][j] = toupper(palavra.at(h));
								Chars2[k][j] = 1;
								j--;
								k++;
							}
							i++;
							break;
						}
					}
				}
			} while (a == 0);
		}
 }
 




