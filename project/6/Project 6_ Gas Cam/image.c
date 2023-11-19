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
    fscanf(inp, "%d\n", &img->maxVal);
    img->pixels = (Pixel **)malloc(sizeof(Pixel) * img->numRows);
    for(int i = 0; i < img->numRows ; i++) {
        img->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * img->numCols);
    }
    
    for (int i = 0; i < img->numRows; i++)
    {
        // printf("here3\n");
        for (int j = 0; j < img->numCols; j++)
        {
            // printf("here4\n");
            fscanf(inp, "%d", &img->pixels[i][j].red);
            fscanf(inp, "%d", &img->pixels[i][j].green);
            fscanf(inp, "%d", &img->pixels[i][j].blue);
        }
    }
    // printf("hwadere\n");
    return img;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{
    FILE *inp = fopen(filename, "w");
    // printf("hwadere\n");
    if (inp == NULL)
    {
        return 0;
    }
    fprintf(inp, "P3\n");
    fprintf(inp, "%d %d\n", pImagePPM->numCols, pImagePPM->numRows);
    fprintf(inp, "%d\n", pImagePPM->maxVal);
    for (int i = 0; i < pImagePPM->numRows; i++)
    {
        for (int j = 0; j < pImagePPM->numCols; j++)
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
    fscanf(inp, "%d\n", &img->maxVal);
    img->pixels = malloc(sizeof(Pixel) * img->numCols * img->numRows);
    for (int i = 0; i < img->numCols * img->numRows; i++)
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
    fprintf(inp, "%d\n", pImagePGM->maxVal);
    for (int i = 0; i < pImagePGM->numCols * pImagePGM->numRows; i++)
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

ImagePGM *convertToPGM(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM = malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic, "P2");
    pImagePGM->numRows = pImagePPM->numRows;
    pImagePGM->numCols = pImagePPM->numCols;
    pImagePGM->maxVal = pImagePPM->maxVal;

    pImagePGM->pixels = malloc(sizeof(Pixel) * pImagePGM->numCols * pImagePGM->numRows);
    int s = 0;
    for(int i = 0; i < pImagePGM->numRows; i++) {
        for(int j = 0; j < pImagePGM->numCols; j++) {
            pImagePGM->pixels[s] = (pImagePPM->pixels[i][j].red + pImagePPM->pixels[i][j].green + pImagePPM->pixels[i][j].blue) / 3;
            s++;
        }
    }

    return pImagePGM;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    ImagePGM *img = malloc(sizeof(ImagePGM));
    strcpy(img->magic, pImagePGM->magic);
    img->numCols = pImagePGM->numCols / 2;
    img->numRows = pImagePGM->numRows / 2;
    img->maxVal = pImagePGM->maxVal;
    img->pixels = malloc(sizeof(Pixel) * img->numCols * img->numRows);
    for (int i = 0; i < (img->numRows* img->numCols); i++)
        {
            img->pixels[i] = (pImagePGM->pixels[i*2] + pImagePGM->pixels[i*2+1] + pImagePGM->pixels[i*2+pImagePGM->numCols] + pImagePGM->pixels[i*2+pImagePGM->numCols+1])/4;
        }
    return img;
}
