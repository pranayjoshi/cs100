#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "image.h"

ImagePPM *readPPM(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return NULL;

    ImagePPM *pImagePPM = (ImagePPM *)malloc(sizeof(ImagePPM));
    fscanf(fp, "%s", pImagePPM->magic);
    fscanf(fp, "%d", &pImagePPM->width);
    fscanf(fp, "%d", &pImagePPM->height);
    fscanf(fp, "%d", &pImagePPM->max_value);

    pImagePPM->pixels = (Pixel **)malloc(sizeof(Pixel *) * pImagePPM->height);

    for(int i = 0; i < pImagePPM->height ; i++) {
        pImagePPM->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * pImagePPM->width);
    }

    for(int i = 0; i < pImagePPM->height; i++) {
        for(int j = 0; j < pImagePPM->width; j++) {
            fscanf(fp, "%d", &pImagePPM->pixels[i][j].red);
            fscanf(fp, "%d", &pImagePPM->pixels[i][j].green);
            fscanf(fp, "%d", &pImagePPM->pixels[i][j].blue);
        }
    }

    return pImagePPM;  
}

// Write out a ppm image stored in a ImagePPM structure into
// the specified file. Return 1 if writing is successful or
// 0 otherwise.
int writePPM(ImagePPM *pImagePPM, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) return 0;

    fprintf(fp, "%s\n", pImagePPM->magic);
    fprintf(fp, "%d %d\n", pImagePPM->width, pImagePPM->height);
    fprintf(fp, "%d\n", pImagePPM->max_value);

    for(int i = 0; i < pImagePPM->height; i++) {
        for(int j = 0; j < pImagePPM->width; j++) {
            fprintf(fp, "%d ", pImagePPM->pixels[i][j].red);
            fprintf(fp, "%d ", pImagePPM->pixels[i][j].green);
            fprintf(fp, "%d ", pImagePPM->pixels[i][j].blue);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 1;
}

// Rotate a ppm image clockwise by 90 degrees, and return the new ppm image.
ImagePPM *rotatePPM(ImagePPM *pImagePPM) {
    ImagePPM *pImagePPM2 = (ImagePPM *)malloc(sizeof(ImagePPM));
    strcpy(pImagePPM2->magic, pImagePPM->magic);
    pImagePPM2->width = pImagePPM->height;
    pImagePPM2->height = pImagePPM->width;
    pImagePPM2->max_value = pImagePPM->max_value;

    pImagePPM2->pixels = (Pixel **)malloc(sizeof(Pixel *) * pImagePPM2->height);

    for(int i = 0; i < pImagePPM2->height ; i++) {
        pImagePPM2->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * pImagePPM2->width);
    }

    for(int i = 0; i < pImagePPM2->height; i++) {
        for(int j = 0; j < pImagePPM2->width; j++) {
            pImagePPM2->pixels[i][j].red = pImagePPM->pixels[pImagePPM->height - j - 1][i].red;
            pImagePPM2->pixels[i][j].green = pImagePPM->pixels[pImagePPM->height - j - 1][i].green;
            pImagePPM2->pixels[i][j].blue = pImagePPM->pixels[pImagePPM->height - j - 1][i].blue;
        }
    }

    return pImagePPM2;
}

// Flip a ppm image horizontally (from left to right), and return the new ppm image.
ImagePPM *flipPPM(ImagePPM *pImagePPM) {
    ImagePPM *pImagePPM2 = (ImagePPM *)malloc(sizeof(ImagePPM));
    strcpy(pImagePPM2->magic, pImagePPM->magic);
    pImagePPM2->height = pImagePPM->height;
    pImagePPM2->width = pImagePPM->width;
    pImagePPM2->max_value = pImagePPM->max_value;

    pImagePPM2->pixels = (Pixel **)malloc(sizeof(Pixel *) * pImagePPM2->height);

    for(int i = 0; i < pImagePPM2->height ; i++) {
        pImagePPM2->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * pImagePPM2->width);
    }

    for(int i = 0; i < pImagePPM2->height; i++) {
        for (int j = 0; j < pImagePPM2->width; j++) {
            pImagePPM2->pixels[i][j].red = pImagePPM->pixels[i][pImagePPM->width - j - 1].red;
            pImagePPM2->pixels[i][j].green = pImagePPM->pixels[i][pImagePPM->width - j - 1].green;
            pImagePPM2->pixels[i][j].blue = pImagePPM->pixels[i][pImagePPM->width - j - 1].blue;
        }
    }

    return pImagePPM2;
}

// Convert a ppm image to a grayscale image, and return the new grayscale image.
ImagePGM *convertToPGM(ImagePPM *pImagePPM) {
    ImagePGM *pImagePGM = (ImagePGM *)malloc(sizeof(ImagePGM));
    strcpy(pImagePGM->magic, "P2");
    pImagePGM->height = pImagePPM->height;
    pImagePGM->width = pImagePPM->width;
    pImagePGM->max_value = pImagePPM->max_value;

    pImagePGM->pixels = (int **)malloc(sizeof(int *) * pImagePGM->height);

    for(int i = 0; i < pImagePGM->height ; i++) {
        pImagePGM->pixels[i] = (int *)malloc(sizeof(int) * pImagePGM->width);
    }

    for(int i = 0; i < pImagePGM->height; i++) {
        for(int j = 0; j < pImagePGM->width; j++) {
            pImagePGM->pixels[i][j] = (int)round( (double) (pImagePPM->pixels[i][j].red + pImagePPM->pixels[i][j].green + pImagePPM->pixels[i][j].blue) / 3);
        }
    }

    return pImagePGM;
}

// Enlarge a ppm image by doubling its size (both width and height), and return the new ppm image.
// Enlarge a ppm image by doubling its size (both width and height), and return the new ppm image. The intensity of pixel (i, j) 
//in the existing image will be duplicated into 4 pixels located at (2*i, 2*j), (2*i+1, 2*j), (2*i, 2*j+1), (2*i+1, 2*j+1) in the new image.

ImagePPM *enlargePPM(ImagePPM *pImagePPM) {
    ImagePPM *pImagePPM2 = (ImagePPM *)malloc(sizeof(ImagePPM));
    strcpy(pImagePPM2->magic, pImagePPM->magic);
    pImagePPM2->height = pImagePPM->height * 2;
    pImagePPM2->width = pImagePPM->width * 2;
    pImagePPM2->max_value = pImagePPM->max_value;

    pImagePPM2->pixels = (Pixel **)malloc(sizeof(Pixel *) * pImagePPM2->height);

    for(int i = 0; i < pImagePPM2->height ; i++) {
        pImagePPM2->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * pImagePPM2->width);
    }

    for(int i = 0; i < pImagePPM->height; i++) {
        for(int j = 0; j < pImagePPM->width; j++) {
            pImagePPM2->pixels[2 * i][2 * j].red = pImagePPM->pixels[i][j].red;
            pImagePPM2->pixels[2 * i][2 * j].green = pImagePPM->pixels[i][j].green;
            pImagePPM2->pixels[2 * i][2 * j].blue = pImagePPM->pixels[i][j].blue;

            pImagePPM2->pixels[2 * i + 1][2 * j].red = pImagePPM->pixels[i][j].red;
            pImagePPM2->pixels[2 * i + 1][2 * j].green = pImagePPM->pixels[i][j].green;
            pImagePPM2->pixels[2 * i + 1][2 * j].blue = pImagePPM->pixels[i][j].blue;

            pImagePPM2->pixels[2 * i][2 * j + 1].red = pImagePPM->pixels[i][j].red;
            pImagePPM2->pixels[2 * i][2 * j + 1].green = pImagePPM->pixels[i][j].green;
            pImagePPM2->pixels[2 * i][2 * j + 1].blue = pImagePPM->pixels[i][j].blue;

            pImagePPM2->pixels[2 * i + 1][2 * j + 1].red = pImagePPM->pixels[i][j].red;
            pImagePPM2->pixels[2 * i + 1][2 * j + 1].green = pImagePPM->pixels[i][j].green;
            pImagePPM2->pixels[2 * i + 1][2 * j + 1].blue = pImagePPM->pixels[i][j].blue;
        }
    }

    return pImagePPM2;
}

// Shrink a ppm image by reducing its size (both width and height) into the half, and return the new ppm image.
//Shrink a ppm image by reducing its size (both width and height) into the half, and return the new ppm image. 
//If the original height or width is odd, discard the last row or column. 
//The intensity of the new image pixel located at (i, j) will be the average of 4 pixels located at (2*i, 2*j), 
//(2*i+1, 2*j), (2*i, 2*j+1), and (2*i+1, 2*j+1) in the existing image. 
//Please use the round function when converting a double to an integer.
ImagePPM *shrinkPPM(ImagePPM *pImagePPM) {
    ImagePPM *pImagePPM2 = (ImagePPM *)malloc(sizeof(ImagePPM));
    strcpy(pImagePPM2->magic, pImagePPM->magic);
    pImagePPM2->height = (pImagePPM->height) / 2;
    pImagePPM2->width = (pImagePPM->width) / 2;
    pImagePPM2->max_value = pImagePPM->max_value;

    pImagePPM2->pixels = (Pixel **)malloc(sizeof(Pixel *) * pImagePPM2->height);

    for(int i = 0; i < pImagePPM2->height ; i++) {
        pImagePPM2->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * pImagePPM2->width);
    }

    for(int i = 0; i < pImagePPM2->height; i++) {
        for(int j = 0; j < pImagePPM2->width; j++) {
            pImagePPM2->pixels[i][j].red = (int)round( (double) (pImagePPM->pixels[2 * i][2 * j].red + pImagePPM->pixels[2 * i + 1][2 * j].red + pImagePPM->pixels[2 * i][2 * j + 1].red + pImagePPM->pixels[2 * i + 1][2 * j + 1].red) / 4);
            pImagePPM2->pixels[i][j].green = (int)round( (double) (pImagePPM->pixels[2 * i][2 * j].green + pImagePPM->pixels[2 * i + 1][2 * j].green + pImagePPM->pixels[2 * i][2 * j + 1].green + pImagePPM->pixels[2 * i + 1][2 * j + 1].green) / 4);
            pImagePPM2->pixels[i][j].blue =  (int)round( (double) (pImagePPM->pixels[2 * i][2 * j].blue + pImagePPM->pixels[2 * i + 1][2 * j].blue + pImagePPM->pixels[2 * i][2 * j + 1].blue + pImagePPM->pixels[2 * i + 1][2 * j + 1].blue) / 4);
        }
    }

    return pImagePPM2;
}

// Invert each color of a ppm image by subtracting its red/green/blue intensity
// from the maximum-value of the image, and return the new ppm image.
ImagePPM *invertPPM(ImagePPM *pImagePPM) {
    ImagePPM *pImagePPM2 = (ImagePPM *)malloc(sizeof(ImagePPM));
    strcpy(pImagePPM2->magic, pImagePPM->magic);
    pImagePPM2->height = pImagePPM->height;
    pImagePPM2->width = pImagePPM->width;
    pImagePPM2->max_value = pImagePPM->max_value;

    pImagePPM2->pixels = (Pixel **)malloc(sizeof(Pixel *) * pImagePPM2->height);

    for(int i = 0; i < pImagePPM2->height ; i++) {
        pImagePPM2->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * pImagePPM2->width);
    }

    for(int i = 0; i < pImagePPM2->height; i++) {
        for(int j = 0; j < pImagePPM2->width; j++) {
            pImagePPM2->pixels[i][j].red = pImagePPM->max_value - pImagePPM->pixels[i][j].red;
            pImagePPM2->pixels[i][j].green = pImagePPM->max_value - pImagePPM->pixels[i][j].green;
            pImagePPM2->pixels[i][j].blue = pImagePPM->max_value - pImagePPM->pixels[i][j].blue;
        }
    }

    return pImagePPM2;
}

// Crop a ppm image. The crop window is specified by two corners (r1, c1) and (r2, c2), both inclusive.
//The crop window is specified by two corners (r1, c1) and (r2, c2), both inclusive. 
//You can assume (r1, c1) and (r2, c2) are within the ppm image, but (r1, c1) could be any one of the four corners and (r2, c2) is always the opposite corner.
ImagePPM *cropPPM(ImagePPM *pImagePPM, int r1, int c1, int r2, int c2) {
    int croppedHeight = abs(r2 - r1) + 1;
    int croppedWidth = abs(c2 - c1) + 1;

    ImagePPM *pImagePPM2 = (ImagePPM *)malloc(sizeof(ImagePPM));
    strcpy(pImagePPM2->magic, pImagePPM->magic);
    pImagePPM2->height = croppedHeight;
    pImagePPM2->width = croppedWidth;
    pImagePPM2->max_value = pImagePPM->max_value;

    pImagePPM2->pixels = (Pixel **)malloc(sizeof(Pixel *) * croppedHeight);

    for(int i = 0; i < croppedHeight ; i++) {
        pImagePPM2->pixels[i] = (Pixel *)malloc(sizeof(Pixel) * croppedWidth);
    }

    //where to start copying
    int startRow = r1 < r2 ? r1 : r2;
    int startCol = c1 < c2 ? c1 : c2;

    for(int i = 0; i < croppedHeight; i++) {
        for(int j = 0; j < croppedWidth; j++) {
            pImagePPM2->pixels[i][j].red = pImagePPM->pixels[startRow + i][startCol + j].red;
            pImagePPM2->pixels[i][j].green = pImagePPM->pixels[startRow + i][startCol + j].green;
            pImagePPM2->pixels[i][j].blue = pImagePPM->pixels[startRow + i][startCol + j].blue;
        }
    }

    return pImagePPM2;
}

//free the space used by a ppm image.
void freeSpacePPM(ImagePPM *pImagePPM) {
    for(int i = 0; i < pImagePPM->height; i++) {
        free(pImagePPM->pixels[i]);
    }
    free(pImagePPM->pixels);
    free(pImagePPM);
}