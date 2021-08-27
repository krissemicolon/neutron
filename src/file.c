
void read_file(char *filename) {
    FILE *code_file;    
    code_file = fopen(filename, "r");
    fgets(codebuff, sizeof(codebuff), code_file);
}