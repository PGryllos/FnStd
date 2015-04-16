/* MedianList
 *
 * Copyright(c) 2015 Gryllos Prokopis
 *
 * hosted on: https://github.com/PGryllos
 *
 */

#ifndef __MEDIAN_H
#define __MEDIAN_H

#include <boost/heap/fibonacci_heap.hpp>
#include <boost/container/vector.hpp>
#include <boost/unordered_map.hpp>

struct HeapBucket
{
    int value;
    unsigned int index;

    HeapBucket() {}
    HeapBucket(int value,unsigned int index) : value(value), index(index) {}
};

/* comparison functor (similar to less) to provide for MaxHeap */
struct less_
{
    bool operator()(const HeapBucket& b1,const HeapBucket& b2) const
    {
        return b1.value < b2.value;
    }
};

/* comparison functor (similar to greater) to provide for MinHeap */ 
struct greater_
{
    bool operator()(const HeapBucket& b1,const HeapBucket& b2) const
    {
        return b1.value > b2.value;
    }
};

typedef boost::heap::fibonacci_heap<HeapBucket,boost::heap::compare<less_> > MaxHeap;
typedef boost::heap::fibonacci_heap<HeapBucket,boost::heap::compare<greater_> > MinHeap;

/* Handle_t will be used to find data types of objects to be removed */
struct Handle_t
{
    int f; //boolean variable to find whick type is active (if 0->heap1)
    MaxHeap::handle_type maxH;
    MinHeap::handle_type minH;
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

typedef boost::unordered_map<int, FastVector> HashProfit;
typedef std::pair<HashProfit::iterator,bool> itExtended;

/* MedianList: data structure to maintain the median of list of integers with 
   basic functionality, insert(),remove(),getMedian() */
class MedianList
{
    private:
        float median;
        MaxHeap maxHeap;
        MinHeap minHeap;
        HashProfit map;
        itExtended iter1;
        VectorIter iter2;
        Handle_t handler;

        /* helper functions */
        void pushMaxHeap(int& value);
        void pushMinHeap(int& value);
        void balanceL(); //removes minHeap top and adds it to maxHeap
        void balanceR(); //removes maxHeap top and adds it to minHeap
        void balance();
        void updateMedian();
    public:
        MedianList() : median(0) {}

        /* medianList interface */
        float getMedian(); //returns median of MedianList
        void insert(int& value); //inserts value in MedianList,
        void remove(int& value); //removes value from MedianList,
};

#endif // _MEDIAN_H
