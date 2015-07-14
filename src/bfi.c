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

    // using chars (1 byte each). TODO: add flags for different max size? 
    // start with 16 bytes. We'll resize (both up and down) as needed.
    // doing everything on the stack for speed.
    // resizing, multiply by 2 once limit reached. 
    // divide by 2 after reaching (max_ptr / 2) * .75.
    char mem[16]; 
    int index = 0;

    
    //keep track of current char
    char curr;

    while((curr = fgetc(src)) != EOF){
        switch(curr){

            // increment value at ptr
            case '+':
                mem[index]++;
                break;

            // decrement value at ptr
            case '-':
                mem[index]--;
                break;
            
            // increment index of ptr
            case '>':
                index++;
                break;

            // decrement index of ptr
            case '<':
                index--;
                break;

            // output value at ptr
            case '.':
                
                break;
            
            // store one byte of user input in ptr
            case ',':

                break;

            /* TODO JUMP STATEMENTS */
    }


    fclose(src);
    return(0);
}
