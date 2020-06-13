#include <stdio.h>
#include <float.h>

// Function of overflow double type
int OverflowChar(){

    double a = DBL_MAX;
    printf ("--------- BEFORE Overflow ---------\n");
    printf ("Number value: %e\n", a);

    a*=10;
    printf ("--------- AFTER Overflow ---------\n");
    printf ("Number value: %e\n", a);

    return 0;
}

// Function of underflow double type
int UnderflowChar(){

    double a = -DBL_MAX;
    printf ("--------- BEFORE Underflow ---------\n");
    printf ("Number value: %e\n", a);

    a*=10;
    printf ("--------- AFTER Underflow ---------\n");
    printf ("Number value: %e\n", a);

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

    printf ("Press 1 if you want to use Overflow of double type.\n"
            "Press 2 if you want to use Underflow of double type.\n");
    scanf("%d", &answer);

    while(answerCorrect == 0){
        if (answer == 1){
            printf ("You chooced to use Overflow of double type.\n");
            OverflowChar();
            answerCorrect = 1;
        } else if (answer == 2){
            printf ("You chooced to use Underflow of double type.\n");
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
