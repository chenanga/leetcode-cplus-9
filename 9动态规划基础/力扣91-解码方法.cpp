#include<iostream>
#include<vector>

using namespace std;

//�ݹ� ��ʱ
// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s[0] == '0')
//             return 0;
//         int res = __numDecodings(s, s.size());
//         if(flag)
//             return 0;
//         return res;
//     }
//     bool flag = false;
//     //�����ַ���s�ķ�����,sΪs[0....len]
//     int __numDecodings(string s, int len){
//         if(len == 1 || len == 0) return 1;

//         string str = s.substr(len-2, 2);
//         int num = atoi(str.c_str());
//         // cout<<"len = "<<len<<",num = "<<num<<endl;
//         if(num == 0){
//             flag = true;
//             return 0;
//         }
//         if(num == 10 || num == 20){ //10��20���޷����
//             return __numDecodings(s, len-2) ;
//         }
//         else if( num >= 10 && num <= 26 ) 
//             return __numDecodings(s, len-1) + __numDecodings(s, len-2) ;
//         else 
//             return __numDecodings(s, len-1);

//     }
// };
// //�ݹ� ���仯����
// class Solution {
// public:
//     int numDecodings(string s) {
//         memo = vector<int>(s.size() + 1, -1);
//         memo[0] = memo[1] = 1;
//         if(s[0] == '0')
//             return 0;
//         int res = __numDecodings(s, s.size());
//         if(flag)
//             return 0;
//         return res;
//     }
// private:
//     bool flag = false;
//     vector<int> memo; //strΪs[0....len]������
//     //�����ַ���s�ķ�����,sΪs[0....len]
//     int __numDecodings(string s, int len){

//         if(memo[len] != -1)
//             return memo[len];

//         string str = s.substr(len-2, 2);
//         int num = atoi(str.c_str());

//         if(num == 0 || num == 30 || num == 40 || num == 50 || num == 60 || num == 70 || num == 80 || num == 90 ){
//             flag = true;
//             return 0;
//         }
//         if(num == 10 || num == 20) //10��20���޷����
//             return memo[len] = __numDecodings(s, len-2) ;
//         else if( num >= 11 && num <= 26 ) 
//             return memo[len] = (__numDecodings(s, len-1) + __numDecodings(s, len-2)) ;
//         else //01--09 ��27 -- 99
//             return memo[len] =__numDecodings(s, len-1);

//     }
// };

// //�ݹ� ���仯������
// //�Ż�1���ַ���substr������ʱ����ת��intֱ���ж�
// class Solution {
// public:
//     int numDecodings(string s) {
//         memo = vector<int>(s.size() + 1, -1);
//         memo[0] = memo[1] = 1;
//         if(s[0] == '0')
//             return 0;
//         int res = __numDecodings(s, s.size());
//         if(flag)
//             return 0;
//         return res;
//     }
// private:
//     bool flag = false;
//     vector<int> memo; //strΪs[0....len]������
//     //�����ַ���s�ķ�����,sΪs[0....len]
//     int __numDecodings(string s, int len){

//         if(memo[len] != -1)
//             return memo[len];

//         if( s[len-1] == '0' && (s[len-2] != '1' && s[len-2] != '2')){
//             flag = true;
//             return 0;
//         }
//         if(s[len-1] == '0' && (s[len-2] == '1' || s[len-2] == '2')) //10��20���޷����{
//             return memo[len] = __numDecodings(s, len-2) ;
//         else if(s[len-2] == '1' || (s[len-2] == '2' && s[len-1] <= '6') ) 
//             return memo[len] = (__numDecodings(s, len-1) + __numDecodings(s, len-2)) ;
//         else //01--09 ��27 -- 99
//             return memo[len] =__numDecodings(s, len-1);

//     }
// };

// //��̬�滮 
// class Solution {
// public:
//     int numDecodings(string s) {
//         vector<int>memo(s.size() + 1, -1);
//         memo[0] = memo[1] = 1;
//         if(s[0] == '0')
//             return 0;

//         for(int i = 2; i <= s.size(); i ++){
//             if(s[i-2] == '1' && s[i-1] >= '1' && s[i-1] <= '9' ){//11-19
//                 memo[i] = memo[i-1] + memo[i-2];
//             }
//             else if(s[i-2] == '2' && s[i-1] >= '1' && s[i-1] <= '6'){//21-26
//                 memo[i] = memo[i-1] + memo[i-2];
//             }
//             else if(s[i-1] == '0' && (s[i-2] == '1' || s[i-2] == '2')){//10,20
//                 memo[i] = memo[i-2];
//             }
//             else if(s[i-1] == '0' && s[i-2] != '1' && s[i-2] != '2')
//                 return 0;
//             else{
//                 //���ܲ��
//                 memo[i] = memo[i-1];
//             }
//         }

//         return memo[s.size()];
//     }

// };

// //��̬�滮 ,�Ż�1�����ڹٷ�˼·
// //ֻҪs[i-1]��Ϊ0����ô��ǰλ�þͿ��Լ�memo[i-1]
// //���ж�s[i-2]�����s[i-2]��Ϊ0���ҿ������1-26,���memo[i-2]
// /*
// ����ʹ����һ�������˼·����15���Ե���1��5��15����������ϣ��պ����������жϣ�������
// ��10��20���ڴ�0��ֻ����һ�ֿ��ܣ�Ҳ�Ǹպ�ֻ����ڶ����жϣ���һ��

// */
// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s[0] == '0')
//             return 0;

//         vector<int>memo(s.size() + 1, 0);
//         memo[0] = memo[1] = 1;

//         for(int i = 2; i <= s.size(); i ++){
//             if(s[i-1] != '0')
//                 memo[i] += memo[i-1]; //�������1���ַ�����
//             if(s[i-2] != '0' && (s[i-2] - '0')*10 + s[i-1] - '0' <=26)
//                 memo[i] += memo[i-2]; //������������ַ�����
//         }

//         return memo[s.size()];
//     }
// };


//��̬�滮 ,�Ż�2�����ڹٷ�˼·���Ż��ռ�
//ֻҪs[i-1]��Ϊ0����ô��ǰλ�þͿ��Լ�memo[i-1]
//���ж�s[i-2]�����s[i-2]��Ϊ0���ҿ������1-26,���memo[i-2]
/*
����ʹ����һ�������˼·����15���Ե���1��5��15����������ϣ��պ����������жϣ�������
��10��20���ڴ�0��ֻ����һ�ֿ��ܣ�Ҳ�Ǹպ�ֻ����ڶ����жϣ���һ��

*/
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;


        int i_2 = 0, i_1 = 1;//i_2: f(i-2), i_1:f(i-1)
        int i_0; // i_0: f(i)
        for (int i = 1; i <= s.size(); i++) {
            i_0 = 0;
            if (s[i - 1] != '0')
                i_0 += i_1; //�������1���ַ�����
            if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
                i_0 += i_2; //������������ַ�����
            i_2 = i_1;
            i_1 = i_0;
        }

        return i_0;
    }
};

int main() {

	system("pause");
	return 0;
}