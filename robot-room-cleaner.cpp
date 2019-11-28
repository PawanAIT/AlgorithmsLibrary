// Given a robot cleaner in a room modeled as a grid.

// Each cell in the grid can be empty or blocked.

// The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

// When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

// Design an algorithm to clean the entire room using only the 4 given APIs shown below.

// interface Robot {
//   // returns true if next cell is open and robot moves into the cell.
//   // returns false if next cell is obstacle and robot stays on the current cell.
//   boolean move();

//   // Robot will stay on the same cell after calling turnLeft/turnRight.
//   // Each turn will be 90 degrees.
//   void turnLeft();
//   void turnRight();

//   // Clean the current cell.
//   void clean();
// }
// Example:

// Input:
// room = [
//   [1,1,1,1,1,0,1,1],
//   [1,1,1,1,1,0,1,1],
//   [1,0,1,1,1,1,1,1],
//   [0,0,0,1,0,0,0,0],
//   [1,1,1,1,1,1,1,1]
// ],
// row = 1,
// col = 3

// Explanation:
// All grids in the room are marked by either 0 or 1.
// 0 means the cell is blocked, while 1 means the cell is accessible.
// The robot initially starts at the position of row=1, col=3.
// From the top left corner, its position is one row below and three columns right.
// Notes:

// The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
// The robot's initial position will always be in an accessible cell.
// The initial direction of the robot will be facing up.
// All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
// Assume all four edges of the grid are all surrounded by wall.

 public void cleanRoom(Robot robot) {
        // A number can be added to each visited cell
        // use string to identify the class
        Set<String> set = new HashSet<>();
        int cur_dir = 0;   // 0: up, 90: right, 180: down, 270: left
        backtrack(robot, set, 0, 0, 0);
    }

    public void backtrack(Robot robot, Set<String> set, int i, 
    			int j, int cur_dir) {
    	String tmp = i + "->" + j;
    	if(set.contains(tmp)) {
            return;
        }
        
    	robot.clean();
    	set.add(tmp);

    	for(int n = 0; n < 4; n++) {
        // the robot can to four directions, we use right turn
    		if(robot.move()) {
    			// can go directly. Find the (x, y) for the next cell based on current direction
    			int x = i, y = j;
    			switch(cur_dir) {
    				case 0:
    					// go up, reduce i
    					x = i-1;
    					break;
    				case 90:
    					// go right
    					y = j+1;
    					break;
    				case 180:
    					// go down
    					x = i+1;
    					break;
    				case 270:
    					// go left
    					y = j-1;
    					break;
    				default:
    					break;
    			}

    			backtrack(robot, set, x, y, cur_dir);
                       // go back to the starting position
			robot.turnLeft();
    			robot.turnLeft();
    			robot.move();
    			robot.turnRight();
    			robot.turnRight();

    		} 
    		// turn to next direction
    		robot.turnRight();
    		cur_dir += 90;
    		cur_dir %= 360;
    	}

    }


    class Solution {
public:
    unordered_map<int, unordered_map<int, int>> data;
    int x=0;
    int y=0;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int dir=0;
    void cleanRoom(Robot& robot) {
        if(data[x][y]==1){
            return;
        }
        data[x][y]=1;
        robot.clean();
        for(int i=0; i<4; i++){
            if(robot.move()){
                x+=dx[dir];
                y+=dy[dir];
                cleanRoom(robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                x-=dx[dir];
                y-=dy[dir];
            }
            robot.turnRight();
            dir=(dir+1)%4;
        }
    }
};