#include "PlayingCard.hpp"
#include <algorithm>
#include <sstream>
// Use quotation marks to include something in the current directory
bool PlayingCard::_invariant() const {
    // Rank is valid
    bool valid = this->rank() >= this->MIN_RANK() && this->rank() <= this->MAX_RANK();

    // this->suit() in _SUITS
    const vector<string> _SUITS = this->SUITS();
    valid = valid && (find(_SUITS.begin(), _SUITS.end(), this->suit()) != _SUITS.end());
    return valid;
}

PlayingCard::PlayingCard(string suit, int rank) {
    this->_suit = suit;
    this->_rank = rank;
}

const int PlayingCard::MIN_RANK() const {
    return 0;
}

const int PlayingCard::MAX_RANK() const {
    return this->RANK_NAMES().size() - 1;
}

string PlayingCard::suit() const {
    return this->_suit;
}

int PlayingCard::rank() const {
    return this->_rank;
}

string PlayingCard::rankName() const {
    return this->RANK_NAMES().at(this->rank());
}

string PlayingCard::toString() const {
    return this->suit() + ' ' + this->rankName();
}

bool PlayingCard::operator==(const PlayingCard& othercard) const {
    return this->suit() == (&othercard)->suit() && this->rank() == (&othercard)->rank();
}

bool PlayingCard::operator<(const PlayingCard& othercard) const {
    return (this->rank() < (&othercard)->rank()) ||
        ((this->rank() == (&othercard)->rank()) && (this->suit() < (&othercard)->suit()));
}

bool PlayingCard::operator<=(const PlayingCard& othercard) const {
    return (*this == othercard) || (*this < othercard);
}

bool PlayingCard::operator!=(const PlayingCard& othercard) const {
    return !(*this == othercard);
}

bool PlayingCard::operator>(const PlayingCard& othercard) const {
    return (!(*this == othercard)) && (!(*this < othercard));
}

bool PlayingCard::operator>=(const PlayingCard& othercard) const {
    return !(*this < othercard);
}