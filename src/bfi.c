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
    unsigned int size = 16;
    unsigned int mem[size]; 
    unsigned int index = 0;
    
    // store the highest index written to so that we can downsize the memory.
    unsigned int max_index = 0;
    
    //keep track of current char
    char curr;

    while((curr = fgetc(src)) != EOF){
        switch(curr){

            // increment value at ptr
            case '+':
                //increase max index if needed
                if(index > max_index){
                    max_index = index;
                }
                
                //TODO: expand mem if needed
                
                mem[index]++;
                
                break;

            // decrement value at ptr
            case '-':
                mem[index]--;


                // if necessary, find the nex max_index from the old one
                if(index == max_index && mem[index] == 0){
                    for(int i = index; i >= 0; i--){
                        if(mem[i] != 0){
                            max_index = i;
                        }
                    }
                }

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
                putchar(mem[index]);
                break;
            
            // store one byte of user input in ptr
            case ',':
                mem[index] = getchar();
                break;

            /* TODO JUMP STATEMENTS */
    
        }
    }

    fclose(src);
    return(0);
}
