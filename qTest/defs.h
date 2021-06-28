#ifndef _i_defs_included
#define _i_defs_included
#include <cstdio>

#ifdef __linux
#define NONE         "\033[0m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"
#else
#define NONE
#define RED
#define LIGHT_RED
#define GREEN
#define LIGHT_GREEN
#define BLUE
#define LIGHT_BLUE
#define DARY_GRAY
#define CYAN
#define LIGHT_CYAN
#define PURPLE
#define LIGHT_PURPLE
#define BROWN
#define YELLOW
#define LIGHT_GRAY
#define WHITE
#endif

#define PRINNT_TEST_FN() fprintf(stdout,BLUE "\n####################%s####################\n" NONE, __FUNCTION__)
#define PRINNT_TEST_FN_MSG(msg) fprintf(stdout,BLUE "####################%s[%s]####################\n" NONE, __FUNCTION__, msg)

#define TEST_RESULT(expression) \
    if ((expression))\
    {\
        fprintf(stdout,GREEN "PASS: "#expression "\n" NONE);\
    }else{\
        fprintf(stdout,RED "FAILED: "#expression "\n" NONE);\
    }


#define TEST_RESULT1(expression, msg) \
    if ((expression))\
    {\
        fprintf(stdout,GREEN "PASS: "#expression ", msg:%s\n" NONE, msg);\
    }else{\
        fprintf(stdout,RED "FAILED: "#expression ", msg:%s\n" NONE, msg);\
    }

#define TEST_RESULT_DETAIL(expression,file,line,msg) \
    if ((expression))\
    {\
        fprintf(stdout,GREEN "PASS: "#expression ", msg:%s\n" NONE, msg);\
    }else{\
        fprintf(stdout,RED "FAILED: "#expression ", msg:%s [%s(%d)]\n" NONE, msg, file, line);\
    }

#define ALL_PASSED(testsize) fprintf(stdout,GREEN "\n%d Test all passed.\n" NONE, testsize)

#endif // _i_defs_included
