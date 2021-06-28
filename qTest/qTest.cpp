#include <memory>
#include <stack>
#include "qTest.hpp"
#include "defs.h"



namespace global_variable{
    static std::allocator<std::unique_ptr<qtest::TestInfo>> gAlloc;
    static std::stack<std::unique_ptr<qtest::TestInfo>> gTestInfos;
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
    TEST_RESULT_DETAIL(this->test_->reault_, this->location_.file, this->location_.line, this->test_->iss_.str())
    if (this->test_->shutdown_){
        exit(1);
    }
}

qtest::TestInfo* const qtest::internal::MakeRegisterTestInfo(const char* testcasename, const char* testname, CodeLocation location, QTest* test)
{
    auto testInfo = std::make_unique<qtest::TestInfo>(testcasename, testname, location,test);
    
    if(global_variable::gTestInfos.empty()){
        global_variable::gTestInfos = std::stack<std::unique_ptr<qtest::TestInfo>>(global_variable::gAlloc);
    }
    global_variable::gTestInfos.push(std::move(testInfo));
    fprintf(stderr, "size: %d\n", global_variable::gAlloc.max_size());
    fprintf(stderr, "global_variable::gTestInfos：%0X, %d\n", &global_variable::gTestInfos, global_variable::gTestInfos.size());
    return global_variable::gTestInfos.top().get();
}

void run_test()
{
    std::unique_ptr<qtest::TestInfo> testinfo = std::move(global_variable::gTestInfos.top());
    global_variable::gTestInfos.pop();
    testinfo->Run();
}



int main(int argc, char const *argv[])
{
    fprintf(stderr, "global_variable::gTestInfos：%0X, %d\n", &global_variable::gTestInfos, global_variable::gTestInfos.size());
    const size_t sz_test = global_variable::gTestInfos.size();
    if (sz_test > 0)
        run_test();
    ALL_PASSED(sz_test);
    return 0;
}
