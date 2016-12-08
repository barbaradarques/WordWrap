#include "wrapper.h"

using namespace std;

void solve(vector<string> words, int line_width){
	int i, j, k, n = words.size() - 1; // n = número de palavras
	// assim como words, todos os demais vetores começam em 1
	int opt[n+1], cost[n+1][n+1];
	int parent[n+1]; // lista encadeada do caminho ótimo 
	// ex.: parent[j] = i significa que a linha que começa em i termina em j

	/*
	Função de Recorrência:
		opt[j] = min(opt[i-1] + cost[i][j]), para i variando entre 1 e j.
	Onde:
		opt[j] é o custo mínimo para um texto com as j primeiras palavras de "words"
		cost[i][j] é o custo de uma linha iniciando na palavra i e terminando em j
	*/

	// preenche cost
	for(i = 1; i <= n; ++i){
		for(j = i; j <= n; ++j){
			int filled = words[i].length(); // espaço preenchido na linha(no mínimo o tamanho da primeira palavra)
			for(k = i + 1; k <= j; ++k){
				filled += 1 + words[k].length(); // adiciona tamanho da palavra mais espaço entre a anterior a ela
			}
			if(filled > line_width){
				cost[i][j] = INF; // inviabiliza a escolha dessa linha
			} else {
				cost[i][j] = (line_width - filled) * (line_width - filled);
			}	
		}
	}

	// preenche opt
	opt[0] = 0;
	for(j = 1; j <= n; ++j){
		opt[j] = INF;
		for(i = 1; i <= j; ++i){
			if(opt[i-1] + cost[i][j] < opt[j]){ 
				opt[j] = opt[i-1] + cost[i][j];
				parent[j] = i;
			}
		}
	}

	// imprime solução
	int end = n;
	string solution = "";
	while(end > 0) {
		/* 
			como percorre-se o vetor de trás pra frente,
		 	cada palavra é adicionada na frente das já percorridas
		*/
		solution = words[end] + '\n' + solution; // a última palavra não tem espaço
		for(i = end - 1; i >= parent[end]; --i){
			solution = words[i] + " " + solution;
		}
		end = parent[end] - 1;
	}
	cout << solution;
}

