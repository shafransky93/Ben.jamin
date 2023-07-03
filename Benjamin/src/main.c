#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"

void print_help()
{
	printf("                  Hello! 👋 \n");
	printf("Welcome to the ben.jamin programing language 😎 \n \n");

	printf("So far we got a lexer and a parser. The lexer takes the input and turns \nit into a token that I can understand. The parser builds a AST \n(Abstract Semantic Tree) and parses the nodes of the tree into tokens using the lexer.\nIf installed on your system, to load a file type 'ben path/to/file/<filename>.jamin'\nIf just made as a ben.jamin file, to load a file type './ben.jamin path/to/file/<filename>.jamin'\n\n\nThere is now a built-in: print function\n(Im still working on stuff, so not much is functional, but hey... ntbimho 😎)\n\n");
	exit(1);
}

int main(int argc, char* argv[])
{
	
	if (argc < 2)
		print_help();
	
	// code to be ran
	lexer_T* lexer = init_lexer(
		get_file_contents(argv[1])
	);
		
	// parser visiting AST
	parser_T* parser = init_parser(lexer);
	AST_T* root = parser_parse(parser);
	visitor_T* visitor = init_visitor();
	visitor_visit(visitor, root);
	
//	printf("Type: %d\n", root->type);
//	printf("Compound size: %ld\n", root->compound_size);

//	printf("Lexer output:\n");
//	token_T* token = (void*)0;
//
//	while ((token = lexer_get_next_token(lexer)) != (void*)0)
//	{
//		printf("TOKEN(%d, %s)\n", token->type, token->value);
//	}

		
	return 0;
}

