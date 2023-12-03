 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//You will write these two functions at the bottom of this file
void  mergeLists(char * listA[], int sizeA, char* listB[], int sizeB, char * resultBuffer[]);
void mergeSort(char * inPlace[], int listSize);

//this function is useful for reading the input file.
char * mallocStringCopy(char * string){
    char * mem = malloc(strlen(string)+1);
    strcpy(mem, string);
    return mem;
}
//helper function for io errors
void errorinfo(char * msg, char * info){
    if (info)
    printf("ERROR: %s: %s\n",msg, info);
    exit(1);
}
/*
 Open a FILE given by argv[1]
 Sort the words in that file
 Write the words to file given by argv[2]
 */
int main(int argc, char **argv){
    FILE *fin, *fout;
    fin = fopen(argv[1],"r");
    fout = fopen(argv[2],"w");
    if (fin); else errorinfo("fopen failed", argv[1]);
    if (fout); else errorinfo("fopen failed", argv[2]);
    //more than long enough to handle expected input,
    //not long enough to be wasteful
    char inputbuffer[64];
    char* wordList[3200];
    int wordCount = 0;
    //read into a fixed buffer
    //words are not expected to be too long
    while (1==fscanf(fin,"%63s", inputbuffer)){
        //malloc and copy string
        wordList[wordCount++] = mallocStringCopy(inputbuffer);
    }
    //sort the words
    mergeSort(wordList, wordCount);
    //copy words to output
    //adding line breaks to prevent lines exceeding 80 chars
    int lineLength = 0;
    for (int i = 0; i < wordCount; i++){
        int len = strlen(wordList[i]);
        if (lineLength + len >= 80){
            fprintf(fout, "\n");//line break before 80 chars
            lineLength = 0;
        }
        if (lineLength > 0)
            fprintf(fout, " ");//after first word of line, space between words
        lineLength += len+1;//+1 for the space that may follow
        fprintf(fout,"%s",wordList[i]);//no extra space at end of line/file
    }
    fprintf(fout,"\n");
    fclose(fout);
    fclose(fin);
    return 0;
}


//TODO: fill in the blanks below:

//merge two sorted list into a sorted resultBuffer
void  mergeLists(char * listA[], int sizeA, char* listB[], int sizeB, char * resultBuffer[]){
    //TODO:
    //copy listA and listB into resultBuffer
    //result buffer has been allocated
    for (int i = 0; i < sizeA; i++){
        resultBuffer[i] = listA[i];
    }
    for (int i = 0; i < sizeB; i++){
        resultBuffer[i + sizeA] = listB[i];
    }
}

//mergeSort
//call mergeSort on each half of array
//then merge the results
void mergeSort(char * inPlace[], int listSize){
    if (listSize < 2) return;//if 0 or 1 element then it is already "sorted"
    //malloc a buffer to store the results of the merge
    char ** resultBuffer = malloc(listSize * sizeof(char *));
    
    //TODO:
    //call mergesort with first half of list, second half of list
    //mergeSort(...);
    mergeSort(inPlace, listSize/2);
    mergeSort(inPlace + listSize/2, listSize - listSize/2);
    
    //TODO:
    //call mergesort with second half of list
    //mergeSort(...);
    mergeSort(inPlace + listSize/2, listSize - listSize/2);


    
    //TODO:
    //merge the first half and the second half into the buffer
    //mergeLists(...);
    mergeLists(inPlace, listSize/2, inPlace + listSize/2, listSize - listSize/2, resultBuffer);

    
    //copy the buffer back into the array
    for (int i = 0; i < listSize; i++){
        inPlace[i] = resultBuffer[i];
    }
    //free the buffer
    free (resultBuffer);
}
