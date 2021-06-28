#include <memory>
#include <stack>
#include "DSA/link/link.hpp"
#include "qTest.hpp"
#include "defs.h"

namespace global_variable{
    static dsa::ds::Link<std::shared_ptr<qtest::TestInfo>> gTestInfos=dsa::ds::Link<std::shared_ptr<qtest::TestInfo>>();
}


void qtest::QTest::on_failure()
{
    this->reault_ = false;
}

qtest::TestInfo::TestInfo(const char* casename, const char* testname, qtest::CodeLocation loc, QTest* test)
    : testcasename_(casename), testname_(testname),  location_(loc), test_(test)
{

}

void qtest::TestInfo::Run()
{
    this->test_->TestBody();
    TEST_RESULT_DETAIL(
        this->test_->reault_, 
        this->location_.file, 
        this->location_.line, 
        this->testcasename_,
        this->testname_,
        this->test_->iss_.str().c_str())

    if (this->test_->shutdown_){
        exit(1);
    }
}

qtest::TestInfo* const qtest::internal::MakeRegisterTestInfo(const char* testcasename, const char* testname, CodeLocation location, QTest* test)
{
    auto testInfo = std::make_shared<qtest::TestInfo>(testcasename, testname, location,test);
    global_variable::gTestInfos.push_back(testInfo);
    return global_variable::gTestInfos.back().get();
}

void run_test()
{
    auto testinfo = global_variable::gTestInfos.back();
    global_variable::gTestInfos.pop_back();
    testinfo->Run();
}


__attribute__((constructor)) void before_main()  
{  
    const size_t sz_test = global_variable::gTestInfos.size();
    if (sz_test > 0)
        run_test();
    ALL_PASSED(sz_test);
}

__attribute__((destructor)) void after_main()  
{  

}

int main(int argc, char const *argv[])
{

    return 0;
}
