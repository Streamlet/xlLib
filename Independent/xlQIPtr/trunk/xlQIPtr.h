/*******************************************************************************

    Copyright (C) Streamlet. All rights reserved.

    File Name:   xlQIPtr.h
    Author:      Streamlet
    Create Time: 2009-03-22
    Description: Smart pointer

    Version history:
        2009-03-22 Created by Streamlet.
        2009-03-27 Released first version.(1.0.0.1)


*******************************************************************************/

#ifndef __XLQIPTR_H_B0788703_ABD1_457D_8FEC_E527581FD9EF_INCLUDED__
#define __XLQIPTR_H_B0788703_ABD1_457D_8FEC_E527581FD9EF_INCLUDED__


namespace xl
{

#ifndef NULL
#define NULL 0
#endif

    /// @brief Smart Pointer.
    template <typename T>
    class QIPtr
    {
    public:
        /**
         * @brief Default constructor.
         */
        QIPtr();

        /**
         * @brief Constructor. Must give an heap address. Sample use: QIPtr<int> p(new int);.
         * @param pData [in] A heap address, usually returned by operator new.
         * @remark operator delete must not be called, if using QIPtr.
         */
        QIPtr(T *pData);

        /**
         * @brief Copy construction.
         * @param that [in] The pointer to be copied.
         */
        QIPtr(const QIPtr<T> &that);

        /**
         * @brief Destructor. Inside this function, the heap address will be released if there is no more references.
         */
        ~QIPtr();
    public:

        /**
         * @brief Operator *, use it as usual.
         * @return return a reference of T-typed object.
         */
        T &operator*() const;

        /**
         * @brief Operator ->, use it as usual.
         * @return return the address of the object.
         */
        T *operator->() const;

        /**
         * @brief Copy operator, use it as usual.
         * @param that [in] The pointer to be copied.
         * @return Reference of this object
         */
        QIPtr<T> &operator=(const QIPtr<T> &that);

        /**
         * @brief Compare operator, use it as usual.
         * @param that [in] The pointer to be compared.
         * @return Return true if the two points equals, return false otherwise.
         */
        bool operator==(const QIPtr<T> &that) const;

        /**
         * @brief Compare operator, use it as usual.
         * @param that [in] The pointer to be compared.
         * @return Return true if the two points do not equals, return false otherwise.
         */
        bool operator!=(const QIPtr<T> &that) const;

    private:
        void AddRef();
        void Release();

    private:
        T *m_pData;
        size_t *m_pcRefs;
    };

    template <typename T>
    inline void QIPtr<T>::AddRef()
    {
        if (this->m_pcRefs == NULL)
        {
            this->m_pcRefs = new size_t;
            *this->m_pcRefs = 0;
        }

        ++*this->m_pcRefs;
    }

    template <typename T>
    inline void QIPtr<T>::Release()
    {
        if (this->m_pcRefs == NULL)
        {
            return;
        }

        if (--*this->m_pcRefs > 0)
        {
            return;
        }
        
        delete this->m_pcRefs;

        //if (this->m_pData == NULL)
        //{
        //    return;
        //}

        delete this->m_pData;
    }


    template <typename T>
    inline QIPtr<T>::QIPtr() : m_pData(NULL), m_pcRefs(NULL)
    {
    }

    template <typename T>
    inline QIPtr<T>::QIPtr(T *pData) : m_pData(NULL), m_pcRefs(NULL)
    {
        this->m_pData = pData;
        this->AddRef();
    }

    template <typename T>
    inline QIPtr<T>::QIPtr(const QIPtr<T> &that) : m_pData(NULL), m_pcRefs(NULL)
    {
        this->m_pData = that.m_pData;
        this->m_pcRefs = that.m_pcRefs;
        this->AddRef();
    }

    template <typename T>
    inline QIPtr<T>::~QIPtr()
    {
        this->Release();
    }

    template <typename T>
    inline T &QIPtr<T>::operator*() const
    {
        return *this->m_pData;
    }

    template <typename T>
    inline T *QIPtr<T>::operator->() const
    {
        return this->m_pData;
    }

    template <typename T>
    inline QIPtr<T> &QIPtr<T>::operator=(const QIPtr<T> &that)
    {
        //if (this == &that)
        //{
        //    return *this;
        //}

        if (this->m_pData == that.m_pData)
        {
            return *this;
        }

        this->Release();

        this->m_pData = that.m_pData;
        this->m_pcRefs = that.m_pcRefs;
        this->AddRef();    

        return *this;
    }

    template <typename T>
    inline bool QIPtr<T>::operator==(const QIPtr<T> &that) const
    {
        return this->m_pData == that.m_pData;
    }

    template <typename T>
    inline bool QIPtr<T>::operator!=(const QIPtr<T> &that) const
    {
        return this->m_pData != that.m_pData;
    }


} // namespace xl

#endif // #ifndef __XLQIPTR_H_B0788703_ABD1_457D_8FEC_E527581FD9EF_INCLUDED__
