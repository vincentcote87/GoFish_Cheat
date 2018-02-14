#ifndef TESTSTANDARDDECK_H_INCLUDED
#define TESTSTANDARDDECK_H_INCLUDED

#include <gtest/gtest.h>
#include <memory>
#include "../include/StandardDeck.h"

/**
 * A test fixture for decks, where a new, full standard deck of 52 standard
 * cards is constructed for each individual test case.
 */
class TestStandardDeck : public ::testing::Test
{
protected:
    /**
     * Constructs a new TestStandardDeck.
     */
    TestStandardDeck();

    /**
     * Virtual destructor.
     */
    virtual ~TestStandardDeck();

    /**
     * Setup for each test case in the fixture. Creates a new StandardDeck,
     * put in a new shared pointer for <code>_deck</code>.
     */
    virtual void SetUp();

    /**
     * Tear down for each test case in the fixture. Resets the <code>_deck</code>
     * shared pointer.
     */
    virtual void TearDown();

    /**
     * A new, full deck of 52 standard cards which is used for test cases.
     */
    std::shared_ptr<StandardDeck> _deck;
};

#endif // TESTSTANDARDDECK_H_INCLUDED
