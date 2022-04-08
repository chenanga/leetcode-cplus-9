#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];


        return max(tryRangeRob(nums, 0, nums.size() - 2), tryRangeRob(nums, 1, nums.size() - 1));
    }
private:
    //对num[start, end]进行偷窃，获得最大值
    int tryRangeRob(vector<int>& nums, int start, int end) {

        if (start > end) return 0;
        else if (start == end) return nums[start];
        //memo[i]表示考虑 偷取nums[0...i]所能获得的最大利益
        vector<int> memo(nums.size(), -1);

        memo[start] = nums[start];//初始化第一个房子
        memo[start + 1] = max(nums[start], nums[start + 1]); //初始化第二个

        for (int i = start + 2; i <= end; i++)
            //memo[i]等于 
            //1，不偷 第i个，偷前i-1个最大的
            //2，偷 第i个，偷前i-2个最大的
            memo[i] = max(memo[i - 1], nums[i] + memo[i - 2]);
        return memo[end];
    }

};


int main() {

	system("pause");
	return 0;
}