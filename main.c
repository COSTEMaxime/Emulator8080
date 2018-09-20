#include <stdlib.h>
#include <stdio.h>
#include "disassembler/disassembler.c"

int main(int argc, char * argv[]) {
    
    if (argc != 2) {
        printf("Error : 1 argument is required");
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Error : couldn't open the file %s", argv[1]);
        return 1;
    }

    fseek(f, 0l, SEEK_END);
    int f_size = ftell(f);
    fseek(f, 0l, SEEK_SET);

    unsigned char *buffer = NULL;
    buffer = malloc(f_size);
    if (buffer == NULL) {
        printf("Error : couldn't allocate %d bytes of memory", f_size);
        fclose(f);
        return 1;
    }

    fread(buffer, f_size, 1, f);
    fclose(f);

    int program_counter = 0;
    while (program_counter < f_size) {
        program_counter += disassemble8080(buffer, program_counter);
    }

    return 0;
}