#include<iostream>
#include<vector>

using namespace std;

//递归 超时
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
//     //返回字符串s的方法数,s为s[0....len]
//     int __numDecodings(string s, int len){
//         if(len == 1 || len == 0) return 1;

//         string str = s.substr(len-2, 2);
//         int num = atoi(str.c_str());
//         // cout<<"len = "<<len<<",num = "<<num<<endl;
//         if(num == 0){
//             flag = true;
//             return 0;
//         }
//         if(num == 10 || num == 20){ //10和20都无法拆分
//             return __numDecodings(s, len-2) ;
//         }
//         else if( num >= 10 && num <= 26 ) 
//             return __numDecodings(s, len-1) + __numDecodings(s, len-2) ;
//         else 
//             return __numDecodings(s, len-1);

//     }
// };
// //递归 记忆化搜索
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
//     vector<int> memo; //str为s[0....len]的总数
//     //返回字符串s的方法数,s为s[0....len]
//     int __numDecodings(string s, int len){

//         if(memo[len] != -1)
//             return memo[len];

//         string str = s.substr(len-2, 2);
//         int num = atoi(str.c_str());

//         if(num == 0 || num == 30 || num == 40 || num == 50 || num == 60 || num == 70 || num == 80 || num == 90 ){
//             flag = true;
//             return 0;
//         }
//         if(num == 10 || num == 20) //10和20都无法拆分
//             return memo[len] = __numDecodings(s, len-2) ;
//         else if( num >= 11 && num <= 26 ) 
//             return memo[len] = (__numDecodings(s, len-1) + __numDecodings(s, len-2)) ;
//         else //01--09 ，27 -- 99
//             return memo[len] =__numDecodings(s, len-1);

//     }
// };

// //递归 记忆化搜索，
// //优化1，字符串substr操作耗时，不转换int直接判断
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
//     vector<int> memo; //str为s[0....len]的总数
//     //返回字符串s的方法数,s为s[0....len]
//     int __numDecodings(string s, int len){

//         if(memo[len] != -1)
//             return memo[len];

//         if( s[len-1] == '0' && (s[len-2] != '1' && s[len-2] != '2')){
//             flag = true;
//             return 0;
//         }
//         if(s[len-1] == '0' && (s[len-2] == '1' || s[len-2] == '2')) //10和20都无法拆分{
//             return memo[len] = __numDecodings(s, len-2) ;
//         else if(s[len-2] == '1' || (s[len-2] == '2' && s[len-1] <= '6') ) 
//             return memo[len] = (__numDecodings(s, len-1) + __numDecodings(s, len-2)) ;
//         else //01--09 ，27 -- 99
//             return memo[len] =__numDecodings(s, len-1);

//     }
// };

// //动态规划 
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
//                 //不能拆分
//                 memo[i] = memo[i-1];
//             }
//         }

//         return memo[s.size()];
//     }

// };

// //动态规划 ,优化1，基于官方思路
// //只要s[i-1]不为0，那么当前位置就可以加memo[i-1]
// //再判断s[i-2]，如果s[i-2]不为0，且可以组成1-26,则加memo[i-2]
// /*
// 这里使用了一个巧妙的思路，如15可以当作1，5和15，是两种组合，刚好满足两种判断，加两次
// 而10，20由于带0，只能有一种可能，也是刚好只满足第二个判断，加一次

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
//                 memo[i] += memo[i-1]; //可以组合1个字符译码
//             if(s[i-2] != '0' && (s[i-2] - '0')*10 + s[i-1] - '0' <=26)
//                 memo[i] += memo[i-2]; //可以组合两个字符译码
//         }

//         return memo[s.size()];
//     }
// };


//动态规划 ,优化2，基于官方思路，优化空间
//只要s[i-1]不为0，那么当前位置就可以加memo[i-1]
//再判断s[i-2]，如果s[i-2]不为0，且可以组成1-26,则加memo[i-2]
/*
这里使用了一个巧妙的思路，如15可以当作1，5和15，是两种组合，刚好满足两种判断，加两次
而10，20由于带0，只能有一种可能，也是刚好只满足第二个判断，加一次

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
                i_0 += i_1; //可以组合1个字符译码
            if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
                i_0 += i_2; //可以组合两个字符译码
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