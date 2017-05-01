// unit test on playGreatHall function (line 1319)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <strings.h>
#include <stdio.h>
#include <assert.h>

// int playGreatHall(struct gameState *state, int handPos, int currentPlayer)
// returns 0 on normal exit
// should add an action
// and should draw a card
int main() {
    printf("\n###################\n");
    printf("Card test (unit test) - Great Hall\n");

    int i, p;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount = 1;
    int deckCount = 1;
    int coppers[MAX_HAND];
    int great_halls[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        great_halls[i] = great_hall;
    }

    // cycle through each player
    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        G.deckCount[p] = deckCount;
        // there is a single great hall in hand
        // and one copper available to be drawn from the deck
        memcpy(G.hand[p], great_halls, sizeof(int) * handCount);
        memcpy(G.deck[p], coppers, sizeof(int) * deckCount);

        printf("-- Testing successful return\n");
        int testGreatHall;
        testGreatHall = playGreatHall(&G, 0, p);
        if (testGreatHall == 0)
            printf("playGreatHall(): PASS successful return\n");
        else
            printf("playGreatHall(): FAIL unsuccessful return\n");

        printf("--Testing hand count\n");
        if (G.handCount[p] == 1)
            printf("playGreatHall(): PASS hand holds only 1 card\n");
        else
            printf("playGreatHall(): FAIL hand holds %d cards, expected 1\n", G.handCount[p]);

        printf("-- Testing discard\n");
        if (G.handCount[p] > 0) {
            int count = 0;
            for (i = 0; i < G.handCount[p]; i++) {
                if (G.hand[p][i] == great_hall)
                    count++;
            }
            if (count != 0)
                printf("playGreatHall(): FAIL great hall card has not been discarded\n");
            else
                printf("playGreatHall(): PASS great hall card has been discarded\n");
        }
        else
            printf("playGreatHall(): PASS great hall card has been discarded\n");

        printf("-- Testing number of actions\n");
        if (G.numActions >= 1)
            printf("playGreatHall(): PASS 1 more action has been made available\n");
        else 
            printf("playGreatHall(): FAIL %d actions are left, expected at least 1\n", G.numActions);
    }

    return 0;
}