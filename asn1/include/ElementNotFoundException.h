#ifndef ELEMENTNOTFOUNDEXCEPTION_H_INCLUDED
#define ELEMENTNOTFOUNDEXCEPTION_H_INCLUDED

#include <exception>

/**
 * An exception class to be thrown when we try to operate on a collection with an element which
 * is not able to be found (not in the collection).
 */
class ElementNotFoundException : public std::exception
{
public:
    /**
     * Constructs a new ElementNotFoundException.
     */
    ElementNotFoundException():std::exception() {};

    /**
     * Virtual destructor.
     */
    virtual ~ElementNotFoundException() {}

    /**
     * Generates an error message.
     *
     * @return A cstring of the error message.
     */
    virtual const char* what() const noexcept
    {
        return "ElementNotFoundException";
    }
};

#endif // ELEMENTNOTFOUNDEXCEPTION_H_INCLUDED
