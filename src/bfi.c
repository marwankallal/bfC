#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_SIZE 16

void resize_mem(unsigned char *mem, unsigned int index, unsigned int size, unsigned int max_index, unsigned int min_mem);

int main(int argc, char *argv[]){
    
    // handle args
    if(argc != 2){
        printf("usage: ./bfi /path/to/file");
        return(-1);
    }
    
    // open file
    FILE *srcf = fopen(argv[1], "rb");
    if(!srcf){
        printf("Could not open file %s", argv[1]);
    }

    // load the file into memory. This saves time by buffering and makes
    // jump commands significantly faster.
    fseek(srcf, 0, SEEK_END);
    long flen = ftell(srcf);
    fseek(srcf, 0, SEEK_SET);
    
    char src[flen];
    fread(src, flen, 1, srcf);
    fclose(srcf);

    // keep track of position in file
    int pos = 0;

    // using chars (1 byte each). TODO: add flags for different max size? 
    // start with 16 bytes. We'll resize (both up and down) as needed.
    // resizing, multiply by 2 once limit reached. 
    // divide by 2 after reaching (max_ptr) * .75.
    unsigned int size = MIN_SIZE;
    
    // allocate and zero initial mem block
    unsigned char *mem = (unsigned char *) malloc(size);
    memset(mem, 0, size);

    unsigned int index = 0;
    
    // store the highest index written to so that we can downsize the memory.
    unsigned int max_index = 0;
    // store low threshold so we dont have to recalculate
    unsigned int min_mem = size * 0.75 + 1;
    
    for(; pos < flen; pos++){
        switch(src[pos]){

            // increment value at ptr
            case '+':
                // increase max index if needed
                if(index > max_index){
                    max_index = index;
                }
               
                resize_mem(mem, index, size, max_index, min_mem); 
                
                mem[index]++;
                
                break;

            // decrement value at ptr
            case '-': 
                mem[index]--;

                // if necessary, find the new max_index from the old one
                if(index == max_index && mem[index] == 0){
                    for(int i = index; i >= 0; i--){
                        if(mem[i] != 0){
                            max_index = i;
                        }
                    }
                }
                
                resize_mem(mem, index, size, max_index, min_mem); 
                
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
                resize_mem(mem, index, size, max_index, min_mem); 
                mem[index] = getchar();
                break;

            // forward jump
            case '[':

                break;
            
            //backwards jump
            case ']':

                break;
    
        }
    }

    return(0);
}

void resize_mem(unsigned char *mem, unsigned int index, unsigned int size, unsigned int max_index, unsigned int min_mem){

    // expand mem if needed
    while(index >= size){
        mem = realloc(mem, size * 2);
        memset(mem + size, 0, size);
        size *= 2;
    }

    // reduce memory if possible
    if(max_index < min_mem && min_mem > MIN_SIZE){
        mem = realloc(mem, min_mem);
        size = min_mem;
    }

    min_mem = size * 0.75 + 1;
    return;
} 
