#include "HashSet.h";

// hashing function f(x) = (multiplier * x + offset) % size, where p1 and p2 are primes 
int hash(int value, int size) {
	long long multiplier = 47;
	long long offset = 197;

	return abs(multiplier * value + offset) % size;
}

void incrementCycleArrayIndex(int& index, int size) {
	index++;
	if (index == size) {
		index = 0;
	}
}

HashSet::HashSet(const std::vector<int>& storage) {
	capacity_ = 2 * storage.size();
	storage_.resize(capacity_);
	isCellEmpty_.resize(capacity_);

	std::fill(isCellEmpty_.begin(), isCellEmpty_.end(), true);

	for (int value : storage) {
		insert(value);
	}
}


bool HashSet::insert(int value) {
	int index = hash(value, capacity_);

	while (!isCellEmpty_[index]) {
		if (storage_[index] == value) {
			return false;
		}

		incrementCycleArrayIndex(index, capacity_);
	}

	storage_[index] = value;
	isCellEmpty_[index] = false;

	return true;
}

bool HashSet::contains(int value) {
	int index = hash(value, capacity_);

	while (!isCellEmpty_[index]) {
		if (storage_[index] == value) {
			return true;
		}

		incrementCycleArrayIndex(index, capacity_);
	}

	return false;
}