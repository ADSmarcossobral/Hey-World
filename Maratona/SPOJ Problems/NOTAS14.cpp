/*
	Link da questão: http://br.spoj.com/problems/NOTAS14/
	Status da solução: Accepted
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int vetor[n];
	for(int x = 0; x < n; x++){
		cin >> vetor[x];
	}
	int freq[2][n], mais_freq = 0, saida;
	for(int x = 0; x < n; x++){
		freq[0][x] = vetor[x];
		freq[1][x] = 1;
		for(int y = x+1; y < n; y++){
			if(vetor[y] == -1)
				continue;
			if(freq[0][x] == vetor[y]){
				freq[1][x]++;
				vetor[y] = -1;
			}
		}
		if(mais_freq < freq[1][x]){
			saida = freq[0][x];
			mais_freq = freq[1][x];
		} else if(mais_freq == freq[1][x]){
			if(saida < freq[0][x])
				saida = freq[0][x];
		}
	}
	cout << saida;
	return 0;
}
