#include "FrenchCard.hpp"
#include <cassert>

const vector<string> FrenchCard::_SUITS { "Clubs", "Diamonds", "Hearts", "Spades" };
const vector<string> FrenchCard::_RANK_NAMES 
    { "(unused)", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack", "Queen", "King"};
const int FrenchCard::_MIN_RANK = 1;
const int FrenchCard::_MAX_RANK = _RANK_NAMES.size() - 1;

FrenchCard::FrenchCard(string suit, int rank) : PlayingCard(suit, rank) {
    // Calls PlayingCard's constructor *first*
    // Doesn't do anything else
    // Postcondition:
    assert(this->_invariant());
}

const int FrenchCard::MIN_RANK() const {
    return _MIN_RANK;
}

const vector<string> FrenchCard::RANK_NAMES() const {
    return _RANK_NAMES;
}

const vector<string> FrenchCard::SUITS() const {
    return _SUITS;
}

string FrenchCard::toString() const {
    return this->rankName() + " of " + this->suit();
}

vector<PlayingCard*> FrenchCard::makeDeck() {
    vector<PlayingCard*> deck;
    
    for (int rank = _MIN_RANK; rank <= _MAX_RANK; rank++) {
        for (vector<string>::const_iterator suit = _SUITS.cbegin(); suit != _SUITS.cend(); suit++) {
            deck.push_back(new FrenchCard(*suit, rank));   
        }
    }
    
    return deck;
}
