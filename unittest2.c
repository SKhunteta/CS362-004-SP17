// unit testing for the getCost function
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// getCost takes one parameter: int cardNumber
// it uses a switch to match the card with its cost, which is returned.
int main() {
    printf("\n####################\n");
    printf("Unit test 3 - getCost()\n");
    // to test these, we will simply pass any out of the 27 card types
    // and compare the results of the getCost function
    if(getCost(0) == 0)
        printf("getCost(): PASS cost of Curse is correct\n");
    else
        printf("getCost(): FAIL cost of Curse is incorrect\n");

    if(getCost(1) == 2)
        printf("getCost(): PASS cost of Estate is correct\n");
    else
        printf("getCost(): FAIL cost of Estate is incorrect\n");

    if(getCost(2) == 5)
        printf("getCost(): PASS cost of Dutchy is correct\n");
    else
        printf("getCost(): FAIL cost of Dutchy is incorrect\n");

    if(getCost(3) == 8)
        printf("getCost(): PASS cost of Province is correct\n");
    else
        printf("getCost(): FAIL cost of Province is incorrect\n");

    if(getCost(4) == 0)
        printf("getCost(): PASS cost of Copper is correct\n");
    else
        printf("getCost(): FAIL cost of Copper is incorrect\n");

    if(getCost(5) == 3)
        printf("getCost(): PASS cost of Silver is correct\n");
    else
        printf("getCost(): FAIL cost of Silver is incorrect\n");

    // if time to do it, add tests for each card.

    return 0;
}