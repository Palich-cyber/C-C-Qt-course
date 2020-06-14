#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define FILE_COUNT 10
#define RANDOM_COUNT 1000

// Function for seed start point for a generation random values
int setSeed(){

    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    srand (spec.tv_nsec);

    return 0;
}

// Value validation function
/* Input:
   inputString - string for validtion
   minValue    - minimum value for a generation random values
   maxValue    - maximum value for a generation random values
   Output:
   >0 - value of inputString;
   0  - if inputString value is an invalid
*/
int isCorrectInputString(const char *inputString, int minValue, int maxValue){

    int correct = 1,
        i       = 0,
        value   = 0;

    while (inputString[i] != '\0'){
        if (!isdigit(inputString[i])) correct = 0;
        i++;
    }

    if (correct){
        value = atoi(inputString);
        if (value < minValue || value >= maxValue) value = 0;
    }

    return value;
}

// Function of the dialog for setting the maximum value for a generation random values
/* Output:
   0     - if the maximum value for a generation random values is an invalid;
   >= 0  - the maximum value for a generation random values
*/
int dialogEnterMaxRandom(const char *dialogString){

    char  inputString[4];
    int   maxRandom;

    printf(dialogString);

    scanf("%s", inputString);
    maxRandom = isCorrectInputString(inputString, 2, 10000);
    if (!maxRandom){
        printf("Invalid values. Please try again enter.\n"
               "Valid range: from 2 to 9999.\n");
    }

    return maxRandom;
}

// Function of creation a file
int creatFile (int maxRandomValue){

    char fileName[10];
    FILE *filePointer;
    static int fileCurrentNum = 0;

    sprintf (fileName, "file%d", fileCurrentNum);
    filePointer = fopen (fileName, "w+");

    setSeed();

    fprintf (filePointer, "Number:\t\tValue:\n\n");
    for (int i = 1; i <= RANDOM_COUNT; i++) {
        fprintf (filePointer, "%d:\t\t\t%d\n", i, rand()%maxRandomValue);
    }

    fclose (filePointer);
    printf	("%s was created\n", fileName);

    fileCurrentNum++;

    return 0;
}

int main (){

    int maxRandom = 0;
    printf ("This program to create 1000 random values for each file within 10 files.\n"
            "Please, enter the maximum value for generation of random values.\n"
            "Valid range: from 2 to 9999.\n");
    while(!maxRandom) maxRandom = dialogEnterMaxRandom("MAX random value: ");

    for (int i = 0; i < FILE_COUNT; i++){
        creatFile (maxRandom);
    }

    return 0;
}
