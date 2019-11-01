# Resource_allocation
A resource allocation algorithm implementation in C++

Assume that you want to allocate 10 slots to a set of active users at each timestamps (e.g. each 1ms) as follows:<br/>
• Total number of users is 10, but not all of them are active (sending traffic) at the same time.<br/>
• A maximum of 5 active users can be scheduled at the same time in each slot.<br/>
• Users belong to two different groups depending on their ID, group id = UE id %2;<br/>
• Each resource block can transport a maximum of 10 kbytes, and there are 25 resource blocks in each slot.<br/>
• group 1 can have a maximum of 15 resource blocks per slot.<br/>
• The traffic arrival rate for each users follows the uniform distribution ranging from 1kbytes to 250 kbytes. The traffic is renewed every 10 ms.<br/>
• No QoS is considered (i.e. all the traffics have the same priority).<br/>
<br/>
the scheduler prints the scheduling decision at each slot for each group. It generates an array of Demands of 10 users and their respective index, which is shown at the beginning. It contains  allocation matrix which it’s columns are resource blocks and each row corrsponds to each slot. The allocation matrix is initialized with -1. The numbers inside the matrix are the index of user.
