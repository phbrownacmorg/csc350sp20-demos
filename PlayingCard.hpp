#ifndef _PLAYING_CARD_H
#define _PLAYING_CARD_H
/* The frog guts scattered above are preprocessor directives to keep this
    file from being read more than once in the course of a single
    compilation.
*/
#include <vector>
#include <string>
using namespace std;


class PlayingCard {
    /*
        Class to represent a playing card of a type that is defined by
        rank and suit.  Cards are immutable once created.
    */
    
    protected:
        int _rank;
        string _suit;

        // Protected constructor, so PlayingCard can't be instantiated directly
        PlayingCard(string suit, int rank);
    
        // Query methods
        virtual bool _invariant() const; 
    
    public:
        // Access to class constants
        virtual const int MIN_RANK() const;
        virtual const int MAX_RANK() const;

        // =0 makes this a pure virtual function, which makes PlayingCard an abstract class
        virtual const vector<string> RANK_NAMES() const =0;
        virtual const vector<string> SUITS() const =0;

        // Query methods,followed by const to tell the compiler they don't change the object
        virtual string suit() const;
        virtual int rank() const;
        virtual string rankName() const;
        virtual string toString() const;
        // More query methods, doing operator overriding
        virtual bool operator==(const PlayingCard& othercard) const;
        virtual bool operator<(const PlayingCard& othercard) const;
        virtual bool operator<=(const PlayingCard& othercard) const;
        virtual bool operator!=(const PlayingCard& othercard) const;
        virtual bool operator>(const PlayingCard& othercard) const;
        virtual bool operator>=(const PlayingCard& othercard) const;

        // Immutable object, so no mutator methods
};

#endif
/* Nothing goes down here. */
