#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "image.h"

ImagePPM *readPPM(char *fn)
{
    FILE *input = fopen(fn, "r");
    if (input == NULL) return NULL;
    ImagePPM *copyImg = malloc(sizeof(ImagePPM));
    fscanf(input, "P3\n%d %d\n%d\n", &copyImg->numCols, &copyImg->numRows, &copyImg->maxVal);

    copyImg->pixels = (Pixel **)malloc(sizeof(Pixel) * copyImg->numRows);

    for (int i = 0; i < copyImg->numRows; i++)
    {
        copyImg->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * copyImg->numCols);
    }

    for (int i = 0; i < copyImg->numRows; i++)
    {
        for (int j = 0; j < copyImg->numCols; j++)
        {
            fscanf(input, "%d %d %d", &copyImg->pixels[i][j].red, &copyImg->pixels[i][j].green, &copyImg->pixels[i][j].blue);
        }
    }
    return copyImg;
}

int writePPM(ImagePPM *PpmImg, char *fn)
{
    FILE *input = fopen(fn, "w");
    if (input == NULL)return 0;

    fprintf(input, "P3\n%d %d\n%d\n", PpmImg->numCols, PpmImg->numRows, PpmImg->maxVal);
    for (int i = 0; i < PpmImg->numRows; i++)
    {
        for (int j = 0; j < PpmImg->numCols; j++)
        {
            fprintf(input, "%d %d %d\n", PpmImg->pixels[i][j].red, PpmImg->pixels[i][j].green, PpmImg->pixels[i][j].blue);
        }
    }
    fclose(input);
    return 1;
}

void freePPM(ImagePPM *PpmImg)
{
    for (int i = 0; i < PpmImg->numRows; i++)
    {
        free(PpmImg->pixels[i]);
    }
    free(PpmImg->pixels);
    free(PpmImg);

    return;
}

ImagePGM *readPGM(char *fn)
{
    FILE *input = fopen(fn, "r");
    if (input == NULL) return NULL;
    ImagePGM *copyImg = malloc(sizeof(ImagePGM));
    fscanf(input, "P2\n%d %d\n%d\n", &copyImg->numCols, &copyImg->numRows, &copyImg->maxVal);
    copyImg->pixels = malloc(sizeof(int *) * copyImg->numRows);
    for (int i = 0; i < copyImg->numRows; i++)
    {
        copyImg->pixels[i] = malloc(sizeof(int) * copyImg->numCols);
    }
    for (int i = 0; i < copyImg->numRows; i++)
    {
        for (int j = 0; j < copyImg->numCols; j++)
        {
            fscanf(input, "%d", &copyImg->pixels[i][j]);
        }
    }
    return copyImg;
}
int writePGM(ImagePGM *PgmImg, char *fn)
{
    FILE *input = fopen(fn, "w");
    if (input == NULL) return 0;
    fprintf(input, "P2\n%d %d\n%d\n", PgmImg->numCols, PgmImg->numRows, PgmImg->maxVal);
    // loop through the pixels and print them
    for (int i = 0; i < PgmImg->numRows; i++)
    {
        for (int j = 0; j < PgmImg->numCols; j++)
        {
            fprintf(input, "%d\n", PgmImg->pixels[i][j]);
        }
    }
    fclose(input);
    return 1;
}
void freePGM(ImagePGM *PgmImg)
{
    for (int i = 0; i < PgmImg->numRows; i++)
    {
        free(PgmImg->pixels[i]);
    }
    free(PgmImg->pixels);
    free(PgmImg);
    return;
}

ImagePGM *convertToPGM(ImagePPM *PpmImg)
{
    ImagePGM *PgmImg = malloc(sizeof(ImagePGM));
    strcpy(PgmImg->magic, "P2");

    // copying values
    PgmImg->numRows = PpmImg->numRows;
    PgmImg->numCols = PpmImg->numCols;
    PgmImg->maxVal = PpmImg->maxVal;

    PgmImg->pixels = malloc(sizeof(int *) * PgmImg->numRows);
    for (int i = 0; i < PgmImg->numRows; i++)
    {
        PgmImg->pixels[i] = malloc(sizeof(int) * PgmImg->numCols);
    }
    for (int i = 0; i < PgmImg->numRows; i++)
    {
        for (int j = 0; j < PgmImg->numCols; j++)
        {
            // getting values from PpmImg
            int red = PpmImg->pixels[i][j].red;
            int green = PpmImg->pixels[i][j].green;
            int blue = PpmImg->pixels[i][j].blue;
            PgmImg->pixels[i][j] = ( red + green + blue) / 3;
        }
    }

    return PgmImg;
}

ImagePGM *shrinkPGM(ImagePGM *PgmImg)
{
    ImagePGM *copyImg = malloc(sizeof(ImagePGM));
    // copy to copyImg
    strcpy(copyImg->magic, PgmImg->magic);

    int diff = 2;

    copyImg->numCols = PgmImg->numCols / diff;
    copyImg->numRows = PgmImg->numRows / diff;
    copyImg->maxVal = PgmImg->maxVal;
    copyImg->pixels = malloc(sizeof(int *) * copyImg->numRows);
    for (int i = 0; i < copyImg->numRows; i++)
    {
        copyImg->pixels[i] = malloc(sizeof(int) * copyImg->numCols);
    }
    for (int i = 0; i < copyImg->numRows; i++)
    {
        for (int j = 0; j < copyImg->numCols; j++)
        {
            // using them directly was causing error so i used them in variables
            int i1 = PgmImg->pixels[2 * i][2 * j];
            int i2 = PgmImg->pixels[2 * i][2 * j + 1];
            int i3 = PgmImg->pixels[2 * i + 1][2 * j];
            int i4 = PgmImg->pixels[2 * i + 1][2 * j + 1];

            copyImg->pixels[i][j] = (i1 + i2 + i3 + i4) / 4;
        }
    }
    return copyImg;
}
