#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv){

    // check if no arguments are passed
    if (argv[1] == NULL){
        printf("This program requires at least one argument\n");
        return 0;
    }
    int i = 1;
    double min = atof(argv[i]);
    double max = atof(argv[i]);
    while (argv[i] != NULL ){
        double num = atof(argv[i]);
        if (num < min){
            min = num;
        }
        if (num > max){
            max = num;
        }
        i++;
    }
    printf("The range of these %d values is %lf\n", i-1, max-min);

}