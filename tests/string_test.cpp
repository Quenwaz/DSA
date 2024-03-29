#include "qTest/qTest.hpp"
#include "DSA/string/string.hpp"

TEST(test_vector, t1)
{
    dsa::ds::String test1("fjdsaljfeifdsajfl");

    ASSERT_TRUE(test1.size() == 17);
    ASSERT_TRUE(test1.find("jfeif") == 6);
    ASSERT_TRUE(test1.index_KMP("jfeif") == 6);

    test1 = "dabxabxababxabwabxad";
    ASSERT_TRUE(test1.index_KMP("abxabwabxad") == 9);

}