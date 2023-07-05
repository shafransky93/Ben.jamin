#include <stdio.h>
#include <string.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"



#define MAX_LIMIT 20
void print_help()
{
    printf("Sup, you seem to be haiving a hard time loading a file, try the following usage:\nben.jamin <filename>.jamin\n");
    
    printf("If installed on your system, to load a file type 'ben path/to/file/<filename>.jamin'\nIf just made as a ben.jamin file, to load a file type './ben.jamin path/to/file/<filename>.jamin'\n\n\nThere are a few built-in function's:\n  print\n  pointer (prints the current pointer of the variable)\n  peace (exits the program and prints a oodby statement)\n\n(Im still working on stuff, so not much is functional, but hey... ntbimho 😎)\n\n");
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc >= 2){
        for(int i = 1; i < argc; i++){
            int len = strlen(argv[i]);
            char* last_four = &argv[i][len-6];
            if(strcmp(last_four,".jamin") == 0){
                                lexer_T* lexer = init_lexer(
                    get_file_contents(argv[i])
                );
                parser_T* parser = init_parser(lexer);
                AST_T* root = parser_parse(parser, parser->scope);
                visitor_T* visitor = init_visitor();
                visitor_visit(visitor, root);
            }
            
            else {
                print_help();
            }
        }
    }

    else {
        char input[MAX_LIMIT];
        printf("                  Hello! 👋 \n");
		printf("Welcome to the Ben.jamin language v. 0.0.1!\nCreated by Benjamin Shafransky 😎 \n \n");


        while(1){
        printf("🫙 > ");
            fgets(input,MAX_LIMIT, stdin);
            lexer_T* lexer = init_lexer(input);
            parser_T* parser = init_parser(lexer);
            AST_T* root = parser_parse(parser, parser->scope);
            visitor_T* visitor = init_visitor();
            visitor_visit(visitor, root);
        }
    }
    return 0;
}
