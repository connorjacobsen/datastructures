#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "../include/stack.hpp"
#include "../include/queue.hpp"
#include "../include/linked_list.hpp"
#include "../include/map.hpp"

TEST_CASE( "Stack", "[stack]" )
{
	Stack<int> stack = Stack<int>();

	/* #size() returns 0 after initialization */
	REQUIRE( stack.empty() == true );

	stack.push( 5 );
	REQUIRE( stack.empty() == false );
	REQUIRE( stack.size()  == 1 );

	stack.push(6);
	REQUIRE( stack.top()   == 6 );
	REQUIRE( stack.size()  == 2 );

	REQUIRE( stack.pop()   == 6 );
	REQUIRE( stack.size()  == 1 );
	REQUIRE( stack.pop()   == 5 );
	REQUIRE( stack.size()  == 0 );
}

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

TEST_CASE( "LinkedList prepend", "[linked_list - prepend]" )
{
	LinkedList<int> linked_list = LinkedList<int>();

	// after initialization *head and *tail should be nullptrs
	REQUIRE( linked_list.empty() == true );

	linked_list.prepend( 42 );
	REQUIRE( linked_list.empty() == false );
}

TEST_CASE( "LinkedList append empty list", "[linked_list - append empty]" )
{
	LinkedList<int> linked_list = LinkedList<int>();

	// after initialization *head and *tail should be nullptrs
	REQUIRE( linked_list.empty() == true );

	linked_list.append( 42 );
	REQUIRE( linked_list.empty() == false );
}

TEST_CASE( "LinkedList append non-empty list", "[linked_list - append non-empty]")
{
	LinkedList<int> linked_list = LinkedList<int>();

	// after initialization *head and *tail should be nullptrs
	REQUIRE( linked_list.empty() == true );

	linked_list.append( 42 );
	REQUIRE( linked_list.empty() == false );

	linked_list.append( 13 );
	REQUIRE( linked_list.length() == 2 );
}

TEST_CASE( "LinkedList decapitate", "[linked_list - decapitate]" )
{
	LinkedList<int> linked_list1 = LinkedList<int>();
	LinkedList<int> linked_list2 = LinkedList<int>();

	// list with one item
	linked_list1.prepend( 42 );
	REQUIRE( linked_list1.empty() == false );
	REQUIRE( linked_list1.decapitate() == 42 );
	REQUIRE( linked_list1.empty() == true );

	// list with multiple items
	linked_list2.prepend( 42 );
	linked_list2.prepend( 13 );
	REQUIRE( linked_list2.length() == 2 );
	REQUIRE( linked_list2.decapitate() == 13 );
	REQUIRE( linked_list2.length() == 1 );
}

TEST_CASE( "LinkedList decaudate", "[linked_list - decaudate]" )
{
	LinkedList<int> linked_list1 = LinkedList<int>();
	LinkedList<int> linked_list2 = LinkedList<int>();

	// list with one item
	linked_list1.prepend( 42 );
	REQUIRE( linked_list1.empty() == false );
	REQUIRE( linked_list1.decaudate() == 42 );
	REQUIRE( linked_list1.empty() == true );

	// list with multiple items
	linked_list2.prepend( 42 );
	linked_list2.prepend( 13 );
	REQUIRE( linked_list2.length() == 2 );
	REQUIRE( linked_list2.decaudate() == 42 );
	REQUIRE( linked_list2.length() == 1 );
}

TEST_CASE( "LinkedList contains", "[linked_list - contains]" )
{
	LinkedList<int> linked_list = LinkedList<int>();
	linked_list.prepend( 42 );
	linked_list.append( 13 );
	linked_list.prepend( 29 );
	linked_list.append( 7 );

	REQUIRE( linked_list.contains( 1 )   == false );
	REQUIRE( linked_list.contains( 42 )  == true );
	REQUIRE( linked_list.contains( 21 )  == false );
	REQUIRE( linked_list.contains( 13 )  == true );
	REQUIRE( linked_list.contains( 16 )  == false );
	REQUIRE( linked_list.contains( 7 )   == true );
	REQUIRE( linked_list.contains( 99 )   == false );
	REQUIRE( linked_list.contains( 29 )  == true );
}

TEST_CASE( "LinkedList indexOf", "[linked_list - indexOf]" )
{
	LinkedList<int> linked_list = LinkedList<int>();
	linked_list.prepend( 4 );
	linked_list.prepend( 3 );
	linked_list.prepend( 2 );
	linked_list.prepend( 1 );

	REQUIRE( linked_list.indexOf( 4 )  == 3 );
	REQUIRE( linked_list.indexOf( 3 )  == 2 );
	REQUIRE( linked_list.indexOf( 2 )  == 1 );
	REQUIRE( linked_list.indexOf( 1 )  == 0 );
	REQUIRE( linked_list.indexOf( 42 ) == -1 );
}

TEST_CASE( "LinkedList itemAt{Head, Tail}", "[linked_list - itemAt{Head, Tail}]" )
{
	LinkedList<int> linked_list = LinkedList<int>();
	linked_list.prepend( 4 );
	linked_list.prepend( 3 );
	linked_list.prepend( 2 );
	linked_list.prepend( 1 );

	REQUIRE( linked_list.itemAtHead() == 1 );
	REQUIRE( linked_list.itemAtTail() == 4 );
}

TEST_CASE( "LinkedList itemAtIndex", "[linked_list - itemAtIndex]" )
{
	LinkedList<int> linked_list = LinkedList<int>();
	linked_list.prepend( 4 );
	linked_list.prepend( 3 );
	linked_list.prepend( 2 );
	linked_list.prepend( 1 );

	REQUIRE( linked_list.itemAtIndex( 3 ) == 4 );
	REQUIRE( linked_list.itemAtIndex( 2 ) == 3 );
	REQUIRE( linked_list.itemAtIndex( 1 ) == 2 );
	REQUIRE( linked_list.itemAtIndex( 0 ) == 1 );
	REQUIRE( linked_list.itemAtIndex( 33 ) == 4 );
}

TEST_CASE( "LinkedList insertAt", "[linked_list - insertAt]" )
{
	LinkedList<int> linked_list = LinkedList<int>();
	linked_list.prepend( 4 );
	linked_list.prepend( 3 );
	linked_list.prepend( 2 );
	linked_list.prepend( 1 );

	linked_list.insertAt( 42, 3 );
	REQUIRE( linked_list.length() == 5 );
	REQUIRE( linked_list.itemAtIndex( 0 ) == 1 );
	REQUIRE( linked_list.itemAtIndex( 1 ) == 2 );
	REQUIRE( linked_list.itemAtIndex( 2 ) == 3 );
	REQUIRE( linked_list.itemAtIndex( 3 ) == 42 );
	REQUIRE( linked_list.itemAtIndex( 4 ) == 4 );
}

TEST_CASE( "LinkedList removeAt", "[linked_list - removeAt]" )
{
	LinkedList<int> linked_list = LinkedList<int>();
	linked_list.prepend( 4 );
	linked_list.prepend( 3 );
	linked_list.prepend( 2 );
	linked_list.prepend( 1 );

	REQUIRE( linked_list.length() == 4 );
	REQUIRE( linked_list.removeAt(2) == 3 );
	REQUIRE( linked_list.length() == 3 );
	REQUIRE( linked_list.removeAt( 5 ) == 4 );
	REQUIRE( linked_list.length() == 2 );
	REQUIRE( linked_list.removeAt( 0 ) == 1 );
	REQUIRE( linked_list.length() == 1 );
	REQUIRE( linked_list.removeAt( 0 ) == 2 );
	REQUIRE( linked_list.length() == 0 );
}

TEST_CASE( "Map", "[map]" )
{
	Map<std::string> map = Map<std::string>( 50 );

	REQUIRE( map.size() == 0 );
	REQUIRE( map.map_array_size == 50 );
	REQUIRE( map.map_size == 0 );

	// resize the map_array
	map.realloc();
	REQUIRE( map.map_array_size == 100 );

	// map should be empty
	REQUIRE( map.empty() == true );

	// map should not be full
	REQUIRE( map.full()  == false );
}

TEST_CASE( "Map - Insert", "[map - insert]" )
{
	Map<std::string> map = Map<std::string>( 50 );

	REQUIRE( map.size() == 0 );
	// REQUIRE( map.map[ 0 ].key == "" );
	map.insert( "hello", "world" );
	REQUIRE( map.size() == 1 );
}

TEST_CASE( "Map - Remove", "[map - remove]" )
{
	Map<std::string> map = Map<std::string>( 20 );

	REQUIRE( map.size() == 0 );
	map.insert( "hello", "world" );
	REQUIRE( map.size() == 1 );
	map.insert( "name", "Connor" );
	REQUIRE( map.size() == 2 );
	map.remove( "name" );
	REQUIRE( map.size() == 1 );
}

TEST_CASE( "Map - Contains", "[map - contains]" )
{
	Map<std::string> map = Map<std::string>( 20 );

	map.insert( "hello", "world" );
	map.insert( "foo", "bar" );

	REQUIRE( map.contains( "foo" ) == true );
	REQUIRE( map.contains( "baz" ) == false );
}

TEST_CASE( "Map - Get", "[map - get]" )
{
	Map<std::string> map = Map<std::string>( 20 );

	map.insert( "hello", "world" );
	map.insert( "foo", "bar" );

	REQUIRE( map.get( "foo" ) == "bar" );
}
