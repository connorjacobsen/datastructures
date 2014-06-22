#ifndef _KEY_VALUE_PAIR_HPP_
#define _KEY_VALUE_PAIR_HPP_

template <typename T>
class KeyValuePair
{
public:
	std::string key;
	T value;
	bool free;
	bool deleted;

	KeyValuePair() : key(""), free(true), deleted(false) {}
	KeyValuePair( std::string key, T value ) : key(key), value(value), free(true), deleted(false) {}
};

#endif // _KEY_VALUE_PAIR_HPP_