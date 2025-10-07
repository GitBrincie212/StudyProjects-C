#include <stdio.h>

/** The second program in the learning process of C. This is by
 * far more simple than the first program, as seen below in the code:
 */
const char ALPHABET[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z'
};

/// Just a function for separating concerns
int read_process() {
    char target_char;

    while(1) {
        printf("Enter a letter: ");
        scanf(" %c", &target_char);
        for (int i = 0; i <= sizeof(ALPHABET) / sizeof(ALPHABET[0]); i++) {
            if(ALPHABET[i] == target_char) {
                return i;
            }
        }
        printf("The supplied character is not in the alphabet\n");
    }
}

int main(void) {
    int target_idx = read_process();
    for (int i = target_idx; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%c", ALPHABET[j]);
        }
        printf("\n");
    }

    return 0;
}
