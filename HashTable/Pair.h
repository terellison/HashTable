#pragma once
template<typename Key, typename Value>
struct Pair
{
	Key key;
	Value value;

	Pair(const Key& key, const Value& value)
	{
		this->key = key;
		this->value = value;
	}

	Pair(const Pair& other)
	{
		this->key = other.key;
		this->value = other.value;
	}

	bool operator==(const Pair& other)
	{
		return (this->key == other.key) && (this->value == other.value);
	}
};