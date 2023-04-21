#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a card
struct Card {
    enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES} suit;
    short pips;
};

// Define a function to shuffle the deck 
void shuffleDeck(struct Card *deck, int numCards) {
    int i, j;
    struct Card temp;

    srand(time(NULL));

    for (i = numCards - 1; i > 0; i--) {
        j = rand() % (i + 1);

        // Swap cards
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Define a function to deal out a hand of 7 cards 
struct Card* dealHand(struct Card *deck) {
    static struct Card hand[7];

    int i;
    for (i = 0; i < 7; i++) {
        hand[i] = deck[i];
    }

    return hand;
}

// Define a function to check if a hand contains a pair 
int hasPair(struct Card *hand) {
    int i, j;

    for (i = 0; i < 6; i++) {
        for (j = i+1; j < 7; j++) {
            if (hand[i].pips == hand[j].pips) {
                return 1;
            }
        }
    }

    return 0;
}

// Define a function to check if a hand contains two pairs 
int hasTwoPair(struct Card *hand) {
    int i, j, pairs = 0;

    for (i = 0; i < 6; i++) {
        for (j = i+1; j < 7; j++) {
            if (hand[i].pips == hand[j].pips) {
                pairs++;
                if (pairs == 2) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Define a function to check if a hand contains three of a kind 
int hasThreeOfKind(struct Card *hand) {
    int i, j, k;

    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 6; j++) {
            for (k = j+1; k < 7; k++) {
                if (hand[i].pips == hand[j].pips && hand[j].pips == hand[k].pips) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Define a function to check if a hand contains a full house 
int hasFullHouse(struct Card *hand) {
    int i, j, k, l, m;

    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 6; j++) {
            for (k = j+1; k < 7; k++) {
                for (l = 0; l < 5; l++) {
                    for (m = l+1; m < 6; m++) {
                        if (l != i && l != j && l != k && m != i && m != j && m != k) {
                            if (hand[i].pips == hand[j].pips && hand[j].pips == hand[k].pips && hand[l].pips == hand[m].pips) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
                           
// Define a function to check if a hand contains four of a kind 
int hasFourOfKind(struct Card *hand) {
    int i, j, k, l;

    for (i = 0; i < 4; i++) {
        for (j = i+1; j < 5; j++) {
            for (k = j+1; k < 6; k++) {
                for (l = k+1; l < 7; l++) {
                    if (hand[i].pips == hand[j].pips && hand[j].pips == hand[k].pips && hand[k].pips == hand[l].pips) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    struct Card deck[52];
    int i, j, numHands = 1000000;
    int noPairCount = 0, onePairCount = 0, twoPairCount = 0, threeOfKindCount = 0, fullHouseCount = 0, fourOfKindCount = 0;

    // Initialize deck
    for (i = 0; i < 52; i++) {
        deck[i].suit = i / 13;
        deck[i].pips = i % 13 + 1;
    }

    

    // Deal out hands and count hand types
    for (i = 0; i < numHands; i++) {
        // Shuffle deck
    shuffleDeck(deck, 52);
        struct Card *hand = dealHand(deck);
        if (!hasPair(hand)) {
            noPairCount++;
        } else if (hasTwoPair(hand)) {
            twoPairCount++;
        } else if (hasThreeOfKind(hand)) {
            threeOfKindCount++;
        } else if (hasFullHouse(hand)) {
            fullHouseCount++;
        } else if (hasFourOfKind(hand)) {
            fourOfKindCount++;
        } else {
            onePairCount++;
        }
    }

    // Print probabilities
    printf("No Pair: %.4f%%\n", (float)(noPairCount / numHands )* 100);
    printf("One Pair: %.4f%%\n", (float)(onePairCount / numHands) * 100);
    printf("Two Pair: %.4f%%\n", (float)(twoPairCount / numHands) * 100);
    printf("Three of a Kind: %.4f%%\n", (float)(threeOfKindCount / numHands) * 100);
    printf("Full House: %.4f%%\n", (float)(fullHouseCount / numHands) * 100);
    printf("Four of a Kind: %.4f%%\n", (float)(fourOfKindCount / numHands) * 100);

    return 0;
}