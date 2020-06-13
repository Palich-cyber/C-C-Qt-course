#include <stdio.h>
#include <conio.h>

int main(){

    int number;

    printf("Press any number on the keyboard.\n"
           "The program will display the first letter of the entered number.\n");

    number = getch();
    while(number!=27){

    switch (number) {
        //number 1
        case 49:
            printf("The first letter of number 1 is 'O'.\n");
            break;
        case 79:
            printf("The first letter of number 1 is 'O'.\n");
            break;
        //number 2
        case 50:
            printf("The first letter of number 2 is 'T'.\n");
            break;
        //number 3
        case 51:
            printf("The first letter of number 3 is 'T'.\n");
            break;
        //number 4
        case 52:
            printf("The first letter of number 4 is 'F'.\n");
            break;
        //number 5
        case 53:
            printf("The first letter of number 5 is 'F'.\n");
            break;
        //number 6
        case 54:
            printf("The first letter of number 6 is 'S'.\n");
            break;
        //number 7
        case 55:
            printf("The first letter of number 7 is 'S'.\n");
            break;
        //number 8
        case 56:
            printf("The first letter of number 8 is 'E'.\n");
            break;
        //number 9
        case 57:
            printf("The first letter of number 9 is 'N'.\n");
            break;
        //number 0
        case 48:
            printf("The first letter of number 0 is 'Z'.\n");
            break;
        default:
            break;
       };
    number = getch();
    }

    printf("Program operation completed successfully.");

    return 0;
}
