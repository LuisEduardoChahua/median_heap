Median heap
===========
##Description
A median heap is a priority queue that can access in constant time the median value of the content values.

##Operations supported
Operation|Cost
---------|----
Insertion|O(log n)
Get median|O(1)
Remove median|O(log n)

##Under the hood
The median heap uses a max heap and a min heap. All the items bigger than the median are inserted in the min heap and all the items smaller than the median are inserted in the max heap. With that we have O(log n) time to access the next bigger and the next smaller item inserted in the median heap.

With all that in mind you can imagine how is going to perform insertions in the median heap. After inserting a new item in the median heap it will put it in the max heap if the item is smaller than the median and it will put it in the min heap if the item is bigger than the median. Afterwards if the difference between the size of the min heap and the max heap is bigger than 1 (the current median is wrong) and it has to balance them. If the min heap is bigger it will add the median into the max heap and it will extract the min from the min heap and that item will be the new median. The case when the max heap is bigger can be easily deduced.
