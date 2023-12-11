#include <stdio.h>
/* usage of the struct is optional */
typedef struct _petdata
{
    char name[15];
    double wt;
    int age;
} PetData;

int main(int argc, char *argv[])
{

    /* Type your code here. */
    FILE *fin1;
    fin1 = fopen(argv[1], "r");
    int count = 0;
    PetData pet;
    char inputbuffer[1000];
    double total = 0;

    printf("Name                Weight   Age\n");
    while (fgets(inputbuffer, 64, fin1) != NULL)
    {
        if (sscanf(inputbuffer, "%14s %lf %d", pet.name, &pet.wt, &pet.age) == 3)
        {
            if (pet.wt > 0 && pet.wt <= 100 && pet.age <= 25)
            {
                total += pet.age;
                count++;
                printf("%-14s %-8.1lf %d\n", pet.name, pet.wt, pet.age);
            }
        }
    }
    double average = total / count;
    printf("Average age %.2lf\n", average);
    fclose(fin1);
    return 0;
}
