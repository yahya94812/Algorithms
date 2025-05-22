#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SIZE 256

char pattern[ASCII_SIZE], text[ASCII_SIZE], shiftTable[ASCII_SIZE];
int pattern_length, text_length;

// Function declarations
void createShiftTable();
int horsepool();

int main() {
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    pattern_length = strlen(pattern);
    text_length = strlen(text);

    int found_at = horsepool();

    if (found_at == -1)
        printf("Pattern not found.\n");
    else
        printf("Pattern found at position: %d\n", found_at + 1);  // 1-based index

    return 0;
}

// Create the shift table used in Horspool algorithm
void createShiftTable() {
    for (int i = 0; i < ASCII_SIZE; i++) {
        shiftTable[i] = pattern_length;
    }

    for (int j = 0; j < pattern_length - 1; j++) {
        int char_index = (int)pattern[j];
        shiftTable[char_index] = pattern_length - 1 - j;
    }
}

// Horspool string matching algorithm
int horsepool() {
    createShiftTable();

    int i = pattern_length - 1;

    while (i <= text_length - 1) {
        int k = 0;

        // Compare pattern from right to left
        while (k < pattern_length && pattern[pattern_length - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == pattern_length) {
            // Match found
            return i - pattern_length + 1;
        } else {
            // Mismatch: use shift table
            int shift_char = (int)text[i];
            i += shiftTable[shift_char];
        }
    }

    return -1;  // Pattern not found
}
