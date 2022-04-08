#include<iostream>
#include<vector>

using namespace std;

//包含输出测试的
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if(nums.size() == 1) return 1;
//         //memo[i][0] 为第i个元素结尾的降序的最大摆动序列，降序指的是上一个元素到元素i是降序
//         //memo[i][1] 为第i个元素结尾的升序的最大摆动序列，升序指的是上一个元素到元素i是升序
//         vector<vector<int>> memo(nums.size(), vector<int>(2, 1));//初始化
//         //转移方程为
//         //j降序的 + 1 ，if nums[i] > nums[j],  0 < j < i-1
//         //j升序的 + 1 ，if nums[i] < nums[j],  0 < j < i-1
//         for(int i = 1; i < nums.size(); i ++){
//             // cout<<"第"<<i<<"轮开始------"<<endl;
//             for(int j = 0; j < i; j ++){
//                 // cout<<"更新前-第"<<j<<"小轮:"<<"memo[i][0] = "<<memo[i][0]<<", memo[i][1] = "<<memo[i][1]<<endl;

//                 if(nums[i] < nums[j])
//                     memo[i][0] = max(memo[i][0], memo[j][1] + 1);
//                 if(nums[i] > nums[j])
//                     memo[i][1] = max(memo[i][1], memo[j][0] + 1);
//                 // cout<<"更新后-第"<<j<<"小轮:"<<"memo[i][0] = "<<memo[i][0]<<", memo[i][1] = "<<memo[i][1]<<endl;
//             }
//             // cout<<"第"<<i<<"轮结束#######"<<endl;
//         }
//         int res = 1;
//         for(int i = 0; i < nums.size(); i ++){
//             res = max(res, memo[i][0]);
//             res = max(res, memo[i][1]);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if(nums.size() == 1) return 1;
//         //memo[i][0] 为第i个元素结尾的降序的最大摆动序列，降序指的是上一个元素到元素i是降序
//         //memo[i][1] 为第i个元素结尾的升序的最大摆动序列，升序指的是上一个元素到元素i是升序
//         vector<vector<int>> memo(nums.size(), vector<int>(2, 1));//初始化
//         //转移方程为
//         //j降序的 + 1 ，if nums[i] > nums[j],  0 < j < i-1
//         //j升序的 + 1 ，if nums[i] < nums[j],  0 < j < i-1
//         for(int i = 1; i < nums.size(); i ++)
//             for(int j = 0; j < i; j ++){

//                 if(nums[i] < nums[j])
//                     memo[i][0] = max(memo[i][0], memo[j][1] + 1);
//                 if(nums[i] > nums[j])
//                     memo[i][1] = max(memo[i][1], memo[j][0] + 1);
//             }

//         int res = 1;
//         for(int i = 0; i < nums.size(); i ++){
//             res = max(res, memo[i][0]);
//             res = max(res, memo[i][1]);
//         }
//         return res;
//     }
// };

//基于官方的优化
//证明出来i一定只和i-1有关
//
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        //memo[i][0] 为第i个元素结尾的降序的最大摆动序列，降序指的是上一个元素到元素i是降序
        //memo[i][1] 为第i个元素结尾的升序的最大摆动序列，升序指的是上一个元素到元素i是升序
        vector<vector<int>> memo(nums.size(), vector<int>(2, 1));//初始化
        //转移方程为
        //j降序的 + 1 ，if nums[i] > nums[j],  0 < j < i-1
        //j升序的 + 1 ，if nums[i] < nums[j],  0 < j < i-1
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < nums[i - 1]) {
                memo[i][0] = max(memo[i][0], memo[i - 1][1] + 1);
                memo[i][1] = memo[i - 1][1];
            }
            else if (nums[i] > nums[i - 1]) {
                memo[i][1] = max(memo[i][1], memo[i - 1][0] + 1);
                memo[i][0] = memo[i - 1][0];
            }
            else {
                memo[i][0] = memo[i - 1][0];
                memo[i][1] = memo[i - 1][1];
            }
        }

        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, memo[i][0]);
            res = max(res, memo[i][1]);
        }
        return res;
    }
};


//待写，空间优化

int main() {

	system("pause");
	return 0;
}
