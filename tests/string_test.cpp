#include "qTest/qTest.hpp"
#include "DSA/string/string.hpp"
#include <string>

TEST(test_vector, t1)
{
    dsa::ds::String test1("fjdsaljfeifdsajfl");
    const dsa::ds::String test2("jfeif");

    ASSERT_TRUE(test1.size() == 17);
    ASSERT_TRUE(test1.find(test2) == 6);
}