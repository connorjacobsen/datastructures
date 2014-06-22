#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include "key_value_pair.hpp"

template <typename T>
class Map
{
public:
	KeyValuePair<T>* map;
	unsigned int map_array_size;
	unsigned int map_size = 0;

	// Default constructor.
	explicit Map()
	{
		KeyValuePair<T>* tmp = new KeyValuePair<T>[ 50 ];
		map_array_size = 50;
		map = tmp;
	}

	explicit Map( unsigned int initial_size )
	{
		KeyValuePair<T>* tmp = new KeyValuePair<T>[ initial_size ];
		map_array_size = initial_size;
		map = tmp;
	}

	// Resize the map array - doubles the previous Map size.
	void realloc()
	{
		KeyValuePair<T>* tmp = new KeyValuePair<T>[ map_array_size * 2 ];
		for( int i = 0; i < map_array_size; i++ ) {
			tmp[ i ] = map[ i ];
		}
		map = tmp;
		map_array_size = map_array_size * 2;
	}

	// Returns the size of the Map.
	unsigned int size()
	{
		return map_size;
	}

	// Returns true if the Map is empty, false otherwise.
	bool empty()
	{
		return map_size == 0;
	}

	// Returns true if the current map array is full, false otherwise.
	bool full()
	{
		return map_size == map_array_size;
	}

	// Insert a key, value pair into the Map.
	//
	// Inserts the key, value pair into the first available slot in the Map.
	void insert( std::string key, T value )
	{
		if( full() ) {
			// if the map is full, increase the Map size
			realloc();
		}
		for( int i = 0; i < map_array_size; i++ ) {
			if( map[ i ].free == true ) {
				// found a free string
				map[ i ].key = key;
				map[ i ].value = value;
				map[ i ].free = false;
				++map_size;
				break;
			}
		}
	}

	// Remove the first occurrence of the given key in the Map.
	void remove( std::string key )
	{
		for( int i = 0; i < map_size; i++ ) {
			if( map[ i ].key == key ) {
				map[ i ].deleted = true;
				map[ i ].free    = true;
				--map_size;
				break;
			}
		}
	}

	// Returns true if the Map contains the given key, false otherwise.
	bool contains( std::string key )
	{
		for( int i = 0; i < map_size; i++ ) {
			if( map[ i ].key == key )
				return true;
		}
		return false;
	}

	// Returns the value for the given key.
	T get( std::string key )
	{
		for( int i = 0; i < map_size; i++ ) {
			if( map[ i ].key == key )
				return map[ i ].value;
		}
	}
};

#endif // _MAP_HPP_
