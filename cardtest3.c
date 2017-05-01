// unit test on playVillage function (line 1307)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <strings.h>
#include <stdio.h>
#include <assert.h>

// int playVillage(struct gameState *state, int handPos, int currentPlayer)
// returns 0 on normal exit
// should add a card to hand and increase number of actions by 2
int main() {
    printf("\n####################\n");
    printf("Card test (unit test) - Village\n");

    int i, p;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount = 1;
    int deckCount = 1;
    int coppers[MAX_HAND];
    int villages[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        villages[i] = village;
    }

    // cycle through each player
    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        G.deckCount[p] = deckCount;
        // there is a single village in hand
        // and one copper available to be drawn from the deck
        memcpy(G.hand[p], villages, sizeof(int) * handCount);
        memcpy(G.deck[p], coppers, sizeof(int) * deckCount);

        printf("-- Testing successful return\n");
        int testVillage;
        testVillage = playVillage(&G, 0, p);
        if (testVillage == 0)
            printf("playVillage(): PASS successful return\n");
        else
            printf("playVillage(): FAIL unsuccsesful return\n");

        printf("-- Testing hand count\n");
        if (G.handCount[p] == 1)
            printf("playVillage(): PASS hand holds only 1 card\n");
        else
            printf("playVillage(): FAIL hand holds %d cards, expected 1\n", G.handCount[p]);

        printf("--Testing discard\n");
        if (G.handCount[p] > 0) {
            int count = 0;
            for (i = 0; i < G.handCount[p]; i++) {
                if (G.hand[p][i] == village)
                    count++;
            }
            if (count != 0)
                printf("playVillage(): FAIL village card has not been discarded\n");
            else
                printf("playVillage(): PASS village card has been discarded\n");
        }
        else
            printf("playVillage(): PASS village card has been discarded\n");

        printf("-- Testing number of actions\n");
        if (G.numActions >= 2)
            printf("playVillage(): PASS 2 more actions have been made available\n");
        else
            printf("playVillage(): FAIL %d actions are left, expected at least 2\n", G.numActions);
    }

    return 0;
}