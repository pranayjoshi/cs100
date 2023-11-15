#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Usage: %s copy-ppm input.ppm output.ppm\n", argv[0]);
		printf("       %s copy-pgm input.pgm output.pgm\n", argv[0]);
		printf("       %s grayscale input.ppm output.pgm\n", argv[0]);
		printf("       %s shrink input.pgm output.pgm\n", argv[0]);
		return 1;
	}

	char *command = argv[1];
	char *inputFilename = argv[2];
	char *outputFilename = argv[3];

	if (strcmp(command, "copy-ppm") == 0)
	{
		ImagePPM *pImagePPM = readPPM(inputFilename);
		if (pImagePPM == NULL)
		{
			printf("Unable to read the PPM file: %s\n", inputFilename);
			return 2;
		}
		int success = writePPM(pImagePPM, outputFilename);
		if (!success)
		{
			printf("Unable to write to the file: %s\n", outputFilename);
			freePPM(pImagePPM);
			return 3;
		}
		freePPM(pImagePPM);
	}
	else if (strcmp(command, "copy-pgm") == 0)
	{
		ImagePGM *pImagePGM = readPGM(inputFilename);
		if (pImagePGM == NULL)
		{
			printf("Unable to read the PGM file: %s\n", inputFilename);
			return 4;
		}
		int success = writePGM(pImagePGM, outputFilename);
		if (!success)
		{
			printf("Unable to write to the file: %s\n", outputFilename);
			freePGM(pImagePGM);
			return 5;
		}
		freePGM(pImagePGM);
	}
	else if (strcmp(command, "grayscale") == 0)
	{
		ImagePPM *pImagePPM = readPPM(inputFilename);
		if (pImagePPM == NULL)
		{
			printf("Unable to read the PPM file: %s\n", inputFilename);
			return 6;
		}
		ImagePGM *pImagePGM = convertToPGM(pImagePPM);
		int success = writePGM(pImagePGM, outputFilename);
		if (!success)
		{
			printf("Unable to write to the file: %s\n", outputFilename);
			freePPM(pImagePPM);
			freePGM(pImagePGM);
			return 7;
		}
		freePPM(pImagePPM);
		freePGM(pImagePGM);
	}
	else if (strcmp(command, "shrink") == 0)
	{
		ImagePGM *pOrig = readPGM(inputFilename);
		if (pOrig == NULL)
		{
			printf("Unable to read the PGM file: %s\n", inputFilename);
			return 8;
		}
		ImagePGM *pShrink = shrinkPGM(pOrig);
		int success = writePGM(pShrink, outputFilename);
		if (!success)
		{
			printf("Unable to write to the file: %s\n", outputFilename);
			freePGM(pOrig);
			freePGM(pShrink);
			return 9;
		}
		freePGM(pOrig);
		freePGM(pShrink);
	}
	else
	{
	   printf("Unrecognized command\n");
	   return 10;
	}

	return 0;
}
