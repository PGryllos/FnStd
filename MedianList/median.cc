/* MedianList
 *
 * Copyright(c) 2015 Gryllos Prokopis
 *
 * hosted on: https://github.com/PGryllos
 *
 */


inline void MedianList::pushMaxHeap(int& value)
{
    handler.maxH = maxHeap.emplace(value,map[value].Vector.size());
    handler.f = 0;
    iter1 = map.emplace(value,handler);
    if (!iter1.second)
    {
        (iter1.first->second).Vector.push_back(handler);
    }
}

inline void MedianList::pushMinHeap(int& value)
{
    handler.minH = minHeap.emplace(value,map[value].Vector.size());
    handler.f = 1;
    iter1 = map.emplace(value,handler);
    if (!iter1.second)
    {
        (iter1.first->second).Vector.push_back(handler);
    }
}

inline void MedianList::balanceL()
{
    handler.maxH = maxHeap.push(minHeap.top());
    handler.f = 0;
    map[minHeap.top().value].Vector[minHeap.top().index] = handler;
    minHeap.pop();
}

inline void MedianList::balanceR()
{
    handler.minH = minHeap.push(maxHeap.top());
    handler.f = 1;
    map[maxHeap.top().value].Vector[maxHeap.top().index] = handler;
    maxHeap.pop();
}

inline void MedianList::balance()
{
    int size1 = maxHeap.size();
    int size2 = minHeap.size();

    if ((size1 - size2) > 1)
        balanceR();
    else
    if ((size2 - size1) > 1)
        balanceL();
}

inline void MedianList::updateMedian()
{

    int size1 = maxHeap.size();
    int size2 = minHeap.size();

    if (size1 == size2)
    {
        if (size1 != 0)
            median = (float)(maxHeap.top().value + minHeap.top().value)/2;
    }
    else if (size1 > size2)
        median = maxHeap.top().value;
    else if (size2 > size1)
        median = minHeap.top().value;
}

/* get Median */
float MedianList::getMedian()
{
   return median;
}

/* insert value to the list */
void MedianList::insert(int& value)
{

    /* if MedianList contains two or more elements */
    if ((maxHeap.size() > 0) && (minHeap.size() > 0))
    {
        if (maxHeap.size() > minHeap.size())
        {
            if (value < median)
            {
                balanceR();
                pushMaxHeap(value);
                median = maxHeap.top().value;
            }
            else
            {
                pushMinHeap(value);
                median = (float)(maxHeap.top().value + minHeap.top().value)/2;
            }

        }
        else if (minHeap.size() > maxHeap.size())
        {
            if (value > median)
            {
                balanceL();
                pushMinHeap(value);
                median = minHeap.top().value;
            }
            else
            {
                pushMaxHeap(value);
                median = (float)(maxHeap.top().value + minHeap.top().value)/2;
            }
        }
        else
        {
            if (value < median)
            {
                pushMaxHeap(value);
                median = maxHeap.top().value;
            }
            else
            {
                pushMinHeap(value);
                median = minHeap.top().value;
            }

        }
    }
    /* if MedianList contains one element */
    else if (maxHeap.size() == 1)
    {
        if (median > value)
        {
            balanceR();
            pushMaxHeap(value);
        }
        else
        {
            pushMinHeap(value);
        }
        median = (float)(maxHeap.top().value + minHeap.top().value)/2;
    }
    else if (minHeap.size() == 1)
    {
        if (median < value)
        {
            balanceL();
            pushMinHeap(value);
        }
        else
        {
            pushMaxHeap(value);
        }
        median = (float)(maxHeap.top().value + minHeap.top().value)/2;
    }
    else
    /* if MedianList is empty */
    {
        pushMaxHeap(value);
        median = value;
    }
}

/* remove value from the list */
void MedianList::remove(int& value)
{

    /* find object in MedianList with value == value */
    handler = map[value].Vector.back();
    /* remove object from heap */
    if (handler.f == 0)
    {
        maxHeap.erase(handler.maxH);
    }
    else
    {
        minHeap.erase(handler.minH);
    }
    /* remove handler from vector */
    map[value].Vector.pop_back();
    balance();
    updateMedian();
}
