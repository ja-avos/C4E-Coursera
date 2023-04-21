/*
    Program for week 2 honors assignment. Randomly generated poker hands.
    Juan Avelino
    2023/04/19
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 7
#define DECK_SIZE 52

#define HANDS 1000000

typedef enum suit { 
    clubs, diamonds, hearts, spades 
    } suit;

typedef struct card { 
    suit suit; 
    int pips;
    } card;

typedef enum Type { 
    high_or_less, pair, two_pair, three_of_a_kind, straight, flush, full_house, four_of_a_kind, straight_flush, royal_flush
    } Type;

/*
    Generates a deck of cards
*/
void generateDeck(card* deck) {

    for (int i = 0; i < 52; i++) {
        deck[i].suit = i / 13;
        deck[i].pips = (i % 13) + 1;
    }
}

/*
    Prints a hand of cards
*/
void printHand(card* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        switch (hand[i].suit) // Print the suit based on the enumeration
        {
        case clubs:
            printf("C");
            break;
        case diamonds:
            printf("D");
            break;
        case hearts:
            printf("H");
            break;
        case spades:
            printf("S");
            break;
        }

        printf("%d ", hand[i].pips);
    }
}

/*
    Shuffle a deck of cards
*/
void shuffleDeck(card* deck) {
    srand(time(NULL));

    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/*
    Deal out a hand of cards
*/
void dealHand(card* deck, card* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

/*
    Checks if a hand is a royal flush
*/
int checkRoyalFlush(card* hand) {
    int suit_c = 0;

    while(suit_c < 4) {
        int pips[13] = {0};

        for (int i = 0; i < HAND_SIZE; i++) {
            if (hand[i].suit == suit_c) {
                pips[hand[i].pips - 1]++;
            }
        }

        if (pips[0] == 1 && pips[9] == 1 && pips[10] == 1 && pips[11] == 1 && pips[12] == 1) {
            return 1;
        }

        suit_c++;
    }

    return 0;
}

/*
    Checks if a hand is a straight flush
*/
int checkStraightFlush(card* hand) {
    int suit_c = 0;

    while(suit_c < 4) {
        int pips[13] = {0};

        for (int i = 0; i < HAND_SIZE; i++) {
            if (hand[i].suit == suit_c) {
                pips[hand[i].pips - 1]++;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (pips[i] >= 1 && pips[i + 1] >= 1 && pips[i + 2] >= 1 && pips[i + 3] >= 1 && pips[i + 4] >= 1) {
                return 1;
            }
        }

        suit_c++;
    }

    return 0;
}

/*
    Evaluates a hand of cards
*/
Type evaluateHand(card* hand) {
    int pips[13] = {0};
    int suits[4] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        pips[hand[i].pips - 1]++;
        suits[hand[i].suit]++;
    }

    int pairs_c = 0;
    int three_of_a_kind_c = 0;
    int four_of_a_kind_c = 0;

    for (int i = 0; i < 13; i++) {
        if (pips[i] == 2) {
            pairs_c++;
        } else if (pips[i] == 3) {
            three_of_a_kind_c++;
        } else if (pips[i] == 4) {
            four_of_a_kind_c++;
        }
    }

    int flush_c = 0;

    for (int i = 0; i < 4; i++) {
        if (suits[i] >= 5) {
            flush_c = 1;
        }
    }

    int straight_c = 0;

    for (int i = 0; i < 9; i++) {
        if (pips[i] >= 1 && pips[i + 1] >= 1 && pips[i + 2] >= 1 && pips[i + 3] >= 1 && pips[i + 4] >= 1) {
            straight_c = 1;
        }
    }

    if (four_of_a_kind_c) {
        return four_of_a_kind;
    } else if (three_of_a_kind_c >= 1 && pairs_c >= 1) {
        return full_house;
    } else if (flush_c) {
        if (checkRoyalFlush(hand)) {
        return royal_flush;
        }
        if (straight_c && checkStraightFlush(hand))
            return straight_flush;
        else
            return flush;
    } else if (straight_c == 1) {
        return straight;
    } else if (three_of_a_kind_c == 1) {
        return three_of_a_kind;
    } else if (pairs_c == 2) {
        return two_pair;
    } else if (pairs_c == 1) {
        return pair;
    }
    
    return high_or_less;
}

int main() {
    card* deck[DECK_SIZE];
    generateDeck(deck);

    int hand_count[10] = {0};

    for (int i = 0; i < HANDS; i++) {
        printf("Hand %d\n", i);
        
        shuffleDeck(deck);

        card* hand[HAND_SIZE];
        dealHand(deck, hand);

        hand_count[evaluateHand(hand)]++;
    }

    printf("Hands: Qty, probability\n");
    printf("High or less: %d, %f\n", hand_count[high_or_less], (float)hand_count[high_or_less] / HANDS);
    printf("Pair: %d, %f\n", hand_count[pair], (float)hand_count[pair] / HANDS);
    printf("Two pair: %d, %f\n", hand_count[two_pair], (float)hand_count[two_pair] / HANDS);
    printf("Three of a kind: %d, %f\n", hand_count[three_of_a_kind], (float)hand_count[three_of_a_kind] / HANDS);
    printf("Straight: %d, %f\n", hand_count[straight], (float)hand_count[straight] / HANDS);
    printf("Flush: %d, %f\n", hand_count[flush], (float)hand_count[flush] / HANDS);
    printf("Full house: %d, %f\n", hand_count[full_house], (float)hand_count[full_house] / HANDS);
    printf("Four of a kind: %d, %f\n", hand_count[four_of_a_kind], (float)hand_count[four_of_a_kind] / HANDS);
    printf("Straight flush: %d, %f\n", hand_count[straight_flush], (float)hand_count[straight_flush] / HANDS);
    printf("Royal flush: %d, %f\n", hand_count[royal_flush], (float)hand_count[royal_flush] / HANDS);

    return 0;
}