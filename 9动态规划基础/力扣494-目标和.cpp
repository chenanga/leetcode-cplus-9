#include<iostream>
#include<vector>

using namespace std;

// //回溯
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {

//         __findTargetSumWays(nums, 0, target, 0);
//         return count;
//     }
// private:
//     int count = 0;
//     //在nums[0...index)找是否能构成target
//     void __findTargetSumWays(vector<int>& nums, int index, int target, int sum){
//         if(index == nums.size()){
//             if(sum == target)
//                 count ++;
//             return;
//         }
//         __findTargetSumWays(nums, index + 1, target, sum + nums[index]);
//         __findTargetSumWays(nums, index + 1, target, sum - nums[index]);
//         return;
//     }
// };


//参考官方思路
//设添加负号的所有元素为neg，数组总和为sum，则添加正号的元素为sum-neg，那么则需要让正的元素减去负的元素==target
//即 sum-neg - neg == target, 得到neg = (sum-target)/2
/*由于数组nums 中的元素都是非负整数，neg 也必须是非负整数，所以上式成立的前提是sum−target 是非负偶数。
若不符合该条件可直接返回0。

若上式成立，问题转化成在数组nums 中选取若干元素，使得这些元素之和等于neg，计算选取元素的方案数。我们可以使用动态规划的方法求解。

*/
//dp[i][j]表示在数组nums的前i个元素中选取，使得这些元素和为j的方案数，即在[0...i-1]中选取
//dp[i][j] = dp[i-1][j](j < nums[i]), dp[i-1][j-nums[i-1]]  (j >= nums[i])
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for(int i : nums)
//             sum += i;
//         if(sum - target < 0 || (sum-target)%2 == 1)
//             return 0;
//         int neg = (sum - target) / 2;
//         int n = nums.size();
//         vector<vector<int>>memo (n + 1, vector<int>(neg + 1, 0));
//         memo[0][0] = 1;

//         for(int i = 1; i <= n; i ++){
//             for(int j = 0; j <= neg; j ++){
//                 if(j < nums[i-1])
//                     memo[i][j] = memo[i-1][j];
//                 else
//                     memo[i][j] = memo[i-1][j] + memo[i-1][j-nums[i-1]]; 
//             }
//         }
//         return memo[n][neg];
//     }
// };

// //使用了两行数组，空间比之前优化了
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for(int i : nums)
//             sum += i;
//         if(sum - target < 0 || (sum-target)%2 == 1)
//             return 0;
//         int neg = (sum - target) / 2;
//         int n = nums.size();
//         vector<vector<int>>memo (2, vector<int>(neg + 1, 0));
//         memo[0][0] = 1;

//         for(int i = 1; i <= n; i ++){
//             for(int j = 0; j <= neg; j ++){
//                 if(j < nums[i-1])
//                     memo[i%2][j] = memo[(i-1)%2][j];
//                 else
//                     memo[i%2][j] = memo[(i-1)%2][j] + memo[(i-1)%2][j-nums[i-1]]; 
//             }
//         }
//         return memo[n%2][neg];
//     }
// };

// //使用了1行数组，空间比之前优化了
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for(int i : nums)
//             sum += i;
//         if(sum - target < 0 || (sum-target)%2 == 1)
//             return 0;
//         int neg = (sum - target) / 2;
//         int n = nums.size();
//         vector<int> memo (neg + 1, 0);
//         memo[0] = 1;

//         for(int i = 1; i <= n; i ++){
//             for(int j = neg; j >= 0; j --){
//                 if(j < nums[i-1])
//                     memo[j] = memo[j];
//                 else
//                     memo[j] = memo[j] + memo[j-nums[i-1]]; 
//             }
//         }
//         return memo[neg];
//     }
// };

//使用了1行数组，空间比之前优化了,终止条件位置更改了
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum - target < 0 || (sum - target) % 2 == 1)
            return 0;
        int neg = (sum - target) / 2;
        int n = nums.size();
        vector<int> memo(neg + 1, 0);
        memo[0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = neg; j >= nums[i - 1]; j--)//这里终止条件变了位置，把if判断条件直接放这里了，可以提前终止循环，小小优化了
                memo[j] = memo[j] + memo[j - nums[i - 1]];

        return memo[neg];
    }
};

int main() {

	system("pause");
	return 0;
}