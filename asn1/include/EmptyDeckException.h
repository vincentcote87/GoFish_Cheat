#ifndef EMPTYDECKEXCEPTION_H_INCLUDED
#define EMPTYDECKEXCEPTION_H_INCLUDED

#include <exception>

/**
 * An exception class to be thrown when we try to operate on an empty deck where it's
 * expected to not be empty.
 */
class EmptyDeckException : public std::exception
{
public:
    /**
     * Constructs a new EmptyDeckException.
     */
    EmptyDeckException():std::exception() {};

    /**
     * Virtual destructor.
     */
    virtual ~EmptyDeckException() {}

    /**
     * Generates an error message.
     *
     * @return A cstring of the error message.
     */
    virtual const char* what() const noexcept
    {
        return "EmptyDeckException";
    }
};

#endif // EMPTYDECKEXCEPTION_H_INCLUDED
