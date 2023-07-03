#ifndef _queue_data_struacture_h_
#define _queue_data_struacture_h_
#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace dsa::ds{
namespace queue{



/**
 * \brief 循环队列类定义
 * \tparam T 数据类型
 * \tparam N 队列长度
 */
template <typename T, uint16_t N>
class queue_circle
{
public:
	/**
     * \brief 构造循环队列
     * \param auto_pop 当push发现队列满时， 是否自动pop
     */
    explicit queue_circle(bool auto_pop = false) : m_data{ T() }, m_nRear(0), m_nFront(0), m_bAutoPop(auto_pop){};
public:

    const T& front()
    {
        if (empty())
        {
            throw std::out_of_range("is empty");
        }
        return m_data[m_nFront];
    }

    bool empty() const
    {
        return m_nRear == m_nFront;
    }
 
    bool full() const
    {
        return (m_nRear + 1) % m_nCapacity == m_nFront;
    }

    bool pop()
    {
        if (this->empty()) return false;
        m_nFront = (m_nFront + 1) % m_nCapacity;
        return true;
    }

    bool push(const T& val)
    {
        if (this->full()) {
            if (this->m_bAutoPop)
                this->pop();
            else
                return false;
        }
        m_data[m_nRear] = val;
        m_nRear = (m_nRear + 1) % m_nCapacity;
        return true;
    }

    template <class _Predicate>
    bool exist_if(_Predicate pred) const
    {
        return std::any_of(m_data, m_data + m_nMaxSize, pred);
    }


    bool exist(const T& val) const
    {
        const auto iter_find = std::find(m_data, m_data + m_nMaxSize, val);
        return iter_find != m_data + m_nMaxSize;
    }

private:
    enum {
    	// 容器可容纳尺寸
        m_nMaxSize = N,
    	// 实际容器大小
        m_nCapacity
    };

    T m_data[m_nCapacity];
    uint32_t m_nRear;
    uint32_t m_nFront;
    const bool m_bAutoPop;
};


template<typename T>
class QueueCircleLink
{
public:
    struct LinkNode{
        T data;
        LinkNode* next;
    };

    QueueCircleLink();
public:
    void enque(const T& data);
    bool deque(T& data);
private:
    size_t size_;
    LinkNode* rear_;
};



}  // namespace queue
}
#endif // _queue_data_struacture_h_