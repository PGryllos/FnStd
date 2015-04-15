#ifndef __FIFO_H
#define __FIFO_H
#define FIFO_SIZE 10000

#include <utility>

/* CircFifo: this is an implementation of circular fifo that uses a static array
   The size of the fifo must not exceed the pre determined size. */
template< typename T1 > class CircFifo
{
    private:
        int head = 0;
        int tail = -1;

        T1* staticArray;

    public:
        /* default constructor */
        CircFifo()
        {
            staticArray = new T1[FIFO_SIZE];
        }
        CircFifo(int arraySize)
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
