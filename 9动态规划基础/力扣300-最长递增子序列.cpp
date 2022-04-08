#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //lis(i)表示以第i个数组作为结尾的最长上升子序列的长度
    //lis(i) = max(1 + lis(j) if nums[i] > nums[j]), for(0,i-1)
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        //memo[i]表示以第i个数组作为结尾的最长上升子序列的长度    
        vector<int> memo(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    memo[i] = max(memo[i], 1 + memo[j]);

        //方案1，直接排序从大到小，取第一个元素
        // sort(memo.begin(), memo.end(), greater<int>());
        // return memo[0];

        //方案2，循环一遍，取最大值,比方案1快一些，因为是取最大值，方案1是做了排序，多了一些无用操作
        int res = 1;
        for (int i = 0; i < nums.size(); i++)
            res = max(res, memo[i]);
        return res;

    }


};

int main() {

	system("pause");
	return 0;
}