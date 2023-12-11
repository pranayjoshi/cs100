#include <stdio.h>
/* usage of the struct is optional */
typedef struct _petdata {
    char name[15];
    double wt;
    int age;
} PetData;

int main(int argc, char * argv[]) {

   /* Type your code here. */

   int errorCount = 0;
   FILE *fin1, *fin2, *fout, *error;
    fin1 = fopen(argv[1], "r");
    fin2 = fopen(argv[2], "r");
    fout = fopen(argv[3], "w");
    error = fopen("errors.txt", "w");
    if (fin1); else{
        errorCount++;
        printf("ERROR: fopen failed %s\n", argv[1]);
    }
    if (fin2); else{
        errorCount++;
        printf("ERROR: fopen failed %s\n", argv[2]);
    }
    if (fout); else{
        errorCount++;
        printf("ERROR: fopen failed %s\n", argv[3]);
    }

    PetData pet;
    char inputbuffer[1000];
    while(fgets(inputbuffer, 64, fin1) != NULL){
    if (sscanf(inputbuffer, "%63s %lf %d", pet.name, &pet.wt, &pet.age) == 3)
        fprintf(fout, "%s %.1lf %d\n", pet.name, pet.wt, pet.age);
    else {
        errorCount++;
        fprintf(error, "%s", inputbuffer);
    }
    }
    while(fgets(inputbuffer, 64, fin2) != NULL){
    if (sscanf(inputbuffer, "%63s %lf %d", pet.name, &pet.wt, &pet.age) == 3)
        fprintf(fout, "%s %.1lf %d\n", pet.name, pet.wt, pet.age);
    else {
        errorCount++;
        fprintf(error, "%s", inputbuffer);
    }
    }
    printf("%d errors.\n", errorCount);
    fclose(fout);
    fclose(fin1);
    fclose(fin2);
    fclose(error);

   return 0;
}
