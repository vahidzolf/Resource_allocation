# Resource_allocation
A resource allocation algorithm implementation in C++

The cpp code file is the answer to the following question: 

Assume that you want to allocate 10 slots to a set of active users at each timestamps (e.g. each 1ms) as follows:
• Total number of users is 10, but not active at the same time.
• 5 active users can be scheduled at the same time in each slot.
• Users belong to two different groups depending on their ID, group id = UE id %2;
• Each resource block can transport a maximum of 10 kbytes, and there are 25 resource blocks in each slot.
• group 1 can have a maximum of 15 resource blocks per slot.
• The traffic arrival rate for each users follows the uniform distribution ranging from 1kbytes to 250 kbytes. The traffic is renewed every 10 ms.
• No QoS is considered (i.e. all the traffics have the same priority).

The C code generates an array of Demands of 10 users and their respective index, which is printed at the beginning of running the script. I have allocation matrix which it’s columns are resource blocks and it’s rows are for each slot. The allocation matrix is initialized with -1. The numbers inside the matrix are the index of user. 
