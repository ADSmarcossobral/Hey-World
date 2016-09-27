/*
	Descrição: Jogo da forca com verbos no Simple Present
	Versão 1.0
	
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define qtd_palavras 2 // Mudar valor inteiro para quantidade de palavras que compor o jogo
#define tam_palavras 10
#define alfabeto 26
#define tam_dicas 256
#define tam_definicao 256

// Menu que ficará no topo da tela
void tela_inicial(){
			printf("******************************************************************************\n");
			printf("*                     HANGMAN GAME - SIMPLE PRESENT                          *\n");
			printf("*                                                                            *\n");
			printf("*                    1 --> Novo Jogo       0 --> Sair                        *\n");
			printf("*                                                                            *\n");
			printf("******************************************************************************\n");
}
//O tronco completo
void forca_completa(){
	printf("\t******************\n");
	printf("\t**              **\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
	printf("\t**\n");
}
// Parte superior do tronco
void tronco_superior(){
	printf("\t******************\n");
	printf("\t**              **\n");
}
// Cada parte lateral do tronco
void tronco_lat(){
	printf("\t**");
}
// Cada parte lateral do tronco com quebra de linha
void tronco_lat_n(){
	printf("\t**\n");
}
// Cabeça do boneco
void cabeca(){
	tronco_lat();
	printf("\t   ***********\n");
	tronco_lat();
	printf("\t   *  o   o  *\n");
	tronco_lat();
	printf("\t   *    o    *\n");
	tronco_lat();
	printf("\t   *   ---   *\n");
	tronco_lat();
	printf("\t   ***********\n");
}
// Cabeça do boneco ao perder o jogo
void cabeca_lose(){
	tronco_lat();
	printf("\t   ***********\n");
	tronco_lat();
	printf("\t   *  x   x  *\n");
	tronco_lat();
	printf("\t   *    o    *\n");
	tronco_lat();
	printf("\t   *    x    *\n");
	tronco_lat();
	printf("\t   ***********\n");
}
// Pescoço do boneco
void pescoco(){
	tronco_lat();
	printf("\t       **\n");
	tronco_lat();
	printf("\t       **\n");
}
// Braço esquerdo do boneco (Também usado como perna esquerda)
void braco_esq(){
	tronco_lat();
	printf("\t     *\n");
	tronco_lat();
	printf("\t    *\n");
	tronco_lat();
	printf("\t   *\n");
}
// Braço esquerdo e direito do boneco (Também usado como ambas pernas)
void braco_esq_dir(){
	tronco_lat();
	printf("\t     *    *\n");
	tronco_lat();
	printf("\t    *      *\n");
	tronco_lat();
	printf("\t   *        *\n");
}
// Tronco do boneco
void tronco_completo(){
	tronco_lat();
	printf("\t     * ** *\n");
	tronco_lat();
	printf("\t    *  **  *\n");
	tronco_lat();
	printf("\t   *   **   *\n");
	tronco_lat();
	printf("\t       **\n");
	tronco_lat();
	printf("\t       **\n");
}

void tela_inicial();
void cabeca();
void braco_esq();
void braco_esq_dir();
void tronco_completo();
void forca_completa();
void tronco_lat_n();
void cabeca_lose();

int main(){
		
		char palavras[qtd_palavras][tam_palavras] = {"PRINT", "SCANF"}; // Palavras do jogo
		char dicas[qtd_palavras][tam_dicas] = {"SAIDA", "ENTRADA"}; // Dicas das respectivas palavras
		char definicao[qtd_palavras][tam_definicao] = {"BlaBlaBlaBla", "Blablablabla"}; //Descriçãos das respectivas palavras
		char letra; // Letra informada pelo usuário
		int x = 0; // índice aleatório
		int erro; // Quantidade de erros do jogador (O jogo termina com o total de 6 erros)
		int completou = 0; // Quando 1, o jogador vence e o jogo acaba
		int percorrido = 0; // Contando se toda string foi verificada
		int acertou = 0; // Quando o usuário acerta uma letra, seu valor vira 1, mostra-se a letra, e seu valor volta a ser 0
		char new_game = '1'; // Valor 1 para entrar no jogo
		int pos_acertou[10]; // Posição da letra acertada
		int let_inf = 0; // 0 --> Letra não informada | 1 --> Letra já informada
		int pos_let_inf = 0; // Contador para posição do vetor das letra informadas
		char letras_informadas[alfabeto]; // Vetor para armezenar as letras informadas		
		
		while(new_game == '1'){
			tela_inicial();
			printf("\nESCOLHA UMA OPCAO DO MENU: ");
			scanf("%c", &new_game); 
			fflush(stdin);
			if(new_game == '1'){
				system("cls"); // Limpando a tela
				tela_inicial();
				//Pegando um índice aleatório
				srand( (unsigned)time(NULL));
				x = rand() % qtd_palavras; // Sorteando um numero de 0 a Quantidade de palavras
				printf("\n*A PALAVRA POSSUI %d LETRAS* \tDICA: %s\n\n\n", strlen(palavras[x]), dicas[x]);
				erro = 0; // resetando a variável de erros
				completou = 0; // resetando a variável de letras acertadas
				pos_let_inf = 0;
				let_inf = 0;
				for(int k = 0; k < 10; k++){
					pos_acertou[k] = 11;
				}
				for(int k = 0; k < alfabeto; k++){
					letras_informadas[k] = '0';
				}
							
			} else if(new_game == '0'){
				printf("\nJOGO FINALIZADO!\n"); break; // Finalizando jogo caso a opção escolhida seja 0
			} else{
				printf("\nOPCAO INVALIDA! POR FAVOR, ESCOLHA UMA VALIDA!\n\n");
				printf("\n\nPRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU.\n");
				getchar();
				system("cls");
				new_game = '1';
				continue;
			}
			// Exibindo "_" (underlines) para simbolizar as letras da palavra
			for(int y = 0; y < strlen(palavras[x]); y++){
					printf("_ ");
					Beep(1000,100); // Um beep pra enfeitar kkkkkk
			}
			
			while(erro < 7 || completou < strlen(palavras[x]) && new_game == '1'){
				printf("\n\n\n\n\n");
				// Exibindo o tronco e os membros do corpo a cada erro
				if(erro ==0){
					forca_completa();
				}
				if(erro == 1){
					tronco_superior();	cabeca(); tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
				}	
				if(erro == 2){
					tronco_superior();	cabeca(); pescoco(); tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
				}	
				if(erro == 3){
					tronco_superior(); cabeca(); pescoco();	braco_esq();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
				}
				if(erro == 4){
					tronco_superior(); 	cabeca();	pescoco();	braco_esq_dir(); tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n();tronco_lat_n(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
				}
				if(erro == 5){
					tronco_superior();  cabeca();	pescoco();	tronco_completo(); tronco_lat_n();tronco_lat_n();tronco_lat_n(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
				}
				if(erro == 6){
					tronco_superior();  cabeca();	pescoco();	tronco_completo();braco_esq(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
				}
				if(erro == 7){
					tronco_superior();  cabeca_lose();	pescoco();	tronco_completo();braco_esq_dir(); tronco_lat_n();tronco_lat_n();tronco_lat_n();
					printf("\n\nQUE PENA! VOCE PERDEU! :(");
					printf("\n\nPRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU.\n");
					getchar();
					system("cls");
					break;
				}
				// Recebendo a letra
				printf("\n\n\n\n\nINFORME UMA LETRA: ");
				do{
					scanf("%c", &letra);
					fflush(stdin);
					let_inf = 0; // 0 --> Letra não informada
					for(int y = 0; y < alfabeto; y++){
						if(letra == letras_informadas[y]){
							let_inf = 1; // 1 --> Letra informada
						}
					}
					if(let_inf == 1){
						printf("\nA letra ja foi informada! Por favor, informe outra: ");
					}
					
				} while(let_inf == 1); // Repete-se até que a letra não tenha sido informada
				
				letras_informadas[pos_let_inf] = letra; // Salvando a letra informada no vetor
				pos_let_inf++; // Próxima posição no qual a próxima letra informada será salva
				
				letra = toupper(letra); // Convertendo letra para maiúscula
				// Verificando na string se a letra informada existe na palavra
				acertou = 0;
				for(int y = 0; y < strlen(palavras[x]); y++){
					if(letra == palavras[x][y]){
						acertou = 1; 
						pos_acertou[y] = y;
						completou++;
					} 		
				}
				if(acertou){
					system("cls");
					tela_inicial();
					printf("\n*A PALAVRA POSSUI %d LETRAS* \tDICA: %s\n\n\n", strlen(palavras[x]), dicas[x]);
					// Substituindo os underline pelas letras acertadas
					for(int y = 0; y < strlen(palavras[x]); y++){
						if(y == pos_acertou[y]){
							printf("%c ", palavras[x][y]);
						} else{
							printf("_ ");
						}
					}
					Beep(1000,100);
					
				} else if(!acertou){
					erro++;
					system("cls");
					tela_inicial();
					printf("\n*A PALAVRA POSSUI %d LETRAS* \tDICA: %s\n\n\n", strlen(palavras[x]), dicas[x]);
					// Substituindo os underlines pelas letras acertadas
					for(int y = 0; y < strlen(palavras[x]); y++){
						if(y == pos_acertou[y]){
							printf("%c ", palavras[x][y]);
						} else{
							printf("_ ");
						}
					}
					Beep(2000,100);	
				}
				// Quando o jogador acerta a palavra...
				if(completou == strlen(palavras[x])){
					printf("\n\nPARABENS! VOCE GANHOU!\n");
					printf("\n\nSobre o verbo %s", palavras[x]);
					printf("\n\n\t%s", definicao[x]);
					printf("\n\nPRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU.\n");
					getchar();
					system("cls");
					break;
				}				
			}
			printf("\n");
		}
}
