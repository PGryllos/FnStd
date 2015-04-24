Fast not Standard Data Structures (FnStd)
---

This is a collection of Data Structures which you will not find in STL. That's what "not Standard" stands for. You can use this code in your own responsibility because it comes with no Warranty! You can use and redistribute without any constraints as the LICENSE suggests.

If you want to use this repository you need to have C++11 or above. You also need BOOST Library.

content
--
[[MedianList](https://github.com/PGryllos/FnStd/tree/master/MedianList)]  - Calculates the streaming median of a set of integers. For doing that it uses two Fibonacci Heaps.
Inserting to MedianList complexity analysis : 1 lookup to boost Unordered Map (O(c) c is the number of collisions for a specific key) + 1 push_back operation to a boost Vector (O(1)) + 1 push to a Fibonacci Heap (O(1)).
