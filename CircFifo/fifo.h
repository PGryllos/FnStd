/* CircFifo
 *
 * Copyright(c) 2015 Gryllos Prokopis
 *
 * hosted on: https://github.com/PGryllos
 *
 */

#ifndef __FIFO_H
#define __FIFO_H

#include <utility>

/* CircFifo: this is an implementation of circular fifo that uses a static
   array. */
template< typename T1 > class CircFifo
{
    private:
        int head = 0;
        int tail = -1;
        int arraySize;

        T1* staticArray;

    public:
        /* default constructor */
        CircFifo(int arraySize) : arraySize(arraySize)
        {
            staticArray = new T1[arraySize];
        }
        /* destructor needed since we allocate space using new */
        ~CircFifo()
        {
            if (staticArray) delete[] staticArray;
        }
        T1& front(void) const;
        T1& push_back(T1& fifObject_);
        int size(void) const;
        bool pop(void); //returns true if fifo empty
};

#include "fifo.cc"

#endif
