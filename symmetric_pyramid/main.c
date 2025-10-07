#include <stdio.h>

/* One of the many learning programs il be developing for the
 * C programming languages. This is the first one, the symmetrical
 * pyramid where given a positive non-zero number N, we print a shape
 * consisting of 2 mirrored pyramids
 *
 * Explanation: I notice the shape is symmetrical from top to bottom
 * which the process of making it can be extracted into its own function.
 * There will definitely be a better and more clever way of achieving this,
 * as if someone looks more closely, they will notice the pyramid is also symmetrical
 * in the diagonal areas (there are smaller tiles just rotated 90º)
 */

void build_pyramid(const int INDEX, const int MAX_WIDTH) {
    const int CHAR_COUNT = INDEX * 2; // Doubling because there will be just as many '*' as ' '
    const int SPACING = MAX_WIDTH - INDEX; // Gives the padding on the left direction
    const int TOTAL_BUFFER_LEN = CHAR_COUNT + SPACING;
    char buffer[TOTAL_BUFFER_LEN];

    // Pad the buffer based on the calculated spacing
    for (int i = 0; i < SPACING; i++) {
        buffer[i] = ' ';
    }

    for (int j = 0; j < CHAR_COUNT; j++) {
        const int IDX = j + SPACING; // Add-on the SPACING to not override the previous ' '
        if (IDX % 2 == 0) {
            buffer[IDX] = '*';
            continue;
        }
        buffer[IDX] = ' ';
    }

    buffer[TOTAL_BUFFER_LEN - 1] = '\0';
    printf("%s\n", buffer);
}

int read_process() {
    int num = 0;

    while(1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num > 0) {
            return num;
        }
        printf("Number provided is below or equal to zero\n");
    }
}

int main(void) {
    const int NUM = read_process();

    // == Top symmetrical cone ==
    for (int i = NUM; i >= 0; i -= 2) {
        if (i == 0 || i == 2) continue;
        build_pyramid(i, NUM);
    }

    // == Bottom symmetrical cone ==
    const int END = NUM + 2 + (NUM % 2 == 0 ? 2 : 0); // Handling an edge case for even numbers
    for (int i = 4; i < END; i += 2) {
        build_pyramid(i - 1, NUM);
    }
    return 0;
}