#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include "../MedianList/median.h"

#define ITER 300000


using namespace std;

clock_t insertTime = 0, deleteTime = 0, starting_time;

void printAverageTime()
{
    cout<<"Average insertion time: "
        <<((double)insertTime/ITER)/CLOCKS_PER_SEC<<endl;
    cout<<"Average deletion time: "
        <<((double)deleteTime/ITER)/CLOCKS_PER_SEC<<endl;
}

int main (void)
{

    vector<int> values;

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
    while (!values.empty())
    {
        starting_time = clock();

        container.remove(values.back());

        deleteTime += clock() - starting_time;
        values.pop_back();
    }

    printAverageTime();

    return 0;
}
