// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

 

// Example 1:

// Input 1: a maze represented by a 2D array

// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0

// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (4, 4)

// Output: true

// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

// Example 2:

// Input 1: a maze represented by a 2D array

// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0

// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (3, 2)

// Output: false

// Explanation: There is no way for the ball to stop at the destination.
// Note:

// There is only one ball and one destination in the maze.
// Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

class Cell {
        int x;
        int y;
        Cell(int x, int y){
            this.x=x;
            this.y=y;
        }
    }

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        boolean[][] visited = new boolean[maze.length][maze[0].length];
        int[][] directions = {{1,0},{-1,0},{0,1},{0,-1}};

        Cell cell = new Cell(start[0], start[1]);
        Queue<Cell> q = new LinkedList<>();
        q.add(cell);

        while (!q.isEmpty()){
            Cell cur = q.poll();
            visited[cur.x][cur.y]=true;

            if(cur.x==destination[0] && cur.y==destination[1]) return true;

            for(int[] direction : directions) {
                int newX = cur.x;
                int newY = cur.y;

                while(isValid(maze, newX+direction[0], newY+direction[1])){
                    newX+=direction[0];
                    newY+=direction[1];
                }

                if(!visited[newX][newY]) q.add(new Cell(newX, newY));
            }
        }

        return false;
    }

    private boolean isValid(int[][] maze, int x, int y) {
        return x >= 0 && y >= 0 && x<maze.length && y<maze[0].length && maze[x][y]==0;
    }