#ifndef TESTSTANDARDHAND_H_INCLUDED
#define TESTSTANDARDHAND_H_INCLUDED

#include "../include/StandardHand.h"

using std::shared_ptr;

class TestStandardHand : public ::testing::Test
{
protected:
    /**
     * Constructs a new TestStandardHand.
     */
    TestStandardHand();

    /**
     * Virtual destructor.
     */
    virtual ~TestStandardHand();

    /**
     * Setup for each test case in the fixture. Creates a new StandardHand,
     * put in a new shared pointer for <code>_hand</code>.
     */
    virtual void SetUp();

    /**
     * Tear down for each test case in the fixture. Resets the <code>_hand</code>
     * shared pointer.
     */
    virtual void TearDown();

    /**
     * A new, empty hand of standard cards which is used for test cases.
     */
    shared_ptr<StandardHand> _hand;

    shared_ptr<StandardCard> _ace_hearts;

    shared_ptr<StandardCard> _ace_spades;
};

#endif // TESTSTANDARDHAND_H_INCLUDED
