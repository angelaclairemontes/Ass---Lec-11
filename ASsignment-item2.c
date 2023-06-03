#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Function to scan a word and count the occurrences of each letter
void scan_word(int occurrence[26]) {
    char c;
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            occurrence[toupper(c) - 'A']++;
        }
    }
}

// Function to check if two words are anagrams
bool is_anagram(int occurrence1[26], int occurrence2[26]) {
    for (int i = 0; i < 26; i++) {
        if (occurrence1[i] != occurrence2[i]) {
            return false;
        }
    }
    return true;
}

// Function to print the occurrences of each letter in a word
void print_occurrences(int occurrence[26]) {
    for (int i = 0; i < 26; i++) {
        if (occurrence[i] > 0) {
            printf("%c: %d\n", 'A' + i, occurrence[i]);
        }
    }
}

int main(void) {
    // Initialize arrays to store letter occurrences
    int letters1[26] = {0};
    int letters2[26] = {0};

    // Prompt the user to enter the first word
    printf("Enter first word: ");
    scan_word(letters1); // Scan the first word and count occurrences

    // Prompt the user to enter the second word
    printf("Enter second word: ");
    scan_word(letters2); // Scan the second word and count occurrences

    // Check if the two words are anagrams
    bool anagram = is_anagram(letters1, letters2);

    // Print the result based on the anagram check
    if (anagram) {
        printf("\nThe words are anagrams.\n");
    } else {
        printf("\nThe words are not anagrams.\n");
    }

    return 0;
}
