For our final project, we choose to use the OpenFlights data set to run our algorithm. 	Provided two cities, our goal is to find the shortest path between them. Then, we would like to find the ranking of each airports.
First, we processed the dataset, what we need are only the Airports and Route subset of the original data. Then we transformed the original data into an array format. This is the most difficult part, because none of us did something like this before. We searched a lot of tutorials online before we knew how to do this. We created Airport and Route class to access the data we need, and we build the adjacent matrix to get the adjacent airports in Graph Class.

We have successfully implemented Traversals(BFS), Dijkstra’s, and PageRank Algorithm. 

To get the result of our program, we use ./finalproj to run our program. First, we test our BFS algorithm. A sentence in the terminal says to start testing BFS, and then we need to enter an airport's IATA code. Then we can get all the airports that this airport can go to. We also can get the number of airports it can reach.

From example, we I type in “TSL” as the airport’s IATA code, the output will be:

1
Your starting airport is “TSL”
“TSL”
1

This means the airport TSL has no place to go except itself.



Next, we test our Page Rank algorithm. We can type in anything we want to run this test. It will pop out the ranking of all airports, and each airport is represented by its IATA code. If there is no corresponding IATA code for that airport, it will display \N. The smaller the number, the higher the ranking of the airport. 
I only show a few airports’ ranking displayed in the terminal:

Now it is the PageRank algorithm
Press any keys to continue
a
Please wait for a second
7175:"CNR"
7176:"TLX"
7177:"ZIC"
7178:"TTC"
7179:"API"
7180:"CVE"
7181:"PAL"
7182:"PZA"
7183:\N
7184:"TQS"



Finally, we test our Dijkstra algorithm. We enter the IATA code of the source point, followed by the IATA code of the destination airport. According to the shortest route between these two points, all airports in the shortest route will be displayed in the terminal.

For example, when I try to get the shortest path between STL and GSJ. There is no path between them.

In terminal:

Now it is the Dijkstra algoritm 
Please enter the source airport you wanted to search
STL    
Please enter the destination airport you wanted to search
GSJ
Please wait for a second
Our source airport is "STL"
Our destination airport is "GSJ"
There is no path between them.

Let’s test something else. When I try to test the shortest path between BFS and ORD. This will show up in the terminal:

Now it is the Dijkstra algoritm 
Please enter the source airport you wanted to search
BFS
Please enter the destination airport you wanted to search
ORD
Please wait for a second
Our source airport is "BFS"
Our destination airport is "ORD"
Shortest distance between them is 6160.36
"BFS"
"GLA"
"YYZ"
"ORD"
