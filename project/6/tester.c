#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened



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

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

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

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM)
{
    free(pImagePPM->pixels);
    free(pImagePPM);
    return;
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename)
{
    FILE *inp = fopen(filename, "r");
    if (inp == NULL)
    {
        return NULL;
    }
}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename)
{
    FILE *inp = fopen(filename, "w");
    if (inp == NULL)
    {
        return 0;
    }
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM)
{
    free(pImagePGM->pixels);
    free(pImagePGM);
    return;
}

ImagePGM *convertToPGM(ImagePPM *pImagePPM)
{
    return NULL;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    return NULL;
}
