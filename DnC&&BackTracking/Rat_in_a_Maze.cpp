#include <iostream>

#include <vector>

using namespace std;

bool isSafe(vector<vector<bool>> visited, int newx, int newy, int row, int col, int maze[][4])
{
    if (
        (newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        (maze[newx][newy] == 1) && (visited[newx][newy] == false))
    {
        return true;
    }
    else
        return false;
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> visited ,bool pathfound)
{
    // base condition

    if (srcx == row - 1 && srcy == col - 1)
    {
        cout << output << endl;
        pathfound = true;
        return;
    }
    // up
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(visited, newx, newy, row, col, maze))
    {
        visited[newx][newy] = true;
        output.push_back('u');
        printAllPath(maze, row, col, newx, newy, output, visited,pathfound);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // down
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(visited, newx, newy, row, col, maze))
    {
        visited[newx][newy] = true;
        output.push_back('d');
        printAllPath(maze, row, col, newx, newy, output, visited,pathfound);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // right

    newx = srcx;
    newy = srcy + 1;
    if (isSafe(visited, newx, newy, row, col, maze))
    {
        visited[newx][newy] = true;
        output.push_back('r');
        printAllPath(maze, row, col, newx, newy, output, visited,pathfound);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // left

    newx = srcx;
    newy = srcy - 1;
    if (isSafe(visited, newx, newy, row, col, maze))
    {
        visited[newx][newy] = true;
        output.push_back('l');
        printAllPath(maze, row, col, newx, newy, output, visited,pathfound);
        output.pop_back();
        visited[newx][newy] = false;
    }

    
}

int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 0, 1},

    };

    int row = 4, col = 4, srcx = 0, srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    bool pathfound = false;
    if (maze[0][0] == 0)
    {
        cout << "There is no path exists";
    }
    else
    {
        printAllPath(maze, row, col, srcx, srcy, output, visited,pathfound);
    }
    if(!pathfound)
    {
        cout<<"no any path";
    }
    
    return 0;
}