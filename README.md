# ICE_Quest
Problem 1:
Write a program that does the following:
Read a double precision number (from stdin) and print the smallest number that is larger than 95% of numbers encountered so far.
Run program on input size = 128,000,000 and provide the time taken. Provide the time taken for this random input along with the solution

Solution: Current Solution involves maintain the history of numbers in a File. 
          Then I read the file, populate the numbers in multiset and calculate the index for 95% and from there, I return the smallest number.
          For this approach, time complexity is O(N+log N) where N is number of records in the file. 
          O(N) - for reading the file and populating in multiset, O(logN) for getting the nth value in multiset.
          When ran for 128000000 records, the program took 94 min 7 secs.
          This can be optimized if I maintain a shared memory for the number history. I will have daemon process first active to keep my shared memory alive.
          In that way, each time my program runs I don't have to keep repopulating the data into multiset. Instead I can update the input number into the shared memory 
          and calculate the smallest number larger than 95% of the sample. In that case, time complexity of the program becomes O(log N).
          
 Problem 2:
 You have a set of parquet tiles of size 3x1 and 2x1 length units.
Parquet tiles are always laid out in strips, for instance 3223 is a strip of length 10.
When two strips are adjacent, no two tiles can share an inner edge.
For instance, strips 3223 and 3322 both start with a 3 so they cannot be neighbors.
But strips 3223 and 22222 of length 10 can be neighbors because they don't share inner edges.
Write a program in C/C++, that does the following:
Find the total number of floor designs which have 11 strips of length 30.  Provide the answer and time taken with the solution

Solution:
I was not able to complete this program. But I wrote basic layout of what I'm trying to do for this problem.
I'm trying to backtrace this problem by creating the strip of length 30 and then creating the design and then populating it in set.
Once I keep updating the set, set.size() will give you the unique number of designs possible.
