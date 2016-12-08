#include "wrapper.h"

using namespace std;

/*
	Função de Recorrência:
		opt[j] = min(opt[i-1] + cost[i][j]), para i variando entre 1 e j.
	Onde:
		opt[j] é o custo mínimo para um texto com as j primeiras palavras de "words"
		cost[i][j] é o custo de uma linha iniciando na palavra i e terminando em j
*/

void solve(vector<string> words, int line_width){
	int i, j, k, n = words.size() - 1; // n = número de palavras
	// assim como "words", todos os demais vetores começam em 1
	int opt[n+1], cost[n+1][n+1];
	int parent[n+1]; // lista encadeada do caminho ótimo 
	// ex.: parent[j] = i significa que a linha ótima que termina em j começa em i

	// preenche cost
	for(i = 1; i <= n; ++i){
		for(j = i; j <= n; ++j){
			int filled = j-i; // characteres preenchidos na linha (inicializado com o # de espaços)
			for(k = i; k <= j; ++k){
				filled += words[k].length(); // adiciona o espaço ocupado por cada palavra
			}
			if(filled > line_width){ 
				cost[i][j] = INF; // inviabiliza a escolha dessas palavras
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
	int end = n; // final da linha
	string solution = "";
	/* 
		como percorre-se o vetor de trás pra frente,
	 	cada palavra nova é adicionada NA FRENTE das já percorridas("solution")
	*/
	while(end > 0){
		solution = words[end] + '\n' + solution; // a última palavra da linha tem '\n' ao invés de espaço
		for(i = end - 1; i >= parent[end]; --i){
			solution = words[i] + ' ' + solution;
		}
		end = parent[end] - 1;
	}
	cout << solution;
}

