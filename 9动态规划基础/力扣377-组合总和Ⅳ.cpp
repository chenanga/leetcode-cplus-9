#include<iostream>
#include<vector>

using namespace std;

//����int���Χ��,Ҳ����longlong��Χ��
//��322����һ���Ľ��˼·
//f(target):��ʾ�ܺ�Ϊtarget����ϸ���
//f(target - nums[i])
//f(target) =  0<=i<nums.size()-1, target-nums[i]>=0, f(target - nums[i])++
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {

//         vector<long long>memo (target + 1, 0);
//         memo[0] = 1; //��ɺ�Ϊ0�������һ��
//         for(int i = 1; i <= target; i ++)
//             for(int j = 0; j < nums.size(); j ++)
//                 if(i >= nums[j])
//                     memo[i] += memo[i-nums[j]] ;

//         return memo[target];

//     }
// };

// //������Ŀ���������������ֲ�Ӱ������ֱ�Ӹ�ֵ0
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {

//         vector<long>memo (target + 1, 0);
//         memo[0] = 1; //��ɺ�Ϊ0�������һ��
//         for(int i = 1; i <= target; i ++)
//             for(int j = 0; j < nums.size(); j ++)
//                 if(i >= nums[j]){
//                     memo[i] += memo[i-nums[j]] ;
//                     if(memo[i] >= INT_MAX)
//                         memo[i] = 0; //��ֹ����������0�������ⲻӰ����
//                 }

//         return memo[target];
//     }
// };

// //������Ŀ���������������ֲ�Ӱ�������������memo[i] + memo[i-nums[j]]С��INT_MAX ������һ�����������ֱ������
// //����ʹ����long������
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {

//         vector<long>memo (target + 1, 0);
//         memo[0] = 1; //��ɺ�Ϊ0�������һ��
//         for(int i = 1; i <= target; i ++)
//             for(int j = 0; j < nums.size(); j ++)
//                 if(i >= nums[j] && memo[i] + memo[i-nums[j]] < INT_MAX)
//                     memo[i] += memo[i-nums[j]] ;


//         return memo[target];
//     }
// };

//С�Ż�ֱ��ʹ��int���顣memo[i] + memo[i-nums[j]] < INT_MAX ǰ�沿�ֿ��ܻ������ֱ�ӱ�������ʹ��memo[i] < INT_MAX - memo[i-nums[j]]
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<int>memo(target + 1, 0);
        memo[0] = 1; //��ɺ�Ϊ0�������һ��
        for (int i = 1; i <= target; i++)
            for (int j = 0; j < nums.size(); j++)
                if (i >= nums[j] && memo[i] < INT_MAX - memo[i - nums[j]])
                    //С�Ż�ֱ��memo[i] + memo[i-nums[j]] < INT_MAX ǰ�沿�ֿ��ܻ������ֱ�ӱ�������ʹ��memo[i] < INT_MAX - memo[i-nums[j]]  
                    memo[i] += memo[i - nums[j]];


        return memo[target];
    }
};

int main() {

	system("pause");
	return 0;
}