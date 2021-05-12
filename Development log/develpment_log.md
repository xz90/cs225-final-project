# CS 225 Data Structures
## Development log (baoyul2-sxxiao2-zikuiw2-xz90)

**April 13th**

Finish the makefile (need to add some files in makefile in the future).
Finish part of the ReadFromFile: FileToString, FileToVector

Next: getVector function and tests. Discussion of BFS traversal algorithm.

Recorder: baoyul2

**April 17th**

Finish the getVector function. Discussed how to do the BFS traversal. 
Assign tasks to finish the Airport clss, Route class, and Graph class, which are helpful for the following algorithms. 

Next: finish the BFS traversal. 

Recorder: baoyul2


**April 23th**

Finished the Airport class, Route class, and Graph class. Also finidhed the test cases for these class.
We tried to write the BFS algorithm but some bug still exists.

Next: find the bug existing in BFS algorithm. Also assign the tasks of Dijkstra algorithm and PageRank algorithm.

Recorder: zikuiw2


**April 27(Tuesday)**

We organized a zoom meeting for cooperation. 

First, we check the previous code we wrote before and solve the problem in the BFS. 
The problem with the code I wrote before is: 
I use the id of each airport to represent each airport. 
However, when we use a limited number of airports to test, the vector will be out of bound.

Therefore, we changed to use iterator to represent the index of airport. This can solve the problem of out of bound.

Then, we decided that our next job is to complete the test cases of both Graph and BFS.

***Note: this log was originally committed in a different file (Development_log2.md in our repo), this log then was copied into here. ***

Recorder: sxxiao2

**May 12(Tuesday)**

We organized a zoom meeting for cooperation. 

We finished algorithms and test cases implementation. Specifically, we implement pagerank and dijsktra algorithms successfully and finished their testing.

Then, we updated the README file and results file. At last, we record the presentation for our final project.

Recorder: xz90