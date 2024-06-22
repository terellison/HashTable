// Main driver / test code

#include <iostream>
#include "HashTable.h"

int main()
{
	HashTable table = HashTable();

	std::string val = "Hello";

	table.Add(val);

	if (!table.Contains(val))
	{
		throw;
	}

	auto tableTwo = new HashTable(table);

	return 0;
}