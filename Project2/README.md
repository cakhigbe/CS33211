# **Banker's Algorithm for Deadlock Avoidance.**

Programming assignment, provide the source codes, documents, and examples in details on github.

Requirements:
> + You are required to use C/C++ in Linux/Unix. You can consider install virtualBox in your non-Linux environment.
> + Programs must succeed in compilation and execute as required.
> + Readme, documentation and example are required.

Considers a system with five processes P0 through P4 and three resources of type A, B, C. 
Resource type A has 10 instances, B has 5 instances and type C has 7 instances. 

Suppose at time t0 following snapshot of the system has been taken:
![image](https://user-images.githubusercontent.com/70984569/206687135-fef783d4-332b-4fa6-940f-e06dbeb55008.png)

Implement's the Banker’s algorithm to answer the following question：
+ Is the system in a safe state? 
+ If Yes, then what is the safe sequence?
