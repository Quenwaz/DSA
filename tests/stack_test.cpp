#include "qTest/qTest.hpp"
#include "DSA/stack/starck.hpp"
#include <string>

TEST(test_stack, t1)
{
    dsa::ds::Stack<int> test1;
    test1.push(1);
    test1.push(4);
    test1.push(5);
    test1.push(6);
    test1.push(7);
    ASSERT_EQ(5, test1.size());
    ASSERT_EQ(7, test1.top());
    test1.pop();
    ASSERT_EQ(6, test1.top());
    test1.pop();
    ASSERT_EQ(5, test1.top());
    test1.pop();
    ASSERT_EQ(4, test1.top());
    test1.pop();
    ASSERT_EQ(1, test1.top());
   
    test1.pop();
    ASSERT_TRUE(test1.empty());
}
