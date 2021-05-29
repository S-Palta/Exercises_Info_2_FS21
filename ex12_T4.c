#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define GRIDSIZE 7
#define MAXQSIZE 49

struct Point {
    int x;
    int y;
};

struct queueNode {
    struct Point pt;  // The coordinates of a cell
    int dist;  // cell's distance of from the source
};

bool isValid(int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < GRIDSIZE) &&
           (col >= 0) && (col < GRIDSIZE);
}

struct queueNode queue[MAXQSIZE];

int front = -1;
int rear = -1;
int size = -1;

bool q_isempty()
{
    return size < 0;
}

void q_enqueue(struct queueNode value){
    if(size < MAXQSIZE){
        if(size<0){
            queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXQSIZE-1){
            queue[0] = value;
            rear = 0;
            size++;
        } else {
            queue[rear+1] = value;
            rear++;
            size++;
        }
    } else {
        printf("Queue is full\n");
    }
}

int q_dequeue(){
    if(size<0){
        printf("Queue is empty\n");
    } else {
        size--;
        front++;
    }
}

struct queueNode q_front(){
    return queue[front];
}

int sp_algo(int A[GRIDSIZE][GRIDSIZE], struct Point start, struct Point end){
    // BFS
    // These arrays are used to get row and column
    // numbers of 4 neighbors of a given cell

    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    // initialise visited and add start to queue
    bool visited[GRIDSIZE][GRIDSIZE];
    memset(visited, false, sizeof visited);

    // Distance of source cell is 0
    struct queueNode start_node = {start, 0};
    q_enqueue(start_node);
    visited[start.x][start.y] = true;
    while(!q_isempty()){
        struct queueNode currentNode = q_front();
    
        struct Point pt = currentNode.pt;
 
        // If we have reached the destination cell, we are done
        if (pt.x == end.x && pt.y == end.y){
            return currentNode.dist;
        }
        // Dequeue the front 
        q_dequeue();

        //enqueue its neighbors (efficiently)
        int i;
        for (i = 0; i < 4; i++){
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
             
            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (isValid(row, col) && A[row][col] == '.' && !visited[row][col]){
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                struct queueNode adjCell = { {row, col},
                                      currentNode.dist + 1 };
                q_enqueue(adjCell);
            }
        }
    }
}

int main(void){
  int A[7][7] =
    {
        { '.', '.', '#', '.', '.', '#', '#'},
        { '.', '.', '#', '.', '.', '.', '.'},
        { '.', '.', '#', '.', '#', '.', '.'},
        { '.', '.', '#', '.', '#', '.', '#'},
        { '#', '.', '#', '.', '#', '.', '.'},
        { '.', '.', '#', '.', '.', '#', '.'},
        { '#', '.', '.', '.', '.', '.', '.'},
    };
  struct Point start = {0, 0};
  struct Point end = {2, 6};

  int spDist = sp_algo(A, start, end);
  printf("%d", spDist);
}