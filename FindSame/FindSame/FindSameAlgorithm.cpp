#include "FindSameAlgorithm.h"
#include "HashSet.h"
#include <algorithm>
#include <iostream>

enum SizeOrder {
	MIN_SIZE, MAX_SIZE
};

const std::vector<int>& chooseVector(const std::vector<int>& firstArray,
	const std::vector<int>& secondArray, SizeOrder order) {
	bool isFirstSmaller = firstArray.size() < secondArray.size();
	bool isFindingSmaller = order == MIN_SIZE;

	if ((isFirstSmaller && isFindingSmaller) || (!isFindingSmaller && !isFirstSmaller)) {
		return firstArray;
	}
	else
	{
		return secondArray;
	}
}

int FindSameAlgorithm::findSameNumber(const std::vector<int>& firstArray, 
	const std::vector<int>& secondArray, const AlgorithmType algorithmType) {
	switch (algorithmType)
	{
	case WITH_LIBRARY_SET:
		return algorithmWithLibrarySet(firstArray, secondArray);
	case WITH_HASHSET:
		return algorithmWithHashSet(firstArray, secondArray);
	case SORTING:
		return algorithmSorting(firstArray, secondArray);
	}
}

int FindSameAlgorithm::algorithmWithLibrarySet(const std::vector<int>& firstArray,
											   const std::vector<int>& secondArray) {
	if (firstArray.size() == 0 || secondArray.size() == 0) {
		return 0;
	}
	
	std::unordered_set<int> arrayElements;
	std::vector<int> smallArray = chooseVector(firstArray, secondArray, MIN_SIZE);
	std::vector<int> bigArray = chooseVector(firstArray, secondArray, MAX_SIZE);

	for (int element : smallArray) {
		arrayElements.insert(element);
	}

	int numberOfSameElements = 0;

	for (int element : bigArray) {
		numberOfSameElements += arrayElements.count(element);
	}

	return numberOfSameElements;
}

int FindSameAlgorithm::algorithmWithHashSet(const std::vector<int>& firstArray,
											const std::vector<int>& secondArray) {
	if (firstArray.size() == 0 || secondArray.size() == 0) {
		return 0;
	}

	std::vector<int> smallArray = chooseVector(firstArray, secondArray, MIN_SIZE);
	std::vector<int> bigArray = chooseVector(firstArray, secondArray, MAX_SIZE);
	HashSet arrayElements(smallArray);

	int numberOfSameElements = 0;

	for (int element : bigArray) {
		if (arrayElements.contains(element)) {
			numberOfSameElements++;
		}
	}

	return numberOfSameElements;
}

int FindSameAlgorithm::algorithmSorting(const std::vector<int>& firstArray,
										const std::vector<int>& secondArray) {
	if (firstArray.size() == 0 || secondArray.size() == 0) {
		return 0;
	}

	std::vector<int> smallArray = chooseVector(firstArray, secondArray, MIN_SIZE);
	std::vector<int> bigArray = chooseVector(firstArray, secondArray, MAX_SIZE);

	sort(smallArray.begin(), smallArray.end());

	int numberOfSameElements = 0;
	for (int element : bigArray) {
		if (binary_search(smallArray.begin(), smallArray.end(), element)) {
			numberOfSameElements++;
		}
	}

	return numberOfSameElements;
}

int main() {
	return 0;
}
