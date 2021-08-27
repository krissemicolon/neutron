#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "interpreter.h"
#include "tokens.h"
#include "cli.h"
#include "main.h"

typedef struct {
    char *file;
} settings;

static char codebuff[sizeof(char) * 6000];

int main(int argc, char **argv) {
    settings stg = {
        .file = "main.bf"
    };

    int options;
    while ((options = getopt(argc, argv, "hvf:")) != -1) {
        switch (options) {
            case 'h':
                print_help();
            break;

            case 'v':
                print_version();
            break;

            case 'f':
                stg.file = optarg;
                read_file(stg.file);
                interpret(codebuff);
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
    fgets(codebuff, sizeof(codebuff), code_file);
}