#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

// //计算出来每个strs对应的0，1个数
// //nums[i][0]表示第strs[i]含有0的个数
// //nums[i][1]表示第strs[i]含有1的个数

// //memo[i][j]表示i个0和j个1能表示的最大子集长度
// //memo[i][j] = 从 nums[i][] nums[n][] 且
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> nums(strs.size(), vector<int>(2, 0));
//         for(int i = 0; i < strs.size(); i ++)
//             for(int j = 0; j < strs[i].size(); j ++){
//                 if(strs[i][j] == '0')
//                     nums[i][0]++;
//                 else if(strs[i][j] == '1')
//                     nums[i][1]++;
//             }

//         vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0)); //memo[i][j]表示i个0和j个1能表示的最大子集长度

//         for(int i = 1; i <= m; i ++){
//             for(int j = 1; j <= n; j ++){
//                 // cout<<" memo["<<i<<"]["<<j<<"] = "<<memo[i][j];
//                 for(int k = 0; k < nums.size(); k ++){
//                     if(i >= nums[k][0] && j >= nums[k][1])
//                         memo[i][j] = max(memo[i][j],  memo[i-nums[k][0]][j-nums[k][1]]);
//                 }
//                 memo[i][j] += 1;
//                 cout<<"memo["<<i<<"]["<<j<<"] = "<<memo[i][j]<<"  ";
//             }
//             cout<<endl;
//         }

//         return memo[m][n];
//     }
// };


// //通过64/71个用例, ac了，原因是三重循环的j和k应该从0开始，之前写成从1开始
// //计算出来每个strs对应的0，1个数
// //nums[i][0]表示第strs[i]含有0的个数
// //nums[i][1]表示第strs[i]含有1的个数

// //memo[i][j][k] 考虑放入第strs[i]和不放入的最大值
// //memo[i][j][k] = 从 nums[i][] nums[n][] 且
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

//         for(int i = 0; i < strs.size(); i ++)
//             for(int j = 0; j < strs[i].size(); j ++){
//                 // if(strs[i][j] == '0')
//                 //     nums[i][0]++;
//                 // else if(strs[i][j] == '1')
//                 //     nums[i][1]++;
//                 //优化后如下所示
//                 nums[i][strs[i][j] - '0']++;
//             }

//         vector<vector<vector<int>>> memo(nums.size(),vector<vector<int>>(m + 1, vector<int>(n + 1, 0))); //memo[i][j][k]表示考虑放入和不放入strs[i], j个0和k个1能表示的最大子集长度
//         for(int i = 0; i <= m; i ++){
//             for(int j = 0; j <= n; j ++)
//             if(i >= nums[0][0] && j >= nums[0][1])
//                 memo[0][i][j] = 1;
//         }
//         for(int i = 1; i < nums.size(); i ++){
//             for(int j = 0; j <= m; j ++){
//                 for(int k = 0; k <= n; k ++){

//                     memo[i][j][k] = memo[i-1][j][k];
//                     if( j >= nums[i][0] && k >= nums[i][1])
//                         memo[i][j][k] = max(memo[i][j][k], 1 + memo[i-1][j-nums[i][0]][k-nums[i][1]]);

//                 }
//             }
//         }
//         return memo[strs.size()-1][m][n];
//     }
// };

// //使用滚动数组方式，，节省空间，空间消耗从99.9MB降为11.5MB
// //使用了两行数组
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

//         for(int i = 0; i < strs.size(); i ++)
//             for(int j = 0; j < strs[i].size(); j ++)
//                 nums[i][strs[i][j] - '0']++;

//         vector<vector<vector<int>>> memo(2,vector<vector<int>>(m + 1, vector<int>(n + 1, 0))); //memo[i][j][k]表示考虑放入和不放入strs[i], j个0和k个1能表示的最大子集长度
//         for(int i = 0; i <= m; i ++){
//             for(int j = 0; j <= n; j ++)
//             if(i >= nums[0][0] && j >= nums[0][1])
//                 memo[0][i][j] = 1;
//         }
//         for(int i = 1; i < nums.size(); i ++){
//             for(int j = m; j >= 0; j --){
//                 for(int k = n; k >= 0; k --){

//                     memo[i%2][j][k] = memo[(i-1)%2][j][k];
//                     if( j >= nums[i][0] && k >= nums[i][1])
//                         memo[i%2][j][k] = max(memo[i%2][j][k], 1 + memo[(i-1)%2][j-nums[i][0]][k-nums[i][1]]);

//                 }
//             }
//         }
//         return memo[(strs.size()-1)%2][m][n];
//     }
// };

//使用一行数组，倒叙，节省空间 时间

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> nums(strs.size(), vector<int>(2, 0));

        for (int i = 0; i < strs.size(); i++)
            for (int j = 0; j < strs[i].size(); j++)
                nums[i][strs[i][j] - '0']++;

        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0)); //memo[i][j][k]表示考虑放入和不放入strs[i], j个0和k个1能表示的最大子集长度
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++)
                if (i >= nums[0][0] && j >= nums[0][1])
                    memo[i][j] = 1;
        }
        for (int i = 1; i < nums.size(); i++)
            for (int j = m; j >= nums[i][0]; j--)
                for (int k = n; k >= nums[i][1]; k--) {

                    memo[j][k] = max(memo[j][k], 1 + memo[j - nums[i][0]][k - nums[i][1]]);
                }


        return memo[m][n];
    }
};


//官方题解，思路基本一样
// class Solution {
// public:
//     vector<int> getZerosOnes(string& str) {
//         vector<int> zerosOnes(2);
//         int length = str.length();
//         for (int i = 0; i < length; i++) {
//             zerosOnes[str[i] - '0']++;
//         }
//         return zerosOnes;
//     }

//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int length = strs.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         for (int i = 0; i < length; i++) {
//             vector<int>&& zerosOnes = getZerosOnes(strs[i]);
//             int zeros = zerosOnes[0], ones = zerosOnes[1];
//             for (int j = m; j >= zeros; j--) {
//                 for (int k = n; k >= ones; k--) {
//                     dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

int main() {

    system("pause");
    return 0;
}