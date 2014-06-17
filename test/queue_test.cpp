#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "../include/queue.hpp"

TEST_CASE( "Queue", "[queue]" )
{
	Queue<int> queue = Queue<int>();

	// size after initialization should be zero
	REQUIRE( queue.size()  == 0 );
	REQUIRE( queue.empty() == true );

	queue.push( 5 );
	REQUIRE( queue.size()  == 1 );
	REQUIRE( queue.empty() == false );

	queue.push( 4 );
	REQUIRE( queue.size()  == 2 );

	REQUIRE( queue.front() == 5 );
	REQUIRE( queue.back()  == 4 );

	REQUIRE( queue.pop()   == 5 );
	REQUIRE( queue.size()  == 1 );
}