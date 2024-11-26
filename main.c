#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char* digits, char** letters, int index, char** combos, int* returnSize, int* currString) {
    if (index == strlen(digits)) {
        (*currString)++;
        return;
    }

    char *possLetters = letters[digits[index]];
    for (int i = 0; i < strlen(possLetters); i++) {
        if (index != 0 && *currString != 0 && combos[*currString][index - 1] == '\0') {
            strcpy(combos[*currString], combos[*currString - 1]);
        }
        combos[*currString][index] = possLetters[i];
        dfs(digits, letters, index + 1, combos, returnSize, currString);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    char *letters['9' + 1];
    letters['2'] = "abc";
    letters['3'] = "def";
    letters['4'] = "ghi";
    letters['5'] = "jkl";
    letters['6'] = "mno";
    letters['7'] = "pqrs";
    letters['8'] = "tuv";
    letters['9'] = "wxyz";

    int possibleCombos = 1;
    for (int i = 0; i < strlen(digits); i++) {
        possibleCombos *= strlen(letters[digits[i]]);
    }
    *returnSize = possibleCombos;

    char** combos = (char**)malloc(possibleCombos * sizeof(char*));
    for (int i = 0; i < possibleCombos; i++) {
        combos[i] = (char*)calloc(strlen(digits) + 1, sizeof(char));
    }
    int currString = 0;

    dfs(digits, letters, 0, combos, returnSize, &currString);

    return combos;
}

void freeCombos(char** combos, int returnSize) {
    for (int i = 0; i < returnSize; i++) {
        free(combos[i]);
    }
    free(combos);
}

int main() {
    char* digits1 = "23";
    int returnSize1 = 0;
    char** result1 = letterCombinations(digits1, &returnSize1);
    printf("Output for Example 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("%s ", result1[i]);
        free(result1[i]);
    }
    free(result1);
    printf("\n");

    char* digits2 = "";
    int returnSize2 = 0;
    char** result2 = letterCombinations(digits2, &returnSize2);
    printf("Output for Example 2:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("%s ", result2[i]);
        free(result2[i]);
    }
    free(result2);
    printf("\n");

    char* digits3 = "2";
    int returnSize3 = 0;
    char** result3 = letterCombinations(digits3, &returnSize3);
    printf("Output for Example 3:\n");
    for (int i = 0; i < returnSize3; i++) {
        printf("%s ", result3[i]);
        free(result3[i]);
    }
    free(result3);
    printf("\n");

    return 0;
}