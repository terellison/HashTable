#include "HashTable.h"
#include <ctime>

U_INT HashTable::Hash(const std::string& val) const
{
    auto _f = 0.0f;

    for (auto i = val.begin(); i != val.end(); ++i)
    {
        _f = (_f * 10) + (*i - '0');
    }

    auto hash = static_cast<U_INT>(std::hash<float>()(_f));

    return hash;
}

size_t HashTable::Size() const
{
    return this->bucketCount;
}

void HashTable::Add(const std::string& val)
{
    auto hash = this->Hash(val);
    auto bucketNum = hash % this->bucketCount;

    auto& bucket = this->buckets[bucketNum];

    auto newEntry = Pair<U_INT, std::string>(hash, val);

    bucket.push_back(newEntry);
}

HashTable::HashTable()
{
    std::srand((unsigned)std::time(0));
    this->bucketCount = (static_cast<size_t>(std::rand() % 13)) + 1;
    this->buckets = new std::vector<Pair<U_INT, std::string>>[bucketCount];
}

HashTable::HashTable(const HashTable& other)
{
}

bool HashTable::Contains(const std::string& val) const
{
    bool contains = false;
    
    auto hash = this->Hash(val);
    auto bucketNum = hash % this->bucketCount;

    auto pair = Pair<unsigned int, std::string>{ hash, val };

    auto& bucket = this->buckets[bucketNum];

    for (auto i = bucket.begin(); i != bucket.end(); ++i)
    {
        if (*i == pair)
        {
            contains = true;
            break;
        }
    }

    return contains;
}

HashTable::~HashTable()
{
    delete[] this->buckets;
    this->buckets = nullptr;
}
