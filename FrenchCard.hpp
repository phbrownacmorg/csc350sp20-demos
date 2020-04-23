#ifndef _FRENCH_CARD_H
#define _FRENCH_CARD_H

#include <string>
#include <vector>
#include "PlayingCard.hpp"
using namespace std;

class FrenchCard : public PlayingCard {
    
    public:
        // Class constants (static means class not instance, const means they're constants)
        static const vector<string> _SUITS;
        static const vector<string> _RANK_NAMES;
        static const int _MIN_RANK;
        static const int _MAX_RANK;

        // Constructor is public this time.  You can actually make these.
        FrenchCard(string suit, int rank);

        // Virtual access to constants
        virtual const int MIN_RANK() const;
        virtual const vector<string> RANK_NAMES() const;
        virtual const vector<string> SUITS() const;

        // Query method, marked as const to promise that it won't change the object
        virtual string toString() const;
    
        // Class method to make a deck of these things
        static vector<PlayingCard*> makeDeck();
};



#endif
