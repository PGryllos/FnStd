Fast not Standard Data Structures (FnStd)
---

This is a collection of Data Structures which you will not find in STL. That's what "not Standard" stands for. You can use this code in your own responsibility because it comes with no Warranty! You can use and redistribute without any constraints as the LICENSE suggests.

If you want to use this repository you need to have C++11 or above. You also need BOOST Library.

content
--
[[MedianList](https://github.com/PGryllos/FnStd/tree/master/MedianList)]  - Calculates the streaming median of a set of integers. For doing that it uses two Fibonacci Heaps.

Inserting to MedianList complexity analysis : 1 lookup to boost Unordered Map (O(C) C is the number of collisions for a specific key) + 1 push_back operation to an std vector (O(1)) + 1 push to a Fibonacci Heap (O(1)).

Deletion from MedianList complexity analysis: 1 lookup to boost Unordered Map (O(C)) + 1 deletion from Boost Fibonacci Heap (O(logN) N is the number of elements in the MedianLists) + 1 pop_back operation from std vector (O(1)).

[[CircFifo](https://github.com/PGryllos/FnStd/tree/master/CircFifo)] - Circular Queue implemented only with static array.

[[TopX](https://github.com/PGryllos/FnStd/tree/master/TopX] - Keeps ten highest values in static array. All other values are stores in a Fibonacci Heap.  

credits to [stackoverflow user](http://stackoverflow.com/users/448810/user448810) from whom I saw the two heap solution for the running median problem.
