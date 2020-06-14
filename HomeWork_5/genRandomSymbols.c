#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_CHAR_COUNT 1000

int setSeed();
int generateRandomChars(int maxCharCount);
int isCorrectInputString(const char *inputString, int minValue, int maxValue);
int dialogEnterCharCount(const char *dialogString);
int mainDialog();

int main (){

    printf("The program displays a thousand random character values to the console.\n");

    while(mainDialog() == 1);

    return 0;
}

// Function for seed start point for a generation random values
int setSeed(){

    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);
    srand (spec.tv_nsec);

    return 0;
}

// Function for generatio of random symbols according ASCII without digits (48-57)
int generateRandomChars(int maxCharCount){

    int tmp[maxCharCount];
    setSeed();

    for (int i = 0; i < maxCharCount; i++){
        tmp[i] = rand()%256;
        while (tmp[i] > 47 && tmp[i] < 58) tmp[i] = rand()%256; // Symbol from ASCII without digits (48-57)

        printf("Massive element num:\t%d\tSymbol:\t%c\tNum in ASCII:\t%d\n", i, tmp[i], tmp[i]);
    }

    return 0;
}

// Value validation function
/* Input:
   inputString - string for validtion
   minValue    - minimum value for a generation random values
   maxValue    - maximum value for a generation random values
   Output:
   >0  - value of inputString;
   -1  - if inputString value is an invalid
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
        if (value < minValue || value > maxValue) value = -1;
    }

    return value;
}

// Function of the dialog for setting the number of cycles
/* Output:
   -1    - if the number of cycles is an invalid;
   >= 0  - the number of cycles
*/
int dialogEnterCharCount(const char *dialogString){

    char inputString[10];
    int  charCount;

    printf(dialogString);

    scanf("%s", inputString);
    charCount = isCorrectInputString(inputString, 0, MAX_CHAR_COUNT);
    if (charCount == -1){
        printf("Invalid values (Need values from 0 to %d). Please try again enter.\n", MAX_CHAR_COUNT);
    }

    return charCount;
}

// Function of main dialog
int mainDialog(){

    char repeat;
    int  repeatCorrect,
         value = -1;

    printf ("How many many values do you want to print?\n"
            "Valid range: from 0 to %d\n", MAX_CHAR_COUNT);

    while (value == -1) value = dialogEnterCharCount("Values count: ");

    generateRandomChars(value);

    // Do you want to repeat?
    printf ("Do you want to repeat?\n"
            "Press Y or N.\n");
    repeatCorrect = 0;
    repeat = ' ';

    while(repeatCorrect == 0){
        if (repeat == 'Y'){
            repeatCorrect = 1;
            value = 1;
        } else if (repeat == 'N'){
            repeatCorrect = 1;
            value = 0;
        } else{
            scanf("%c", &repeat);
        }
    }

    return value;
}
