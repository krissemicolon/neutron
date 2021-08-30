#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "preprocessor.h"
#include "interpreter.h"
#include "tokens.h"
#include "cli.h"
#include "main.h"

static char codebuff[sizeof(char) * 6000];

int main(int argc, char **argv) {
    char *file;

    int options;
    while ((options = getopt(argc, argv, "hvf:i:")) != -1) {
        switch (options) {
            case 'h':
                print_help();
            break;

            case 'v':
                print_version();
            break;

            case 'f':
                file = optarg;
                read_file(file);
                interpret(preprocess(codebuff));
            break;

            case 'i':
                interpret(preprocess(optarg));
            break;
        }
    }

    if(optind == 1) {
        print_usage();
        puts("neutron -h for more information");
        exit(2);
    }

    return 0;
}

void read_file(char *filename) {
    FILE *code_file;    
    code_file = fopen(filename, "r");
    #pragma GCC diagnostic ignored "-Wunused-result" 
    fgets(codebuff, sizeof(codebuff), code_file);
}