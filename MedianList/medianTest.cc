#include <stdio.h>
#include <stdlib.h>
#include "median.h"


using namespace std;

int main () 
{
    srand (time(NULL));
    MedianList a;
    for (int i=0; i<100000; i++)
    {
        int r = rand() % 100000 + 0;
        a.insert(r);
    }
    cout<<a.getMedian();
    return 0;
}
