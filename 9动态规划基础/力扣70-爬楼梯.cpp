#include<iostream>
#include<vector>

using namespace std;

// //记忆化搜索
// class Solution {
// public:
//     int climbStairs(int n) {
//         memo = vector<int>(n+1,-1);
//         return calcWays(n);
//     }
// private:
//     vector<int> memo;
//     int calcWays(int n){
//         if(n == 1)
//             return 1;
//         if(n == 2)
//             return 2;
//         if(memo[n] == -1){
//             memo[n] = calcWays(n - 1) + calcWays(n - 2);
//         }
//         return memo[n];
//     }
// };

//动态规划
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;

        vector<int>memo = vector<int>(n + 1, -1);
        memo[1] = 1;
        memo[2] = 2;
        for (int i = 3; i <= n; i++)
            memo[i] = memo[i - 1] + memo[i - 2];

        return memo[n];
    }
};

int main() {

	system("pause");
	return 0;
}