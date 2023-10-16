#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <float.h>

char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}

int getCount(char csvfile[], int testc, char *testv[]) {
    FILE *fp = fopen(csvfile, "r");
    char line[300];
    int count = 0;
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL) {
        int pass = 1;
        int colIndex = 0;
        char *token, *lineptr;

        lineptr = line;
        while ((token = strsep(&lineptr, ",")) != NULL) {
            if (colIndex < testc * 3 && strcmp(token, testv[colIndex]) != 0) {
                pass = 0;
                break;
            }

            colIndex++;
        }
        if (pass) {
            count++;
        }
    }

    fclose(fp);
    return count;
}

void printAddr(char csvfile[], int testc, char *testv[]) {
    char * data[1000][12];
    char line[300];
    int j = 0;
    FILE *fp = fopen(csvfile,"r");
    while(!feof(fp)){
        j++;
        fgets(line,sizeof(line),fp);
        char temp[strlen(line)+1];
        strcpy(temp, line);
        int i=0;
        char *start=temp;
        while (1) {
            char *token = strsep(&start, ",");
            if (token==NULL) break; // no more
            data[j][i] = token;
            i++; 
            // printf("%d: token=%s\n", i, token);
        }
        for (int i = 0; i < 12; i++) {
            printf("%s ", data[j][i]);
        }
        printf("\n");
    }

    for(int i=0;i<12;i++){
        if(strcmp(data[1][i],testv[1])){
            
        }
    }
}

int main(){
    // FILE *fp=fopen("Sacramentorealestatetransactions.csv", "r");
    printAddr("Sacramentorealestatetransactions.csv", 3, {""});
}