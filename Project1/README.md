# **Producer Consumer.**

Programming assignment, provide the source codes, documents, and examples in details on github.

Requirements:
> + You are required to use C/C++ in Linux/Unix. You can consider install virtualBox in your non-Linux environment.
> + Programs must succeed in compilation and execute as required.
> + Readme, documentation and example are required.

Problem Statement:
+ The producer generates items and puts items onto the table. 
+ The consumer will pick up items. 
+ The table can only hold two items at the same time. 
+ When the table is complete, the producer will wait. 
+ When there are no items, the consumer will wait. 
+ We use semaphores to synchronize producer and consumer.
+ Mutual exclusion should be considered. 
+ We use threads in the producer program and consumer program. 
+ Shared memory is used for the “table”.

We expect to use these two programs (producer and consumer) like this:
> $ gcc producer.c -pthread -lrt -o producer
> $ gcc consumer.c -pthread -lrt -o consumer
> $ ./producer & ./consumer &
