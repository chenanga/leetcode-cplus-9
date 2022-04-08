#include<iostream>
#include<vector>

using namespace std;



// //动态规划
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         //memo[i][j]代表当前坐标到finish的不同路径数量,long long 防止溢出
//         vector<vector<long>> memo(m, vector<long>(n, 0));//初始化,含有障碍物的格子也被置为0，后续不能更改含有障碍物的盒子
//         if(obstacleGrid[m-1][n-1] != 1)//如果右下角一格没有障碍物，则置为1
//             memo[m-1][n-1] = 1;

//         for(int i = n-2; i >= 0; i --)//初始化最下面一行
//             if(obstacleGrid[m-1][i] != 1)//如果当前格子无障碍物，则设置为和他的下一个相同，如果有障碍物，则跳过，因为初始化时候已经置0
//                 memo[m-1][i] = memo[m-1][i+1];

//         for(int i = m-2; i >= 0; i --)//初始化最右边一列
//             if(obstacleGrid[i][n-1] != 1)
//                 memo[i][n-1] = memo[i+1][n-1];

//         for(int i = m-2; i >=0; i --){
//             for(int j = n-2; j >= 0; j --){
//                 if(obstacleGrid[i][j] != 1)
//                 memo[i][j] = memo[i+1][j] + memo[i][j+1];
//             }
//         }
//         return memo[0][0];
//     }
// };

//动态规划，空间优化,使用两行数组
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //memo[i][j]代表当前坐标到finish的不同路径数量,long long 防止溢出
        vector<long>next(n, 0);

        if (obstacleGrid[m - 1][n - 1] != 1)//如果右下角一格没有障碍物，则置为1
            next[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)//初始化最下面一行
            if (obstacleGrid[m - 1][i] != 1)//如果当前格子无障碍物，则设置为和他的下一个相同，如果有障碍物，则跳过，因为初始化时候已经置0
                next[i] = next[i + 1];

        for (int i = m - 2; i >= 0; i--) {
            vector<long>cur(n, 0);
            if (obstacleGrid[i][n - 1] != 1)//初始化倒数第二行最右边一个数
                cur[n - 1] = next[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] != 1)
                    cur[j] = next[j] + cur[j + 1];
                else
                    cur[j] = 0;

            }
            next = cur;
        }

        return next[0];
    }
};

int main() {

	system("pause");
	return 0;
}