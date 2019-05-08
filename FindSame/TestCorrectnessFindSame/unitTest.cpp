#include "stdafx.h"
#include "CppUnitTest.h"
#include <chrono>
#include <iostream>
#include "../FindSame/FindSameAlgorithm.cpp"
#include "../FindSame/HashSet.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFindSame
{		
	TEST_CLASS(TestDifferentAlgorithmSpeed)
	{
	public:
		TEST_METHOD(TestSmall)
		{
			std::vector<int> first({ 1, 2, 6, 3, -1, 18 });
			std::vector<int> second({ 4, 1, 18, 5, 6, -1 });
			
			auto firstTime = std::chrono::steady_clock::now();
			Assert::AreEqual(4, FindSameAlgorithm::findSameNumber(first, second, WITH_HASHSET));
			auto secondTime = std::chrono::steady_clock::now();
			Assert::AreEqual(4, FindSameAlgorithm::findSameNumber(first, second, WITH_LIBRARY_SET));
			auto thirdTime = std::chrono::steady_clock::now();
			Assert::AreEqual(4, FindSameAlgorithm::findSameNumber(first, second, SORTING));
			auto fouthTime = std::chrono::steady_clock::now();

			Logger::WriteMessage("SmallTest");
			Logger::WriteMessage(("HashSet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::microseconds>(secondTime - firstTime).count())).c_str());
			Logger::WriteMessage(("LibrarySet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::microseconds>(thirdTime - secondTime).count())).c_str());
			Logger::WriteMessage(("Sorting: " + std::to_string(
				std::chrono::duration_cast<std::chrono::microseconds>(fouthTime - thirdTime).count())).c_str());
		}
		// HashSet:  851 microseconds
		// LibrarySet: 389 microseconds
		// Sorting: 164 microseconds

		TEST_METHOD(TestMedium)
		{
			std::vector<int> div2;
			for (int i = 0; i < 1000; i += 2) {
				div2.push_back(i);
			}

			std::vector<int> div3;
			for (int i = 0; i < 1000; i += 3) {
				div3.push_back(i);
			}

			auto firstTime = std::chrono::steady_clock::now();
			Assert::AreEqual(167, FindSameAlgorithm::findSameNumber(div2, div3, WITH_HASHSET));
			auto secondTime = std::chrono::steady_clock::now();
			Assert::AreEqual(167, FindSameAlgorithm::findSameNumber(div2, div3, WITH_LIBRARY_SET));
			auto thirdTime = std::chrono::steady_clock::now();
			Assert::AreEqual(167, FindSameAlgorithm::findSameNumber(div2, div3, SORTING));
			auto fouthTime = std::chrono::steady_clock::now();

			Logger::WriteMessage("MediumTest");
			Logger::WriteMessage(("HashSet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::microseconds>(secondTime - firstTime).count())).c_str());
			Logger::WriteMessage(("LibrarySet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::microseconds>(thirdTime - secondTime).count())).c_str());
			Logger::WriteMessage(("Sorting: " + std::to_string(
				std::chrono::duration_cast<std::chrono::microseconds>(fouthTime - thirdTime).count())).c_str());
		}
		// HashSet: 3137 microseconds
		// LibrarySet: 6655 microseconds
		// Sorting: 2800 microseconds

		TEST_METHOD(TestLarge)
		{
			std::vector<int> div2;
			for (int i = 0; i < 1000000; i += 2) {
				div2.push_back(i);
			}


			std::vector<int> div3;
			for (int i = 0; i < 1000000; i += 3) {
				div3.push_back(i);
			}

			auto firstTime = std::chrono::steady_clock::now();
			Assert::AreEqual(166667, FindSameAlgorithm::findSameNumber(div2, div3, WITH_HASHSET));
			auto secondTime = std::chrono::steady_clock::now();
			Assert::AreEqual(166667, FindSameAlgorithm::findSameNumber(div2, div3, WITH_LIBRARY_SET));
			auto thirdTime = std::chrono::steady_clock::now();
			Assert::AreEqual(166667, FindSameAlgorithm::findSameNumber(div2, div3, SORTING));
			auto fouthTime = std::chrono::steady_clock::now();

			Logger::WriteMessage("LargeTest");
			Logger::WriteMessage(("HashSet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::milliseconds>(secondTime - firstTime).count())).c_str());
			Logger::WriteMessage(("LibrarySet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::milliseconds>(thirdTime - secondTime).count())).c_str());
			Logger::WriteMessage(("Sorting: " + std::to_string(
				std::chrono::duration_cast<std::chrono::milliseconds>(fouthTime - thirdTime).count())).c_str());
		}
		// HashSet: 3985 milliseconds
		// LibrarySet: 9329 milliseconds
		// Sorting: 3259 milliseconds

		TEST_METHOD(TestOneSmallOneLarge)
		{
			std::vector<int> large;
			for (int i = 0; i < 1000000; i++) {
				large.push_back(i);
			}


			std::vector<int> small({671111, 89, -12, 1234, 9011, 224552, 5, 3990130});
			int ans = FindSameAlgorithm::findSameNumber(small, large, WITH_HASHSET);

			auto firstTime = std::chrono::steady_clock::now();
			Assert::AreEqual(6, FindSameAlgorithm::findSameNumber(small, large, WITH_HASHSET));
			auto secondTime = std::chrono::steady_clock::now();
			Assert::AreEqual(6, FindSameAlgorithm::findSameNumber(small, large, WITH_LIBRARY_SET));
			auto thirdTime = std::chrono::steady_clock::now();
			Assert::AreEqual(6, FindSameAlgorithm::findSameNumber(small, large, SORTING));
			auto fouthTime = std::chrono::steady_clock::now();

			Logger::WriteMessage("TestOneSmallOneLarge");
			Logger::WriteMessage(("HashSet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::milliseconds>(secondTime - firstTime).count())).c_str());
			Logger::WriteMessage(("LibrarySet: " + std::to_string(
				std::chrono::duration_cast<std::chrono::milliseconds>(thirdTime - secondTime).count())).c_str());
			Logger::WriteMessage(("Sorting: " + std::to_string(
				std::chrono::duration_cast<std::chrono::milliseconds>(fouthTime - thirdTime).count())).c_str());
		}
		// HashSet: 3975 milliseconds
		// LibrarySet: 7314 milliseconds
		// Sorting: 2885 milliseconds
	};

	TEST_CLASS(TestCorrectness)
	{
		TEST_METHOD(TestEmptyIntersection)
		{
			std::vector<int> first({4, -3, 10});
			std::vector<int> second({1, 98, -10, 75, 2});

			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, WITH_HASHSET));
			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, WITH_LIBRARY_SET));
			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, SORTING));
		}

		TEST_METHOD(TestOneEmpty) 
		{
			std::vector<int> first;
			std::vector<int> second({ 1, 98, -10, 75, 2 });

			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, WITH_HASHSET));
			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, WITH_LIBRARY_SET));
			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, SORTING));
		}

		TEST_METHOD(TestSimilarArrays)
		{
			std::vector<int> elements({1, -4, 89, 12});

			Assert::AreEqual(4, FindSameAlgorithm::findSameNumber(elements, elements, WITH_HASHSET));
			Assert::AreEqual(4, FindSameAlgorithm::findSameNumber(elements, elements, WITH_LIBRARY_SET));
			Assert::AreEqual(4, FindSameAlgorithm::findSameNumber(elements, elements, SORTING));
		}

		TEST_METHOD(TestDifferenceInSign) 
		{
			std::vector<int> first({1, 2, 4});
			std::vector<int> second({-1, -2, -4});

			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, WITH_HASHSET));
			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, WITH_LIBRARY_SET));
			Assert::AreEqual(0, FindSameAlgorithm::findSameNumber(first, second, SORTING));
		}

		TEST_METHOD(TestSameElementsInOtherOrder) 
		{
			std::vector<int> first({ 1, -4, 89, 12, 15 });
			std::vector<int> second({ 15, 89, -4, 1, 12 });

			Assert::AreEqual(5, FindSameAlgorithm::findSameNumber(first, second, WITH_HASHSET));
			Assert::AreEqual(5, FindSameAlgorithm::findSameNumber(first, second, WITH_LIBRARY_SET));
			Assert::AreEqual(5, FindSameAlgorithm::findSameNumber(first, second, SORTING));
		}
	};
}