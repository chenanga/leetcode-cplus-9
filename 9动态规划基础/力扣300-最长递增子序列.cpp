#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //lis(i)��ʾ�Ե�i��������Ϊ��β������������еĳ���
    //lis(i) = max(1 + lis(j) if nums[i] > nums[j]), for(0,i-1)
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        //memo[i]��ʾ�Ե�i��������Ϊ��β������������еĳ���    
        vector<int> memo(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    memo[i] = max(memo[i], 1 + memo[j]);

        //����1��ֱ������Ӵ�С��ȡ��һ��Ԫ��
        // sort(memo.begin(), memo.end(), greater<int>());
        // return memo[0];

        //����2��ѭ��һ�飬ȡ���ֵ,�ȷ���1��һЩ����Ϊ��ȡ���ֵ������1���������򣬶���һЩ���ò���
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