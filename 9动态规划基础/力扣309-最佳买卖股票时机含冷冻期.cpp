#include<iostream>
#include<vector>

using namespace std;

//动态规划没有做出来，看了官方题解做出来的
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n <= 1) return 0;
//         //memo[i][0]代表第i天持有股票，说明是i-1天买入，或者i-1天就已经持有 max(memo[i-1][0],memo[i-1][2]-prices[i] )
//         //memo[i][1]代表第i天未持有股票，且处于冷冻期.说明i-1天持有，i天卖出 memo[i-1][0] + prices[i]
//         //memo[i][2]代表第i天未持有股票，且不处于冷冻期. i-1天时候是冷冻期或者一直不是max(memo[i-1][1],memo[i-1][2])
//     /*
//     memo[i][] 表示第 i 天结束之后的「累计最大收益
//     这里的「处于冷冻期」指的是在第 i 天结束之后的状态。
//     也就是说：如果第 i 天结束之后处于冷冻期，那么第 i+1天无法买入股票。
//     */
//         vector<vector<int>> memo(n, vector<int>(3, -1));
//         memo[0][0] = - prices[0]; //第0天持有的，只能是当天买的
//         memo[0][1] = 0; //代表第0天未持有股票，且不处于冷冻期
//         memo[0][2] = 0; //代表第0天未持有股票，且处于冷冻期

//         for(int i = 1; i < n; i ++){

//             memo[i][0] = max(memo[i-1][0], memo[i-1][2]-prices[i] );
//             memo[i][1] = memo[i-1][0] + prices[i];
//             memo[i][2] = max(memo[i-1][1],memo[i-1][2]);
//         }
//         //这里需要返回memo[n-1][0],memo[n-1][1],memo[n-1][2]的最大值
//         //但是由于如果最后一天持有股票肯定是没有另外两个高的，故也可以写成max(memo[n-1][1],memo[n-1][2])
//         // return max(max(memo[n-1][0],memo[n-1][1]),memo[n-1][2]);
//         return max(memo[n-1][1],memo[n-1][2]);

//     }
// };

//优化1，空间，由于每一天状态只和前一天有关
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        //memo[i][0]代表第i天持有股票，说明是i-1天买入，或者i-1天就已经持有 max(memo[i-1][0],memo[i-1][2]-prices[i] )
        //memo[i][1]代表第i天未持有股票，且处于冷冻期.说明i-1天持有，i天卖出 memo[i-1][0] + prices[i]
        //memo[i][2]代表第i天未持有股票，且不处于冷冻期. i-1天时候是冷冻期或者一直不是max(memo[i-1][1],memo[i-1][2])
    /*
    memo[i][] 表示第 i 天结束之后的「累计最大收益
    这里的「处于冷冻期」指的是在第 i 天结束之后的状态。
    也就是说：如果第 i 天结束之后处于冷冻期，那么第 i+1天无法买入股票。
    */

        vector<int> pre(3, 0);
        pre[0] = -prices[0];//初始化为0，且第一个元素置为- prices[0]

        vector<int> cur(3, -1);
        // memo[0][0] = - prices[0]; //第0天持有的，只能是当天买的
        // memo[0][1] = 0; //代表第0天未持有股票，且不处于冷冻期
        // memo[0][2] = 0; //代表第0天未持有股票，且处于冷冻期
        for (int i = 1; i < n; i++) {

            cur[0] = max(pre[0], pre[2] - prices[i]);
            cur[1] = pre[0] + prices[i];
            cur[2] = max(pre[1], pre[2]);
            pre = cur;
        }
        //这里需要返回memo[n-1][0],memo[n-1][1],memo[n-1][2]的最大值
        //但是由于如果最后一天持有股票肯定是没有另外两个高的，故也可以写成max(memo[n-1][1],memo[n-1][2])
        // return max(max(memo[n-1][0],memo[n-1][1]),memo[n-1][2]);
        return max(cur[1], cur[2]);

    }
};

int main() {

	system("pause");
	return 0;
}