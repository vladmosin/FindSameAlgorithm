#pragma once

#include <vector>
#include <unordered_set>
#include "HashSet.h"

/* Two types of algorithms:
1) With map - O(n1 + n2) time with big constant
2) Sorting - O((n1 + n2)log(min(n1, n2))) time with small constant
*/
enum AlgorithmType
{
	WITH_LIBRARY_SET, WITH_HASHSET, SORTING
};

class FindSameAlgorithm {
public:
	static int findSameNumber(const std::vector<int>& firstArray, 
		const std::vector<int>& secondArray, const AlgorithmType algorithmType = SORTING);
private:
	static int algorithmWithLibrarySet(const std::vector<int>& firstArray, 
		                               const std::vector<int>& secondArray);
	static int algorithmWithHashSet(const std::vector<int>& firstArray,
		const std::vector<int>& secondArray);
	static int algorithmSorting(const std::vector<int>& firstArray,
		const std::vector<int>& secondArray);
};