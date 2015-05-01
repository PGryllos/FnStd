Fast not Standard Data Structures (FnStd)
-----------------------------


This is a collection of Data Structures which you will not find in STL. That's what "not Standard" stands for.<br>You can use this code in your own responsibility because it comes with no Warranty!<br>You can use and redistribute without any constraints as the LICENSE suggests.

If you want to use this repository you need to have C++11 or above. You also need BOOST Library.

content
--
[[MedianList](https://github.com/PGryllos/FnStd/tree/master/MedianList)]<br>Calculates the streaming median of a set of integers. For doing that it uses two Fibonacci Heaps and a hashtable.

<b>Inserting to MedianList complexity analysis</b><br>1 lookup to boost Unordered Map (O(C1) C1 is the number of collisions for a specific key)+<br>1 push_back operation to an std vector (O(C2))+<br>1 push to a Fibonacci Heap (O(C3))<br><b>-> O(C1) + O(C2) + O(C3)</b>

<b>Deletion from MedianList complexity analysis</b><br>1 lookup to boost Unordered Map (O(C1))+<br>1 deletion from Boost Fibonacci Heap (O(logN) N is the number of elements in the MedianLists)+<br>1 pop_back operation from std vector (O(C2))<br><b>-> O(C1) + O(logN) + O(C2)</b>

[[CircFifo](https://github.com/PGryllos/FnStd/tree/master/CircFifo)]<br>Circular Queue implemented only with static array.

[[TopX](https://github.com/PGryllos/FnStd/tree/master/TopX)]<br>Keeps ten highest values in static array. All other values are stores in a Fibonacci Heap.


TODO LIST
--
* Make MedianList and TopX type independent (templates)<br>
* Implement remove method for TopX<br>
* Benchmark medianList (use std list for the same purpose and compare)<br>


credits to [stackoverflow user](http://stackoverflow.com/users/448810/user448810) from whom I saw the two heap solution for the running median problem  [here](http://stackoverflow.com/a/10931091/4068678).
