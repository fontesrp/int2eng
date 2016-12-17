#include <stdio.h>

#define MAX_NUMBER_DIGITS 66
#define MAX_NAME_CHARS 933

/*
 seven hundred and seventy-seven vigintillion,
 seven hundred and seventy-seven novemdecillion,
 seven hundred and seventy-seven octodecillion,
 seven hundred and seventy-seven septendecillion,
 seven hundred and seventy-seven sexdecillion,
 seven hundred and seventy-seven quindecillion,
 seven hundred and seventy-seven quattuordecillion,
 seven hundred and seventy-seven tredecillion,
 seven hundred and seventy-seven duodecillion,
 seven hundred and seventy-seven undecillion,
 seven hundred and seventy-seven decillion,
 seven hundred and seventy-seven nonillion,
 seven hundred and seventy-seven octillion,
 seven hundred and seventy-seven septillion,
 seven hundred and seventy-seven sextillion,
 seven hundred and seventy-seven quintillion,
 seven hundred and seventy-seven quadrillion,
 seven hundred and seventy-seven trillion,
 seven hundred and seventy-seven billion,
 seven hundred and seventy-seven million,
 seven hundred and seventy-seven
 */

void readInputNumber(char * inputNumber) {
	unsigned char i;
	char c = getchar();
	for (i = 0; i < MAX_NUMBER_DIGITS - 1 && c != '\0' && c != '\n' && c != '\r'; i++) {
		inputNumber[i] = c;
		c = getchar();
	}
	inputNumber[i] = '\0';
}

int main(int argc, const char * argv[]) {

	char inputNumber[MAX_NUMBER_DIGITS], numberName[MAX_NAME_CHARS];

	printf("Enter number: ");
	readInputNumber(inputNumber);

	printf("\nEntered: %s", inputNumber);

	// convert2eng(inputNumber, numberName);
	printf("\n%s\n", numberName);

	return 0;
}
