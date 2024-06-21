#include "Pair.h"
#include <vector>
#include <string>
#pragma once
class HashTable
{
private:
	std::vector<Pair<float, std::string>>* buckets;
	size_t bucketNum;
	unsigned int Hash(const std::string& val) const;
public:
	size_t Size() const;
	void Add(const std::string& val);
	HashTable(size_t& size);
	HashTable(const HashTable& other);
	~HashTable();
};
