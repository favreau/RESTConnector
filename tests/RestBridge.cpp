
/* Copyright (c) 2015, Human Brain Project
 *                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 */

#define BOOST_TEST_MODULE restZeqTranslator

#include <boost/test/unit_test.hpp>
#include <restbridge/RestBridge.h>

#include <lunchbox/rng.h>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<unsigned long long> dis(0,60000);

BOOST_AUTO_TEST_CASE( test_construction )
{
    BOOST_CHECK_NO_THROW( restbridge::RestBridge( "localhost", 12345 ));
}

BOOST_AUTO_TEST_CASE( test_invalid_run )
{
    const unsigned short port =  dis(gen) + 1024;
    restbridge::RestBridge bridge( "localhost", port );
    bridge.run( "bla" );
    BOOST_CHECK_THROW( bridge.run( "blub" ), std::runtime_error );
}

BOOST_AUTO_TEST_CASE( test_invalid_stop )
{
    const unsigned short port =  dis(gen) + 1024;
    restbridge::RestBridge bridge( "localhost", port );
    BOOST_CHECK_THROW( bridge.stop(), std::runtime_error );
}

BOOST_AUTO_TEST_CASE( test_run_stop )
{
    const unsigned short port =  dis(gen) + 1024;
    restbridge::RestBridge bridge( "localhost", port );
    bridge.run( "bla" );
    bridge.stop();
}
