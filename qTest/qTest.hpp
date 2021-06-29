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

class TestInfo;
class QTest{
public:
    QTest(): reault_(true), shutdown_(false){}
    virtual void TestBody() = 0;
    void on_failure();
    void shutdown(){this->shutdown_=true;}
    friend class TestInfo;
protected:
    void set_last_expression();
protected:
    bool reault_;
    bool shutdown_;
    std::vector<std::pair<std::string, std::string>> expression_;
    std::ostringstream iss_;
};


class TestInfo
{
public:
    TestInfo();
    TestInfo(const char* casename, const char* testname, CodeLocation loc, QTest* test);

    void Run();
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
expression_.push_back({#expression, ""});\
if ((expression));\
else {on_failure();}this->iss_

#define EXPECT_FALSE(expression)\
this->set_last_expression();\
expression_.push_back({"!"#expression, ""});\
if (!(expression));\
else {on_failure();}this->iss_

#define ASSERT_TRUE(expression)\
expression_.push_back({#expression, ""});\
if ((expression));\
else {on_failure();shutdown();}

#define ASSERT_FALSE(expression)\
expression_.push_back({"!"#expression, ""});\
if (!(expression));\
else {on_failure();shutdown();}

#define ASSERT_EQ(value, expression)\
expression_.push_back({#value"=="#expression, ""});\
if ((value) == (expression));\
else {on_failure();shutdown();}

#define EXPECT_EQ(value, expression)\
this->set_last_expression();\
expression_.push_back({#value"=="#expression, ""});\
if ((value) == (expression));\
else {on_failure();}this->iss_

#endif // _q_test_included__