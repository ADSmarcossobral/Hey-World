// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Antônio Marcos Sobral Ramos
//  email: marcossobral94@gmail.com
//  Matrícula: 2016116007
//  Semestre: 2016.2

#include <stdio.h>
#include <stdlib.h>
#include "sys/types.h"
#include <winsock.h>
#include "errno.h"
#include <windows.h>
#include <conio.h>
#include <string.h>
// Variáveis para socket cliente
WSADATA cliente_data;
SOCKET cliente_sock;
SOCKADDR_IN cliente_sock_connect;
char cliente_buffer[1024];
char cliente_buffer2[1024];
int cliente_bytes;
//Variáveis para socket servidor
WSADATA servidor_data; 
SOCKET servidor_sock; 
SOCKADDR_IN servidor_sock_connect; 
char servidor_buffer[1024];
char servidor_buffer2[1024];
int servidor_bytes;

void tabuleiro(int tab[][3], int jogador[][3]){
	system("cls");
	printf("===================================================\n");
	printf("Jogadores conectados! Vamos jogar!\n");
	printf("===================================================\n");
	// Mostrando tabuleiro
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

char *memcpy(char *dest, char *orig, int n){
    int i;
    for(i=0 ; i < n ; i++)
        dest[i] = orig[i];
    return dest;
}

void escolherPos(int player, int jogador[][3], int tab[][3], char *buffer, int tipo_connect){
	int celula_valida = 0, erro = 0;
	char celula[2];
	while(!celula_valida){ // Enquanto a celula informada for inválida, continue pedidindo uma célula válida
		if((tipo_connect == 1 && player == 2) || (tipo_connect == 2 && player == 1)){
			int n = strlen(buffer);
			memcpy(celula,buffer,n);
		}else if(erro){ // Se a célula informada já foi selecionada ou inválida...
			tabuleiro(tab, jogador); //Mostre o tabuleiro
			printf("\n\nCelula ja selecionada ou invalida! Player %d, informe uma outra celula: ", player);
			fflush(stdin);
			gets(celula);
			int n = strlen(celula);
			memcpy(buffer,celula,n);
			} else{ // Primeira mensagem para o player
				tabuleiro(tab, jogador);
				printf("\n\nPlayer %d, escolha uma celula: ", player);
				fflush(stdin);
				gets(celula);
				int n = strlen(celula);
				memcpy(buffer,celula,n);
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
	tabuleiro(tab, jogador);
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

void game_over(){
	closesocket(servidor_sock);
	WSACleanup();
	printf("\n\nPressione qualquer tecla para finalizar.\n");
	getch();
}

int main(){
	int conectado = 0, tipo_connect;
	int tab[3][3], jogador[3][3], jogadas = 0, player = 1, vencedor = 0;
	char celula[2];
	printf("Escolha: 1 --> Conectar a um player | 2 --> Criar um servidor de conexao: ");
	scanf("%d", &tipo_connect);
	if(tipo_connect == 1){ // Conectando a um servidor
		if(WSAStartup(MAKEWORD(1,1),&cliente_data)==SOCKET_ERROR){
			printf("Erro ao inicializar o winsock");
			return 0;
		}
		if((cliente_sock = socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR){
			printf("Erro ao criar socket");
			return 0;
		}
		cliente_sock_connect.sin_family=AF_INET;
		cliente_sock_connect.sin_port=htons(1234);
		cliente_sock_connect.sin_addr.s_addr=inet_addr("127.0.0.1");
		if(connect(cliente_sock,(SOCKADDR*)&cliente_sock_connect,sizeof(cliente_sock_connect))==SOCKET_ERROR){
			printf("Erro ao se conectar");
			return 0;
		}
		while(jogadas != 9 || !vencedor){
			while(1){
				Sleep(1);
				if(player == 1){
					escolherPos(player, jogador, tab, cliente_buffer, tipo_connect);
					strcat(cliente_buffer,"\r\n");
					send(cliente_sock,cliente_buffer,strlen(cliente_buffer),0);
					jogadas++;
					vencedor = verifica_vencedor(jogador);
					player = 2;
				}
				if(vencedor == 1){
					tabuleiro(tab, jogador);
					printf("\n\nO Player 1 venceu!");
					game_over();
					return 0;
				}
				if(jogadas == 9){
					tabuleiro(tab, jogador);
					printf("\n\nNao houve vencedor!");
					game_over();
					return 0;
				}
				if(player == 2){
					memset(cliente_buffer2,0,1024);
					cliente_bytes=recv(cliente_sock,cliente_buffer2,1024,0);
					escolherPos(player, jogador, tab, cliente_buffer2, tipo_connect);
					jogadas++;
					vencedor = verifica_vencedor(jogador);
					player = 1;
				}
				if(vencedor == 2){
					tabuleiro(tab, jogador);
					printf("\n\nO Player 2 venceu!");
					game_over();
					return 0;
				}
				if(cliente_bytes==-1){
					printf("Conexão perdida");
					getch();
					return 0;
				}
				if(jogadas == 9){
					tabuleiro(tab, jogador);
					printf("\n\nNao houve vencedor!");
					game_over();
					return 0;
				}
			}
		}
		
	} else if(tipo_connect == 2){ // Criando servidor
		if(WSAStartup(MAKEWORD(1,1),&servidor_data)==SOCKET_ERROR){ 
			printf("Erro ao inicializar o winsock"); 
			return 0; 
		} 
		if((servidor_sock = socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR){ 
			printf("Erro ao criar socket"); 
			return 0; 
		} 
		servidor_sock_connect.sin_family=AF_INET; 
		servidor_sock_connect.sin_port=htons(1234); 
		if(bind(servidor_sock,(SOCKADDR*)&servidor_sock_connect,sizeof(servidor_sock_connect))==SOCKET_ERROR){ 
			printf("Erro ao utilizar a funcao BIND"); 
			getch();
			return 0; 
		} 
		printf("===================================================\n");
		printf("Aguardando jogador...\n");
		listen(servidor_sock,1); 
		while((servidor_sock = accept(servidor_sock,0,0))==SOCKET_ERROR){ 
				Sleep(1); 
		} 
		while(jogadas != 9 || !vencedor){
			tabuleiro(tab, jogador);
			while(1){
				Sleep(1);
				vencedor = verifica_vencedor(jogador);
				if(player == 1){
					memset(servidor_buffer2,0,1024);
					servidor_bytes=recv(servidor_sock,servidor_buffer2,1024,0);
					escolherPos(player, jogador, tab, servidor_buffer2, tipo_connect);
					jogadas++;
					vencedor = verifica_vencedor(jogador);
					player = 2;
				}
				if(vencedor == 1){
					tabuleiro(tab, jogador);
					printf("\n\nO Player 1 venceu!");
					game_over();
					return 0;
				}
				if(jogadas == 9){
					tabuleiro(tab, jogador);
					printf("\n\nNao houve vencedor!");
					game_over();
					return 0;
				}
				if(player == 2){
					escolherPos(player, jogador, tab, servidor_buffer, tipo_connect);
					strcat(servidor_buffer,"\r\n");
					send(servidor_sock,servidor_buffer,strlen(servidor_buffer),0);
					jogadas++;
					vencedor = verifica_vencedor(jogador);
					player = 1;
				}
				if(vencedor == 2){
					tabuleiro(tab, jogador);
					printf("\n\nO Player 2 venceu!");
					game_over();
					return 0;
				}
				if(jogadas == 9){
					tabuleiro(tab, jogador);
					printf("\n\nNao houve vencedor!");
					game_over();
					return 0;
				}
				if(servidor_bytes==-1){
					printf("Conexão perdida\n");
					getch();
					return 0;
				}
			}
		}
	}
	return 0;
}