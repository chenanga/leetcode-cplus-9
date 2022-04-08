#include<iostream>
#include<vector>

using namespace std;

// f(S):组成可选金额s所需的最少硬币数量
//F(S)=F(S−C)+1
//最优子结构,没做出来
//f(s)：组成可选金额s所需的最小硬币数量
//f(s) = f(s-c)+1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int max = amount + 1; //因为最小面值为1，最坏情况max为ammount
        //memo[i] = f[i]
        vector<int>memo(amount + 1, max);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (int j = 0; j < coins.size(); j++)
                //确保j-allCoins[i] >=0
                if (i >= coins[j])
                    memo[i] = min(memo[i], (memo[i - coins[j]] + 1));

        return (memo[amount] == max ? -1 : memo[amount]);
    }
};
int main() {

	system("pause");
	return 0;
}

/*
1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 5 5 5
	0 1 2 3 4 5 6 7 8 9 10 11 钱数

1	0 1 0 0 0 0 0 0 0 0 0 0
1	0 1 2 1 1 1 1 1 1 1 1 1
1	0 1 2 3 2 2 2 2 2 2 2 2
1	0 1 2 3 4 3 3 3 3 3 3 3
1	0 1 2 3 4 5 4 4 4 4 4 4
1	0 1 2 3 4 5 6 5 5 5 5 5
1	0 1 2 3 4 5 6 7 6 6 6 6
1	0 1 2 3 4 5 6 7 8 7 7 7
1	0 1 2 3 4 5 6 7 8 9 8 8
1	0 1 2 3 4 5 6 7 8 9 10 9
1	0 1 2 3 4 5 6 7 8 9 10 11
1	0 1 2 3 4 5 6 7 8 9 10 11
2	0 1 2 3 4 5 6 7 8 9 10 11
2	0 1 2 3 4 5 6 7 8 9 10 11
2	0 1 2 3 4 5 6 7 8 9 10 11
2	0 1 2 3 4 5 6 7 8 9 10 11
2	0 1 2 3 4 5 6 7 8 9 10 11
2	0 1 2 3 4 5 6 7 8 9 10 11
5	0 1 2 3 4 5 6 7 8 9 10 11
5	0 1 2 3 4 5 6 7 8 9 10 11
5	0 1 2 3 4 5 6 7 8 9 10 11

*/