#include<iostream>
#include<vector>

using namespace std;

// //深度搜索，超时
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         __minPathSum(grid, 0, 0, 1, grid[0][0]);
//         sort(res.begin(), res.end(), less<int>());
//         return res[0];
//     }
// private:
//     int d[2][2] = {{0,1},{1,0}}; //向右，向下
//     int m,n;
//     vector<int>res;
//     bool inArea(int x, int y){
//         return x>=0 && x<m && y>=0 && y<n;
//     }
//     void __minPathSum(vector<vector<int>>& grid, int startx, int starty, int step, int cursum){
//         if(step == m+n-1){
//             res.push_back(cursum);
//             return;
//         }

//         for(int i = 0; i < 2; i ++){
//             int newx = startx + d[i][0];
//             int newy = starty + d[i][1];
//             if( inArea(newx, newy))
//                 __minPathSum(grid, newx, newy, step+1, cursum + grid[newx][newy]);

//         }
//         return;

//     }
// };

//递归，超时
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         return calcWays(grid, 0, 0);
//     }
// private:
//     int m,n;
//     bool inArea(int x, int y){
//         return x>=0 && x<m && y>=0 && y<n;
//     }
//     //计算当前点到右下角的最短距离
//     int calcWays(vector<vector<int>>& grid, int startx, int starty){

//         if( inArea(startx+0, starty+1) && inArea(startx+1, starty+0) )
//             return min(calcWays(grid, startx, starty+1), calcWays(grid,startx+1,starty)) + grid[startx][starty];
//         else if(inArea(startx, starty+1))
//             return calcWays(grid, startx, starty+1) + grid[startx][starty];
//         else if(inArea(startx+1, starty))
//             return calcWays(grid,startx+1,starty) + grid[startx][starty];
//         else    
//             return grid[startx][starty]; //此时是最后右下角的数字

//     }
// };


// //记忆化搜索
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         dp = vector<vector<int>>(m, vector<int>(n, -1));
//         return calcWays(grid, 0, 0);
//     }
// private:
//     int m,n;
//     bool inArea(int x, int y){
//         return x>=0 && x<m && y>=0 && y<n;
//     }
//     vector<vector<int>> dp;//记忆当前点距离右下角的最短距离
//     //计算当前点到右下角的最短距离
//     int calcWays(vector<vector<int>>& grid, int startx, int starty){
//         if(dp[startx][starty] != -1)
//             return dp[startx][starty];
//         if( inArea(startx+0, starty+1) && inArea(startx+1, starty+0) )
//             return dp[startx][starty] = min(calcWays(grid, startx, starty+1), calcWays(grid,startx+1,starty)) + grid[startx][starty];
//         else if(inArea(startx, starty+1))
//             return dp[startx][starty] = calcWays(grid, startx, starty+1) + grid[startx][starty];
//         else if(inArea(startx+1, starty))
//             return dp[startx][starty] = calcWays(grid,startx+1,starty) + grid[startx][starty];
//         else    
//             return dp[startx][starty] = grid[startx][starty]; //此时是最后右下角的数字

//     }
// };

// //记忆化搜索,优化1，边界判断修改
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         dp = vector<vector<int>>(m, vector<int>(n, -1));
//         return calcWays(grid, 0, 0);
//     }
// private:
//     int m,n;

//     vector<vector<int>> dp;//记忆当前点距离右下角的最短距离
//     //计算当前点到右下角的最短距离
//     int calcWays(vector<vector<int>>& grid, int startx, int starty){
//         if(startx == m-1 && starty == n-1)
//             return dp[startx][starty] = grid[startx][starty]; //此时是最后右下角的数字
//         if(dp[startx][starty] != -1)
//             return dp[startx][starty];

//         if(startx == m-1)
//             return dp[startx][starty] = calcWays(grid, startx, starty+1) + grid[startx][starty];
//         else if(starty == n-1)
//             return dp[startx][starty] = calcWays(grid,startx+1,starty) + grid[startx][starty];
//         else
//             return dp[startx][starty] = min(calcWays(grid, startx, starty+1), calcWays(grid,startx+1,starty)) + grid[startx][starty];    


//     }
// };

//动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp;//记忆当前点距离右下角的最短距离
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        //初始化dp数组最右边一列
        for (int i = m - 2; i >= 0; i--)
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];

        //初始化dp数组最下边一行
        for (int i = n - 2; i >= 0; i--)
            dp[m - 1][i] = dp[m - 1][i + 1] + grid[m - 1][i];

        //初始化其他地方，从下往上，从右往左
        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];

        return dp[0][0];
    }
};

int main() {

	system("pause");
	return 0;
}