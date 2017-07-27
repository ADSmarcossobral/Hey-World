//  ----- Dados do Aluno -----
//  Nome: Antônio Marcos Sobral Ramos
//  email: marcossobral94@gmail.com
//  Matrícula: 2016116007
//  Semestre: 2016.2
//  Questão: 07 (Jogo da Velha)

#include <stdio.h>
#include <stdlib.h>

void tabuleiro(int tab[][3], int jogador[][3]){
	// Mostrando tabuleiro
	printf("==================================================\n");
	printf("\t\tJOGO DA VELHA\n");
	printf("==================================================\n\n");
	printf("    1     2     3"); // Colunas 1, 2 e 3
	for(int x = 0; x < 3; x++){
		printf("\n%c ", 65 + x); // Mostrando linhas A, B e C
		for(int y = 0; y < 3; y++){
			if(tab[x][y] == 1){
				if(jogador[x][y] == 1){ // Se preenchido pelo player 1, mostre X
					printf("__X__");
				} else if(jogador[x][y] == 2){ // Se preenchido pelo player 2, mostre O
					printf("__O__");
				}
			} else{
				if(65 + x == 67){ // Se a coluna for C, mostre espaços ao invés de underlines
					printf("     ");
				} else{
					printf("_____");
				}
			}
			if(y == 2) // No final da coluna não mostre a |
				break;
			printf("|");
		}
	}
}

void escolherPos(int player, int jogador[][3], int tab[][3]){
	int celula_valida = 0, erro = 0;
	char celula[2];
	while(!celula_valida){ // Enquanto a celula informada for inválida, continue pedidindo uma célula válida
		if(erro){ // Se a célula informada já foi selecionada ou inválida...
			system("cls"); // Limpe a tela
			tabuleiro(tab, jogador); //Mostre o tabuleiro
			printf("\n\nCelula ja selecionada ou invalida! Player %d, informe uma outra celula: ", player);
			fflush(stdin);
			gets(celula);
		} else{ // Primeira mensagem para o player
			system("cls"); 
			tabuleiro(tab, jogador);
			printf("\n\nPlayer %d, informe a celula desejada: ", player);
			fflush(stdin);
			gets(celula);
		}
		erro = 0;
		for(int x = 0; x < 3 && !celula_valida && !erro; x++){ // Verificando se a célula informada é válida ou se já foi selecionada
			for(int y = 0; y < 3; y++){
				if(celula[0] == 65 + x && celula[1] == 49 + y){ // 65 + 0 = A | 65 + 1 = B | 65 + 2 = C | 49 + 0 = 1 | 49 + 1 = 2 | 49 + 2 = 3
					if(tab[x][y] != 1){ // Se a posição na tabela não foi marcada...
						tab[x][y] = 1; // Marque-a
						if(player == 1){ // Se for o player 1...
							jogador[x][y] = 1; // Marque com 1 a mesma posição na matriz jogador
							celula_valida = 1; // A célula informada é válida
							break;
						} else if(player == 2){ // Se for o player 2...
							jogador[x][y] = 2; // Marque com 2 a mesma posição na matriz jogador
							celula_valida = 1; // A célula informada é válida
							break;
						}						
					} else{ // Caso a posição já foi selecionada...
						erro = 1;
						break;
					}
					
				}
				if(x == 2 && y == 2){ // Se todas as posições forem verificadas e nenhuma ação foi tomada, a céluda informada é inválida
					erro = 1;
				}
			}
		}
	}
}

int verifica_vencedor(int jogador[][3]){
	int vencedor_1 = 0, vencedor_2 = 0, vencedor = 0;
	for(int x = 0; x < 3 && !vencedor; x++){ // Verificando na horizontal
		vencedor_1 = 0;
		vencedor_2 = 0;
		for(int y = 0; y < 3; y++){
			if(jogador[x][y] == 1){
				vencedor_1++;
			} else if(jogador[x][y] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}			
		}
	}
	for(int x = 0; x < 3 && !vencedor; x++){ // Verificando na vertical
		vencedor_1 = 0;
		vencedor_2 = 0;
		for(int y = 0; y < 3; y++){
			if(jogador[y][x] == 1){
				vencedor_1++;
			} else if(jogador[y][x] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}			
		}
	}
	vencedor_1 = 0;
	vencedor_2 = 0;
	for(int x = 0; x < 3 && !vencedor; x++){ // Verificando na diagonal esquerda pra direita
			if(jogador[x][x] == 1){
				vencedor_1++;
			} else if(jogador[x][x] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}
	}
	vencedor_1 = 0;
	vencedor_2 = 0;
	for(int x = 0; x < 3;){ // Verificando na diagonal direita pra esquerda
		for(int y = 2; y >= 0; y--){
			if(jogador[x][y] == 1){
				vencedor_1++;
			} else if(jogador[x][y] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}
			x++;		
		}
	}
	return 0;
}

int main(){
	int tab[3][3], jogador[3][3], jogadas = 0, player = 1, vencedor = 0;
	tabuleiro(tab, jogador);
	while(jogadas != 9 || !vencedor){
		if(player == 1){
			escolherPos(player, jogador, tab);
			jogadas++;
			vencedor = verifica_vencedor(jogador);
			player = 2;
		}
		if(vencedor == 1){
			system("cls");
			tabuleiro(tab, jogador);
			printf("\n\nO Player 1 venceu!");
			break;
		}
		if(jogadas == 9){
			system("cls");
			tabuleiro(tab, jogador);
			printf("\n\nNao houve vencedor!");
			break;
		}
		if(player == 2){
			escolherPos(player, jogador, tab);
			vencedor = verifica_vencedor(jogador);
			jogadas++;
			player = 1;
		}
		if(vencedor == 2){
			system("cls");
			tabuleiro(tab, jogador);
			printf("\n\nO Player 2 venceu!");
			break;
		}
		if(jogadas == 9){
			system("cls");
			tabuleiro(tab, jogador);
			printf("\n\nNao houve vencedor!");
			break;
		}
	}
	return 0;
}