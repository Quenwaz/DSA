#include "qTest/qTest.hpp"
#include "DSA/queue/queue_of_circle.hpp"

TEST(test_queue, t1)
{

    dsa::ds::queue::queue_circle<int, 3> test1;

    ASSERT_TRUE(test1.push(1)==true);
    ASSERT_TRUE(test1.push(2) == true);
    ASSERT_TRUE(test1.push(3) == true);
    ASSERT_TRUE(test1.push(4) == false);
    ASSERT_TRUE(test1.full() == true);
    ASSERT_TRUE(test1.exist(1) == true);
    ASSERT_TRUE(test1.exist(-1) == false);
    ASSERT_TRUE(test1.front() == 1);
    ASSERT_TRUE(test1.pop() == true);
    ASSERT_TRUE(test1.pop() == true);
    ASSERT_TRUE(test1.pop() == true);
    ASSERT_TRUE(test1.pop() == false);
    ASSERT_TRUE(test1.empty() == true);
}




