#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256
#define MAX_SIZE 300
char pattern[MAX_SIZE], text[MAX_SIZE], shift_table[ASCII_SIZE];
int pattern_length, text_length;

int horse_pool();

int main() {
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    pattern_length = strlen(pattern);
    text_length = strlen(text);

    int found_at = horse_pool();

    if (found_at == -1)
        printf("Pattern not found.\n");
    else
        printf("Pattern found at position: %d\n", found_at + 1);  // 1-based index

    return 0;
}

// Create the shift table used in Horspool algorithm
void create_shift_table() {
    for (int i = 0; i < ASCII_SIZE; i++) {
        shift_table[i] = pattern_length;
    }

    for (int j = 0; j < pattern_length - 1; j++) {
        int char_index = (int)pattern[j];
        shift_table[char_index] = (pattern_length - 1) - j; //use left most index_location for shifting
    }

    return;
}

// Horspool string matching algorithm
int horse_pool() {
    create_shift_table();

    int i = pattern_length - 1; //i points to the chars of text string

    while (i < text_length) {
        int j = 0; //j points to the chars of pattern string

        // Compare pattern from right to left
        while (j < pattern_length && pattern[(pattern_length - 1) - j] == text[i - j]) {
            j++;
        }

        if (j == pattern_length) {
            // Match found
            return i - pattern_length + 1; //+1 for pointing the first (left most) char of matching string
        } else {
            // Mismatch: use shift table
            int char_index = (int)text[i];
            i += shift_table[char_index];
        }
    }

    return -1;  // Pattern not found
}
