#include "qTest/qTest.hpp"
#include "DSA/heap/heap.hpp"

TEST(test_heap, t1)
{
   dsa::ds::CMinHeap minHeap(5);
    // 退化成单链表
    for (size_t i = 1;i < 6; ++i)
        minHeap.insert(i);

    for(size_t i =0;i < minHeap.size(); ++i){
        printf("%d ", minHeap[i]);
    }
    printf("\n");
    EXPECT_TRUE(minHeap[0] == 1)<< "最小堆插入验证1";
    EXPECT_TRUE(minHeap[4] == 5)<<"最小堆插入验证1";

    int test2[] ={5, 2, 6, 9,3,1};
    dsa::ds::CMinHeap minHeap2(test2, sizeof(test2)/sizeof(test2[0]));
    for(size_t i =0;i < minHeap2.size(); ++i){
        printf("%d ", minHeap2[i]);
    }
    printf("\n");
    EXPECT_TRUE(minHeap2[0] == 1)<< "最小堆插入验证2-查询";
    EXPECT_TRUE(minHeap2[5] == 6) << "最小堆插入验证2-查询";
    EXPECT_TRUE(minHeap2[3] == 9) <<"最小堆插入验证2-查询";
    int remove_val = 0;
    minHeap2.removeat(3, remove_val);
    EXPECT_TRUE(remove_val == 9) <<"最小堆插入验证2-删除";
    EXPECT_TRUE(minHeap2.size() == 5)<<"最小堆插入验证2-删除";
    EXPECT_TRUE(minHeap2.leftchild(3) == -1) <<"最小堆插入验证2-查询";
    EXPECT_TRUE(minHeap2.rightchild(0) == 2) <<"最小堆插入验证2-查询";
}