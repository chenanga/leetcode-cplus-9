#include<iostream>
#include<vector>

using namespace std;

// //自顶向下，递归
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         memo = vector<int>(nums.size(), -1);
//         return tryRob(nums, 0);
//     }
// private:
//     //memo[i]表示考虑 nums[i...n）所能获得的最大利益
//     vector<int> memo; 

//     //考虑抢劫 nums[index...nums.size()) 这个范围内的所有房子
//     int tryRob(vector<int>& nums, int index){
//         if(index >= nums.size())
//             return 0;
//         if(memo[index] != -1)
//             return memo[index];
//         int res = 0;
//         for(int i = index; i <nums.size(); i ++){
//             res = max(res, nums[i] + tryRob(nums, i + 2));
//         }
//         memo[index] = res;
//         return memo[index];
//     }
// };

// //动态规划1
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0) return 0;

//         //memo[i]表示考虑 nums[i...n-1]所能获得的最大利益
//         vector<int> memo(len, -1);

//         memo[len - 1] = nums[len - 1];//初始化最后一个房子

//         for(int i = len - 2; i >= 0; i --){
//             //memo[i]
//             for(int j = i; j < len; j ++)//每次尝试从当前房子向后偷取
//                 memo[i] = max(memo[i], nums[j] +(j + 2 < len ? memo[j+2] : 0));//防止j+2越界
//         }
//         return memo[0];
//     }

// };

//动态规划2,和上一个定义不一样
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        //memo[i]表示考虑 偷取nums[0...i]所能获得的最大利益
        vector<int> memo(len, -1);

        memo[0] = nums[0];//初始化第一个房子

        for (int i = 1; i < len; i++)
            //memo[i]
            for (int j = i; j >= 0; j--)//每次尝试从i往前偷取
                memo[i] = max(memo[i], nums[j] + (j - 2 >= 0 ? memo[j - 2] : 0));//防止j-2越界

        return memo[len - 1];
    }
};

int main() {

	system("pause");
	return 0;
}