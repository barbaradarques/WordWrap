/*******************************************************************************
 * Example source code for using the argtable3 library to implement:
 *
 *     myprog [-lRv] [-k <int>] [-D MACRO]... [-o <output>] [--help]
 *        [--version] <file> [<file>]...
 *
 * This file is part of the argtable3 library.
 *
 * Copyright (C) 1998-2001,2003-2011,2013 Stewart Heitmann
 * <sheitmann@users.sourceforge.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of STEWART HEITMANN nor the  names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL STEWART HEITMANN BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
// source modificado

#include "argtable3.h"
#include "argparse.h"
#include <iostream>
#include <string>
#include <vector>

#define LEN_DEFAULT 40; // valor default para o tamanho das linhas finais

using namespace std;

int argparse(int *len, vector<string> *words, int argc, char *argv[]){
	struct arg_str *text_ = arg_strn(NULL,NULL,NULL,0,1,"Text to make word wrap - enclose it in double quotes.");
	struct arg_int *len_ = arg_int0("l","len",NULL,"Sets length of lines after word wrap processing.");
	struct arg_lit *help_ = arg_litn("h", "help", 0, 1, "Displays the help and exits.");
	struct arg_lit *inline_ = arg_litn("i", "inline", 0, 1, "Text will be passed by input and not by argument. Only the last line can be empty.");
	struct arg_end *end_ = arg_end(20);
	void* argtable[] = {text_,len_,help_,inline_,end_};

    const char* progname = argv[0];
    int nerrors;
    int exitcode=0;

	/* Parse the command line as defined by argtable[] */
    nerrors = arg_parse(argc,argv,argtable);

    /* special case: '--help' takes precedence over error reporting */
    if(help_->count > 0){
        printf("Uso: %s", progname);
        arg_print_syntax(stdout,argtable,"\n");
		cout << "Utility to apply word wrap to text." << endl;
        arg_print_glossary(stdout,argtable,"  %-25s %s\n");
        exitcode=0;
        goto exit;
	}

    /* If the parser returned any errors then display them and exit */
    if(nerrors > 0){
        /* Display the error details contained in the arg_end struct.*/
        arg_print_errors(stdout,end_,progname);
        cout << "Tente '" << progname << " --help' for help on how to use." << endl;
        exitcode=1;
        goto exit;
	}

    /* special case: uname with no command line options induces brief help */
    if(argc==1){
        exitcode=2;
        goto exit;
	}

	if(len_->ival[0]==0){
		*len = LEN_DEFAULT;
	} else {
		*len = len_->ival[0];
	}
    if(inline_->count > 0){
		string line, lines;
		do{
			getline(std::cin, line);
			lines += line;
		}while(line.size()!=0);
		split(lines, *words, ' ');
	} else {
		string text(text_->sval[0]);
		split(text, *words, ' ');
	}
	words->insert(words->begin(),""	);

	exit:
	/* deallocate each non-null entry in argtable[] */
	arg_freetable(argtable,sizeof(argtable)/sizeof(argtable[0]));

	return exitcode;
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	// by Baltasarq used under CC BY-SA 3.0
	// Source: https://stackoverflow.com/posts/5888676/revisions
	// Original page: https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
	// License URL: https://creativecommons.org/licenses/by-sa/3.0/
	// Baltasaq URL:
	//  - https://stackoverflow.com/users/266978/baltasarq
	//  - http://jbgarcia.webs.uvigo.es/
	// As of October 15, 2020 at 15:40 (UTC-4)
	// kept unchanged according to the original to that date.

    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}
