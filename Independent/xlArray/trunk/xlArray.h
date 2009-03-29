/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   xlArray.h
    Author:      Streamlet
    Create Time: 2009-03-27
    Description: Dynamic Array

    Version history:
        2009-03-27 Streamlet: Created.
        2009-03-29 Streamlet: Finished basic coding.



*******************************************************************************/

#ifndef __XLARRAY_H_154EDDC1_C5DB_48CF_ACBF_856D8E76E50A_INCLUDED__
#define __XLARRAY_H_154EDDC1_C5DB_48CF_ACBF_856D8E76E50A_INCLUDED__

namespace xl
{

#ifndef NULL
#define NULL 0
#endif

    template <typename T>
    class Array
    {
    public:
        /**
         * @brief Default constructor. It will construct the array with no element.
         */
        Array();

        /**
         * @brief Constructor. It will construct the array with several elements, but will not initialize the elements.
         * @param nSize The size of the array.
         */
        Array(int nSize);

        /**
         * @brief Constructor. It will construct the array with several elements,and initialize the elements with the same value.
         * @param nSize The size of the array.
         * @param tValue [in] The value of all the elements.
         */
        Array(int nSize, const T &tValue);

        /**
         * @brief Copy constructor.
         * @param that [in] The object to copy.
         */
        Array(const Array<T> &that);

        /**
         * @brief Destructor.
         */
        ~Array();

    public:
        /**
         * @brief Copy operator.
         * @param that [in] The object to copy.
         * @return Return this object.
         */
        Array<T> &operator=(const Array<T> &that);

        /**
         * @brief Compare operator.
         * @param that [in] The object to compare with.
         * @return Return true if the two array completely equals, return false otherwise.
         */
        bool operator==(const Array<T> &that) const;

        /**
         * @brief Compare operator.
         * @param that [in] The object to compare with.
         * @return Return true if the two array does not completely equal, return false otherwise.
         */
        bool operator!=(const Array<T> &that) const;

        /**
         * @brief Index operator.
         * @param nIndex The zero-based index.
         * @return Return the reference of the element.
         * @remark Do make sure the index is in the correct range.
         */
        T &operator[](int nIndex);

        /**
         * @brief Index operator, constant version.
         * @param nIndex The zero-based index.
         * @return Return the constant reference of the element.
         * @remark Do make sure the index is in the correct range.
         */
        const T &operator[](int nIndex) const;

    public:

        /**
         * @brief Get the size of the array.
         * @return Return the size of the array.
         */
        int Size() const;

        /**
         * @brief Set the size of the array.
         * @param nNewSize New size of the array.
         * @remark If the new size is less than the original size, extra elements at the back of the array will be removed.
         *         If the new size if greater that the original size, all present elements will be reserved, new elements
         *         will not be initialized.
         */
        void SetSize(int nNewSize);

        /**
         * @brief Set several elements of the array to a specified value.
         * @param tValue [in] The value.
         * @param nStart The zero-based index. Elements from nStart to the end of the array will be set with the value.
         * @remark If nStart is less then 0, it will be treated as 0;
         *         if it is greater than or equal to the size of the array, no element will be changed.
         */
        void SetValue(const T &tValue, int nStart);

        /**
         * @brief Set several elements of the array to a specified value.
         * @param tValue [in] The value.
         * @param nStart The zero-based index. Elements from nStart to the end of the array will be set with the value.
         * @param nCount How many elements to set value.
         * @remark If nStart is less then 0, it will be treated as 0.
         *         If it is greater than or equal to the size of the array, or nStart + nCount is greater than 
         *         or equal to the size of the array, the part out of range will not be changed.
         */
        void SetValue(const T &tValue, int nStart, int nCount);

        /**
         * @brief Delete an element specified by the index.
         * @param nIndex The zero-based index.
         * @remark Nothing will be done if nIndex is out of range.
         */
        void DeleteAt(int nIndex);

        /**
         * @brief Insert an element before an existed element specified by the index.
         * @param nIndex The zero-based index.
         * @param tValue [in] The value to insert.
         * @remark nIndex can equal to the size of the array, in this case new element will be append at the back.
         *         Nothing will be done if nIndex is out of range.
         */
        void InsertAt(int nIndex, const T &tValue);

        /**
         * @brief Insert all elements (from an array) before an existed element specified by the index.
         * @param nIndex The zero-based index.
         * @param that [in] The array contains elements to insert.
         * @remark nIndex can equal to the size of the array, in this case new element will be append at the back.
         *         Nothing will be done if nIndex is out of range.
         */
        void InsertAt(int nIndex, const Array<T> &that);

        /**
         * @brief Insert several elements (from an array) before an existed element specified by the index.
         * @param nIndex The zero-based index.
         * @param that [in] The array contains elements to insert.
         * @param nStart The zero-based index. Elements (of that) from nStart to the end (of that) will be inserted.
         * @remark nIndex can equal to the size of the array, in this case new element will be append at the back.
         *         Nothing will be done if nIndex is out of range.
         *         If nStart is less then 0, it will be treated as 0;
         *         if it is greater than or equal to the size of the array, no elements will not be inserted.
         */
        void InsertAt(int nIndex, const Array<T> &that, int nStart);

        /**
         * @brief Insert several elements (from an array) before an existed element specified by the index.
         * @param nIndex The zero-based index.
         * @param that [in] The array contains elements to insert.
         * @param nStart The zero-based index. Elements (of that) from nStart will be inserted.
         * @param nCount How many elements (of that) will be inserted.
         * @remark nIndex can equal to the size of the array, in this case new element will be append at the back.
         *         Nothing will be done if nIndex is out of range.
         *         If nStart is less then 0, it will be treated as 0.
         *         If it is greater than or equal to the size of the array, or nStart + nCount is greater than 
         *         or equal to the size of the array, the part out of range will not be inserted.
         */
        void InsertAt(int nIndex, const Array<T> &that, int nStart, int nCount);

        /**
         * @brief Delete an element at the front of the array. Nothing will be done if the array is empty.
         */
        void PopFront();

        /**
         * @brief Delete an element at the back of the array. Nothing will be done if the array is empty.
         */
        void PopBack();

        /**
         * @brief Insert an element at the front of the array.
         * @param tValue The element to insert.
         */
        void PushFront(T tValue);

        /**
         * @brief Insert an element at the back of the array.
         * @param tValue The element to insert.
         */
        void PushBack(T tValue);

        /**
         * @brief Insert all elements of another array at the front of this array.
         * @param that [in] The array contains elements to insert.
         */
        void AppendFront(const Array<T> &that);

        /**
         * @brief Insert several elements of another array at the front of this array.
         * @param that [in] The array contains elements to insert.
         * @param nStart The zero-based index. Elements (of that) from nStart to the end (of that) will be inserted.
         * @remark If nStart is less then 0, it will be treated as 0;
         *         if it is greater than or equal to the size of the array, no elements will not be inserted.
         */
        void AppendFront(const Array<T> &that, int nStart);

        /**
         * @brief Insert several elements of another array at the front of this array.
         * @param that [in] The array contains elements to insert.
         * @param nStart The zero-based index. Elements (of that) from nStart will be inserted.
         * @param nCount How many elements (of that) will be inserted.
         * @remark If nStart is less then 0, it will be treated as 0.
         *         If it is greater than or equal to the size of the array, or nStart + nCount is greater than 
         *         or equal to the size of the array, the part out of range will not be inserted.
         */
        void AppendFront(const Array<T> &that, int nStart, int nCount);

        /**
         * @brief Insert all elements of another array at the back of this array.
         * @param that [in] The array contains elements to insert.
         */
        void AppendBack(const Array<T> &that);


        /**
         * @brief Insert several elements of another array at the back of this array.
         * @param that [in] The array contains elements to insert.
         * @param nStart The zero-based index. Elements (of that) from nStart to the end (of that) will be inserted.
         * @remark If nStart is less then 0, it will be treated as 0;
         *         if it is greater than or equal to the size of the array, no elements will not be inserted.
         */
        void AppendBack(const Array<T> &that, int nStart);

        /**
         * @brief Insert several elements of another array at the back of this array.
         * @param that [in] The array contains elements to insert.
         * @param nStart The zero-based index. Elements (of that) from nStart to the end (of that) will be inserted.
         * @param nCount How many elements (of that) will be inserted.
         * @remark If nStart is less then 0, it will be treated as 0.
         *         If it is greater than or equal to the size of the array, or nStart + nCount is greater than 
         *         or equal to the size of the array, the part out of range will not be inserted.
         */
        void AppendBack(const Array<T> &that, int nStart, int nCount);

    private:
        void Release();
        int GetWellSize(int nTotalSize);
        void CopyData(T *pDest, T *pSrc, int nCount, bool bHighAddrToLowAddr = false);

    private:
        T *m_pData;
        int m_nMemSize;
        int m_nStart;
        int m_nEof;
    };

    template <typename T>
    inline Array<T>::Array() : m_pData(NULL), m_nMemSize(0),  m_nStart(0), m_nEof(0)
    {

    }

    template <typename T>
    inline Array<T>::Array(int nSize)
    {
        m_nMemSize = GetWellSize(nSize);
        m_nStart = (m_nMemSize - nSize) / 2;
        m_nEof = m_nStart + nSize;
        m_pData = new T[m_nMemSize];
    }


    template <typename T>
    Array<T>::Array(int nSize, const T &tValue)
    {
        m_nMemSize = GetWellSize(nSize);
        m_nStart = (m_nMemSize - nSize) / 2;
        m_nEof = m_nStart + nSize;
        m_pData = new T[m_nMemSize];

        for (int i = this->m_nStart; i < this->m_nEof; ++i)
        {
            m_pData[i] = tValue;
        }

    }

    template <typename T>
    inline Array<T>::Array(const Array<T> &that)
    {
        m_pData = NULL;
     
        *this = that;
    }


    template <typename T>
    inline Array<T>::~Array()
    {
        Release();
    }

    template <typename T>
    Array<T> &Array<T>::operator=(const Array<T> &that)
    {
        Release();

        int nThatSize = that.Size();
        m_nMemSize = GetWellSize(nThatSize);
        m_nStart = (m_nMemSize - nThatSize) / 2;
        m_nEof = m_nStart + nThatSize;
        m_pData = new T[m_nMemSize];

        CopyData(m_pData + m_nStart, that.m_pData + that.m_nStart, nThatSize);

        return *this;
    }

    template <typename T>
    bool Array<T>::operator==(const Array<T> &that) const
    {
        if (this->Size() != that.Size())
        {
            return false;
        }

        for (int i = m_nStart; i < m_nEof; ++i)
        {
            if (m_pData[i] != that.m_pData[i])
            {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    bool Array<T>::operator!=(const Array<T> &that) const
    {
        if (this->Size() != that.Size())
        {
            return true;
        }

        for (int i = m_nStart; i < m_nEof; ++i)
        {
            if (m_pData[i] != that.m_pData[i])
            {
                return true;
            }
        }

        return false;
    }

    template <typename T>
    inline T &Array<T>::operator[](int nIndex)
    {
        return m_pData[m_nStart + nIndex];
    }

    template <typename T>
    inline const T &Array<T>::operator[](int nIndex) const
    {
        return m_pData[m_nStart + nIndex];
    }

    template <typename T>
    inline int Array<T>::Size() const
    {
        return m_nEof - m_nStart;
    }

    template <typename T>
    void Array<T>::SetSize(int nNewSize)
    {
        // Free spaces at the back is enough
        if (m_nMemSize - m_nStart >= nNewSize)
        {
            m_nEof = m_nStart + nNewSize;

            return;
        }

        // Not enough spaces at the back
        int nWellSize = GetWellSize(nNewSize);
        
        if (nWellSize <= m_nMemSize)
        {
            // New space size is not larger than current space size
            // It implies there a lot of spaces wasted at the front
            // Recalculate the start offset and move the elements

            int nNewStart = (m_nMemSize - nNewSize) / 2;

            //if (nNewStart < m_nStart)
            //{
                CopyData(m_pData + nNewStart, m_pData + m_nStart, m_nEof - m_nStart);
            //}
            //else
            //{
            //    CopyData(m_pData + nNewStart, m_pData + m_nStart, m_nEof - m_nStart, true);
            //}

            m_nStart = nNewStart;
            m_nEof = m_nStart + nNewSize;
        }
        else
        {
            // Current space is not large enough, reallocate and move elements

            T *pNewData = new T[nWellSize];
            int nNewStart = (nWellSize - nNewSize) / 2;

            CopyData(pNewData + nNewStart, m_pData + m_nStart, m_nEof - m_nStart);

            Release();

            m_nStart = nNewStart;
            m_nEof = m_nStart + nNewSize;
            m_nMemSize = nWellSize;
            m_pData = pNewData;
        }
    }

    template <typename T>
    void Array<T>::SetValue(const T &tValue, int nStart)
    {
        for (int i = m_nStart + nStart; i < m_nEof; i++)
        {
            (*this)[i] = tValue;
        }
    }

    template <typename T>
    void Array<T>::SetValue(const T &tValue, int nStart, int nCount)
    {
        for (int i = m_nStart + nStart; i < m_nEof && i < m_nStart + nStart; i++)
        {
            (*this)[i] = tValue;
        }
    }


    template <typename T>
    void Array<T>::DeleteAt(int nIndex)
    {
        if (nIndex < 0 || nIndex >= Size())
        {
            return;
        }

        if (nIndex <= m_nEof - m_nStart - nIndex)
        {
            // The element to be deleted is near the front

            CopyData(m_pData + m_nStart + 1, m_pData + m_nStart, nIndex, true);

            ++m_nStart;
        }
        else
        {
            // It is near the back

            CopyData(m_pData + m_nStart + nIndex, m_pData + m_nStart + nIndex + 1, m_nEof - m_nStart - nIndex);

            --m_nEof;
        }
    }

    template <typename T>
    inline void Array<T>::InsertAt(int nIndex, const T &tValue)
    {
        InsertAt(nIndex, Array<T>(1, tValue));
    }

    template <typename T>
    inline void Array<T>::InsertAt(int nIndex, const Array<T> &that)
    {
        InsertAt(nIndex, that, 0, that.Size());
    }

    template <typename T>
    inline void Array<T>::InsertAt(int nIndex, const Array<T> &that, int nStart)
    {
        InsertAt(nIndex, that, nStart, that.Size() - nStart);
    }

    template <typename T>
    void Array<T>::InsertAt(int nIndex, const Array<T> &that, int nStart, int nCount)
    {
        if (nIndex < 0 || nIndex > Size())
        {
            return;
        }

        if (nStart < 0)
        {
            nStart = 0;
        }

        if (nCount > that.Size() - nStart)
        {
            nCount = that.Size() - nStart;
        }

        if ( m_nStart >= nCount &&
            (nIndex <= m_nEof - m_nStart - nIndex || m_nMemSize - m_nEof < nCount))
        {
            // In this case:
            // There are enough spaces at the front,
            // and (the position to insert is near the front, or there is not enough space at the back)

            CopyData(m_pData + m_nStart - nCount, m_pData + m_nStart, nIndex);
            CopyData(m_pData + m_nStart - nCount + nIndex, that.m_pData + that.m_nStart + nStart, nCount);
            
            m_nStart -= nCount;

            return;
        }
        // Else:
        // There is not enough space at the front,
        // or (the position to insert is near the back, and there are enough spaces at the back)
        else if (m_nMemSize - m_nEof >= nCount)
        {
            // There are enough spaces at the back

            CopyData(m_pData + m_nStart + nIndex + nCount, m_pData + m_nStart + nIndex, m_nEof - m_nStart - nIndex, true);
            CopyData(m_pData + m_nStart + nIndex, that.m_pData + that.m_nStart + nStart, nCount);

            m_nEof += nCount;

            return;
        }

        // Now the case is:
        // There is not enough space at the front or enough space at the back to hold the new elements itself
        // But the total of the spaces might hold them

        int nNewSize = Size() + nCount;
        int nWellSize = GetWellSize(nNewSize);
        int nNewStart;

        if (nNewSize <= m_nMemSize)
        {
            // New size is not larger than current size,
            // the total of the spaces can hold new elements.
            // Rearrange the elements

            nNewStart = (m_nMemSize - nNewSize) / 2;

            CopyData(m_pData + nNewStart, m_pData + m_nStart, nIndex);
            CopyData(m_pData + nNewStart + nIndex + nCount, m_pData + m_nStart + nIndex, m_nEof - m_nStart - nIndex, true);
            CopyData(m_pData + nNewStart + nIndex, that.m_pData + that.m_nStart + nStart, nCount);

            m_nStart = nNewStart;
            m_nEof = m_nStart + nNewSize;
        }
        else
        {
            // Not enough spaces, reallocate.

            T *pNewData = new T[nWellSize];
            nNewStart = (nWellSize - nNewSize) / 2;

            CopyData(pNewData + nNewStart, m_pData + m_nStart, nIndex);
            CopyData(pNewData + nNewStart + nIndex, that.m_pData + that.m_nStart + nStart, nCount);
            CopyData(pNewData + nNewStart + nIndex + nCount, m_pData + m_nStart + nIndex, m_nEof - m_nStart - nIndex);

            Release();

            m_nStart = nNewStart;
            m_nEof = m_nStart + nNewSize;
            m_nMemSize = nWellSize;
            m_pData = pNewData;
        }
    }

    template <typename T>
    inline void Array<T>::PopFront()
    {
        DeleteAt(0);
    }

    template <typename T>
    inline void Array<T>::PopBack()
    {
        DeleteAt(Size() - 1);
    }

    template <typename T>
    inline void Array<T>::PushFront(T tValue)
    {
        InsertAt(0, tValue);
    }

    template <typename T>
    inline void Array<T>::PushBack(T tValue)
    {
        InsertAt(Size(), tValue);
    }

    template <typename T>
    inline void Array<T>::AppendFront(const Array<T> &that)
    {
        InsertAt(0, that);
    }
    template <typename T>
    inline void Array<T>::AppendFront(const Array<T> &that, int nStart)
    {
        InsertAt(0, that, nStart);
    }

    template <typename T>
    inline void Array<T>::AppendFront(const Array<T> &that, int nStart, int nCount)
    {
        InsertAt(0, that, nStart, nCount);
    }

    template <typename T>
    inline void Array<T>::AppendBack(const Array<T> &that)
    {
        InsertAt(this->Size(), that);
    }

    template <typename T>
    inline void Array<T>::AppendBack(const Array<T> &that, int nStart)
    {
        InsertAt(this->Size(), that, nStart);
    }

    template <typename T>
    inline void Array<T>::AppendBack(const Array<T> &that, int nStart, int nCount)
    {
        InsertAt(this->Size(), that, nStart, nCount);
    }

    template <typename T>
    inline void Array<T>::Release()
    {
        if (m_pData != NULL)
        {
            delete[] m_pData;
        }
    }

    template <typename T>
    inline int Array<T>::GetWellSize(int nTotalSize)
    {
        nTotalSize -= 1;

        for (int i = 1; i < sizeof(int) * 8; i <<= 1)
        {
            nTotalSize |= nTotalSize >> i;
        }

        return ++nTotalSize;
    }
    
    template <typename T>
    void Array<T>::CopyData(T *pDest, T *pSrc, int nCount, bool bHighAddrToLowAddr)
    {
        if (bHighAddrToLowAddr)
        {
            for (int i = nCount - 1; i >= 0; --i)
            {
                pDest[i] = pSrc[i];
            }
        }
        else
        {
            for (int i = 0; i < nCount; ++i)
            {
                pDest[i] = pSrc[i];
            }
        }
    }

} // namespace xl

#endif // #ifndef __XLARRAY_H_154EDDC1_C5DB_48CF_ACBF_856D8E76E50A_INCLUDED__
