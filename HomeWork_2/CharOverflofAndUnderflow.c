#include <stdio.h>

// Function of overflow symbol
int OverflowChar(){

    char a = 127;
    printf ("--------- BEFORE Overflow ---------\n");
    printf ("Number value 'a' = %d\n", a);
    printf ("Char value 'a' = %c\n\n", a);

    a++;
    printf ("--------- AFTER Overflow ---------\n");
    printf ("Number value 'a' = %d\n", a);
    printf ("Char value 'a' = %c\n\n", a);

    return 0;
}

// Function of underflow symbol
int UnderflowChar(){

    char a = -128;
    printf ("--------- BEFORE Underflow ---------\n");
    printf ("Number value 'a' = %d\n", a);
    printf ("Char value 'a' = %c\n\n", a);

    a--;
    printf ("--------- AFTER Underflow ---------\n");
    printf ("Number value 'a' = %d\n", a);
    printf ("Char value 'a' = %c\n\n", a);

    return 0;
}

// Function of a main dialog
/* Output:
   1 - if need to repeat a dialog;
   0 - if need to close a dialog
*/
int MainDialog(){

    int  answer;
    int  answerCorrect = 0;
    char repeat = ' ';
    int  repeatCorrect = 0;
    int  value;

    printf ("Press 1 if you want to use Overflow of symbol 'a'.\n"
            "Press 2 if you want to use Underflow of symbol 'a'.\n");
    scanf("%d", &answer);

    while(answerCorrect == 0){
        if (answer == 1){
            printf ("You chooced to use Overflow of symbol 'a'.\n");
            OverflowChar();
            answerCorrect = 1;
        } else if (answer == 2){
            printf ("You chooced to use Underflow of symbol 'a'.\n");
            UnderflowChar();
            answerCorrect = 1;
        } else{
            printf ("Press 1 or 2.\n");
            scanf("%d", &answer);
        }
    }

    printf ("Do you want to repeat?\n"
            "Press Y or N.\n");

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

int main(){

    while(MainDialog() == 1);

    return 0;
}
