#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Value validation function
/* Output:
   1 - if value is a valid;
   0 - if value is an invalid
*/
int isCorrectInputString(const char *inputString){

    int correct = 1,
        i       = 0;

    while (inputString[i] != '\0'){
        if (!isdigit(inputString[i])) correct = 0;
        i++;
    }

    return correct;
}

// Function of the dialog for setting the value of birthday
/* Output:
   -1    - if the value of birthday is an invalid;
   >= 0  - the value of birthday
*/
int dialogEnterBirthday(const char *dialogString){

    char  inputString[4];
    int   birthdayValue;

    printf(dialogString);

    scanf("%s", inputString);
    if (isCorrectInputString(inputString)) birthdayValue = atoi(inputString);
    else {
        printf("Invalid values. Please try again enter.\n");
        birthdayValue = -1;
    }

    return birthdayValue;
}

// Recursive function of summ all elements in massive
/* Input:
   massivePointer - pointer to massive for summ all elements
   massiveSize    - size of massive
   Output:
   result of summ all elements in massive
*/
int recursiveSumm(const int *massivePointer, size_t massiveSize){

    return (massiveSize) ? *massivePointer + recursiveSumm(massivePointer+1, massiveSize-1) : 0;
}

// Function of main dialog
int mainDialog(){

    char repeat;
    int  repeatCorrect   = 0,
         value;
    int  birthday[3]     = {-1, -1, -1};                                     // day, month, year.
    int  dayCalendar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // day number according a calendar
                                                                             // if leap year is false.

    printf ("Please enter the date of your birthday.\n");

    // YEAR:
    while (birthday[2] == -1){
        birthday[2] = dialogEnterBirthday("Year:\t");
        if (birthday[2] > 9999){
            printf ("Invalid year number. Valid year number from 0 to 9999.\n"
                    "Please try again enter.\n");
            birthday[2] = -1;
        }
    }
    if (birthday[2]%4 == 0) dayCalendar[1] = 29; // if leap year is true

    // MONTH:
    while (birthday[1] == -1){
        birthday[1] = dialogEnterBirthday("Month:\t");
        if (birthday[1] > 12 || birthday[1] == 0){
            printf ("Invalid month number. Valid month number from 01 to 12.\n"
                    "Please try again enter.\n");
            birthday[1] = -1;
        }
    }

    // DAY:
    while (birthday[0] == -1){
        birthday[0] = dialogEnterBirthday("Day:\t");
        if (birthday[0] > dayCalendar[birthday[1]-1] || birthday[0] == 0){
            printf ("Invalid day number. Valid day number according a calendar.\n"
                    "Please try again enter.\n");
            birthday[0] = -1;
        }
    }

    // Calculate summ all massive elements
    int summ = recursiveSumm(birthday, 3);
    printf ("Summary of the numbers your birthday %d.%d.%d is: %d\n\n", birthday[0], birthday[1], birthday[2], summ);

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

int main (){

    while(mainDialog() == 1);

    return 0;
}
