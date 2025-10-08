#include <stdbool.h>
#include <stdio.h>

/* One of if not the easiest program to write in C, this is the third one in the list,
 * no need to explain any stuff. No comments needed
 *
 */

int main(void) {
    int num;
    while(1) {
        printf("Supply a number of asterisks: ");
        scanf("%d", &num);
        if (num >= 3) {
            break;
        }
        printf("The number has to be above 3\n");
    }

    for (int x = 0; x <= num; x++) {
        for (int y = 0; y <= num; y++) {
            /* It requires the outline of the square, as such the outlines are defined,
             * on the combinations [x = 0, y = ?] or [x = ?, y = 0] where "?" can be any value
             */
            const bool is_asterisk_outline = x == 0 || y == 0 || x == num || y == num;

            if (is_asterisk_outline) {
                printf("*");
                continue;
            }
            printf(" ");
        }
        printf("\n");
    }
}
