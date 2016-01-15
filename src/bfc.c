#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv){
    // handle args
    if(argc != 3){
        printf("usage: ./bfc /path/to/input.bf /path/to/output.bfc");
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

    for(; pos < flen; pos++){
        switch(src[pos]){
            case '[':
                //TODO:find matching brace and replace [ with pos
                break;
            case ']':
                //todo:find matching brace and replace ] with pos
                break;
        }
    }

    return 0;
}

int find_match_open(unsigned int pos, char *src){
    pos++;
    for(int weight = 1; weight != 0; pos++){
        switch(src[pos]){
            case '[':
                weight++;
                break;
            case ']':
                weight--;
                break;
        }
    }
    return pos;
}

int find_match_closed(unsigned int pos, char *src){
    pos--;
    for(int weight = 1; weight != 0; pos--){
        switch(src[pos]){
            case ']':
                weight++;
                break;
            case '[':
                weight--;
                break;
        }
    }
    return pos;
}

