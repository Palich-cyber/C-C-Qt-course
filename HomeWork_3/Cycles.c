#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Value validation function
/* Output:
   1 - if value is a valid;
   0 - if value is an invalid
*/
int isCorrectInputString(char *inputString){

    int correct = 1,
        i = 0;

    while (inputString[i] != '\0'){
        if (!isdigit(inputString[i])) correct = 0;
        i++;
    }

    return correct;
}

// Function of the dialog for setting the number of cycles
/* Output:
   -1    - if the number of cycles is an invalid;
   >= 0  - the number of cycles
*/
int dialogEnterCycleCount(char *dialogString){

    char *inputString[7];
    int   cycleCount;

    printf(dialogString);

    scanf("%s", inputString);
    if (isCorrectInputString(inputString)) cycleCount = atoi(inputString);
    else {
        printf("Incorrect values (Need values from 0 to 9999999). Please retry enter.\n");
        cycleCount = -1;
    }

    return cycleCount;
}

int main(){

    int doWhileCycleCount = -1,
        forCycleCount     = -1,
        whileCycleCount   = -1;

    while (doWhileCycleCount == -1){
        doWhileCycleCount = dialogEnterCycleCount("Enter number of do-while-cycles: ");
    }

    while (forCycleCount == -1){
        forCycleCount = dialogEnterCycleCount("Enter number of for-cycles at each do-while-cycle: ");
    }

    while (whileCycleCount == -1){
        whileCycleCount = dialogEnterCycleCount("Enter number of while-cycles at each for-cycle: ");
    }

    int i = 0;

    do {
        i++;
        printf("do-while-cycle number is %d\n" , i);
        int j = 0;
            while (j < whileCycleCount){
            j++;
            printf("while-cycle number is %d\n" , j);
                for (int k = 0; k < forCycleCount; k++){
                    printf("for-cycle number is %d\n" , k);
                }
           }
    }
    while (i < doWhileCycleCount);


    return 0;
}
