#include <stdlib.h>
#include <stdio.h>

#include "cli.h"

#ifndef VERSION
#define VERSION "Version Error"
#endif

void print_logo() {
    printf(
        "                            _\n"
        "                          .' `'.__\n"
        "                         /      \\ `'\"-,\n"
        "        .-''''--...__..-/ .     |      \\\n"
        "      .'               ; :'     '.  a   |\n"
        "     /                 | :.       \\     =\\\n"
        "    ;                   \':.      /  ,-.__;.-;`\n"
        "   /|     .              '--._   /-.7`._..-;`\n"
        "  ; |       '                |`-'      \\  =|\n"
        "  |/\\        .   -' /     /  ;         |  =/\n"
        "  (( ;.       ,_  .:|     | /     /\\   | =|\n"
        "   ) / `\\     | `\"\"`;     / |    | /   / =/\n"
        "     | ::|    |      \\    \\ \\    \\ `--' =/\n"
        "    /  '/\\    /       )    |/     `-...-`\n"
        "   /    | |  `\\    /-'    /;\n"
        "   \\  ,,/ |    \\   D    .'  \\\n"
        "    `\"\"`   \\  nnh  D_.-'L__nnh\n"
        "            `\"\"\"`\n"
        "I like elephants and god likes elephants\n"
    );
}

void print_usage() {
    puts("Usage: neutron -f <file>");
}

void print_help() {
    print_logo();
    printf("\n");
    print_usage();
    printf("\n");
    printf(
        "Options:\n"
        "-f\t\tInput the file that you want to run\n"
        "-h\t\tPrint the help page\n"
        "-v\t\tPrint version information\n"
        "Example:\n"
        "neutron -f main.bf\n"
        );

    exit(0);
}

void print_version() {
    print_logo();
    printf("\n");
    printf("Version: "VERSION"\n");
    exit(0);
}