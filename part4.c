#include <stdio.h>
#include <stdlib.h>
void double_space(FILE *, FILE *);
void prn_info(char *);
main(int argc, char **argv){
    FILE *ifp, *ofp;
    if(argc!=3){
        prn_info(argv[0]);
        exit(1);
    }
    ifp=fopen(argv[1], "r"); /* open for reading */
    ofp=fopen(argv[2], "w"); /* open for writing */
    double_space(ifp, ofp);
    fclose(ifp);
    fclose(ofp);
}

int lineCounter = 0;
void makeNewArray(char array[200], FILE *ofp, int addNewLine) {
    int i;
    lineCounter++;
    for (i = 200; i >= 0; i--) {
        if (array[i] != -1 && array[i] != '\0') {
            // Write the character to a file
            putc(array[i], ofp);
        }
    }
    if(addNewLine == 1){
        putc('\n', ofp);
    }
}


void double_space(FILE *ifp, FILE *ofp){
    int c;
    char array[200] = {-1};
    int counter = 0;
    while((c=getc(ifp))!=EOF){
        if(c == '\n'){
            // tell the computer it is the end of the array
            array[counter] = '\0';

            // reset counter 
            counter = 0;
            
            // reverse the array 
            makeNewArray(array, ofp, 1);

            // reset the array
            int resetVariable;
            for (resetVariable = 0; resetVariable < 200; resetVariable++) {
                array[resetVariable] = -1;
            }
        }
        else{
            array[counter] = c;
            counter++;
        }
    }

    // account for the last line in the file
    makeNewArray(array, ofp, 0);
}
void prn_info(char *pgm_name){
    printf("\n%s%s%s\n\n%s%s\n\n",
    "Usage: ", pgm_name, " infile outfile",
    "The contents of infile will be double-spaced ",
    "and written to outfile.");
}
