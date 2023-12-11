#include <stdio.h>
#include <stdlib.h>

typedef struct _petdata {
    char name[15];
    double wt;
    int age;
} PetData;

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        FILE *fin = fopen(argv[i], "r");
        if (!fin) {
            perror("Failed to open input file");
            continue;
        }

        PetData pets[1000];
        int count = 0;
        double totalWt = 0, totalAge = 0;
        char line[64];
        while (fgets(line, sizeof(line), fin) && count < 1000) {
            if (sscanf(line, "%14s %lf %d", pets[count].name, &pets[count].wt, &pets[count].age) == 3) {
                totalWt += pets[count].wt;
                totalAge += pets[count].age;
                count++;
            }
        }

        if (count > 0) {
            double averageWt = totalWt / count;
            double averageAge = totalAge / count;

            for (int j = 0; j < count; j++) {
                if (pets[j].wt > averageWt && pets[j].age > averageAge) {
                    printf("%s\n", pets[j].name);
                }
            }
        }

        fclose(fin);
    }

    return 0;
}