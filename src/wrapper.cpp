#include "wrapper.h"

using namespace std;

/*
	Função de Recorrência:
		opt[j] = min(opt[i-1] + lineCost(i,j)), para i variando entre 1 e j.
	Onde:
		opt[j] é o custo mínimo para um texto com as j primeiras palavras de "words_"
		lineCost(i,j) é o custo de uma linha iniciando na palavra i e terminando em j
*/

Text::Text(std::vector<string>& words, int line_width)
	: words_(words), line_width_(line_width){
}

void Text::solve(){
	int i, j, k, n = words_.size() - 1; // n = número de palavras
	// assim como "words_", todos os demais vetores começam em 1
	int opt[n+1];
	int parent[n+1]; // lista encadeada do caminho ótimo 
	// ex.: parent[j] = i significa que a linha ótima que termina em j começa em i

	// preenche opt
	opt[0] = 0;
	for(j = 1; j <= n; ++j){
		opt[j] = INF;
		for(i = 1; i <= j; ++i){
			int new_total = opt[i-1] + lineCost(i,j);
			if(new_total < opt[j]){ 
				opt[j] = new_total;
				parent[j] = i;
			}
		}
	}
	
	// imprime solução
	int end = n; // final da linha
	string solution = "";
	/* 
		como percorre-se o vetor de trás pra frente,
	 	cada palavra nova é adicionada ANTES das já percorridas("solution")
	*/
	while(end > 0){
		solution = words_[end] + '\n' + solution; // a última palavra da linha tem '\n' ao invés de espaço
		for(i = end - 1; i >= parent[end]; --i){
			solution = words_[i] + ' ' + solution;
		}
		end = parent[end] - 1;
	}
	cout << solution;
}

int Text::lineCost(int i, int j){
	int filled = j-i; // characteres preenchidos na linha (inicializado com o # de espaços)
	for(int k = i; k <= j; ++k){
		filled += words_[k].length(); // adiciona o espaço ocupado por cada palavra
	}
	if(filled > line_width_){
		return INF; // inviabiliza a escolha dessas palavras
	} else { 
		return (line_width_ - filled) * (line_width_ - filled);
	}
}

