# CS 225 Data Structures
## Project Proposal (rittika2-gcevans-xz33-atharva2)

1. **Leading Question** Given two cities, we would like to find the shortest route between them with the shortest number of connections.
   Then, we would like to display this route on an interactive map of the globe.
2. **Dataset Acquistion and Processing** We propose using the [OpenFlights Dataset](https://openflights.org/data.html). We will focus on the
   Route subset of this data, which consists of airline information, source airport, destination airport, and number of stops. This data is 
   provided in a `*.dat` format, and we will cite this reference from [Stack Overflow](https://stackoverflow.com/questions/15528468/how-to-read-dat-files-in-c)
   to load the data into an array format. For our graph structure, we propose that the nodes will be the airport ID and an edge will exist between
   two nodes if there exists a flight, or route, between those two airports. We will assign the weights of each edge to be (1/number of routes).
   We recognize that this data is large, and potentially error-ridden; thus, we will drop any records that don't contain all of the fields and/or
   any malformed records.
3. **Graph Algorithms** For our graph traversal, we propose to implement a simple BFS using an iterator. We expect the input to our iterator
   constructor to be the starting airport ID node. Every time we call `operator++` on our implemented iterator, we expect it to update its internal
   position to a new airport ID node, until there are no nodes left to traverse. 
   
   For one of our algorithms, we propose implementing Dijikstra's Algorithm. We expect the input to be the starting airport ID node and the destination
   airport ID node. We expect the output to be the shortest path with the smallest number of connections from the starting airport to the destination
   airport.
   
   For our final algorithm, we propose projecting our found shortest path (subgraph) onto a world map, using the locations of the airport IDs. We will 
   map the respective latitude and longitudes of each airport onto the map, and then project our graph. We expect the input to be the shortest path
   found using our Dijikstra's Algorithm implementation.
4. **Timeline** 

   April 7 - sync to complete project proposal and team contract
   
   April 9 - submit project proposal and team contract
   
   April 12 - set up initial repository and Makefile
   
   April 15 - finish reading in data into array format and write simple tests to verify correctness
   
   April 19 - convert array format into graph format and pass simple tests
   
   April 22 - write BFS iterator and verify with tests
   
   April 29 - write Dijikstra's and verify with tests
   
   May 5 - write graph projection onto World Map and verify with tests
   
   May 7 - finish report
   
   May 9 - sync to record final presentation
   
   May 11 - finish editing presentation and submit
