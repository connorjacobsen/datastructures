#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "../include/stack.hpp"

TEST_CASE( "Constructors work correctly", "[stack constructor]" ) 
{
	Stack<int> stack = Stack<int>();

	REQUIRE( stack.storage.size() == 0 );
}

TEST_CASE( "Size", "[size]" )
{
	Stack<int> stack = Stack<int>();

	/* #size() returns 0 after initialization */
	REQUIRE( stack.size() == 0 );
}

TEST_CASE( "Empty", "[empty]" )
{
	Stack<int> stack = Stack<int>();

	/* #size() returns 0 after initialization */
	REQUIRE( stack.empty() == true );
}

TEST_CASE( "Top", "[top]" )
{
	Stack<int> stack = Stack<int>();
	stack.push( 1 );
	stack.push( 2 );
	stack.push( 3 );

	REQUIRE( stack.size() == 3 );
	REQUIRE( stack.top()  == 3 );
	REQUIRE( stack.size() == 3 );
}

TEST_CASE( "Push", "[push]" )
{
	Stack<int> stack = Stack<int>();

	/* #size() returns 0 after initialization */
	REQUIRE( stack.empty() == true );

	stack.push( 5 );
	REQUIRE( stack.empty() == false );
	REQUIRE( stack.size()  == 1 );
}

TEST_CASE( "Pop", "[pop]" )
{
	Stack<int> stack = Stack<int>();

	/* #size() returns 0 after initialization */
	REQUIRE( stack.empty() == true );

	stack.push( 5 );
	REQUIRE( stack.empty() == false );
	REQUIRE( stack.size()  == 1 );

	stack.push(6);
	REQUIRE( stack.size()  == 2 );

	REQUIRE( stack.pop()  == 6 );
	REQUIRE( stack.size() == 1 );
	REQUIRE( stack.pop()  == 5 );
	REQUIRE( stack.size() == 0 );
}