# baoyul2-sxxiao2-zikuiw2-xz90
##### (1) The location of all major code, data, and results.
We have used the airports and routes data for our final project, which are stored in the “**airports.dat.txt**” and “**routes.dat.txt**”, respectively. 
We have created “**Airport**” and “**Route**” class to access some data such as airports’ ID, name, IATA, position, location and altitude; routes’ IATA, source airport, destination airport and stops. 
The “**Graph**” class is to build the adjacent matrix and get the adjacent airports, which is helpful for the following algorithms. 
The “**BFS**” class performs Breadth First Search Algorithm, which can traverse and show all the connected airports given a root airport. 
The “**Dijkstra**” class performs Dijkstra’s Algorithm, which is used to find the shortest path given a source airport and destination airport, and calculate the shortest distance between these two airports. 
The “**PageRank**” class performs PageRank Algorithm, which is used to measure the importance of each airport and conduct a ranking for all the airports in our data set. 
The “**ReadFromFile**” file is used to transform the data in txt file into string and vectors, which are used in “main.cpp” to perform our results. 
The **tests** file stores our test for all the algorithms and functions. 

##### (2) Full instructions on how to build and run your executable, including how to define the input data and output location for each method. 
The way to build our executable is to type in `make` in our repository. Then we will obtain our executable `finalproj`. To run our executable, we just need to type in the code `./finalproj`
1. After succesfully execute our executable, please wait for a second for processing data.
2. Then the command line will pop out our first algorithm: ***BFS algorithm*** . Just typing in one random airport's IATA code (in uppercases letter), e.g. `ORD`, as the starting point of BFS algorithm. If the input is not listed in our data set, it will be required to retype it. Then wait a second and the result of such BFS traversal will show in the command line.
3. After popping out the result, the command line will then show we entered the executation of ***PageRank algorithm***. Typing into anything to execute the PageRank algorithm. It will correctly show our pagerank result.
4. Finally we entered to execute our ***Dijkstra's algorithm***. Just like above, please typing in the source airport's IATA code and destination's IATA code, e.g. `PVG` for source Airport and `GKA` for our destination airport. Then if everything is successful, the shortest distance with its corresponding shortest path will be shown.

##### (3) Full instructions how to build and run your test suite, including a general description on what tests you have created. It is in your best interest to make the instructions (and the running of your executables and tests) as simple and straightforward as possible.
**Instruction:**
To build and run our test case, it is simple to implement. You just need to input this command in your terminal: `make test` and `./test`. Then, you can test all the test cases that we designed. All the tests are expected to be passed.
Specifically, we created basic test cases for each function in each designed class:
**readFile class test cases 
Airport class test cases
Route class test cases
Graph and BFS test cases
PageRank test cases
Dijkstra test cases**
Each of these cases are marked with explanation on both the the first line and the last line for the ease of reading. e.g.: 
>// TEST CASES FOR ROUTE CLASS <br>
... <br>
// END OF TEST CASES FOR ROUTE CLASS

##### (4) Here is the link to our video:
https://youtu.be/clXhWeD3bqE