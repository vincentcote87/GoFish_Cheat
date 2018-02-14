#ifndef CARDALREADYINDECKEXCEPTION_H_INCLUDED
#define CARDALREADYINDECKEXCEPTION_H_INCLUDED

#include <exception>

/**
 * An exception class to be thrown when we try to add a card which is
 * already in the deck.
 */
class CardAlreadyInDeckException : public std::exception
{
public:
    /**
     * Constructs a new CardAlreadyInDeckException.
     */
    CardAlreadyInDeckException():std::exception() {}

    /**
     * Virtual destructor.
     */
    virtual ~CardAlreadyInDeckException() {}

    /**
     * Generates an error message.
     *
     * @return A cstring of the error message.
     */
    virtual const char* what() const noexcept
    {
        return "CardAlreadyInDeckException";
    }
};

#endif // CARDALREADYINDECKEXCEPTION_H_INCLUDED
