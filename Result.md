# RESULT
For our final project, we choose to use the OpenFlights data set to run our algorithm. 	Provided two cities, our goal is to find the shortest path between them. Then, we would like to find the most important airport in our data set and do a ranking for the airports.

First, we processed the dataset, what we need are only the Airports and Route subset of the original data. Then we transformed the original data into an array format. This is the most difficult part, because none of us did something like this before. We searched a lot of tutorials online before we knew how to do this. We created Airport and Route class to access the data we need, and we build the adjacent matrix to get the adjacent airports in Graph Class.

We have successfully implemented Traversals(BFS), Dijkstra’s, and PageRank Algorithm. To get the result of our program, we use ./finalproj to run our program. 

<br />
---
<br />

First, we test our **BFS algorithm**. The goal of BFS algorithm is to traverse all the connected airports given a root airports. 

A sentence in the terminal says to start testing BFS, and then we need to enter an airport's IATA code. Then we can get all connected airports of it (If A-B-C, we can consider A and C are connected). We also can get the number of the connected airports including itself. 

For examples, when we type in TSL as the airport’s IATA code, the output will be:

Your starting airport is “TSL”<br />
“TSL”<br />
1

This means the airport TSL has no connected airportes. 

Then if we type in ORD, it will show all the connected airports, 

Your starting airport is "ORD"
3214
BFS:
"ORD"
"YEG"
"YHZ"
......

This means that the number of connected airports of ORD is 3214 and the connected airports include "YEG", "YHZ" and so on. 

<br />
---
<br />

Next, we test our **PageRank algorithm**. The goal of the PageRank algorithm is to find the most important airport in our data set and list the ranking of the importance of the airports. 

We can type in anything we want to run this test. It will pop out the ranking of all airports, and each airport is represented by its IATA code. If there is no corresponding IATA code for that airport, it will display \N. The number shows the rank of the airports. 

I only show a few airports’ ranking displayed in the terminal:

Now it is the PageRank algorithm<br />
Press any keys to continue<br />
a<br />
Please wait for a second<br />
1:"FRA"<br />
2:"CDG"<br />
3:"AMS"<br />
4:"IST"<br />
5:"ATL"<br />

This shows the most important airport in our data set is "FRA". And shown output displays the top 5 important airports in our data set. 


<br />
---
<br />

Finally, we test our **Dijkstra algorithm**. The goal of the Dijkstra algorithm is to find the shortest path given two airports and calculate the shortest distance. 

We enter the IATA code of the source point, followed by the IATA code of the destination airport. According to the shortest route between these two points, all airports in the shortest route will be displayed in the terminal.

For example, when I try to get the shortest path between STL and GSJ. There is no path between them.

In terminal:

Now it is the Dijkstra algoritm <br />
Please enter the source airport you wanted to search<br />
STL    <br />
Please enter the destination airport you wanted to search<br />
GSJ<br />
Please wait for a second<br />
Our source airport is "STL"<br />
Our destination airport is "GSJ"<br />
There is no path between them.<br />

_Let’s test something else. When I try to test the shortest path between BFS and ORD. This will show up in the terminal:_

Now it is the Dijkstra algoritm <br />
Please enter the source airport you wanted to search<br />
BFS<br />
Please enter the destination airport you wanted to search<br />
ORD<br />
Please wait for a second<br />
Our source airport is "BFS"<br />
Our destination airport is "ORD"<br />
Shortest distance between them is 6160.36<br />
"BFS"<br />
"GLA"<br />
"YYZ"<br />
"ORD"<br />
