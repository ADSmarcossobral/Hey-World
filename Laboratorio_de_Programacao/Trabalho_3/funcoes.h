/*
	Terceiro Trabalho de Laboratório de Programação 
	Instituto Federal da Bahia - IFBA
	Discente: Antônio Marcos Sobral Ramos
	Matrícula: 2016116007
	Data: 07/05/2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define tamanho 10

typedef struct Principal principal;

struct Principal{
	int max;
	int atual;		
	int* valor;
};

void anula(principal *LISTA){
	for(int x = 0; x < tamanho; x++){
		LISTA[x].atual = 0;
		LISTA[x].max = 0;
		LISTA[x].valor = NULL;
	}
}
// Testa a abertura do arquivo
int testarArquivo(FILE *dados){
	if(!dados)	
		return 0;
	else 
		return 1;
}
// Pega a posicao, maximo e atual
int pegaPMA(char* linha,char* pos, char* max, char* atual){
	int x = 0;
	for(; linha[x] != 46;x++){
		pos[x] = linha[x];
		pos = (char *)realloc(pos, (strlen(pos) + 1) * sizeof(char));
		pos[x+1] = 0;
	}
	x++;
	for(int y = 0;linha[x] != 46;x++){
		max[y] = linha[x];
		max = (char *)realloc(max, (strlen(max) + 1) * sizeof(char));
		y++;
		max[y] = 0;
	}
	x++;
	for(int y = 0; linha[x] != 46;x++){
		atual[y] = linha[x];
		atual = (char *)realloc(atual, (strlen(atual) + 1) * sizeof(char));
		y++;
		atual[y] = 0;
		
	}
	return x+1;
}
// 
typedef struct Inteiro{
	int num;
	int valido;
}inteiro;
// Converte ASCII para int
inteiro converteASCII(char* string){
	int multi = 1, ascii = 0, sinal = 1, y = 0;
	inteiro num;
	num.num = 0;
	num.valido = 1;
	if(string[0] == '-'){
		sinal = -1;
		y = 1;
		for(int z = 1; z < strlen(string)-1; z++){
			multi = multi * 10;
		}
	} else{
		for(int z = 0; z < strlen(string)-1; z++){
			multi = multi * 10;
		}
	}
	for(;string[y]; y++){
		ascii = 0;
		for(int z = 48; z <= 57; z++){
			if(string[y] == z){
				num.num += (ascii * multi);
				break;
			} else{
				if(z == 57){
					num.valido = 0;
					return num;
				}
				ascii++;
			}
		}
		multi = multi / 10;
	}
	num.num = num.num * sinal;
	return num;
}
// Converte Posição, máximo e atual
int convertePMA(char* pos, char* max, char* atual, inteiro* pma){
	*(pma) = converteASCII(pos);
	*(pma+1) = converteASCII(max);
	*(pma+2) = converteASCII(atual);
	for(int x = 0; x < 3; x++){
		if(!(pma[x].valido)){
			return 0;
		}
	}
	return 1;
}

// Pega os elementos do vetor no arquivo
int pegaVetor(principal *LISTA, char* string, int inicio, int p){
	inteiro num_vetor;
	int y = 0, tam = strlen(string);
	char* aux;
	aux = (char *)malloc(tam * sizeof(char));
	for(int x = 0;string[inicio];inicio++){
		if(string[inicio] != '.'){
			aux[x] = string[inicio];
			x++;
		} else{
			aux[x] = 0;
			num_vetor = converteASCII(aux);
			LISTA[p].valor[y] = num_vetor.num;
			y++;
			x = 0;
			aux = (char *)malloc(tam * sizeof(char));
		}
	}
	return 1;
}
// Lendo dados salvos
int lerDados(principal *LISTA, FILE *dados){
	int aberto;
	dados = fopen("dados.est", "r");
	aberto = testarArquivo(dados);
	if(aberto){
		int inicio, valido, p, m, a;
		inteiro *pma;
		char linha[99] = {}, *pos, *max, *atual;
		pos = (char *) malloc(2 * sizeof(char));
		max = (char *) malloc(2 * sizeof(char));
		atual = (char *) malloc(2 * sizeof(char));
		if(fgets(linha,sizeof(linha),dados) == NULL)
			return 0;
		while(fgets(linha,sizeof(linha),dados) != NULL){
			inicio = pegaPMA(linha,pos,max,atual);
			pma = (inteiro *)malloc(3 * sizeof(inteiro));
			valido = convertePMA(pos,max,atual,pma);
			if(valido){
				p = pma->num - 1;
				m = pma[1].num;
				a = pma[2].num;
				LISTA[p].max = m;
				LISTA[p].atual = a;
				LISTA[p].valor = (int *) malloc(m * sizeof(int));
				valido = pegaVetor(LISTA,linha,inicio,p);
				if(!valido)
					return 0;
			} else{
				return 0;
			}
			
			
		}
		fclose(dados);
		free(pos);
		free(max);
		free(atual);
		free(pma);
		return 1;
	}
	return 0;
}
// Salvando os dados
int salvarDados(principal *LISTA, FILE *dados){
	int aberto, duplica = 1;
	dados = fopen("dados.est", "w");
	aberto = testarArquivo(dados);
	if(aberto){
		for(int x = 0; x < tamanho; x++){
			if(LISTA[x].atual){
				if(duplica){ // Duplicando a primeira linha, pois o programa não está lendo a primeira linha
					for(int a = 0; a < 2; a++){
						fprintf(dados,"%d.%d.%d.", x+1, LISTA[x].max, LISTA[x].atual);
						for(int y = 0; y < LISTA[x].atual; y++){
							fprintf(dados, "%d.", LISTA[x].valor[y]);
						}
						fprintf(dados,"\n");
					}
					duplica = 0;
				}else{
					fprintf(dados,"%d.%d.%d.", x+1, LISTA[x].max, LISTA[x].atual);
					for(int y = 0; y < LISTA[x].atual; y++){
						fprintf(dados, "%d.", LISTA[x].valor[y]);
					}
					fprintf(dados,"\n");
				}
			}
		}
		fclose(dados);
		return 1;
	} else{
		return 0;
	}
}
// Troca posição de duas variáveis
void trocaPos(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// Pega o tamanho total de um vetor ou de toda estrutura
int tamanhoTotal(principal *LISTA){
	int total = 0;
	for(int x = 0; x < tamanho; x++){
		total += LISTA[x].atual;
	}
	return total;
}
//  Menu de opções
void menu(){
	system("cls");
	printf("============================MENU============================\n");
	printf("(0) Redefinir dados de todas estruturas\n");
	printf("(1) Para inserir elemento\n");
	printf("(2) Listar os numeros de todas estruturas\n");
	printf("(3) Listar os numeros ordenados para cada estrutura auxiliar\n");
	printf("(4) Listar todos os numeros de forma ordenada\n");
	printf("(5) Excluir um elemento\n");
	printf("(6) Aumentar o tamanho de uma estrutura auxiliar\n");
	printf("(7) Salvar dados\n");
	printf("(8) Sair\n");
	printf("============================================================\n");
	printf("\nInforme o numero da opcao desejada: ");	
}
// Trata inteiro
int trataInt(int inteiro){
	if(inteiro < 0)
		return 0;
	else
		return 1;
}
// Receber entrada em string, converter para inteiro e validar
int trataEntrada(){
	char entrada_str[99];
	int* entrada_int, sinal, x, retorno, valida_retorno, valido, contInt;
	do{
		valido = 1, sinal = 1, x = 0, retorno = 0, valida_retorno = -1;
		gets(entrada_str);
		fflush(stdin);
		entrada_int = (int *) malloc(strlen(entrada_str) * sizeof(int));
		if(entrada_str[0] == 45){
			sinal = -1;
			x = 1;
		}	
		contInt = 0;
		for(; x < strlen(entrada_str) && valido; x++){
			int p = 0;
			for(int y = 48; y <= 57; y++){
				if(entrada_str[x] == y){
					*(entrada_int+contInt) = p;
					contInt++;
					break;
				} else{
					if(y == 57){
						printf("\nEntrada invalida! Informe uma entrada valida: ");
						valido = 0;
						break;
					}	
					p++;
				}	
			}
		}
		if(valido){
			int multi = 1;
			for(int y = 0; y < contInt-1; y++){
				multi = multi * 10;
			}
			for(int y = 0; y < contInt; y++){
				retorno += (entrada_int[y] * multi);
				multi /= 10;
				if((retorno < 0 || retorno == valida_retorno) && entrada_int[y] != 0){
					valido = 0;
					printf("-> Entrada ultrapassa o tamanho de um tipo inteiro. Informe uma entrada valida: ");
					break;
				}
				valida_retorno = retorno;
			}
			if(valido)
				retorno = retorno * sinal;
		}
	}while(!valido);
	return retorno;
}
// Verifica se o vetor foi alocado
int trataAloc(int *vetor){
	if(!vetor){
		printf("\nERRO -> Sem espaco na memoria.\n\n");
		system("pause");
		return 0;
	} else
		return 1;
}
// Aumenta o tamanho das estruturas
void aumentaTamEstAux(principal *LISTA, int* vetorAux){
	int estrutura, realocado = 0, acresc;
	printf("\nQual o numero da estrutura a ser aumentada?");
	estrutura = trataEntrada() - 1;
	if(estrutura < 0 || estrutura > 10){
		printf("\nEntrada invalida! Tente novamente!");
		aumentaTamEstAux(LISTA,vetorAux);
	}
	if(LISTA[estrutura].max == 0){
		printf("\nA estrutura ainda nao foi criada. Informe outra estrutura!");
		aumentaTamEstAux(LISTA,vetorAux);
	}
	vetorAux = (int *) malloc(LISTA[estrutura].atual * sizeof(int));
	int backup = 0;
	for(int x = 0; x < LISTA[estrutura].atual; x++){ // Faz backup dos elementos da estrutura, para tratar possíveis erros
		*(vetorAux+x) = LISTA[estrutura].valor[x];
	}
	do{
		printf("\nInforme o tamanho a ser acrescentado: ");
		acresc = trataEntrada();
		if(acresc <= 0){
			printf("\nO tamanho deve ser maior que 0. ");
			continue;
		}
		// Validando a entrada
		int valido, validando;
		validando = LISTA[estrutura].max + acresc;
		valido = trataInt(validando);
		if(!valido){
			printf("\nO novo tamanho da estrutura ultrapassa o tamanho de um inteiro. Tente um tamanho menor!");
		} else{
			LISTA[estrutura].valor = (int *) realloc(LISTA[estrutura].valor, (LISTA[estrutura].max + acresc) * sizeof(int));
			realocado = trataAloc(LISTA[estrutura].valor);
			if(realocado){
				if(backup){
					for(int x = 0; x < LISTA[estrutura].atual; x++)
						LISTA[estrutura].valor[x] = *(vetorAux+x);
					free(vetorAux);
				}
				LISTA[estrutura].max += acresc;
				printf("\nRealocado com sucesso!");
			} else
				backup = 1;
		}
	}while(!realocado);
}
// Validando a posição informada pelo usuário
int trataPos(int pos){
	do{
		printf("Em qual estrutura? (De 1 a %d): ", tamanho);
		pos = trataEntrada();
		pos -= 1;
		if(pos < 0 || pos > tamanho){
			printf("Estrutura invalida!\n");
		}
	} while(pos < 0 || pos > tamanho);
	return pos;
}
//Inserindo elemento na estrutura
void insereEle(principal *LISTA){
	int pos, op_est, alocado = 0, a, ret_menu = 0;
	system("cls");
	pos = trataPos(pos);
	if(LISTA[pos].max == 0){
		do{
			printf("\nA estrutura %d ainda nao foi criada. Deseja criar uma nova estrutura? Informe 1 para SIM ou 0 para NAO: ", pos+1);
			op_est = trataEntrada();
			if(op_est != 0 && op_est != 1){
				printf("\nOpcao Invalida!\n");
				system("pause");
			} else if(op_est == 1){
				do{
					printf("\n\nInforme o tamanho que deseja para a estrutura %d: ", pos+1);
					LISTA[pos].max = trataEntrada();
					if(LISTA[pos].max <= 0){
						printf("\n\nInforme um tamanho maior que 0!\n");
						system("pause");
					}else{
						LISTA[pos].valor = (int *)malloc(LISTA[pos].max * sizeof(int));
						alocado = trataAloc(LISTA[pos].valor);
					}
				}while(!alocado);
			} else{
				printf("\n-> Retornando ao menu...");
				ret_menu = 1;
				break;
			}
		}while((op_est != 0 && op_est != 1) || (LISTA[pos].max <= 0));
		if(!ret_menu){
			printf("\n\nEstrutura criada com sucesso!!!");
			printf("\n\nInforme o valor que deseja inserir na estrutura %d: ", pos+1);
			a = LISTA[pos].atual;
			LISTA[pos].valor[a] = trataEntrada();
			LISTA[pos].atual++;
			printf("\nValor inserido com sucesso!!");
		}
	} else{
		if(LISTA[pos].max == LISTA[pos].atual){
			printf("\nA estrutura esta cheia! Retornando ao menu...");
		} else{
			printf("\n\nInforme o valor que deseja inserir na estrutura %d: ", pos+1);
			a = LISTA[pos].atual;
			LISTA[pos].valor[a] = trataEntrada();
			LISTA[pos].atual++;	
			printf("\n\nValor inserido com sucesso!!");	
		}
	}
}
//Lista elementos
void listar(int *vetorAux, int tam_vetAux){
	for(int x = 0; x < tam_vetAux; x++)
		printf("| %d | ", *(vetorAux+x));
}
// Ordenacao selection sort
void ordenar(int *vetorAux, int tam_vetAux){
	int menor;
	for(int x = 0; x < tam_vetAux; x++){
		menor = x;
		for(int y = x + 1; y < tam_vetAux; y++){
			if(vetorAux[y] < vetorAux[menor]){
				menor = y;
			}
		}
		if(x != menor){
			trocaPos(&vetorAux[x],&vetorAux[menor]);
		}
	}
}
// Exclue elemento de uma determinada estrutura
void exclueEle(principal *LISTA, int elemento, int pos){
	int encontrado = -1;
	for(int x = 0; x < LISTA[pos].atual; x++){
		if(LISTA[pos].valor[x] == elemento){
			encontrado = x;
			break;
		}
	}
	if(encontrado == -1){
		printf("\n-> Elemento nao existe na estrutura! Retornando ao menu...");
	}else{
		for(int x = encontrado; x < LISTA[pos].atual - 1; x++){
			LISTA[pos].valor[x] = LISTA[pos].valor[x+1];
		}
		LISTA[pos].atual--;
		printf("\nElemento excluido com sucesso!");
	}
}
//Copiando o vetor original para um outro vetor temporÃ¡rio e executando as opÃ§Ãµes
void toVetor(principal *LISTA, int *vetorAux, int op){
	int p = 0, x = 0;
	for(; x < tamanho; x++){ 
		if(op != 4){
			free(vetorAux);
			vetorAux = (int *) malloc(LISTA[x].atual * sizeof(int));
			p = 0;
		} 
		if(LISTA[x].valor){
			for(int y = 0; y < LISTA[x].atual; y++){
					*(vetorAux+p) = *(LISTA[x].valor+y); // Passando todos os elementos para um novo vetor
					p++;
			}	
			if(op == 2){
				printf("\n\n-> Estrutura %d\n\t-> Tamanho: %d", x+1, LISTA[x].max);
				if (!LISTA[x].atual){
					printf("\n\t\t-> Nao possui elementos.");
				} else{
					printf("\n\t\t-> Elementos: ");
					listar(vetorAux,LISTA[x].atual);
				}	
			}else if(op == 3){
				printf("\n\n-> Estrutura %d\n\t-> Tamanho: %d", x+1, LISTA[x].max);
				if (!LISTA[x].atual){
					printf("\n\t\t-> Nao possui elementos.");
				} else{
					printf("\n\t\t-> Elementos ordenados: ");
					ordenar(vetorAux,LISTA[x].atual);
					listar(vetorAux,LISTA[x].atual);
				}
			} 
		}else if(op != 4){
			printf("\n\n-> Estrutura %d nao possui estrutura auxiliar.", x+1);
		}
	}
	if(op == 4){
			printf("\n\n-> Todos os numeros ordenados: ");
			int final = tamanhoTotal(LISTA);
			ordenar(vetorAux,final);
			listar(vetorAux,final);
	}
	free(vetorAux);
}
void excluir(principal *LISTA){
	int elemento, estrutura;
	estrutura = trataPos(estrutura);
	if(LISTA[estrutura].atual){
		printf("\n-> Elementos da estrutura %d: ", estrutura+1);
		listar(LISTA[estrutura].valor, LISTA[estrutura].atual);
		printf("\n\nQual o elemento a ser excluido? ");
		elemento = trataEntrada();
		exclueEle(LISTA,elemento,estrutura);
	}else{
		printf("\nEstrutura vazia.");
	}
}
int verificaEstruturas(principal *LISTA){
	for(int x = 0; x < tamanho; x++){
		if(LISTA[x].max){
			return 1;
		}
	}
	return 0;
}
//Executando as opções
void opcao(principal *LISTA, int *vetorAux, int op, int *saida, FILE* dados){
	int ok = 0, salvar;
		switch(op){
			case 0:
				ok = verificaEstruturas(LISTA);
				if(ok){
					printf("\nTem certeza que deseja redefinir tudo? 1 -> SIM ou 0 -> NAO: ");
					ok = trataEntrada();
					if(ok == 1){
						anula(LISTA);
						printf("\nEstruturas redefinidas com sucesso!");
					}
					else
						printf("\nOpcao cancelada! Retornando ao menu...");
				} else{
					printf("\nNao ha o que redefinir, as estruturas ja possuem definicoes padroes.");
				}
				break;
			case 1:
				insereEle(LISTA);
				break;
			case 2:
				ok = verificaEstruturas(LISTA);
				if(ok){
					toVetor(LISTA, vetorAux, op);
				}else{
					printf("\nNenhuma estrutura criada.");
				}
				break;
			case 3:
				ok = verificaEstruturas(LISTA);
				if(ok){
					toVetor(LISTA, vetorAux, op);
				}else{
					printf("\nNenhuma estrutura criada.");
				}
				break;
			case 4:
				ok = verificaEstruturas(LISTA);
				if(ok){
					vetorAux = (int *) malloc(tamanhoTotal(LISTA) * sizeof(int));
					toVetor(LISTA, vetorAux, op);
				}else{
					printf("\nNenhuma estrutura criada.");
				}
				break;
			case 5:
				ok = verificaEstruturas(LISTA);
				if(ok){
					excluir(LISTA);
				}else{
					printf("\nNenhuma estrutura criada.");
				}
				break;
			case 6:
				ok = verificaEstruturas(LISTA);
				if(ok){
					aumentaTamEstAux(LISTA, vetorAux);
				}else{
					printf("\nNenhuma estrutura criada.");
				}
				break;
			case 7:
				printf("Deseja salvar os ultimos dados alterados das estruturas? 1 -> SIM ou 0 -> NAO: ");
				salvar = trataEntrada();
				if(salvar){
					salvar = salvarDados(LISTA,dados);
					if(salvar)
						printf("\nDados salvos com sucesso!");
					else
						printf("\nErro ao salvar dos dados!");
				} else{
					printf("\n--> Retornando ao menu...");
				}
				break;
			case 8:
				*saida = 1;
				break;
			default:
				printf("\n\nOpcao invalida!");	
		}
}
