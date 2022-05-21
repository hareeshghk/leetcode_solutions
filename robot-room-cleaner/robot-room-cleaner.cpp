/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

typedef pair<int,int> cell;
vector<vector<int>> dirs {{0,1},{1,0},{0,-1},{-1,0}};
class Solution {
public:
    void cleanRoom(Robot& robot) {
        set<cell> visited;
        visited.insert(cell(0,0));
        backtrack(robot, 0,0, visited, 0);
    }
    
    void backtrack(Robot& robot, int x, int y, set<cell> &visited, int direction) {
        int nextx, nexty;
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            nextx = x+ dirs[(direction+i)%4][0];
            nexty = y+ dirs[(direction+i)%4][1];
            if (visited.count(cell(nextx, nexty)) == 0 && robot.move()) {
                visited.insert(cell(nextx, nexty));
                backtrack(robot, nextx, nexty, visited, (direction+i)%4);
                gobackToOriginal(robot);
            }
            robot.turnRight();
        }
    }
    
    void gobackToOriginal(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};