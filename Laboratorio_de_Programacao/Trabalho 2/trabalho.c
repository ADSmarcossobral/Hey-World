// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Antônio Marcos Sobral Ramos
//  email: marcossobral94@gmail.com
//  Matrícula: 2016116007
//  Semestre: 2016.2

//  Copyright Â© 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>

int pegaAno(char *data){
	int multi = 1, ano = 0, cont = 0;
	//Obtendo o ano
	for(int x = strlen(data) - 1;x >= 0;x--){ // Percorrendo a partir da última posição da string
		int ascii, dec = 0;
		for(ascii=48;ascii<58;ascii++){ // Convertendo os caracteres da tabela ascii para inteiros
			if(data[x] == 47){ // Se o caracter for igual a "/", então o ano já foi pecorrido
				x = -1; // Condição para que não volte para o primeiro for
				break;
			}
			if(data[x] == ascii){
				ano = ano + (dec * multi); // multiplica-se a unidade, depois a dezena, depois a centena e por último o milhar.
				multi = multi * 10;
				break;
			}
			dec++; // O dec incrementa na mesma proporção que o ascii
		}
		cont++; // Somando quantos dígitos são encontrados no ano
	}
	if(cont > 5 || cont == 4){ // Se a quantidade de repitições for maior que 5, a data informada é inválida
		return -1;
	} else{
		if(cont == 3){
			ano = ano + 2000;
		}
		return ano;
	}
}

int pegaMes(char *data){
	int multi = 1, mes = 0, cont = 0, cont2 = 0;
	for(int x = strlen(data) - 1; x >= 0; x--){ //Encontrando a posição da primeira "/"
		if(data[x] != 47){
			cont++;
		} else{
			cont++;
			break;
		}
	}
	for(int x = strlen(data) - 1 - cont;x >= 0;x--){ // Verificando a string a partir da primeira "/" encontrada
		int ascii, dec = 0;

		for(ascii=48;ascii<58;ascii++){
			if(data[x] == 47){
				x = -1;
				break;
			}
			if(data[x] == ascii){
				mes = mes + (dec * multi);
				multi = multi * 10;
				break;
			}
			dec++;
		}
		cont2++; // Contando quantidade de digítos informado no mês
	}
	if(cont2 <= 3){ // Se a quantidade de repetições for maior que 3, a data é inválida
		return mes;
	} else{
		return -1;
	}
}

int pegaDia(char *data){
	int multi = 1, dia = 0, cont = 0, barra_encontrada = 0, cont2 = 0;
	for(int x = strlen(data) - 1; x >= 0; x--){ // Contando as posições já verificadas
		if(data[x] != 47 || (data[x] == 47 && barra_encontrada < 2)){
			cont++;
		}
		if(data[x] == 47){
			barra_encontrada++;
		}
		if(barra_encontrada > 1){
			break;
		}
	}
	for(int x = strlen(data) - 1 - cont;x >= 0;x--){ // Verificando a string a partir da última posição verificada no for anterior
		int ascii, dec = 0;
		for(ascii=48;ascii<58;ascii++){
			if(data[x] == ascii){
				dia = dia + (dec * multi);
				multi = multi * 10;
				break;
			}
			dec++;
		}
		cont2++; // contando a quantidade de digítos informado no dia
	}
	if(cont2 <= 2){ // Se for maior que 2, então a data é inválida
		return dia;
	} else{
		return -1;
	}
}

int val_ano_bi(int ano){
	if(ano % 4 == 0){ // Verificando se o ano é bissexto
		return 1;
	} else{
		return 0;
	}
}

int q1(char *data){
	int multi = 1, ano = 0, mes = 0, dia = 0, pos_verificada = 0;
	//Obtendo o ano, mes e dia
	ano = pegaAno(data);
	mes = pegaMes(data);
	dia = pegaDia(data);
	// Validando os meses de 31 dias
	if((dia > 0 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && ano > 0){
		return 1;
	} else if((dia > 0 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11) && ano > 0){ // Validando os meses de 30 dias
		return 1;
	} else if((dia > 0 && dia <= 28) && mes == 2 && !val_ano_bi(ano) && ano > 0){ // Validando o mês de fevereiro em ano não bissexto
		return 1;
	} else if((dia > 0 && dia <= 29) && mes == 2 && val_ano_bi(ano) && ano > 0){ // Validando o mês de fevereiro em ano bissexto
		return 1;
	} else{ // Caso nenhum caso seja verdadeiro, então a data informada é inválida
		return 0;
	}
}

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    *qtdDias = 0;
    *qtdMeses = 0;
    *qtdAnos = 0;
	int diV = q1(datainicial), dfV = q1(datafinal), anoI, mesI, diaI, anoF, mesF, diaF;
    if(diV == 1 && dfV == 1){
    	anoI = pegaAno(datainicial);
		mesI = pegaMes(datainicial);
		diaI = pegaDia(datainicial);
		anoF = pegaAno(datafinal);
		mesF = pegaMes(datafinal);
		diaF = pegaDia(datafinal);		
		*qtdAnos = anoF - anoI;
		*qtdMeses = mesF - mesI;
		*qtdDias = diaF - diaI;
		if(anoF - anoI >= 0 && mesF - mesI < 0){
			*qtdAnos = *qtdAnos - 1;
			*qtdMeses = 12 - (mesI - mesF);
		}
		if(diaF - diaI < 0){
			if(*qtdMeses == 0){
				if(diaF == 28 && diaI == 29 && mesF == 2 && mesI == 2 && val_ano_bi(anoI) && !val_ano_bi(anoF)){
					*qtdDias = 0;
					*qtdMeses = 0;
				} else{
					*qtdAnos = *qtdAnos - 1;
					*qtdMeses = 11;
					*qtdDias = diaF;
				}
			}else{
				*qtdMeses = *qtdMeses - 1;
				if(mesI == 1 || mesI == 3 || mesI == 5 || mesI == 7 || mesI == 8 || mesI == 10 || mesI == 12){
					*qtdDias = (31 - diaI) + diaF;
				} else if(mesI == 4 || mesI == 6 || mesI == 9 || mesI == 11){ // Validando os meses de 30 dias
					*qtdDias = (30 - diaI) + diaF;
				} else if(mesI == 2 && !val_ano_bi(anoI)){ // Validando o mês de fevereiro em ano não bissexto
					if(!val_ano_bi(anoF)){
						*qtdDias = (28 - diaI) + diaF;
					} else {
						*qtdDias = (28 - diaI) + diaF + 1;
					}
				} else if(mesI == 2 && val_ano_bi(anoI)){ // Validando o mês de fevereiro em ano bissexto
					if(mesF == 2){
						if(val_ano_bi(anoF)){
							*qtdDias = 29 - diaI + diaF;
						}else{
							*qtdDias = 28 - diaI + diaF;
						}
					} else{
						*qtdDias = (29 - diaI) + diaF;
					}
				}
			}
    	} 	
    	return 1;
	} else {
    	return 0;
   	}
}

int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
 	for(int x = 0; x < strlen(texto); x++){
 		if(isCaseSensitive == 1){
 			if(texto[x] == c){
 				qtdOcorrencias++;
 			}
 		} else{
 			if(texto[x] == c || texto[x] == c - 32 || texto[x] == c + 32){
 				qtdOcorrencias++;
 			}
 		}
 	}
	return qtdOcorrencias;
}

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0, y = 0,k = 0, posI;
    for(int x = 0;x < strlen(strTexto);){
		if(strBusca[y] == strTexto[x]){
			posI = x;
			for(;y < strlen(strBusca);y++){
				if(strBusca[y] == strTexto[x]){
					if(y == strlen(strBusca) - 1){
						qtdOcorrencias++;
						posicoes[k] = posI;
						posicoes[k+1] = x;
						k = k + 2;
					}
				} else{
					x++;
					break;
				}
				x++;
			}
			y = 0;
		} else{
			x++;
		}
    }
    return qtdOcorrencias;
}

int q5(int num){
	int n[99], multi = 1, tam = 0;
	for(int x = 0; x < 99; x++){ // Passando cada dígito do número para um vetor
		n[x] = num % 10;
		num = num / 10;
		tam++;
		if(num < 10){
			tam++;
			x++;
			n[x] = num;
			break;
		}
	}
	num = 0;
	for(int x = tam-1; x >= 0; x--){ // Multiplicando os dígitos, o primeiro por 1, o segundo por 10, o terceiro por 100...
		num = num + (n[x] * multi);
		multi = multi * 10;
	}	
    return num;
}

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;
    int nBase[99], multi = 1, tamBase = 0;
	for(int x = 0; x < 99; x++){ // Convertando cada dígito do número base para um vetor
		if(numerobase < 10){
			tamBase++;
			nBase[x] = numerobase;
			break;
		}
		nBase[x] = numerobase % 10;
		numerobase = numerobase / 10;
		tamBase++;
	}
	int nBusca[99], tamBusca = 0;
	for(int x = 0; x < 99; x++){ // Convertendo cada dígito do número que será buscado para um vetor
		if(numerobusca < 10){
			tamBusca++;
			nBusca[x] = numerobusca;
			break;
		}
		nBusca[x] = numerobusca % 10;
		numerobusca = numerobusca / 10;
		tamBusca++;
	}
	int y;
	for(int x = tamBase - 1; x >= 0;){ // Verificando se todos os dígitos dentro do vetor de Busca se encontra no vetor Base sequencialmente
		y = tamBusca - 1;
		if(nBase[x] == nBusca[y]){
			for(;y >= 0;y--){
				if(nBase[x] == nBusca[y] && y == 0){
					qtdOcorrencias++;
					x--;
					break;
				} else if (nBase[x] == nBusca[y]){
					x--;
					continue;
				} else{
					x--;
					break;
				}
			}
		} else{
			x--;
		}
	}
    return qtdOcorrencias;
}