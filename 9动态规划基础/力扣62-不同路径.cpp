#include<iostream>
#include<vector>

using namespace std;

// //动态规划
// class Solution {
// public:
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> memo(m, vector<int>(n, 1));//初始化，最右边一条边和最下边一条边都是1
//         //memo[i][j]代表当前坐标到finish的不同路径数量
//         for(int i = m-2; i >=0; i --){
//             for(int j = n-2; j >= 0; j --){
//                 memo[i][j] = memo[i+1][j] + memo[i][j+1];
//             }
//         }
//         return memo[0][0];
//     }
// };

//
//动态规划,空间优化,s使用了两行数组
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);//初始化，最右边一个数1
        vector<int> next(n, 1);//初始化，最最下边一条边1

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                cur[j] = next[j] + cur[j + 1];
            }
            next = cur;
        }
        return cur[0];
    }
};

int main() {

	system("pause");
	return 0;
}