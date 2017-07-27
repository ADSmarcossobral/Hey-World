//  ----- Dados do Aluno -----
//  Nome: Antônio Marcos Sobral Ramos
//  email: marcossobral94@gmail.com
//  Matrícula: 2016116007
//  Semestre: 2016.2
//  Questão: 08 (Batalha Naval)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TOTAL_BARCOS 5

void preencheTab(int jogador[][10][10]){
	for(int x = 0; x < 2;x++){
		for(int y = 0; y < 10; y++){
			for(int z = 0; z < 10; z++){
				jogador[x][y][z] = 0;
			}
		}
	}
}

void tabuleiro(int jogador[][10][10], int player, int tipo_tab){
	// Mostrando tabuleiro
	printf("\n==================================================\n");
	if(tipo_tab == 1){
		printf("\tBatalha Naval - Tabuleiro Player %d\n", player + 1);
	} else{
		printf("\tBatalha Naval - Tabuleiro do Adversario\n");
	}
	printf("==================================================\n\n");
	printf("   0   1   2   3   4   5   6   7   8   9"); // Colunas de 0 a 9
	for(int x = 0; x < 10; x++){
		printf("\n%c ", 65 + x); // Mostrando linhas de A até J
		for(int y = 0; y < 10; y++){
			if(tipo_tab == 1){ // Mostrando tabuleiro do player 
				if(jogador[player][x][y] == 1){ // Indica a posição do navio
					printf(" N ");
				} else if(jogador[player][x][y] == 2){
					printf(" O ");
				} else if(jogador[player][x][y] == 3){
					printf(" X ");
				} else
					printf("   ");
				printf("|");
			} else{ // Mostrando tabuleiro do adversario
				int aux;
				if(player == 0){	
					aux = 1;	
				} else{
					aux = 0;
				}
				if(jogador[aux][x][y] == 1){
					printf("   ");
				} else if(jogador[aux][x][y] == 2){
					printf(" O ");
				} else if(jogador[aux][x][y] == 3){
					printf(" X ");
				} else
					printf("   ");
				printf("|");
			}
		} 
	}
	printf("\n");
}

void posicoesBarcos(int jogador[][10][10], int player){
	char posicao[2];
	int erro = 0;
	for(player = 0; player <= 1; player++){
		int barcos = 0, ok = 0, tamanhoBarco = 4, escolha = 0, opcao = 0;
		for(int z = 0; z < TOTAL_BARCOS; z++){
			if(z >= 5){
				tamanhoBarco = 2;
			}
			ok = 0;
			while(!ok){
				fflush(stdin);
				if(erro){
					erro = 0;
					system("cls");
					tabuleiro(jogador, player,1);
					printf("\nPosicao invalida! Por favor, informe uma posicao valida: ");
					fflush(stdin);
					gets(posicao);
				}else{
					system("cls");
					tabuleiro(jogador, player,1);
					printf("\nPlayer %d, informe a posicao inicial do seu barco de tamanho %d: ",player + 1, tamanhoBarco);
					fflush(stdin);
					gets(posicao);	
				}
				ok = 0;
				opcao = 0;
				for(int j = 0; j < 10 && !erro && !ok; j++){
					for(int k = 0; k < 10 && !ok; k++){
						if(posicao[0] == 65 + j && posicao[1] == 48 + k){
							if(tamanhoBarco != 1){
								printf("Seu barco pode ser completado nas seguintes opcoes de posicoes: ");
							}	
							if(tamanhoBarco == 4){
								opcao++;
								if(jogador[player][j][k-1] != 1 && jogador[player][j][k-2] != 1 && jogador[player][j][k-3] != 1){ // Horizontal p/ esquerda
									if(k-1 >= 0 && k-2 >= 0 && k-3 >= 0){
										printf("\n%d - %c%c, %c%c e %c%c", opcao, 65 + j, 48 + k -1, 65 + j, 48 + k - 2, 65 + j, 48 + k - 3);
									}
								}
								opcao++;
								if(jogador[player][j-1][k] != 1 && jogador[player][j-2][k] != 1 && jogador[player][j-3][k] != 1){ // Vertical subindo
									if(j-1 >= 0 && j-2 >= 0 && j - 3 >= 0){
										printf("\n%d - %c%c, %c%c e %c%c", opcao, 65 + j - 1, 48 + k, 65 + j - 2, 48 + k, 65 + j - 3, 48 + k);
									}
								}
								opcao++;
								if(jogador[player][j][k+1] != 1 && jogador[player][j][k+2] != 1 && jogador[player][j][k+3] != 1){ // Horizontal p/ direita
									if(k+1 < 10 && k+2 < 10 && k+3 < 10){
										printf("\n%d - %c%c, %c%c e %c%c", opcao, 65 + j, 48 + k+1, 65 + j, 48 + k+2, 65 + j, 48 + k+3);
									}	
								}
								opcao++;
								if(jogador[player][j+1][k] != 1 && jogador[player][j+2][k] != 1 && jogador[player][j+3][k] != 1){ // Vertical descendo
									if(j+1 < 10 && j+2 < 10 && j+3 < 10){
										printf("\n%d - %c%c, %c%c e %c%c", opcao, 65 + j+1, 48 + k, 65 + j+2, 48 + k, 65 + j+3, 48 + k);
									}
								}
								int opcao_valida = 0;
								while(!opcao_valida){
									printf("\nEscolha uma opcao valida: ");
									fflush(stdin);
									scanf("%d", &escolha);
									if(escolha == 1){
										if(jogador[player][j][k-1] != 1 && jogador[player][j][k-2] != 1 && jogador[player][j][k-3] != 1){ // Horizontal p/ esquerda
											if(k-1 >= 0 && k-2 >= 0 && k-3 >= 0){
												jogador[player][j][k] = 1;
												jogador[player][j][k-1] = 1;
												jogador[player][j][k-2] = 1;
												jogador[player][j][k-3] = 1;
												break;
											} else{
												continue;
											}	
										} else{
											continue;
										}
									} else if(escolha ==  2){
										if(jogador[player][j-1][k] != 1 && jogador[player][j-2][k] != 1 && jogador[player][j-3][k] != 1){ // Vertical subindo
											if(j-1 >= 0 && j-2 >= 0 && j - 3 >= 0){
												jogador[player][j][k] = 1;
												jogador[player][j-1][k] = 1;
												jogador[player][j-2][k] = 1;
												jogador[player][j-3][k] = 1;
												break;
											} else{
												continue;
											}
										} else{
											continue;
										}
									} else if(escolha == 3){
										if(jogador[player][j][k+1] != 1 && jogador[player][j][k+2] != 1 && jogador[player][j][k+3] != 1){ // Horizontal p/ direita
											if(k+1 < 10 && k+2 < 10 && k+3 < 10){
												jogador[player][j][k] = player;
												jogador[player][j][k+1] = player;
												jogador[player][j][k+2] = player;
												jogador[player][j][k+3] = player;
												break;
											} else{
												continue;
											}
										} else{
											continue;
										}
									} else if(escolha == 4){
										if(jogador[player][j+1][k] != 1 && jogador[player][j+2][k] != 1 && jogador[player][j+3][k] != 1){ // Vertical descendo
											if(j+1 < 10 && j+2 < 10 && j+3 < 10){
												jogador[player][j][k] = player;
												jogador[player][j+1][k] = player;
												jogador[player][j+2][k] = player;
												jogador[player][j+3][k] = player;
												break;
											} else{
												continue;
											}		
										} else{
											continue;
										}
									}
								}
								ok = 1;
								tamanhoBarco = 3;
								break;
							} else if(tamanhoBarco == 3){
								opcao++;
								if(jogador[player][j][k-1] != 1 && jogador[player][j][k-2] != 1){ // Horizontal p/ esquerda
									if(k-1 >= 0 && k-2 >= 0){
										printf("\n%d - %c%c, %c%c", opcao, 65 + j, 48 + k -1, 65 + j, 48 + k - 2);
									}
								}
								opcao++;
								if(jogador[player][j-1][k] != 1 && jogador[player][j-2][k] != 1){ // Vertical subindo
									if(j-1 >= 0 && j-2 >= 0){
										printf("\n%d - %c%c, %c%c", opcao, 65 + j - 1, 48 + k, 65 + j - 2, 48 + k);	
									}
								}
								opcao++;
								if(jogador[player][j][k+1] != 1 && jogador[player][j][k+2] != 1){ // Horizontal p/ direita
									if(k+1 < 10 && k+2 < 10){
										printf("\n%d - %c%c, %c%c", opcao, 65 + j, 48 + k+1, 65 + j, 48 + k+2);
									}
									
								}
								opcao++;
								if(jogador[player][j+1][k] != 1 && jogador[player][j+2][k] != 1){ // Vertical descendo
									if(j+1 < 10 && j+2 < 10){
										printf("\n%d - %c%c, %c%c", opcao, 65 + j+1, 48 + k, 65 + j+2, 48 + k);
									}
								}
								
								int opcao_valida = 0;
								while(!opcao_valida){
									printf("\nEscolha uma opcao valida: ");
									fflush(stdin);
									scanf("%d", &escolha);
									if(escolha == 1){
										if(jogador[player][j][k-1] != 1 && jogador[player][j][k-2] != 1){ // Horizontal p/ esquerda
											if(k-1 >= 0 && k-2 >= 0){
												jogador[player][j][k] = 1;
												jogador[player][j][k-1] = 1;
												jogador[player][j][k-2] = 1;
												break;
											}else{
												continue;
											}	
										} else{
											continue;
										}
									} else if(escolha ==  2){
										if(jogador[player][j-1][k] != 1 && jogador[player][j-2][k] != 1){ // Vertical subindo
											if(j-1 >= 0 && j-2 >= 0){
												jogador[player][j][k] = 1;
												jogador[player][j-1][k] = 1;
												jogador[player][j-2][k] = 1;
												break;
											}else{
												continue;
											}	
										} else{
											continue;
										}
									} else if(escolha == 3){
										if(jogador[player][j][k+1] != 1 && jogador[player][j][k+2] != 1){ // Horizontal p/ direita
											if(k+1 < 10 && k+2 < 10){
												jogador[player][j][k] = 1;
												jogador[player][j][k+1] = 1;
												jogador[player][j][k+2] = 1;
												break;
											}else {
												continue;
											}
										} else{
											continue;
										}
									} else if(escolha == 4){
										if(jogador[player][j+1][k] != 1 && jogador[player][j+2][k] != 1){ // Vertical descendo
											if(j+1 < 10 && j+2 < 10){
												jogador[player][j][k] = 1;
												jogador[player][j+1][k] = 1;
												jogador[player][j+2][k] = 1;
												break;
											}else{
												continue;
											}
										} else{
											continue;
										}
									}
								}
								ok = 1;
								tamanhoBarco = 1;
								break;
							} else if(tamanhoBarco == 1){
								if(jogador[player][j][k] != 1){
									jogador[player][j][k] = 1;
									ok = 1;
									break;
								} else{
									erro = 1;
									break;
								}
							} else if(tamanhoBarco == 2){
								opcao++;
								if(jogador[player][j][k-1] != 1){ // Horizontal p/ esquerda
									if(k-1 >= 0){
										printf("\n%d - %c%c", opcao, 65 + j, 48 + k -1);
									}
								}
								opcao++;
								if(jogador[player][j-1][k] != 1){ // Vertical subindo
									if(j-1 >= 0){
										printf("\n%d - %c%c", opcao, 65 + j - 1, 48 + k);	
									}
								}
								opcao++;
								if(jogador[player][j][k+1] != 1){ // Horizontal p/ direita
									if(k+1 < 10 && k+2 < 10){
										printf("\n%d - %c%c", opcao, 65 + j, 48 + k+1);
									}
								}
								opcao++;
								if(jogador[player][j+1][k] != 1){ // Vertical descendo
									if(j+1 < 10 && j+2 < 10){
										printf("\n%d - %c%c", opcao, 65 + j+1, 48 + k);
									}
								}
								int opcao_valida = 0;
								while(!opcao_valida){
									printf("\nEscolha uma opcao valida: ");
									fflush(stdin);
									scanf("%d", &escolha);
									if(escolha == 1){
										if(jogador[player][j][k-1] != 1){ // Horizontal p/ esquerda
											if(k-1 >= 0){
												jogador[player][j][k] = 1;
												jogador[player][j][k-1] = 1;
												break;
											}else{
												continue;
											}	
										} else{
											continue;
										}
									} else if(escolha ==  2){
										if(jogador[player][j-1][k] != 1){ // Vertical subindo
											if(j-1 >= 0 && j-2 >= 0){
												jogador[player][j][k] = 1;
												jogador[player][j-1][k] = 1;
												break;
											}else{
												continue;
											}	
										} else{
											continue;
										}
									} else if(escolha == 3){
										if(jogador[player][j][k+1] != 1){ // Horizontal p/ direita
											if(k+1 < 10 && k+2 < 10){
												jogador[player][j][k] = 1;
												jogador[player][j][k+1] = 1;
												break;
											}else {
												continue;
											}
										} else{
											continue;
										}
									} else if(escolha == 4){
										if(jogador[player][j+1][k] != 1){ // Vertical descendo
											if(j+1 < 10 && j+2 < 10){
												jogador[player][j][k] = 1;
												jogador[player][j+1][k] = 1;
												break;
											}else{
												continue;
											}
										} else{
											continue;
										}
									}
								}
								ok = 1;	
							}
						}
						if(j == 9 && k == 9){
								erro = 1;
								break;
						}
					}
				}			
			}
		}
	}
}

void atirar(int jogador[][10][10], int player){
	char posicao[2];
	int ok = 0, erro = 0;
	while(!ok){
		fflush(stdin);
		if(erro){
			erro = 0;
			system("cls");
			tabuleiro(jogador, player, 1);
			tabuleiro(jogador, player, 2);
			printf("\nPosicao invalida! Por favor, informe uma posicao valida: ");
			fflush(stdin);
			gets(posicao);
		}else{
			system("cls");
			tabuleiro(jogador, player, 1);
			tabuleiro(jogador, player, 2);
			printf("\nPlayer %d, informe a posicao em que deseja atirar: ",player+1);
			fflush(stdin);
			gets(posicao);	
		}
		for(int j = 0; j < 10 && !erro && !ok; j++){
			for(int k = 0; k < 10 && !ok; k++){
				if(posicao[0] == 65 + j && posicao[1] == 48 + k){
					if(player == 0){
						if(jogador[1][j][k] == 1){
							jogador[1][j][k] = 2;
							system("cls");
							tabuleiro(jogador, player, 1);
							tabuleiro(jogador, player, 2);
							printf("\n\nVoce acertou! Pressione qualquer tecla para continuar!");
							getch();
							ok = 1;
							break;
						} else if(jogador[1][j][k] != 2 && jogador[1][j][k] != 3){
							jogador[1][j][k] = 3;
							system("cls");
							tabuleiro(jogador, player, 1);
							tabuleiro(jogador, player, 2);
							printf("\n\nVoce errou! Pressione qualquer tecla para continuar!");
							getch();
							ok = 1;
							break;
						}else{
							erro = 1;
							break;
						}
					} else if(player == 1){
						if(jogador[0][j][k] == 1){
							jogador[0][j][k] = 2;
							system("cls");
							tabuleiro(jogador, player, 1);
							tabuleiro(jogador, player, 2);
							printf("\n\nVoce acertou! Pressione qualquer tecla para continuar!");
							getch();
							ok = 1;
							break;
						} else if(jogador[0][j][k] != 2 && jogador[0][j][k] != 3){
							jogador[0][j][k] = 3;
							system("cls");
							tabuleiro(jogador, player, 1);
							tabuleiro(jogador, player, 2);
							printf("\n\nVoce errou! Pressione qualquer tecla para continuar!");
							getch();
							ok = 1;
							break;
						}else{
							erro = 1;
						}
					}
				}
			}
		}
	}
}

int verificaVencedor(int jogador[][10][10], int player){
	for(int y = 0; y < 10; y++){
		for(int z = 0; z < 10; z++){
			if(player == 0){
				if(jogador[1][y][z] == 1){
					return -1;
				}
			} else{
				if(jogador[0][y][z] == 1){
					return -1;
				}
			}
			
		}
	}
	if(player == 0){
		return 1;
	} else {
		return 0;
	}
}

void game_over(int player){
	printf("\n\nO player %d venceu! Pressione qualquer tecla para finalizar o jogo.", player + 1);
	getch();
}

int main(){
	int player = 0, jogador[2][10][10], vencedor = -1;
	preencheTab(jogador);
	posicoesBarcos(jogador, player);
	while(vencedor = -1){
		player = 0;
		atirar(jogador, player);
		vencedor = verificaVencedor(jogador, player);
		if(vencedor > -1){
			system("cls");
			tabuleiro(jogador, 0, 1);
			tabuleiro(jogador, 1, 1);
			game_over(player);
			break;
		}
		player = 1;
		atirar(jogador, player);
		vencedor = verificaVencedor(jogador, player);
		if(vencedor > -1){
			system("cls");
			tabuleiro(jogador, 0, 1);
			tabuleiro(jogador, 1, 1);
			game_over(player);
			break;
		}
	}
	return 0;
}