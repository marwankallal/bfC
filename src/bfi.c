#include <stdio.h>

int main(int argc, char *argv[]){
    
    // handle args
    if(argc != 2){
        printf("usage: ./bfi /path/to/file");
        return(-1);
    }
    
    // open file
    FILE *src = fopen(argv[1], "r");
    if(!src){
        printf("Could not open file %s", argv[1]);
    }

    /* TODO: MEMORY */

    // current character being parsed
    char curr;

    while((curr = fgetc(src)) != EOF){
        switch(curr){

            // increment value at ptr
            case '+':

                break;

            // decrement value at ptr
            case '-':

                break;
            
            // increment index of ptr
            case '>':

                break;

            // decrement index of ptr
            case '<':

                break;

            // output value at ptr
            case '.':

                break;
            
            // store one byte of user input in ptr
            case ',':

                break;

            /* TODO JUMP STATEMENTS */

        }
    }


    fclose(src);
    return(0);
}
