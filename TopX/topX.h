/* TopX (topX.h)
 *
 * Copyright(c) 2015 Gryllos Prokopis
 *
 * hosted on: https://github.com/PGryllos
 *
 */

#ifndef __TOPX_H
#define __TOPX_H

#include <climits>

#include <boost/heap/fibonacci_heap.hpp>
#include <boost/container/vector.hpp>
#include <boost/unordered_map.hpp>

class topTen_
{
    private:
        struct Bucket
        {
            float value;
            int index;

            Bucket() {}
            Bucket(int value,int index) : value(value), index(index) {}
        };

        struct cmp_
        {
            bool operator()(const float& i1, const float& i2) const
            {
                return i1 < i2;
            }
        };

        typedef boost::heap::fibonacci_heap<float,boost::heap::compare<cmp_> > Heap;

        /* Handle_t will be used to find if values belongs to top or else find 
           it in the heap */
        struct Handle_t
        {
            int set;
            Heap::handle_type handler;
        };

        typedef boost::container::vector<Handle_t> BoostVector;
        typedef BoostVector::iterator VectorIter;


        /* FastVector is a wrapper of boost vector that pushes the first element upon
           creation. It will be used to store Handle_t objects */
        struct FastVector
        {
            BoostVector Vector;
            FastVector() {}
            FastVector(const Handle_t& handler)
            {
                Vector.push_back(handler);
            }

        };

        typedef boost::unordered_map<int, FastVector> HashTable;
        typedef std::pair<HashTable::iterator,bool> itExtended;

        Heap heap;
        int full; //if full > 9 top ten is full
        HashTable map;


        void sortTen(short index);
        void updateTenth(void);

    public:
        float ten [10] = {0,0,0,0,0,0,0,0,0,0};

        /* member functions */
        topTen_() : full(0) , changed(false) 
        {
            heap.push(INT_MIN);
        }
        void insert(float profitability);
        int HeapSize(void);
        bool changed;
};

#include "topX.cc"

#endif
