// unit test on playSmithy function (line 1294)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// int playSmithy(struct gameState *state, int handPos, int currentPlayer)
// returns 0 on normal exit
// should add three cards to hand
int main() {
    printf("\n####################\n");
    printf("Card test (unit test) - Smithy\n");

    int i, p;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount = 1;
    int deckCount = 3;
    int coppers[MAX_HAND];
    int smithys[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        smithys[i] = smithy;
    }

    // cycle through each player
    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);
        G.handCount[p]  = handCount;
        G.deckCount[p] = deckCount;
        // There is a single Smithy in hand,
        // and three Coppers in deck available to draw
        memcpy(G.hand[p], smithys, sizeof(int) * handCount);
        memcpy(G.deck[p], coppers, sizeof(int) * deckCount);

        printf("-- Testing successful return\n");
    	int testSmithy;
    	testSmithy = playSmithy(&G, 0, p);
    	if (testSmithy == 0)
            printf("playSmithy(): PASS successful return\n");
    	else
    	    printf("playSmithy(): FAIL unsuccessful return\n");

        printf("-- Testing hand count\n");
        if (G.handCount[p] == 3)
            printf("playSmithy(): PASS Hand holds 3 cards\n");
        else
            printf("playSmithy(): FAIL Hand holds %d cards, expected 3\n", G.handCount[p]);

        printf("-- Testing discard\n");
        if (G.handCount[p] > 0) {
            int count = 0;
            for (i = 0; i < G.handCount[p]; i++) {
                if (G.hand[p][i] == smithy)
                    count++;
            }
            if (count != 0)
                printf("playSmithy(): FAIL smithy card has not been discarded\n");
            else
                printf("playSmithy(): PASS smithy card has been discarded\n");
        }
        else
            printf("playSmithy(): PASS smithy card has been discarded\n");

    }

    return 0;
}