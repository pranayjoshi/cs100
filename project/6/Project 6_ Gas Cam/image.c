#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename)
{
    FILE *inp = fopen(filename, "r");
    if (inp == NULL)
    {
        return NULL;
    }
    ImagePPM *img = malloc(sizeof(ImagePPM));
    fscanf(inp, "P3\n");
    fscanf(inp, "%d %d\n", &img->numCols, &img->numRows);
    img->pixels = malloc(sizeof(Pixel) * img->numCols * img->numRows);
    for (int i = 0; i <= img->numCols; i++)
    {
        for (int j = 0; j <= img->numRows; j++)
        {
            fscanf(inp, "%d %d %d", &img->pixels[i][j].red, &img->pixels[i][j].green, &img->pixels[i][j].blue);
        }
    }
    return img;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{
    FILE *inp = fopen(filename, "w");
    if (inp == NULL)
    {
        return 0;
    }
    fprintf(inp, "P3\n");
    fprintf(inp, "%d %d\n", pImagePPM->numCols, pImagePPM->numRows);
    for (int i = 0; i <= pImagePPM->numCols; i++)
    {
        for (int j = 0; j <= pImagePPM->numRows; j++)
        {
            fprintf(inp, "%d %d %d\n", pImagePPM->pixels[i][j].red, pImagePPM->pixels[i][j].green, pImagePPM->pixels[i][j].blue);
        }
    }
    fclose(inp);
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
    ImagePGM *img = malloc(sizeof(ImagePGM));
    fscanf(inp, "P2\n");
    fscanf(inp, "%d %d\n", &img->numCols, &img->numRows);
    img->pixels = malloc(sizeof(Pixel) * img->numCols * img->numRows);
    for (int i = 0; i <= img->numCols * img->numRows; i++)
    {
        fscanf(inp, "%d", &img->pixels[i]);
    }
    return img;
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
    fprintf(inp, "P2\n");
    fprintf(inp, "%d %d\n", pImagePGM->numCols, pImagePGM->numRows);
    for (int i = 0; i <= pImagePGM->numCols * pImagePGM->numRows; i++)
    {
        fprintf(inp, "%d\n", pImagePGM->pixels[i]);
    }
    fclose(inp);
    return 1;
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
    ImagePGM *img = malloc(sizeof(ImagePGM));
    img->numCols = pImagePPM->numCols;
    img->numRows = pImagePPM->numRows;
    img->pixels = malloc(sizeof(int) * img->numCols * img->numRows);
    for (int i = 0; i < (img->numCols); i++)
    {
        for (int j = 0; j < (img->numRows); j++)
        {
            img->pixels[i][j] = (pImagePPM->pixels[i][j].red + pImagePPM->pixels[i][j].green + pImagePPM->pixels[i][j].blue) / 3;
        }
    }
    return img;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    ImagePGM *img = malloc(sizeof(ImagePGM));
    img->numCols = pImagePGM->numCols / 2;
    img->numRows = pImagePGM->numRows / 2;
    img->pixels = malloc(sizeof(int) * img->numCols * img->numRows);
    for (int i = 0; i < (img->numCols); i++)
    {
        for (int j = 0; j < (img->numRows); j++)
        {
            int xc = pImagePGM->pixels[i * 2][j * 2];
            int xs = pImagePGM->pixels[i * 2][j * 2 + 1];
            int xt = pImagePGM->pixels[i * 2 + 1][j * 2];
            int xw = pImagePGM->pixels[i * 2 + 1][j * 2 + 1];
            img->pixels[i][j] = (xt + xw + xc + xs) / 4;
        }
    }
    return img;
}
