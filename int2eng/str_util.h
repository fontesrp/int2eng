//
//  str_util.h
//  int2eng
//

#ifndef str_util_h
#define str_util_h

#include <stdlib.h>

/*
 * Capitalizes the first letter of a string
*/
void strProper(char * str) {
    char c = str[0];
    if (c >= 'a' && c =< 'z') {
        str[0] = c - ' '; // minus 32
    }
}

/*
 * Copies @strSize chars from @original to @clone, regardles of their content
 * @original = "abc\0d" and strSize = 5 will make @clone = "abc\0d"
*/
void cloneStr(char * original, unsigned long strSize, char * clone) {
    for (; strSize > 0; strSize--) {
        clone[strSize - 1] = original[strSize - 1];
    }
}

/*
 * Returns number of chars before '\0'
 * @str = "abc\0d", will return 3
*/
unsigned long strLen(char * str, unsigned long maxLength) {
    unsigned long i;
    for (i = 0; i < maxLength && str[i] != '\0'; i++) {
        ;
    }
    return i;
}

/*
 * Merges two strings without changing their contents and returns the resulting string's lenth (same as strLen)
 * @prefix = "abc\0g" and @sufix = "def\0h" will make @mergeInto = "abcdef\0" and @sizeOfResult = 6
*/
unsigned long strMerge(char * prefix, unsigned long sizeOfPfx, char * sufix, unsigned long sizeOfSfx, char * mergeInto, unsigned long sizeOfResult) {

    char * prefixClone, * sufixClone;
    unsigned long i, j;

    sizeOfPfx = strLen(prefix, sizeOfPfx);
    sizeOfSfx = strLen(sufix, sizeOfSfx);

    prefixClone = (char *) malloc(sizeOfPfx + 1); // "+ 1" includes '\0'
    sufixClone = (char *) malloc(sizeOfSfx + 1);

    cloneStr(prefix, sizeOfPfx + 1, prefixClone);
    cloneStr(sufix, sizeOfSfx + 1, sufixClone);

    for (i = 0; i < sizeOfResult && i < sizeOfPfx; i++) {
        mergeInto[i] = prefixClone[i];
    }

    for (j = 0; i + j < sizeOfResult && j < sizeOfSfx; j++) {
        mergeInto[i + j] = sufixClone[j];
    }

    if (i + j < sizeOfResult) {
        mergeInto[i + j] = '\0';
        sizeOfResult = i + j;
    } else {
        mergeInto[--sizeOfResult] = '\0';
    }

    free(prefixClone);
    free(sufixClone);
    
    return sizeOfResult;
}

#endif /* str_util_h */
