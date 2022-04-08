#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1

// Define suits, ranks, and respective names
enum Suit { Spades, Clubs, Diamonds, Hearts};
enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
char * SuitNames[] = {"Spades", "Clubs", "Diamonds", "Hearts"};
char * RankNames[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// struct for a card
typedef struct CardStructure
{
    enum Suit suit;
    enum Rank rank;
} Card;

// Method prototyping
void playMove(Card * playerHand[], Card * compHand[]);
void dealCards(Card * playerHand[], Card * compHand[], Card * deck[]);
int compareCards(Card * playerCard, Card * compCard);
int checkWin(Card * playerHand[], Card * compHand[]);


int main()
{
    Card * playerHand[52];
    Card * compHand[52];
    Card * deck[52];
    char playAgain;

    puts("Welcome to War! You literally duel the computer by comparing\n"            // Basic greeting and introduction
           "your top card with the computer's top card. Whoever has the highest\n"
           "value card takes the two cards and puts them onto the bottom of their\n"
           "deck. The winner of the game is determined by whoever ends with the\n"
           "entire deck in their possession.\n"
           "From highest to lowest:\n"
           "\tRanks: A K Q J 10 9 8 7 6 5 4 3 2\n"
           "\tSuits: Hearts, Diamonds, Clubs, Spades\n"
           "The game will start shortly.\n");
    sleep(10);                                   // Give user time to read the greeting

    // Main game loop
    do
    {
        dealCards(playerHand, compHand, deck);   // Give the player and computer half the deck
        int moves = 1;                           // Keeps track of number of moves

        while (1)
        {
            printf("Move: %d\n", moves);
            playMove(playerHand, compHand);                 // Player and computer draw their top card and compare, finish turn
            int result = checkWin(playerHand, compHand);
            if (result == 1)
            {
                puts("The player has won the duel!");
                break;
            }
            else if (result == 2)
            {
                puts("The computer has won the duel!");
                break;
            }

            moves++;
        }

        printf("\n\nWould you like to play again? Enter Y for yes, anything else for no: ");  // Prompt to restart game
        scanf(" %c", &playAgain);
        if (toupper(playAgain) != 'Y')
        {
           	int index;
		    for (index = 0; index < 52; index++)
            {
                free(deck[index]);          // Cards were malloced in dealCards(), time to free them
            }
            break;
        }
    } while (1);
    return 0;
}


void dealCards(Card * playerHand[], Card * compHand[], Card * deck[])
{
    int cardsCreated = 0;
    int turn = 0;         // Keeps track of who is supposed to get the card, player = 0, computer = 1
    Card card;            // Card template
    srand(time(NULL));    // Randomize the seed

    while (cardsCreated < 52)
    {
        int index;
		int cardFound = FALSE;
        card.rank = rand() % 13;
        card.suit = rand() % 4;

        for (index = 0; index < cardsCreated; index++)
        {
            Card * deckCard = deck[index];  // Take a card from the deck...

            if (deckCard->rank == card.rank && deckCard->suit == card.suit) // ...and compare it to the newly made card
            {
                cardFound = TRUE;  // Card is a duplicate, exit loop and continue
                break;
            }

        }

        if (cardFound == FALSE)
        {
            if (turn == 0) {
                playerHand[cardsCreated/2] = ( Card *) malloc ( sizeof(Card)); // Malloc the card and give player the card
                playerHand[cardsCreated/2]->suit = card.suit;
                playerHand[cardsCreated/2]->rank = card.rank;
                deck[cardsCreated] = playerHand[cardsCreated/2];               // Add card to deck for comparison purposes
            }
            else if (turn == 1) {
                compHand[(cardsCreated-1)/2] = ( Card *) malloc ( sizeof(Card)); // Malloc the card and give computer the card
                compHand[(cardsCreated-1)/2]->suit = card.suit;
                compHand[(cardsCreated-1)/2]->rank = card.rank;
                deck[cardsCreated] = compHand[(cardsCreated-1)/2];               // Add card to deck for comparison purposes
            }

            turn = (turn == 0) ? 1 : 0;    // Switch turn from 0 -> 1 or 1 -> 0
            cardsCreated++;
        }
    }
	int index;
    for (index = 26; index < 52; index++)   // Set the non-existent cards to NULL
    {
        playerHand[index] = NULL;
        compHand[index] = NULL;
    }
}



void playMove(Card * playerHand[], Card * compHand[])
{
    Card * playerCard = playerHand[0];      // Get top cards and their information
    Card * compCard = compHand[0];
    int pSuit = playerCard->suit;
    int pRank = playerCard->rank;
    int cSuit = compCard->suit;
    int cRank = compCard->rank;
    int result = compareCards(playerCard, compCard);    // If player has the better card, returns 0, otherwise returns 1

    if (!result)
    {
        printf("The player won this turn.\n"
               "\tPlayer's card: %s of %s\n"
               "\tComputer's card: %s of %s\n", RankNames[pRank], SuitNames[pSuit], RankNames[cRank], SuitNames[cSuit]);
       	int index;
	    for (index = 1; index < 52; index++)
        {
            playerHand[index-1] = playerHand[index];    // Shifts every card forward (subtracts one from their index)
            compHand[index-1] = compHand[index];
        }

        int length = 0;
        for (index = 0; index < 52; index++)        // Calculate how many cards in the player's hand with the top card discarded
        {
            if (playerHand[index] != NULL)
                length++;
        }
        playerHand[length] = playerCard;                // Place discarded top card to the bottom of the deck
        playerHand[length+1] = compCard;                // Place the won card to the bottom of the deck
    }

    else
    {
        printf("The computer won this turn.\n"
               "\tPlayer's card: %s of %s\n"
               "\tComputer's card: %s of %s\n", RankNames[pRank], SuitNames[pSuit], RankNames[cRank], SuitNames[cSuit]);
        int index;
		for (index = 1; index < 52; index++)
        {
            playerHand[index-1] = playerHand[index];    // Shifts every card forward (subtracts one from their index)
            compHand[index-1] = compHand[index];
        }

        int length = 0;
        for (index = 0; index < 52; index++)        // Calculate how many cards in the computer's hand with the top card discarded
        {
            if (compHand[index] != NULL)
                length++;
        }
        compHand[length] = compCard;                    // Place discarded top card to the bottom of the deck
        compHand[length+1] = playerCard;                // Place the won card to the bottom of the deck
    }
}


int compareCards(Card * playerCard, Card * compCard)
{
    if (playerCard->rank > compCard->rank)      // Compares ranks
        return 0;
    else if (playerCard->rank < compCard->rank)
        return 1;
    else
    {
        if (playerCard->suit > compCard->suit)  // If ranks match, compare suits
            return 0;
        else
            return 1;
    }
}


int checkWin(Card * playerHand[], Card * compHand[])
{
    int playerLen = 0;
    int compLen = 0;
	int i;
    for (i = 0; i < 52; i++)        // Number of cards is determined by the number of non-NULL cards
    {
        if (playerHand[i] != NULL)
            playerLen++;
        if (compHand[i] != NULL)
            compLen++;
    }
    printf("Player deck size: %d\nComputer deck size: %d\n"
           "----------------------------------------------\n", playerLen, compLen);     // Output current size of player's and computer's deck

    if (playerLen == 52)    // Player has entire deck, player wins
        return 1;
    if (compLen == 52)      // Computer has entire deck, computer wins
        return 2;
    return -1;              // No one has entire deck, continue play
}
