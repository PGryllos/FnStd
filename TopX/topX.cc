/* TopX (topX.cc)
 *
 * Copyright(c) 2015 Gryllos Prokopis
 *
 * hosted on: https://github.com/PGryllos
 *
 */


int topTen_::HeapSize(void)
{
    return heap.size();
}

void topTen_::updateTenth(void)
{
  float temp = ten[9];
  ten[9] = heap.top();

  heap.push(temp);
}

void topTen_::sortTen(short index)
{
    while (ten[index] > ten[index-1])
    {
        /* swap buckets */
        float temp = ten[index-1];
        ten[index-1] = ten[index];
        ten[index] = temp;
        --index;
        if (index == 0) break;
    }
}


void topTen_::insert (float value)
{
    if (full > 9)
    {
        heap.emplace(value);
        if (heap.top() > ten[9])
        {
            changed = true;
            updateTenth();
            sortTen(9);
        }
    }
    else
    {
        changed = true;
        ten[full] = value;

        if (full > 0) sortTen(full);

        ++full;
    }
}

