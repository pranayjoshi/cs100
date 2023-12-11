#include <stdio.h>
/* usage of the struct is optional */
typedef struct _petdata {
    char name[15];
    double wt;
    int age;
} PetData;

int main(int argc, char *argv[]) {

   /* Type your code here. */
    FILE *fout = fopen("pets.txt", "w");
    if (!fout) {
        perror("Failed to open output file");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char filename[64];
        sprintf(filename, "%s.txt", argv[i]);

        FILE *fin = fopen(filename, "r");
        if (!fin) {
            perror("Failed to open input file");
            continue;
        }

        PetData pet;
        int count = 0;
        char line[64];
        while (fgets(line, sizeof(line), fin)) {
            if (sscanf(line, "%14s %lf %d", pet.name, &pet.wt, &pet.age) == 3 && pet.age <= 25) {
                fprintf(fout, "%s %s %.1lf %d\n", argv[i], pet.name, pet.wt, pet.age);
                count++;
            }
        }

        printf("%s: %d\n", argv[i], count);
        fclose(fin);
    }

    fclose(fout);
    return 0;
   return 0;
}
