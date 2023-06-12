//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlMap.h
//    Author:      Streamlet
//    Create Time: 2009-11-07
//    Description: 
//
//------------------------------------------------------------------------------

#ifndef __XLMAP_H_793F2C3D_4121_413E_B70F_E7A686081AC4_INCLUDED__
#define __XLMAP_H_793F2C3D_4121_413E_B70F_E7A686081AC4_INCLUDED__


#include "../../xlDef.h"
#include "xlPair.h"
#include "xlRBTree.h"

namespace xl
{
    template <typename K, typename V>
    class Map : public RBTree<Pair<K, V>>
    {
    public:
        inline Map()
        {

        }

        inline Map(const Map &that) : RBTree<Pair<K, V>>(that)
        {

        }

#ifdef __XL_CPP11

        inline Map(Map &&that) : RBTree<Pair<K, V>>(that)
        {

        }

#endif

        inline Map &operator = (const Map &that)
        {
            if (this == &that)
            {
                return *this;
            }

            *(RBTree<Pair<K, V>> *)this = (RBTree<Pair<K, V>> &)that;

            return *this;
        }

#ifdef __XL_CPP11

        inline Map &operator = (Map &&that)
        {
            if (this == &that)
            {
                return *this;
            }

            *(RBTree<Pair<K, V>> *)this = Memory::Move((RBTree<Pair<K, V>> &)that);

            return *this;
        }

#endif

        inline bool operator == (const Map &that) const
        {
            return *(RBTree<Pair<K, V>> *)this == (RBTree<Pair<K, V>> &)that;
        }

        inline bool operator != (const Map &that) const
        {
            return *(RBTree<Pair<K, V>> *)this != (RBTree<Pair<K, V>> &)that;
        }

        inline V &operator [] (const K &key)
        {
            Iterator it = Find(key);

            if (it == RBTree<Pair<K, V>>::End())
            {
                it = RBTree<Pair<K, V>>::Insert(Pair<K, V>(key));
            }

            return it->Value;
        }

        inline const V &operator [] (const K &key) const
        {
            Iterator it = RBTree<Pair<K, V>>::Find(key);

            if (it == RBTree<Pair<K, V>>::End())
            {
                return V();
            }

            return it->Value;
        }

    private:
        typedef RBTreeNode<Pair<K, V>> NodeType;

    public:
#ifdef __XL_CPP11
        typedef BinTreeIterator<Pair<K, V>, NodeType> Iterator;
        typedef ReverseBinTreeIterator<Pair<K, V>, NodeType> ReverseIterator;
#else
        typedef BinTreeIteratorT<Pair<K, V>, NodeType, false> Iterator;
        typedef BinTreeIteratorT<Pair<K, V>, NodeType, true> ReverseIterator;
#endif

    public:
        inline Iterator Delete(const Iterator& itWhere) {
            return  RBTree<Pair<K, V>>::Delete(itWhere);
        };

        inline ReverseIterator Delete(const ReverseIterator& itWhere) {
            return  RBTree<Pair<K, V>>::Delete(itWhere);
        }

        inline void Delete(const K &key)
        {
            RBTree<Pair<K, V>>::Delete(Find(key));
        }

        inline Iterator Find(const K &key)
        {
            return RBTree<Pair<K, V>>::Find(Pair<K, V>(key));
        }

        inline Iterator Insert(const xl::Pair<K, V> &pair)
        {
            return RBTree<Pair<K, V>>::Insert(pair);
        }

        inline Iterator Insert(const K &key, const V &value)
        {
            return RBTree<Pair<K, V>>::Insert(Pair<K, V>(key, value));
        }
    };

} // namespace xl

#endif // #ifndef __XLMAP_H_793F2C3D_4121_413E_B70F_E7A686081AC4_INCLUDED__
