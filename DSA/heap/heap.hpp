/**
 * @file heap.hpp
 * @author Quenwaz (404937333@qq.com)
 * @brief 堆数据结构的增删改
 * @version 0.1
 * @date 2020-05-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef _h_heap_inclued__
#define _h_heap_inclued__
#include <cstddef>
#include <stdexcept>

namespace dsa::ds{
class CMinHeap
{
private:
    typedef int DataType;
    DataType* m_data_array;
    size_t m_size;
    size_t m_reserve;
public:
	
    /**
     * \brief 后续插入数据的方式构造最小堆
     * \param n_size 指定堆数据长度
     */
    explicit CMinHeap(size_t n_size);

	
    /**
     * \brief 从一维数组中构造最小堆
     * \param _data_array 数组指针
     * \param n_size 数组大小
     * \notes 内存需调用者自行释放
     */
    CMinHeap(DataType* _data_array, size_t n_size);
    ~CMinHeap();
private:
    /**
     * \brief 构建堆
     */
    void make_heap();
	
    /**
     * \brief 如果节点可以到上层， 则持续往上层走， 直到根节点
     * \param npos 指定索引
     */
    void shiftup(size_t npos);

	
    /**
     * \brief 如果节点可以到下层， 则持续往下层走，直到叶子节点
     * \param npos 指定索引
     */
    void shiftdown(size_t npos);

	
    /**
     * \brief 重新分配内存， 指定的数据个数必须不小于当前数据个数
     * \param dsize 分配数据个数
     * \return 返回重新分配后可容纳数据个数
     */
    size_t realloc(size_t dsize);
public:
	
    /**
     * \brief 插入新值
     * \param val 指定值
     */
    void insert(const DataType& val);

	
    /**
     * \brief 删除指定索引的值， 并返回
     * \param npos 指定索引
     * \param val 返回删除的值
     * \return 是否删除成功， 不存在时删除失败 
     */
    bool removeat(size_t npos, DataType& val);

	
    /**
     * \brief 获取数据个数
     * \return 当前数据个数
     */
    size_t size() const;

	
    /**
     * \brief 是否为空树
     * \return true 为空， 否则不为空
     */
    bool empty() const;

	
    /**
     * \brief 获取父节点索引
     * \param npos 指定索引
     * \return 返回父节点索引， -1则不存在父节点
     */
    int parent(size_t npos) const;

	
    /**
     * \brief 获取左子结点索引
     * \param npos 指定索引
     * \return 返回左子结点索引， -1则不存在左子结点
     */
    int leftchild(size_t npos) const;

    /**
     * \brief 获取右子结点索引
     * \param npos 指定索引
     * \return 返回右子结点索引， -1则不存在右子结点
     */
    int rightchild(size_t npos) const;

	
    /**
     * \brief 缩小内存到与当前实际占用数据大小内存一致
     * \return 返回调用后实际内存占用数据个数
     */
    int shrink_to_fit();

	
    /**
	 * \brief  获取指定索引值
	 * \param index 索引
	 * \return 返回值
	 * \exception 数据越界异常std::out_of_range
	 */
    DataType operator[](const size_t index) const;
};


CMinHeap::CMinHeap(size_t n_size)
    : m_data_array(new DataType[n_size])
    , m_reserve(n_size)
    , m_size(0)
{

}

CMinHeap::CMinHeap(DataType* _data_array, size_t n_size)
    : m_data_array(_data_array), m_size(n_size), m_reserve(0)
{
    this->make_heap();
}

CMinHeap::~CMinHeap()
{
    if (m_reserve > 0) {
        delete[] m_data_array;
    }
    m_data_array = nullptr;
    m_size = 0;
    m_reserve = 0;
}

void CMinHeap::make_heap()
{
	if (this->m_size < 2)
	{
        return;
	}

	for (int i = this->m_size / 2 - 1; i >= 0; --i)
	{
        this->shiftdown(i);
	}
}

void CMinHeap::shiftup(size_t npos)
{
    if (npos >= m_size)
    {
        return;
    }

#define shiftup_v2
#ifdef shiftup_v1
    int nparent = -1;
    while ((nparent = this->parent(npos)) >= 0)
    {
        if (m_data_array[npos] > m_data_array[nparent])
            break;

        
        const DataType tmp = m_data_array[nparent];
        m_data_array[nparent] = m_data_array[npos];
        m_data_array[npos] = tmp;
    }
#elif defined(shiftup_v2)
    int nparent = -1;
    size_t ncurpos = npos;
    const DataType fist_value = m_data_array[npos];
    while ((nparent = this->parent(npos)) >= 0)
    {
        if (fist_value > m_data_array[nparent])
            break;
    	
        m_data_array[ncurpos] = m_data_array[nparent];
        ncurpos = nparent;
    }
    m_data_array[ncurpos] = fist_value;
#endif 
}

void CMinHeap::shiftdown(size_t npos)
{
    if (npos >= m_size)
    {
        return;
    }

    size_t ncurpos = npos;
    int nMinPos = this->leftchild(ncurpos);
    if (nMinPos == -1)
    {
        return;
    }
	
    for (; ncurpos < m_size && nMinPos < m_size;)
    {
    	// 获得最小子结点
        if ((nMinPos + 1) < m_size &&m_data_array[nMinPos] > m_data_array[nMinPos + 1])
        {
            ++nMinPos;
        }

        if (m_data_array[ncurpos] <= m_data_array[nMinPos])
        {
            break;
        }

        // 交换
        const DataType tmp = m_data_array[nMinPos];
        m_data_array[nMinPos] = m_data_array[ncurpos];
        m_data_array[ncurpos] = tmp;

		// 当前节点大于最小子节点， 则继续下一层
		ncurpos = nMinPos;
		nMinPos = 2 * nMinPos + 1;
    }
}

size_t CMinHeap::realloc(size_t dsize)
{
    if (dsize < m_size)
        return m_reserve;
	
    m_reserve = dsize;
    DataType* temp = new DataType[m_reserve];
    for (size_t i = 0; i < m_size; ++i)
    {
        temp[i] = m_data_array[i];
    }

    delete[]m_data_array;
    m_data_array = temp;
    return m_reserve;
}


int CMinHeap::parent(size_t npos) const
{
	if (npos == 0 || npos >= m_size)
	{
        return -1;
	}

    return (npos - 1)/2;
}

int CMinHeap::leftchild(size_t npos) const
{
	if (npos >= m_size || (2*npos + 1) > (m_size-1))
	{
        return -1;
	}

    return 2 * npos + 1;	
}

int CMinHeap::rightchild(size_t npos) const
{
    if (npos >= m_size || (2 * npos + 2) > (m_size - 1))
    {
        return -1;
    }

    return 2 * npos + 2;
}

int CMinHeap::shrink_to_fit()
{
    return this->realloc(m_size);
}

CMinHeap::DataType CMinHeap::operator[](const size_t index) const
{
	if (index >= m_size)
	{
		throw std::out_of_range("out of range");
	}

	return m_data_array[index];
}


void CMinHeap::insert(const DataType& val)
{
    if( this->m_reserve <= this->m_size &&
        this->realloc(this->m_reserve * 2) <= m_size)
    {
        return;
    }
	
    m_data_array[m_size] = val;
    this->shiftup(m_size);
    ++m_size;
}


bool CMinHeap::removeat(size_t npos, DataType& val)
{
	if (npos >= m_size)
	{
        return false;
	}

    val = m_data_array[npos];
    m_data_array[npos] = m_data_array[m_size - 1];
    --m_size;

	const int nparent = this->parent(npos);
	if (nparent != -1 && m_data_array[npos] < m_data_array[nparent])
	{
        this->shiftup(npos);
	}else
	{
        this->shiftdown(npos);
	}
    return true;
}


size_t CMinHeap::size() const
{
    return m_size;
}

bool CMinHeap::empty() const
{
    return this->size() == 0;
}

}
#endif // _h_heap_inclued__