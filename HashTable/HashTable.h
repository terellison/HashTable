#include "Pair.h"
#include <vector>
#include <string>

#pragma once

#define U_INT unsigned int

class HashTable
{
private:
	std::vector<Pair<U_INT, std::string>>* buckets;
	size_t bucketCount;
	U_INT Hash(const std::string& val) const;
public:
	size_t Size() const;
	void Add(const std::string& val);
	HashTable();
	HashTable(const HashTable& other);
	bool Contains(const std::string& val) const;
	~HashTable();
};
