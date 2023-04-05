# runMaze using list() and Recursive function
We describe a maze as having row X col cells. For example if row was 3, and col was 4, then we would have a grid of cells as follows. We describe a wall by the two cell numbers the wall separates (smaller number first). If every single wall existed, there would be (row-1)(col) + (col-1)(row) walls.
```
  0 |  1 |  2 |  3 
-------------------  
  4 |  5 |  6 |  7
--------------------
  8 |  9 | 10 | 11

```
![6](https://user-images.githubusercontent.com/60019805/230239129-a75fe4e9-8ef3-4623-86da-bc06c27564a0.gif)
A Maze class (which you do not need to implement) describes a maze using the method described It has member functions that you can use to travel through the maze (ie figure out where you are, know what cells you can reach, etc.)

**A recursive maze runner:**
`int runMaze(Maze& theMaze, int path[], int fromCell, int toCell);`

The runMaze() function will find a path from cell number  _**fromCell**_  to cell number  _**toCell**_. function will "markup" theMaze with the path and pass back an array containing the path (using the cell numbers) from the starting cell to ending cell. The function will return the number of cells along the pathway from the starting cell to the ending cell inclusive.

For example, suppose the fromCell was 0 and the toCell was 3 using the maze below:

```
  0 |  1    2    3 
         ----------  
  4    5 |  6    7
----          
  8    9   10 | 11

```
runMaze() function would put the following into path: {0,4,5,1,2,3} and return 6
![8](https://user-images.githubusercontent.com/60019805/230239164-4429ae5b-fb19-437e-8d52-5a43486f37d8.gif)
# Lists
A list is an **sequence of values**. It may have properties such as being sorted/unsorted, having duplicate values or being unique. The most important part about list structures is that the data has an ordering (which is not the same as being sorted). Ordering simply means that there is an idea that there is a "first" item, a "second" item and so on. Lists typically have a subset of the following operations:

-   initialize
-   add an item to the list
-   remove an item from the list
-   search
-   sort
-   iterate through all items
-   and more...
    

A list may implement only a subset of the above functionality. The description of a list is very general and it can be implemented in a number of different ways.

Two general implementation methods are the array method or the linked list method. We will look at each in turn.
