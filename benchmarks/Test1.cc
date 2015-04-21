#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../MedianList/median.h"
#include "../CircFifo/fifo.h"

#define ITER 300000


using namespace std;

clock_t insertTime = 0, deleteTime = 0, starting_time;

void printAverageTime()
{
    cout<<"Average insertion time for MedianList: "
        <<((double)insertTime/ITER)/CLOCKS_PER_SEC<<endl;
    cout<<"Average deletion time for MedianList: "
        <<((double)deleteTime/ITER)/CLOCKS_PER_SEC<<endl;
}

int main (void)
{

    //vector<int> values;
    CircFifo<int> values(ITER);

    srand (time(NULL));
    MedianList container;

    /* Insert values to container and calculate insertion time */
    for (int i=0; i<ITER; i++)
    {
        int r = rand() % 10000 + 137;
        values.push_back(r);

        starting_time = clock();

        container.insert(r);

        insertTime += clock() - starting_time;
    }

    cout<<"median: "<<container.getMedian()<<endl;

    /* Delete all values from container and calculate deletion time */
    do
    {
        starting_time = clock();

        container.remove(values.front());

        deleteTime += clock() - starting_time;

    }while (!values.pop());

    printAverageTime();

    return 0;
}
