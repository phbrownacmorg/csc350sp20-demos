#ifndef _UNO_CARD_H
#define _UNO_CARD_H

#include <string>
#include <vector>
#include "PlayingCard.hpp"
using namespace std;

class UnoCard : public PlayingCard {
    protected:
        virtual bool _invariant() const;
    
    public:
        // Class constants (static means class not instance, const means they're constants)
        static const vector<string> _SUITS;
        static const vector<string> _COLOR_SUITS;
        static const string _WILD_SUIT;
        static const vector<string> _RANK_NAMES;
        static const int _MAX_COLOR_RANK;

        // Constructor is public this time.  You can actually make these.
        UnoCard(string suit, int rank);

        // Virtual access to constants
        virtual const vector<string> RANK_NAMES() const;
        virtual const vector<string> SUITS() const;

        // Query method, marked as const to promise that it won't change the object
        virtual string toString() const;
    
        // Class method to make a deck of these things
        static vector<PlayingCard*> makeDeck();
};



#endif
