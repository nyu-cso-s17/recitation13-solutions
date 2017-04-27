Recitation 13: Solutions
---------------------------

Assign points to the submissions based on the following:

1 point See if the parallel version has multiple threads (more than one) and give 1 point if some output is produced. Code should compile and run to produce an output, otherwise give 0.

1 point - The parallel version produces the correct output (299999995) all the time. This requires a lock (mutex) variable. The sample parallel.c implementation is included in this repository. 

2 points - 1 point for the two answers in the answers.txt file:
	
	1) Question: Why do you get different outputs? 
		Answer: Because multiple threads update an unprotected global variable concurrently.
	
	2) Question: How did the lock fix the problem we have before?
		Answer: All threads need to acquire the lock to update the global variable/sum and only one thread can access the lock at a time. This serializes accesses to the global sum and thus the sum is always correct.