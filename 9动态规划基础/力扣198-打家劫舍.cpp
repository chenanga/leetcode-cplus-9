#include<iostream>
#include<vector>

using namespace std;

// //�Զ����£��ݹ�
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         memo = vector<int>(nums.size(), -1);
//         return tryRob(nums, 0);
//     }
// private:
//     //memo[i]��ʾ���� nums[i...n�����ܻ�õ��������
//     vector<int> memo; 

//     //�������� nums[index...nums.size()) �����Χ�ڵ����з���
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

// //��̬�滮1
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0) return 0;

//         //memo[i]��ʾ���� nums[i...n-1]���ܻ�õ��������
//         vector<int> memo(len, -1);

//         memo[len - 1] = nums[len - 1];//��ʼ�����һ������

//         for(int i = len - 2; i >= 0; i --){
//             //memo[i]
//             for(int j = i; j < len; j ++)//ÿ�γ��Դӵ�ǰ�������͵ȡ
//                 memo[i] = max(memo[i], nums[j] +(j + 2 < len ? memo[j+2] : 0));//��ֹj+2Խ��
//         }
//         return memo[0];
//     }

// };

//��̬�滮2,����һ�����岻һ��
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        //memo[i]��ʾ���� ͵ȡnums[0...i]���ܻ�õ��������
        vector<int> memo(len, -1);

        memo[0] = nums[0];//��ʼ����һ������

        for (int i = 1; i < len; i++)
            //memo[i]
            for (int j = i; j >= 0; j--)//ÿ�γ��Դ�i��ǰ͵ȡ
                memo[i] = max(memo[i], nums[j] + (j - 2 >= 0 ? memo[j - 2] : 0));//��ֹj-2Խ��

        return memo[len - 1];
    }
};

int main() {

	system("pause");
	return 0;
}