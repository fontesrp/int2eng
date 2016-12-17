#include <stdio.h>
#include "str_util.h"

#define MAX_NUMBER_DIGITS 66
#define MAX_NAME_SIZE 975
#define ONES_NAME_SIZE 6
#define TENS_NAME_SIZE 14
#define HUNDREDS_NAME_SIZE 32
#define TRIO_NAME_SIZE 51

/*
 * The biggest number it's possible to write:
 * seven hundred and seventy-seven vigintillion,
 * seven hundred and seventy-seven novemdecillion,
 * seven hundred and seventy-seven octodecillion,
 * seven hundred and seventy-seven septendecillion,
 * seven hundred and seventy-seven sexdecillion,
 * seven hundred and seventy-seven quindecillion,
 * seven hundred and seventy-seven quattuordecillion,
 * seven hundred and seventy-seven tredecillion,
 * seven hundred and seventy-seven duodecillion,
 * seven hundred and seventy-seven undecillion,
 * seven hundred and seventy-seven decillion,
 * seven hundred and seventy-seven nonillion,
 * seven hundred and seventy-seven octillion,
 * seven hundred and seventy-seven septillion,
 * seven hundred and seventy-seven sextillion,
 * seven hundred and seventy-seven quintillion,
 * seven hundred and seventy-seven quadrillion,
 * seven hundred and seventy-seven trillion,
 * seven hundred and seventy-seven billion,
 * seven hundred and seventy-seven million,
 * seven hundred and seventy-seven thousand
 * seven hundred and seventy-seven
*/

char * nameOnes(char ones) {
    switch (ones) {
    case '1':
        return "one";
    case '2':
        return "two";
    case '3':
        return "three";
    case '4':
        return "four";
    case '5':
        return "five";
    case '6':
        return "six";
    case '7':
        return "seven";
    case '8':
        return "eight";
    case '9':
        return "nine";
    default:
        return "";
    }
}

void nameTeens(char * tensName, char ones) {
    char teenPrefix[ONES_NAME_SIZE], teenSufix[5] = "teen";
    switch (ones) {
    case '0':
        cloneStr("ten", TENS_NAME_SIZE, tensName);
        return;
    case '1':
        cloneStr("eleven", TENS_NAME_SIZE, tensName);
        return;
    case '2':
        cloneStr("twelve", TENS_NAME_SIZE, tensName);
        return;
    case '3':
        cloneStr("thir", 5, teenPrefix);
        break;
    case '5':
        cloneStr("fif", 4, teenPrefix);
        break;
    case '8':
        cloneStr("eigh", 5, teenPrefix);
        break;
    default:
        cloneStr(nameOnes(ones), ONES_NAME_SIZE, teenPrefix);
        break;
    }
    strMerge(teenPrefix, ONES_NAME_SIZE, teenSufix, 5, tensName, TENS_NAME_SIZE);
}

void nameTens(char * tensName, char tens, char ones) {

    char onesName[ONES_NAME_SIZE], tensPrefix[ONES_NAME_SIZE], tensSufix[4] = "ty";

    cloneStr(nameOnes(ones), ONES_NAME_SIZE, onesName);

    switch (tens) {
    case '0':
        cloneStr(onesName, ONES_NAME_SIZE, tensName);
        return;
    case '1':
        nameTeens(tensName, ones);
        return;
    case '2':
        cloneStr("twen", 5, tensPrefix);
        break;
    case '3':
        cloneStr("thir", 5, tensPrefix);
        break;
    case '5':
        cloneStr("fif", 4, tensPrefix);
        break;
    case '8':
        cloneStr("eigh", 5, tensPrefix);
        break;
    default:
        cloneStr(nameOnes(tens), ONES_NAME_SIZE, tensPrefix);
        break;
    }

    if (strLen(onesName, ONES_NAME_SIZE) > 0) {
        strMerge(tensSufix, 4, "-", 2, tensSufix, 4);
    }

    strMerge(tensPrefix, ONES_NAME_SIZE, tensSufix, 4, tensName, TENS_NAME_SIZE);
    strMerge(tensName, TENS_NAME_SIZE, onesName, ONES_NAME_SIZE, tensName, TENS_NAME_SIZE);
}

void nameHundreds(char * hundredsName, char hundreds, char tens, char ones) {

    char tensName[TENS_NAME_SIZE];

    nameTens(tensName, tens, ones);

    if (hundreds == '0') {
        cloneStr(tensName, TENS_NAME_SIZE, hundredsName);
        return;
    }

    strMerge(nameOnes(hundreds), ONES_NAME_SIZE, " hundred and ", 14, hundredsName, HUNDREDS_NAME_SIZE);
    strMerge(hundredsName, HUNDREDS_NAME_SIZE, tensName, TENS_NAME_SIZE, hundredsName, HUNDREDS_NAME_SIZE);
}

void nameTrio(char * trioName, unsigned char trioOrder, char hundreds, char tens, char ones) {

    char hundredsName[HUNDREDS_NAME_SIZE], trioSufix[21], trioPostSufix[7] = "illion";

    nameHundreds(hundredsName, hundreds, tens, ones);

    switch (trioOrder) {
    case 0u:
        cloneStr(hundredsName, HUNDREDS_NAME_SIZE, trioName);
        return;
    case 1u:
        cloneStr(" thousand ", 10, trioSufix);
        break;
    case 2u:
        cloneStr(" m", 3, trioSufix);
        break;
    case 3u:
        cloneStr(" b", 3, trioSufix);
        break;
    case 4u:
        cloneStr(" tr", 4, trioSufix);
        break;
    case 5u:
        cloneStr(" quadr", 7, trioSufix);
        break;
    case 6u:
        cloneStr(" quint", 7, trioSufix);
        break;
    case 7u:
        cloneStr(" sext", 6, trioSufix);
        break;
    case 8u:
        cloneStr(" sept", 6, trioSufix);
        break;
    case 9u:
        cloneStr(" oct", 5, trioSufix);
        break;
    case 10u:
        cloneStr(" non", 5, trioSufix);
        break;
    case 11u:
        cloneStr(" dec", 5, trioSufix);
        break;
    case 12u:
        cloneStr(" undec", 7, trioSufix);
        break;
    case 13u:
        cloneStr(" duodec", 8, trioSufix);
        break;
    case 14u:
        cloneStr(" tredec", 8, trioSufix);
        break;
    case 15u:
        cloneStr(" quattuordec", 13, trioSufix);
        break;
    case 16u:
        cloneStr(" quindec", 9, trioSufix);
        break;
    case 17u:
        cloneStr(" sexdec", 8, trioSufix);
        break;
    case 18u:
        cloneStr(" septendec", 11, trioSufix);
        break;
    case 19u:
        cloneStr(" octodec", 9, trioSufix);
        break;
    case 20u:
        cloneStr(" novemdec", 10, trioSufix);
        break;
    case 21u:
        cloneStr(" vigint", 8, trioSufix);
        break;
    }

    if (trioOrder > 1u) {
        strMerge(trioSufix, 21, trioPostSufix, 7, trioSufix, 20);
        if (strLen(hundredsName, HUNDREDS_NAME_SIZE) > 0) {
            strMerge(trioSufix, 21, ", ", 3, trioSufix, 21);
        }
    }

    strMerge(hundredsName, HUNDREDS_NAME_SIZE, trioSufix, 20, trioName, TRIO_NAME_SIZE);
}

void getNextTrio(char * trio, char * numberStr, long digit) {

    unsigned char i;

    trio[0] = '0';
    trio[1] = '0';
    trio[2] = '0';

    for (i = 0; i < 3 && digit >= 0; i++, digit--) {
        trio[i] = numberStr[digit];
    }
}

void nameNumber(char * numberStr, long digits, char * numberName, long nameLength) {

    char trio[3]; // trio[0] = ones; trio [1] = tens; trio[2] = hundreds
    char trioName[TRIO_NAME_SIZE];
    unsigned char trioOrder;

    digits = strLen(numberStr, digits) - 1;

    for (trioOrder = 0; digits >= 0; digits -= 3, trioOrder++) {
        getNextTrio(trio, numberStr, digits);
        // printf("trio No. %d = {\n\t\"0 (ones)\": %c,\n\t\"1 (tenths)\": %c,\n\t\"2 (hundreds)\": %c\n}\n\n", trioOrder, trio[0], trio[1], trio[2]);
        nameTrio(trioName, trioOrder, trio[2], trio[1], trio[0]);
        strMerge(trioName, TRIO_NAME_SIZE, numberName, nameLength, numberName, nameLength);
    }

    if (strLen(numberName, nameLength) == 0) {
        cloneStr("zero", 5, numberName);
    }

    strProper(numberName);
}

void readInputNumber(char * inputNumber) {
    unsigned char i;
    int c = getchar();
    for (i = 0; i < MAX_NUMBER_DIGITS && c != EOF && c != '\0' && c != '\n' && c != '\r'; i++) {
        if (c < '0' || c > '9') {
            printf("\nInvalid input \"%c\" at digit %d\n", c, i + 1);
            exit(9);
        }
        inputNumber[i] = c;
        c = getchar();
    }
    inputNumber[i] = '\0';
}

int main(int argc, const char * argv[]) {

    char inputNumber[MAX_NUMBER_DIGITS + 1] , numberName[MAX_NAME_SIZE];

    printf("Enter number (up to 66 digits): ");

    readInputNumber(inputNumber);

    printf("\nEntered: %s\n\n", inputNumber);

    nameNumber(inputNumber, MAX_NUMBER_DIGITS, numberName, MAX_NAME_SIZE);

    printf("%s\n", numberName);

    return 0;
}
