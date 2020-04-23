#include "UnoCard.hpp"
#include <algorithm>
#include <cassert>

const vector<string> UnoCard::_SUITS { "Blue", "Green", "Red", "Yellow", "Wild" };
const vector<string> UnoCard::_COLOR_SUITS(_SUITS.begin(), _SUITS.begin() + 4);
const string UnoCard::_WILD_SUIT = _SUITS.at(4);
const vector<string> UnoCard::_RANK_NAMES 
    { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Skip", "Reverse", "Draw 2", "Draw 4", ""};
const int UnoCard::_MAX_COLOR_RANK = _RANK_NAMES.size() - 3;

bool UnoCard::_invariant() const {
    // Rank is valid?
    bool valid = this->rank() >= this->MIN_RANK() && this->rank() <= this->MAX_RANK();

    // Suit is valid?
    if (this->rank() > _MAX_COLOR_RANK) { // One of the wild ranks
        valid = valid && this->suit() == _WILD_SUIT;
    }
    else {
        // rank is one of the color ranks, so this->suit() in _COLOR_SUITS
        valid = valid &&
            (find(_COLOR_SUITS.begin(), _COLOR_SUITS.end(), this->suit()) != _COLOR_SUITS.end());
    }
    return valid;
}

UnoCard::UnoCard(string suit, int rank) : PlayingCard(suit, rank) {
    // Calls PlayingCard's constructor *first*
    // Doesn't do anything else
    // Postcondition:
    assert(this->_invariant());
}

const vector<string> UnoCard::RANK_NAMES() const {
    return _RANK_NAMES;
}

const vector<string> UnoCard::SUITS() const {
    return _SUITS;
}

string UnoCard::toString() const {
    if (this->rank() == this->MAX_RANK()) { // straight Wild, no rank part
        return this->suit();
    }
    else {
        return PlayingCard::toString(); // Call the superclass method
    }
}

vector<PlayingCard*> UnoCard::makeDeck() {
    vector<PlayingCard*> deck;
    
    int rank = 0;
    for (vector<string>::const_iterator suit = _COLOR_SUITS.cbegin(); suit != _COLOR_SUITS.cend(); suit++) {
        deck.push_back(new UnoCard(*suit, rank));
    }

    for (rank = 1; rank <= _MAX_COLOR_RANK; rank++) {
        for (vector<string>::const_iterator suit = _COLOR_SUITS.cbegin(); suit != _COLOR_SUITS.cend(); suit++) {
            for (int i = 0; i < 2; i++) {
                deck.push_back(new UnoCard(*suit, rank));
            }
        }
    }

    // Wild cards
    for (rank = _MAX_COLOR_RANK + 1; rank < static_cast<int>(_RANK_NAMES.size()); rank++) {
        for (int i = 0; i < 4; i++) {
                deck.push_back(new UnoCard(_WILD_SUIT, rank));
        }
    }

    return deck;
}
