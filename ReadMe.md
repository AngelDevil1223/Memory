Project Overview
The four different algorithms to be used are first fit, best fit, next fit and worst fit. Assume 
that memory is partitioned into contiguous segments, where each segment is either occupied by a 
process or is a hole (a contiguous area of free memory). The free list is a list of all the holes. 
Holes in the free list are kept in ascending order of memory address. Adjacent holes in the free 
list should be merged into a single hole. 
The four algorithms to be used for placing a process in memory are: 

• First fit: First fit searches the free list from the beginning, and uses the first hole large 
enough to satisfy the request. If the hole is larger than necessary, it is split, with the process 
occupying the lower address range portion of the hole and the remainder being put on the free list. 

• Best fit: Chooses the smallest hole from the free list that will satisfy the request. If multiple 
holes meet this criterion, choose the lowest address one in the free list. If the hole is larger 
than necessary, it is split, with the process occupying the lower address range portion of the hole 
and the remainder being put on the free list. 

• Worst fit: Chooses the largest hole from the free list that will satisfy the request. If multiple 
holes meet this criterion, choose the earliest one in the free list. If the hole is larger than 
necessary, it is split, with the process occupying the lower address range portion of the hole and 
the remainder being put on the free list. 

• Next Fit: This is like first fit, but begins searching the free list from the position where the 
previous hole was found. It if gets to the end of the free list without finding a large enough 
hole, it wraps around to the beginning. 

The details of the behaviour of the simulation are described on the following pages. You 
implementation
must follow the sequence of events listed.

A process size file is a sequence of entries which describe an initial queue of processes waiting 
to be swapped into memory from disk. The first entry is the head of the queue and the last is the 
tail of the queue. Each entry consists of a (process-id, memory-size) pair. For example:

4 98 
2 33 
1 100 
3 5 
This models an initial queue where process 4 is at the head of the queue and is 98 MB in size, 
process 2 is second in the queue and is size 33 MB, process 1 is third in the queue and is size 100 
MB, etc. 
Points to note: 

• Each process id is a unique positive integer. 

• Each process size is a positive integer ≤ m (the main memory size). 

We may assume the input file being read in will always be in the correct format. The simulation 
should behave as follows:

• Parse the process file to obtain the initial queue of processes waiting to be swapped into 
memory. 

• Assume memory is initially empty. 

• Load the processes from the queue into memory, one by one, according to one of the four algorithms. 

• If a process needs to be loaded, but there is no hole large enough to fit it, then processes 
should be swapped out, one by one, until there is a hole large enough to hold the process needing 
to be loaded.

• If a process needs to be swapped out, choose the one which has the largest size. If two processes 
have equal largest size, choose the one which has been in memory the longest (measured from the 
time it was most recently placed in memory). 

• After a process has been swapped out, it is placed at the end of the queue of processes waiting 
to be swapped in. 

• Once a process has been swapped out for the third time, we assume the process has finished and it 
is not re-queued. Note that not all processes will be swapped out for three times.

• The simulation should terminate once no more processes are waiting to be swapped into memory.


