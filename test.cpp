#include <cstdlib>
#include <vector>

#include "common/defs.h"
#include "queue/queue_of_circle.hpp"
#include "binarysearch/binarysearch.hpp"
#include "sort/sort.hpp"


void test_queue()
{
    PRINNT_TEST_FN();
    queue_circle<int, 3> test1;

    TEST(test1.push(1) == true);
    TEST(test1.push(2) == true);
    TEST(test1.push(3) == true);
    TEST(test1.push(4) == false);
    TEST(test1.full() == true);
    TEST(test1.exist(1) == true);
    TEST(test1.exist(-1) == false);
    TEST(test1.front() == 1);
    TEST(test1.pop() == true);
    TEST(test1.pop() == true);
    TEST(test1.pop() == true);
    TEST(test1.pop() == false);
    TEST(test1.empty() == true); 
}

void test_binary_search()
{
    PRINNT_TEST_FN();
    int test[5] = { 1, 2, 3, 4, 5 };
	TEST(binary_search(test, 5, 2) == 1);
	TEST(binary_search(test, 5, 8) == -1);
}

void test_sort()
{
    PRINNT_TEST_FN();
	std::vector<int> vecTest = { 9, 0, 5, 1, 2, 3, 8, 41, 32, 113, 4, 8 };
	std::vector<int> vecTest1 = { 5, 4, 3, 2, 1 };
	sort::insert_sort(vecTest.begin(), vecTest.end());
	sort::insert_sort(vecTest1.begin(), vecTest1.end());
	TEST(vecTest == std::vector<int>({ 0, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));
	TEST(vecTest != std::vector<int>({ 1, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));
	TEST(vecTest1 == std::vector<int>({ 1, 2, 3, 4, 5 }));
}

int main(int argc, char const *argv[])
{
    test_queue();
    test_binary_search();
    test_sort();
    return 0;
}
