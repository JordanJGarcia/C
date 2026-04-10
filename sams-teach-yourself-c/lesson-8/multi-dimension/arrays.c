/*
 * Name: arrays.c
 * Desc:
 *      Demonstrates use of single-dimensional arrays.
 */

#include <stdio.h>

#define GAMES 4
#define PLAYERS 5

int main(void)
{
    int total, best_player, scores[6][5], x, y;
    float score_avg[6], best_avg = 0;

    for (x = 1; x <= GAMES; x++)
    {
        printf("Getting scoring totals for Game #%d.\n", x);
        for (y = 1; y <= PLAYERS; y++)
        {
            printf("What did player #%d score in the game\? ", y);
            scanf("%d", &scores[y][x]);
        }
    }

    for (x = 1; x <= PLAYERS; x++)
    {
        for (y = 1, total = 0; y <= GAMES; total += scores[x][y++]);
        score_avg[x] = (float)total / GAMES;
    }

    for (x = 1; x <= PLAYERS; x++)
    {
        if (score_avg[x] > best_avg)
        {
            best_avg = score_avg[x];
            best_player = x;
        }
    }

    printf("Player #%d had the best scoring average,\n", best_player);
    printf("at %.2f points per game.\n", score_avg[best_player]);

    return 0;
}
