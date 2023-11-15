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
    fscanf(inp, "%d %d\n", &img->width, &img->height);
    img->pixels = malloc(sizeof(Pixel) * img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++)
    {
        fscanf(inp, "%d %d %d", &img->pixels[i].red, &img->pixels[i].green, &img->pixels[i].blue);
    }
    fclose(inp);
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
    fprintf(inp, "%d %d\n", pImagePPM->width, pImagePPM->height);
    for (int i = 0; i < pImagePPM->width * pImagePPM->height; i++)
    {
        fprintf(inp, "%d %d %d\n", pImagePPM->pixels[i].red, pImagePPM->pixels[i].green, pImagePPM->pixels[i].blue);
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
    fscanf(inp, "%d %d\n", &img->width, &img->height);
    img->pixels = malloc(sizeof(int) * img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++)
    {
        fscanf(inp, "%d", &img->pixels[i]);
    }
    fclose(inp);
    return img;
}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename)
{
    return 0;
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM)
{
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
