#ifndef _WRAPPER_H
#define _WRAPPER_H

#include <vector>
#include <string>
#include <iostream>

#define INF 9999999; // valor muito grande aleatório


class Text{
	private:
		std::vector<std::string>& words_;
		int line_width_;
		int lineCost(int i, int j);
	public:
		Text(std::vector<std::string>& words, int line_width);
		void solve();	
};

#endif