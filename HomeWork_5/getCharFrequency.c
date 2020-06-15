#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_COUNT   10000
#define FILE_NAME_LENGHT 20

int isCorrectInputString(const char *inputString, int maxValue);
int dialogEnterCharCount(const char *dialogString);
char *dialogEnterFileName(const char *dialogString);
char *readFile(const char *fileName, int charCount);
int mainDialog();

int main (){

    printf("This programm calculates the frequency of repetition of characters in a given file.\n"
           "Please enter number of characters and file name.\n");

    while(mainDialog() == 1);

    return 0;
}

// Value validation function
/* Input:
   inputString - string for validtion
   maxValue    - maximum char count in  an input string
   Output:
   >0  - value of inputString;
   -1  - if an input string value is an invalid
*/
int isCorrectInputString(const char *inputString, int maxValue){

    int correct = 1,
        i       = 0,
        value   = 0;

    while (inputString[i] != '\0'){
        if (!isdigit(inputString[i])) correct = 0;
        i++;
    }

    if (correct){
        value = atoi(inputString);
        if (value > maxValue) value = -1;
    }

    return value;
}

// Function of the dialog for setting limit of chars reading from file
/* Output:
   -1    - if limit of chars reading from file more then defined MAX_CHAR_COUNT;
   >= 0  - if limit of chars reading from file less then defined MAX_CHAR_COUNT.
*/
int dialogEnterCharCount(const char *dialogString){

    char inputString[10];
    int  charCount;

    printf(dialogString);

    scanf("%s", inputString);
    charCount = isCorrectInputString(inputString, MAX_CHAR_COUNT);
    if (charCount == -1){
        printf("Invalid values (Need values from 0 to %d). Please try again enter.\n", MAX_CHAR_COUNT);
    }

    return charCount;
}

// Function of the dialog for setting a file name
/* Output:
   0     - if file name is an invalid. Lenght of file name more then defined FILE_NAME_LENGHT;
   > 0   - if file name is a valid.
*/
char *dialogEnterFileName(const char *dialogString){

    char *fileName;
    fileName = (char *)malloc(FILE_NAME_LENGHT*sizeof(char));
    int i = 0;

    printf(dialogString);
    scanf("%s", fileName);

    while (fileName[i] != '\0') i++;

    if (i >= FILE_NAME_LENGHT - 1){
        fileName = NULL;
        printf("Invalid file name. File name must be no more than %d characters.\n"
               "Please try again enter.\n", FILE_NAME_LENGHT);
    }

    return fileName;
}

// Reading from file function
/* Output:
   0     - if file not read;
   > 0   - if file read.
*/
char *readFile(const char *fileName, int charCount){

    char *tmp;
    tmp = (char *)malloc(charCount*sizeof(char));

    if (fileName){
        int i = 0;
        FILE *filePointer;

        filePointer = fopen(fileName, "r");
        if (!filePointer) {
            fprintf (stderr, "Unable to open the file '%s'\n", fileName);
            tmp = NULL;
        }
        else{
            memset(tmp, 0, charCount);

            while (i < charCount-1){
                fscanf (filePointer, "%c", &tmp[i]);
                i++;
            }

            fclose(filePointer);
        }
    }
    else tmp = NULL;

    return tmp;
}

int mainDialog(){

    char *fileName = NULL,
         *stringFromFile  = NULL;
    char ascii[256];
    int  frequencyTable[256];
    char repeat;
    int  repeatCorrect,
         value = -1;

    while (value == -1) value = dialogEnterCharCount("Number of characters: "); 

    do{
        while (!fileName) fileName = dialogEnterFileName("File name: ");
        stringFromFile = readFile(fileName, value);
    }
    while (!stringFromFile);

    for (int i = 0; i < 256; i++){
        ascii[i] = (char) i;
        frequencyTable[i] = 0;
    }

    for (int i = 0; i < value; i++){
        for (int j = 0; j < 256; j++){
            if (stringFromFile[i] == ascii[j]){
                frequencyTable[j]++;
                break;
            }
            else continue;
        }
    }

    printf ("\n\n\t\tNum in ASCII:\tChar:\tChar frequency:\n");
    for (int i = 0; i < 256; i++)
        if (frequencyTable[i]) printf ("\t\t#%d\t%c\t%d\n", i, ascii[i], frequencyTable[i]);

    // Do you want to repeat?
    printf ("/n/nDo you want to repeat?\n"
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
