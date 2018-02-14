#ifndef CARDALREADYINHANDEXCEPTION_H_INCLUDED
#define CARDALREADYINHANDEXCEPTION_H_INCLUDED

#include <exception>

/**
 * An exception class to be thrown when we try to add a card which is
 * already in the hand.
 */
class CardAlreadyInHandException : public std::exception
{
public:
    /**
     * Constructs a new CardAlreadyInHandException.
     */
    CardAlreadyInHandException():std::exception() {}

    /**
     * Virtual destructor.
     */
    virtual ~CardAlreadyInHandException() {}

    /**
     * Generates an error message.
     *
     * @return A cstring of the error message.
     */
    virtual const char* what() const noexcept
    {
        return "CardAlreadyInHandException";
    }
};


#endif // CARDALREADYINHANDEXCEPTION_H_INCLUDED
