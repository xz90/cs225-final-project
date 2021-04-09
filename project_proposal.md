# CS 225 Data Structures
## Project Proposal (baoyul2-sxxiao2-zikuiw2-xz90)

1. **Leading Question** Provided two cities, our goal is to find the shortest route between these cities' airports with the shortest number of connections.
   Then, we would like to find out the mapping of each airports. 
2. **Dataset Acquistion and Processing** We propose using the [OpenFlights Dataset](https://openflights.org/data.html). We will focus on the
   Airports and Route subset of this data, which consists of airports information (Airport ID, latitude, longtitude, and altitude) in airports.dat and airlines information (source airport, destination airport, and number of stops) in routes.dat. This information is available in a `*.dat` format, and we will cite this reference from [StackOverflow](https://stackoverflow.com/questions/15528468/how-to-read-dat-files-in-c)
   to load the data into an array format. In our graph structure, we plan to set the IATA of the airport to node and the route to edges between two airports. The inverse of number of routes between two airports is weights. We will also process the data to remove some wrong information and ignore the airports without IATA number.
   
3. **Graph Algorithms** For our graph traversal, we decided to implement BFS using an iterator. Our input to the iterator constructor would be the starting IATA node. Every time we call `operator++` on our implemented iterator to update its internal
   position to a new airport's IATA node, until no nodes being left to traverse. 
   
   In terms of finding the shortest route between two airports, we decided to use the Dijikstra's Algorithm. Our input will be the starting IATA node and destination IATA node. Our output should be the shortest route between these cities' airports with the shortest number of connections.
   
   Finally, we will measure the significance of the airports using PageRank algorithm. In the routes data set, we have 3321 routes between the airports, with which we can use to count the number and quality of links among the airports to determine a rough estimate of how significant the airport is. The underlying assumption is that more import airports are likely to receive more links from other airports. 

4. **Timeline** 

   April 9 - submit project proposal, team contract and  initial repository

   April 11 - learn how to write Makefile

   April 13 - finish Makefile

   April 15 - read from files and convert the input data into array format in c++

   April 17 - learn how to write some simple test cases, and be able to pass these test cases. 

   April 19 - start to implement BFS to iterate through all the data 

   April 21 - write test cases for BFS traversal and pass them

   April 22/23 - finish BFS traversal and meet with project mentor
   
   April 24 - write Dijikstra's algorithm and verify with test cases

   April 29 - wrtie page rank and verify with tests

   May 6 - finish page rank
   
   May 7 - be able to run through the whole program and start to write final project report
   
   May 9 - record final presentation
   
   May 11 - submit presentation
