#include <iostream>
#include <vector>
#include <string>
#include "wrapper.h"
#include "argparse.h"

using namespace std;

int main(int argc, char *argv[]){
	int len;
	vector<string> words;

	switch(argparse(&len, &words, argc, argv)){
		case 0:// tudo ok
			break;
		case 1:// erro
			return 1;
		case 2:// compatibilidade com codigo original
			int n;
			cin >> len >> n;

			words.clear();
			// preencher primeiro indice para manter compatibilidade com o codigo original
			words.push_back("");
			string aux;
			// para facilitar a implementação, o  vetor de palavras começa a ser preenchido em 1
			for(int i = 1; i <= n; ++i){
				cin >> aux;
				words.push_back(aux);
			}
			break;
	}

	Text txt(words, len);
	txt.solve();
	return 0;
}
