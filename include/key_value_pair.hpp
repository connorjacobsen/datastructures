#ifndef _KEY_VALUE_PAIR_HPP_
#define _KEY_VALUE_PAIR_HPP_

template <typename T>
class KeyValuePair
{
public:
	std::string key;
	T value;
	bool free;

	KeyValuePair() : key(""), free(true) {}
	KeyValuePair( std::string key, T value ) : key(key), value(value), free(true) {}
};

#endif // _KEY_VALUE_PAIR_HPP_