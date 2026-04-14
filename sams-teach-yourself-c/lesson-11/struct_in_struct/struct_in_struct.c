/*
 * Name: struct_in_struct.c
 * Desc:
 *      Demonstrates structures within structures.
 */

#include <stdio.h>

int
main(void)
{
    int length, width;

    struct coord {
        int x;
        int y;
    };

    struct rectangle {
        struct coord top_left;
        struct coord bottom_right;
    } box;

    printf("Enter the top left x coordinate: ");
    scanf("%d", &box.top_left.x);

    printf("Enter the top left y coordinate: ");
    scanf("%d", &box.top_left.y);

    printf("Enter the bottom right x coordinate: ");
    scanf("%d", &box.bottom_right.x);

    printf("Enter the bottom right y coordinate: ");
    scanf("%d", &box.bottom_right.y);

    width = box.bottom_right.x - box.top_left.x;
    length = box.top_left.y - box.bottom_right.y;

    printf("The area is %ld units.\n", (long)(width * length));

    return 0;
}
