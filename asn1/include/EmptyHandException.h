#ifndef EMPTYHANDEXCEPTION_H_INCLUDED
#define EMPTYHANDEXCEPTION_H_INCLUDED

#include <exception>

/**
 * An exception class to be thrown when we try to operate on an empty hand where it's
 * expected to not be empty.
 */
class EmptyHandException : public std::exception
{
public:
    /**
     * Constructs a new EmptyHandException.
     */
    EmptyHandException():std::exception() {};

    /**
     * Virtual destructor.
     */
    virtual ~EmptyHandException() {}

    /**
     * Generates an error message.
     *
     * @return A cstring of the error message.
     */
    virtual const char* what() const noexcept
    {
        return "EmptyHandException";
    }
};

#endif // EMPTYHANDEXCEPTION_H_INCLUDED
