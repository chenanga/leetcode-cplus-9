#include<iostream>
#include<vector>

using namespace std;

//超出int最大范围了,也超出longlong范围了
//和322问题一样的解决思路
//f(target):表示总和为target的组合个数
//f(target - nums[i])
//f(target) =  0<=i<nums.size()-1, target-nums[i]>=0, f(target - nums[i])++
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {

//         vector<long long>memo (target + 1, 0);
//         memo[0] = 1; //组成和为0的组合有一种
//         for(int i = 1; i <= target; i ++)
//             for(int j = 0; j < nums.size(); j ++)
//                 if(i >= nums[j])
//                     memo[i] += memo[i-nums[j]] ;

//         return memo[target];

//     }
// };

// //由于题目不溢出，故溢出部分不影响结果，直接赋值0
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {

//         vector<long>memo (target + 1, 0);
//         memo[0] = 1; //组成和为0的组合有一种
//         for(int i = 1; i <= target; i ++)
//             for(int j = 0; j < nums.size(); j ++)
//                 if(i >= nums[j]){
//                     memo[i] += memo[i-nums[j]] ;
//                     if(memo[i] >= INT_MAX)
//                         memo[i] = 0; //防止溢出，溢出清0，由题意不影响结果
//                 }

//         return memo[target];
//     }
// };

// //由于题目不溢出，故溢出部分不影响结果，如果发现memo[i] + memo[i-nums[j]]小于INT_MAX 继续下一步，如果大于直接跳过
// //这里使用了long型数组
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {

//         vector<long>memo (target + 1, 0);
//         memo[0] = 1; //组成和为0的组合有一种
//         for(int i = 1; i <= target; i ++)
//             for(int j = 0; j < nums.size(); j ++)
//                 if(i >= nums[j] && memo[i] + memo[i-nums[j]] < INT_MAX)
//                     memo[i] += memo[i-nums[j]] ;


//         return memo[target];
//     }
// };

//小优化直接使用int数组。memo[i] + memo[i-nums[j]] < INT_MAX 前面部分可能会溢出，直接报错。可以使用memo[i] < INT_MAX - memo[i-nums[j]]
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<int>memo(target + 1, 0);
        memo[0] = 1; //组成和为0的组合有一种
        for (int i = 1; i <= target; i++)
            for (int j = 0; j < nums.size(); j++)
                if (i >= nums[j] && memo[i] < INT_MAX - memo[i - nums[j]])
                    //小优化直接memo[i] + memo[i-nums[j]] < INT_MAX 前面部分可能会溢出，直接报错。可以使用memo[i] < INT_MAX - memo[i-nums[j]]  
                    memo[i] += memo[i - nums[j]];


        return memo[target];
    }
};

int main() {

	system("pause");
	return 0;
}