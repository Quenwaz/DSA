#include <cstdlib>
#include <vector>

#include "common/defs.h"
#include "queue/queue_of_circle.hpp"
#include "binarysearch/binarysearch.hpp"
#include "sort/sort.hpp"
#include "bst/bst.hpp"


void test_queue()
{
    PRINNT_TEST_FN();
    data_structure::queue::queue_circle<int, 3> test1;

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
	TEST(search::binary_search(test, 5, 2) == 1);
	TEST(search::binary_search(test, 5, 8) == -1);
}

void test_sort()
{
    PRINNT_TEST_FN();
#define TEST_SORT(sort_name)\
{\
    PRINNT_TEST_FN_MSG(#sort_name);\
	std::vector<int> vecTest = { 9, 0, 5, 1, 2, 3, 8, 41, 32, 113, 4, 8 };\
	std::vector<int> vecTest1 = { 5, 4, 3, 2, 1 };\
	sort::sort_name(vecTest.begin(), vecTest.end());\
	sort::sort_name(vecTest1.begin(), vecTest1.end());\
	TEST(vecTest == std::vector<int>({ 0, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));\
	TEST(vecTest != std::vector<int>({ 1, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));\
	TEST(vecTest1 == std::vector<int>({ 1, 2, 3, 4, 5 }));\
}

    TEST_SORT(insert_sort);
    TEST_SORT(bubble_sort);
    TEST_SORT(quick_sort);

#undef TEST_SORT
}

void test_bst()
{
    PRINNT_TEST_FN();

    auto comp = [](const int& lhs, const int& rhs)->short{
        if (lhs == rhs) return 0;
        else if(lhs < rhs) return -1;
        else return 1;
    };

    int arr[] = {4, 2, 1, 7, 3, 8, 6};
    auto root = data_structure::bst::insert_r(NULL, arr[0], comp);
    for (size_t i = 1; i < (sizeof(arr)/ sizeof(arr[0])); ++i)
    {
        data_structure::bst::insert_r(root, arr[i], comp);
    }

    int nDebug = 0;
}

int main(int argc, char const *argv[])
{
    test_queue();
    test_binary_search();
    test_sort();
    test_bst();
    return 0;
}
