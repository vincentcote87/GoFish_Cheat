#ifndef OUTOFBOUNDSEXCEPTION_H_INCLUDED
#define OUTOFBOUNDSEXCEPTION_H_INCLUDED

#include <exception>

/**
 * An exception class which is to be thrown when we try to perform an operation
 * where the index is not in the range of some array/list/other.
 */
class OutOfBoundsException : public std::exception
{
public:
    /**
     * Constructs a new OutOfBoundsException.
     *
     * @param index The index which was used upon throwing this exception.
     * @param lb The lower bound of the range (inclusive).
     * @param ub The upper bound of the range (exclusive).
     */
    OutOfBoundsException(unsigned int index, unsigned int lb, unsigned int ub):
        std::exception(),_index(index),_lb(lb),_ub(ub) {}

    /**
     * Virtual destructor.
     */
    virtual ~OutOfBoundsException() {}

    /**
     * Gets the index which was used upon throwing this exception.
     *
     * @return The index which was either less than the lower bound, or greater
     *         (inclusive) than or equal to the upper bound (exclusive).
     */
    virtual unsigned int getIndex()
    {
        return this->_index;
    }

    /**
     * Gets the valid lower bound of the range tried upon throwing this exception.
     *
     * @return The lower bound (inclusive).
     */
    virtual unsigned int getLowerBound()
    {
        return this->_lb;
    }

    /**
     * Gets the valid upper bound of the range tried upon throwing this exception.
     *
     * @return The upper bound (exclusive).
     */
    virtual unsigned int getUpperBound()
    {
        return this->_ub;
    }

    /**
     * Generates an error message.
     *
     * @return A cstring of the error message.
     */
    virtual const char* what() const noexcept
    {
        return "OutOfBoundsException";
    }
private:
    /**
     * The index.
     */
    unsigned int _index;

    /**
     * The lower bound.
     */
    unsigned int _lb;

    /**
     * The upper bound.
     */
    unsigned int _ub;
};

#endif // OUTOFBOUNDSEXCEPTION_H_INCLUDED
