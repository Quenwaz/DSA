#include <memory>
#include <stack>
#include "DSA/link/single_linked_list.hpp"
#include "qTest.hpp"
#include "defs.h"

namespace global_variable{
    static dsa::ds::Link<std::shared_ptr<qtest::TestInfo>> gTestInfos;
}

void qtest::QTest::set_last_expression()
{
    if (!this->iss_.str().empty() && !this->expression_.empty()){
        this->expression_.back().msg=this->iss_.str();
        this->iss_.str("");
    }
}


qtest::TestInfo::TestInfo(const char* casename, const char* testname, qtest::CodeLocation loc, QTest* test)
    : testcasename_(casename), testname_(testname),  location_(loc), test_(test)
{
}

bool qtest::TestInfo::Run()
{
    this->test_->TestBody();
    this->test_->set_last_expression();

    bool all_success = true;
    fprintf(stderr, WHITE "\n%s(%s) (%s)\n"NONE, this->testcasename_, this->testname_, this->location_.file.c_str());
    for (auto expression: this->test_->expression_)
    {
        if (expression.success)
            fprintf(stderr, GREEN "\t[%s]  %s\n"NONE, expression.expression.c_str(), expression.msg.c_str());
        else {
            all_success = false;
            fprintf(stderr, RED "\t[%s]  %s %s(%d)\n"NONE, expression.expression.c_str(), expression.msg.c_str(),this->location_.file.c_str(), expression.line);
        }
        if (expression.stop){
            break;
        }
    }
    return all_success;
}

qtest::TestInfo* const qtest::internal::MakeRegisterTestInfo(const char* testcasename, const char* testname, CodeLocation location, QTest* test)
{
    auto testInfo = std::make_shared<qtest::TestInfo>(testcasename, testname, location,test);
    global_variable::gTestInfos.push_back(testInfo);
    return global_variable::gTestInfos.back().get();
}

bool run_test()
{
    auto testinfo = global_variable::gTestInfos.back();
    global_variable::gTestInfos.pop_back();
    return testinfo->Run();
}



__attribute__((constructor)) void before_main()  
{  
    const size_t sz_test = global_variable::gTestInfos.size();
    size_t failed = 0;
    for (;!global_variable::gTestInfos.empty();){
        if (!run_test())++failed;
    }
        
    ALL_PASSED(sz_test, failed);
}

__attribute__((destructor)) void after_main()  
{  
}

int main(int argc, char const *argv[])
{
    return 0;
}
