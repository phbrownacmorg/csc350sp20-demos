#include "FrenchCard.hpp"
#include "UnoCard.hpp"
#include <cassert>
#include <iostream>

using namespace std;

bool testFrenchCard() {
    bool success = true;
    vector<PlayingCard*> deck = FrenchCard::makeDeck();
    
    unsigned int deckSize = FrenchCard::_SUITS.size() *
                            (FrenchCard::_MAX_RANK - FrenchCard::_MIN_RANK + 1);
    success = (deck.size() == deckSize);
    for (unsigned int i = 0; i < deckSize; i++) {
        PlayingCard& card = *(deck.at(i));
        unsigned int numSuits = FrenchCard::_SUITS.size();
        cout << i << ": " << card.rank() << " " << card.suit() 
                << ": " << card.toString() << endl;
        // Integer division!
        int rank = (int)((i / numSuits) + FrenchCard::_MIN_RANK);
        string suit = FrenchCard::_SUITS.at(i % numSuits);
        success = success && (card.rank() == rank); 
        success = success && (card.suit() == suit);
        FrenchCard sameCard(suit, rank);
        success = success && (card == sameCard);
        success = success && (card <= sameCard);
        success = success && (card >= sameCard);
        if (i > 0) {
            PlayingCard& prevCard = *(deck.at(i-1));
            success = success && (prevCard != card);
            success = success && (prevCard < card);
            success = success && (prevCard <= card);
            success = success && (card > prevCard);
            success = success && (card >= prevCard);
        }
    }
    
    return success;
}

bool testUnoCard() {
    bool success = true;
    vector<PlayingCard*> deck = UnoCard::makeDeck();
    
    unsigned int deckSize = 108;
    success = (deck.size() == deckSize);

    unsigned int numColorSuits = UnoCard::_COLOR_SUITS.size();

    // Handle zeroes
    unsigned int i = 0;
    for (; i < numColorSuits; i++) {
        PlayingCard& card = *(deck.at(i));
        cout << i << ": " << card.rank() << " " << card.suit() 
                << ": " << card.toString() << endl;
        // Integer division!
        int rank = 0;
        string suit = UnoCard::_COLOR_SUITS.at(i);
        success = success && (card.rank() == rank); 
        success = success && (card.suit() == suit);
        UnoCard sameCard(suit, rank);
        success = success && (card == sameCard);
        success = success && (card <= sameCard);
        success = success && (card >= sameCard);
        if (i > 0) {
            PlayingCard& prevCard = *(deck.at(i-1));
            success = success && (prevCard != card);
            success = success && (prevCard < card);
            success = success && (prevCard <= card);
            success = success && (card > prevCard);
            success = success && (card >= prevCard);
        }
    }
    
    // Handle color cards
    for (i = numColorSuits; i < 100; i++) {
        PlayingCard& card = *(deck.at(i));
        cout << i << ": " << card.rank() << " " << card.suit() 
                << ": " << card.toString() << endl;
        // Integer division!
        int rank = (int)(((i - numColorSuits) / (2 * numColorSuits)) + 1) ;
        string suit = UnoCard::_COLOR_SUITS.at(((i - numColorSuits) / 2) % numColorSuits);
        success = success && (card.rank() == rank); 
        success = success && (card.suit() == suit);
        UnoCard sameCard(suit, rank);
        success = success && (card == sameCard);
        success = success && (card <= sameCard);
        success = success && (card >= sameCard);
        PlayingCard& prevCard = *(deck.at(i-2));
        success = success && (prevCard != card);
        success = success && (prevCard < card);
        success = success && (prevCard <= card);
        success = success && (card > prevCard);
        success = success && (card >= prevCard);
    }

    // Handle wild cards
    for (i = 100; i < deckSize; i++) {
        PlayingCard& card = *(deck.at(i));
        cout << i << ": " << card.rank() << " " << card.suit() 
                << ": " << card.toString() << endl;
        // Integer division!
        int rank = (int)((i - 100) / 4) + UnoCard::_MAX_COLOR_RANK + 1;
        string suit = UnoCard::_WILD_SUIT;
        success = success && (card.rank() == rank); 
        success = success && (card.suit() == suit);
        UnoCard sameCard(suit, rank);
        success = success && (card == sameCard);
        success = success && (card <= sameCard);
        success = success && (card >= sameCard);
        PlayingCard& prevCard = *(deck.at(i-4));
        success = success && (prevCard != card);
        success = success && (prevCard < card);
        success = success && (prevCard <= card);
        success = success && (card > prevCard);
        success = success && (card >= prevCard);
    }

    return success;
}

int main() {
    cout << "Testing FrenchCard...";
    if (testFrenchCard()) {
        cout << "success" << endl;

        cout << endl;
        cout << "Testing UnoCard...";
        if (testUnoCard()) {
            cout << "success" << endl;
        }
        else {
            cout << "UnoCard FAILED!" << endl;
        }
    }
    else {
        cout << "FrenchCard FAILED!" << endl;
    }
}