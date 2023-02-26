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

class StackCalc
{
private:
    dsa::ds::Stack<double> operator_;
public:
    StackCalc(/* args */);
    ~StackCalc();
    double computer(const std::string& expression);
};

StackCalc::StackCalc(/* args */)
{
}

StackCalc::~StackCalc()
{
}

double StackCalc::computer(const std::string& expression)
{
    std::string number_of_string;
    for(size_t i = 0;i < expression.size(); ++i)
    {
        char ch = expression.at(i);
        if(ch >= '0' && ch <= '9'){

        }else{

        }

        switch (ch)
        {
        case '+':
            /* code */
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        default:

            break;
        }
       
    }
}



TEST(test_stack, computer)
{
    const auto expression = "12*2+6/2";
    StackCalc calc;
    ASSERT_EQ(9,calc.computer(expression));
}