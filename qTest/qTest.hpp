#ifndef _q_test_included__
#define _q_test_included__
#include <string>
#include <sstream>
#include <memory>
#include <vector>

namespace qtest{

struct CodeLocation {
  CodeLocation(const std::string& a_file, int a_line)
      : file(a_file), line(a_line) {}

  std::string file;
  int line;
};

struct ExpressionResult{
    std::string expression;
    std::string msg;
    bool success;
    bool stop;
    int line;
};

class TestInfo;
class QTest{
public:
    QTest(){}
    virtual void TestBody() = 0;
    friend class TestInfo;
protected:
    void set_last_expression();
protected:
    std::vector<ExpressionResult> expression_;
    std::ostringstream iss_;
};


class TestInfo
{
public:
    TestInfo();
    TestInfo(const char* casename, const char* testname, CodeLocation loc, QTest* test);

    bool Run();
private:
    const char* const testcasename_;
    const char* const testname_;
    const CodeLocation location_;
    std::unique_ptr<QTest> test_;
};


namespace internal{
     TestInfo* const MakeRegisterTestInfo(const char* testcasename, const char* testname, CodeLocation location, QTest* test);
}

}// namespace qtest


#define QTEST_TEST_CLASS_NAME_(test_case_name, test_name) \
  test_case_name##_##test_name##_Test

#define TEST(casename, test)\
class QTEST_TEST_CLASS_NAME_(casename, test): public qtest::QTest\
{\
public:\
    void TestBody() override;\
    static qtest::TestInfo* const testinfo_;\
};\
qtest::TestInfo* const QTEST_TEST_CLASS_NAME_(casename, test)::testinfo_=\
qtest::internal::MakeRegisterTestInfo(#casename, #test, qtest::CodeLocation(__FILE__, __LINE__), new QTEST_TEST_CLASS_NAME_(casename, test));\
void QTEST_TEST_CLASS_NAME_(casename, test)::TestBody()

#define EXPECT_TRUE(expression)\
this->set_last_expression();\
expression_.push_back({#expression, "", (expression), false, __LINE__});\
this->iss_

#define EXPECT_FALSE(expression)\
this->set_last_expression();\
expression_.push_back({#expression, "", !(expression), false, __LINE__});\
this->iss_

#define ASSERT_TRUE(expression)\
if ((expression))\
    expression_.push_back({#expression, "", true, false, __LINE__});\
else expression_.push_back({#expression, "", false, true, __LINE__})

#define ASSERT_FALSE(expression)\
if (!(expression))\
    expression_.push_back({"!"#expression, "", true, false, __LINE__});\
else expression_.push_back({"!"#expression, "", false, true, __LINE__})

#define ASSERT_EQ(value, expression)\
if ((value) == (expression))\
expression_.push_back({#value"=="#expression, "", true, false, __LINE__});\
else expression_.push_back({#value"=="#expression, "", false, true, __LINE__})

#define EXPECT_EQ(value, expression)\
this->set_last_expression();\
if ((value) == (expression))\
expression_.push_back({#value"=="#expression, "", true, false, __LINE__});\
else expression_.push_back({#value"=="#expression, "", false, false, __LINE__});\
this->iss_

#endif // _q_test_included__