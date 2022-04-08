#include<iostream>
#include<vector>

using namespace std;


// //记忆化搜索
// class Solution {
// public:
//     int integerBreak(int n) {
//         memo = vector<int>(n+1, -1);
//         return breadkInteger(n);
//     }
// private:
//     vector<int> memo;
//     int max3(int a, int b, int c){
//         return max(a, max(b,c));
//     }
//     //将n进行分割（至少分割两部分），可以获得的最大乘积
//     int breadkInteger(int n){
//         if(n == 1) return 1;

//         if(memo[n] != -1)
//             return memo[n];

//         int res = -1;

//         for(int i = 1; i <= n - 1; i ++)
//             // i   n-i
//             res = max3(res, i * (n-i), i * breadkInteger(n-i));

//         memo[n] = res;

//         return res;
//     }
// };

//动态规划
class Solution {
public:
    int integerBreak(int n) {
        //memo[i]表示将数字i进行分割（至少分割两部分），可以获得的最大乘积
        vector<int>memo(n + 1, -1);
        memo[1] = 1;

        for (int i = 2; i <= n; i++)
            //求解memo[i]
            for (int j = 1; j <= i - 1; j++) {
                // j + (i - j)
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
            }

        return memo[n];
    }
private:
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
};

int main() {

	system("pause");
	return 0;
}