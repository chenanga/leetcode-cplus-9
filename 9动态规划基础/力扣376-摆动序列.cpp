#include<iostream>
#include<vector>

using namespace std;

//����������Ե�
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if(nums.size() == 1) return 1;
//         //memo[i][0] Ϊ��i��Ԫ�ؽ�β�Ľ�������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i�ǽ���
//         //memo[i][1] Ϊ��i��Ԫ�ؽ�β����������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i������
//         vector<vector<int>> memo(nums.size(), vector<int>(2, 1));//��ʼ��
//         //ת�Ʒ���Ϊ
//         //j����� + 1 ��if nums[i] > nums[j],  0 < j < i-1
//         //j����� + 1 ��if nums[i] < nums[j],  0 < j < i-1
//         for(int i = 1; i < nums.size(); i ++){
//             // cout<<"��"<<i<<"�ֿ�ʼ------"<<endl;
//             for(int j = 0; j < i; j ++){
//                 // cout<<"����ǰ-��"<<j<<"С��:"<<"memo[i][0] = "<<memo[i][0]<<", memo[i][1] = "<<memo[i][1]<<endl;

//                 if(nums[i] < nums[j])
//                     memo[i][0] = max(memo[i][0], memo[j][1] + 1);
//                 if(nums[i] > nums[j])
//                     memo[i][1] = max(memo[i][1], memo[j][0] + 1);
//                 // cout<<"���º�-��"<<j<<"С��:"<<"memo[i][0] = "<<memo[i][0]<<", memo[i][1] = "<<memo[i][1]<<endl;
//             }
//             // cout<<"��"<<i<<"�ֽ���#######"<<endl;
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
//         //memo[i][0] Ϊ��i��Ԫ�ؽ�β�Ľ�������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i�ǽ���
//         //memo[i][1] Ϊ��i��Ԫ�ؽ�β����������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i������
//         vector<vector<int>> memo(nums.size(), vector<int>(2, 1));//��ʼ��
//         //ת�Ʒ���Ϊ
//         //j����� + 1 ��if nums[i] > nums[j],  0 < j < i-1
//         //j����� + 1 ��if nums[i] < nums[j],  0 < j < i-1
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

//���ڹٷ����Ż�
//֤������iһ��ֻ��i-1�й�
//
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        //memo[i][0] Ϊ��i��Ԫ�ؽ�β�Ľ�������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i�ǽ���
        //memo[i][1] Ϊ��i��Ԫ�ؽ�β����������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i������
        vector<vector<int>> memo(nums.size(), vector<int>(2, 1));//��ʼ��
        //ת�Ʒ���Ϊ
        //j����� + 1 ��if nums[i] > nums[j],  0 < j < i-1
        //j����� + 1 ��if nums[i] < nums[j],  0 < j < i-1
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


//��д���ռ��Ż�

int main() {

	system("pause");
	return 0;
}
