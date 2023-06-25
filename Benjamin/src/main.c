#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"

int main(int argc, char* argv[])
{
	printf("                  Hello! 👋 \n");
	printf("Welcome to the ben.jamin programing language 😎 \n \n");

	printf("So far we got a lexer and a parser. The lexer takes the input and turns \nit into a token that I can understand. The parser builds a AST \n(Abstract Semantic Tree) and parses the nodes of the tree into tokens using the lexer. \n(Im still working on stuff, so not much is functional, but hey... ntbimho)\n\n");
	

	printf("Current example input: \n var name = \"john doe 123\";\n var symbols = \"!@#$^&*()`~-_=+{[}]|:;'?/>.<, 👉👈👇👆🤜🤛 \"; \n print(name,var);\n \n");
	
	// code to be ran
	lexer_T* lexer = init_lexer(
		"var name = \"john doe 123\";\n"
		"var symbols = \"!@#$^&*()`~-_=+{[}]|:;'?/>.<, 👉👈👇👆🤜🤛 \"; \n"
		"print(name)\n"
	);
	
	
	printf("Parser output:\n");
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

