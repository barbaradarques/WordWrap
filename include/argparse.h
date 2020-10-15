#ifndef _ARGPARSE_H
#define _ARGPARSE_H

#include <vector>
#include <string>

int argparse(int *len, std::vector<std::string> *words, int argc, char *argv[]);
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);

#endif