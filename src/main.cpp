#include <iostream>
#include <vector>
#include <string>
#include "wrapper.h"

using namespace std;

int main(int argc, char const *argv[]){
	int len, n;
	cin >> len >> n;
	// para facilitar a implementação, vetor de palavras começa a ser preenchido em 1
	vector<string> words(n+1);
	for(int i = 1; i <= n; ++i){ 
		cin >> words[i];
	}

	solve(words, len);
	return 0;
}