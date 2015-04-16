/* CircFifo
 *
 * Copyright(c) 2015 Gryllos Prokopis
 *
 * hosted on: https://github.com/PGryllos
 *
 */

#include "fifo.h"

/* returns a reference to the oldest element in the fifo */
template< typename T1 >
T1& CircFifo<T1>::front(void) const
{
    return staticArray[head];
}

/* push new element */
template< typename T1 >
T1& CircFifo<T1>::push_back(T1& fifObject_)
{
    if (tail != arraySize - 1)
    {
        tail++;
    }
    else
    {
        tail = 0;
    }
    staticArray[tail] = fifObject_;
    return staticArray[tail];
}

/* remove oldest element */
template< typename T1 >
bool CircFifo<T1>::pop(void)
{
    if (head == tail)
    {
        head = 0;
        tail = -1;
        return true;
    }
    else if (head != arraySize - 1)
    {
        head++;
    }
    else
    {
        head = 0;
    }
    return false;
}

/* return size of unhandled entries */
template< typename T1 >
int CircFifo<T1>::size(void) const
{
    int size = tail - head + 1;
    if (size<0)
    {
        size = tail + arraySize - head + 1;
    }
    return size;
}
