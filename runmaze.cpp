#include "wall.h"
#include "maze.h"
/********************************************************************/
/*                                                                  */
/*  A1 Part 3: runMaze												*/
/*                                                                  */
/*  Author1 Name: Trang Nguyen			                            */
/*      - dlist.h										            */
/*  Author2 Name: Long Nguyen                                       */
/*      - runmaze.cpp									            */
/*                                                                  */
/********************************************************************/

// this function use to find the way out the maze. 
// it will receiving parameter including the maze, the path that was recorded when we are moving, the start (begin position) and the end (the way out position), 
// number of step that we need to get out the maze, and the first position that we start. 
// This function will return the number of Step as a requirement
int mazeRecursion(Maze& theMaze, int path[], int startCell, int endCell, int numOfStep, int theOriginalStart) { 
	int numOfCols = theMaze.numCols(); // get the num of column. that will help to calculate the next step up or down.
	
	if (startCell == endCell) {	//if the position is same at end Cell, it mean we found the way out :)
		if (numOfStep == 0) {
			path[numOfStep++] = startCell; // we need to record the last step
			theMaze.mark(startCell);	// also mark it that we reached this position.
		}
		return numOfStep; //return the number of step
	}
	else {
		if (numOfStep == 0) { // record first step
			path[numOfStep++] = startCell; //record first step and save it to path
			theMaze.mark(startCell); //mark that we reached the end.
			theOriginalStart = startCell; //also mark the position that we begin.
		}
		if (theMaze.canGo(startCell, startCell - numOfCols) && !theMaze.isMarked(startCell - numOfCols)) { // moving up using the position that we are standing, then minus num of column.
			theMaze.mark(startCell); //mark where we are standing
			theMaze.mark(startCell - numOfCols); //mark the next position we are going.
			path[numOfStep++] = startCell - numOfCols; //record the next position to the path.
			return mazeRecursion(theMaze, path, startCell - numOfCols, endCell, numOfStep, theOriginalStart);
		}
		if (theMaze.canGo(startCell, startCell + numOfCols) && !theMaze.isMarked(startCell + numOfCols)) { // moving up using the position that we are standing, then plus num of column.
			theMaze.mark(startCell); //mark where we are standing
			theMaze.mark(startCell + numOfCols); //mark the next position we are going.
			path[numOfStep++] = startCell + numOfCols; //record the next position to the path.
			return mazeRecursion(theMaze, path, startCell + numOfCols, endCell, numOfStep, theOriginalStart);
		}
		if (theMaze.canGo(startCell, startCell - 1) && !theMaze.isMarked(startCell - 1)) { // moving left using the position that we are standing, then minus 1.
			theMaze.mark(startCell); //mark where we are standing
			theMaze.mark(startCell - 1); //mark the next position we are going.
			path[numOfStep++] = startCell - 1; //record the next position to the path.
			return mazeRecursion(theMaze, path, startCell - 1, endCell, numOfStep, theOriginalStart);
		}
		if (theMaze.canGo(startCell, startCell + 1) && !theMaze.isMarked(startCell + 1)) { // moving right using the position that we are standing, then plus 1.
			theMaze.mark(startCell); //mark where we are standing
			theMaze.mark(startCell + 1); //mark the next position we are going
			path[numOfStep++] = startCell + 1; //record the next position to the path.
			return mazeRecursion(theMaze, path, startCell + 1, endCell, numOfStep, theOriginalStart);
		}
		if (theOriginalStart == startCell) { // if after moving up, down, left, right, the position is not change, it mean we cannot move
			return 0;						// also, it mean no wayout. IF, we moving, then back to the begin position, it mean we cannot found the way out. 
		}									// both case must return to 0 (as a requirement).
		else {
			theMaze.mark(path[numOfStep - 1]); //if we found the dead end, we need to back and mark the dead end is reach (then we will not coming back anymore)
			numOfStep--; // it also, we no need this step
			theMaze.unMark(path[numOfStep - 1]);	//unmark the previous postion, then moving back.
			return mazeRecursion(theMaze, path, path[numOfStep - 1], endCell, numOfStep, theOriginalStart);
		}
	}
}

int runMaze(Maze& theMaze, int path[], int startCell, int endCell){
	int numOfStep = 0;
	int theOriginalStart = -1;
	int arr[2000];
	int step=mazeRecursion(theMaze, arr, startCell, endCell, numOfStep, theOriginalStart); // I insert 2 more parameters to count the Num of Step (that what we need
	for (int i = 0; i < step; i++) {														// for this function will return, and the Original Start to know if there
		path[i] = arr[i];																	// is no way out (if we reach the begin place).
	}
	return step;
}

