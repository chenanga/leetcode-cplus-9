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
    //��num[start, end]����͵�ԣ�������ֵ
    int tryRangeRob(vector<int>& nums, int start, int end) {

        if (start > end) return 0;
        else if (start == end) return nums[start];
        //memo[i]��ʾ���� ͵ȡnums[0...i]���ܻ�õ��������
        vector<int> memo(nums.size(), -1);

        memo[start] = nums[start];//��ʼ����һ������
        memo[start + 1] = max(nums[start], nums[start + 1]); //��ʼ���ڶ���

        for (int i = start + 2; i <= end; i++)
            //memo[i]���� 
            //1����͵ ��i����͵ǰi-1������
            //2��͵ ��i����͵ǰi-2������
            memo[i] = max(memo[i - 1], nums[i] + memo[i - 2]);
        return memo[end];
    }

};


int main() {

	system("pause");
	return 0;
}