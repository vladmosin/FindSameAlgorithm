#pragma once

#include <vector>

/* This HashSet is especially for FindSameAlgorithm, so not all methods of library set were implemented */
class HashSet {
private:
	int capacity_;
	std::vector<int> storage_;
	std::vector<bool> isCellEmpty_;
public:
	HashSet(const std::vector<int>& storage);
	bool contains(int value);
	bool insert(int value); // Returns true, if HashSet does not contain value before
};