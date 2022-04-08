#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


//没有写出来
// //和377. 组合总和 Ⅳ很像
// //并且由于拼接单词，所以需要顺序性
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int m = wordDict.size();
//         int n = s.size();
//         //memo[i][j]表示 s[0, i]是否能用wordDict[0,j] 表示 
//         vector<vector<bool>> memo(m, vector<bool>(n, false));

//         for(int i = 0; i < s.size(); i ++){
//             for(int j = 0; j < wordDict.size(); j ++){
//                 if(wordDict[j].size() == i + 1 && wordDict[j] == s.substr(0, i+1)){
//                     memo[i][j] = true;
//                 }

//             }     
//         }


//         for(int i = 1; i < s.size(); i ++){
//             for(int j = 0; j < wordDict.size(); j ++){
//                 if(wordDict[i].size() == j + 1 && wordDict[i] == s.substr(0, j+1)){
//                     memo[i][j] = true;
//                 }
//                 cout<<memo[i][j]<<endl;
//             }  
//         }

//         return true;
//     }
// };

//官方思路
/*
我们定义dp[i] 表示字符串 s 前 i 个字符组成的字符串 s[0..i-1] 是否能被空格拆分成若干个字典中出现的单词。从前往后计算考虑转移方程，每次转移的时候我们需要枚举包含位置 i-1 的最后一个单词，看它是否出现在字典中以及除去这部分的字符串是否合法即可。
公式化来说，我们需要枚举 s[0..i-1] 中的分割点j ，看 s[0..j-1] 组成的字符串 s_1（默认j=0 时 s_1为空串）
和 s[j..i-1] 组成的字符串 s_2是否都合法，如果两个字符串均合法，那么按照定义 s_1和 s_2拼接成的字符串也同样合法。由于计算到 dp[i] 时我们已经计算出了 dp[0..i−1] 的值，因此字符串 s_1是否合法可以直接由dp[j] 得知，剩下的我们只需要看 s_2
​是否合法即可，因此我们可以得出如下转移方程：
dp[i]=dp[j] && check(s[j..i−1])

其中check(s[j..i−1]) 表示子串 s[j..i−1] 是否出现在字典中。
对于检查一个字符串是否出现在给定的字符串列表里一般可以考虑哈希表来快速判断
*/
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int m = wordDict.size();
//         int n = s.size();
//         //用来查找字符串是否在字典中
//         unordered_set<string> wordDictSet(wordDict.begin(),wordDict.end());
//         vector<bool> memo(n + 1,  false); //memo[i]表示 0---i-1共i个字符是否能被字典中表示
//         memo[0] = true;

//         for(int i = 1; i <= n; i ++)
//             for(int j = 0; j < i; j ++)

//                 if(memo[j] && wordDictSet.find(s.substr(j, i-1 - j + 1)) != wordDictSet.end() ){

//                     memo[i] = true;
//                     break;
//                 }

//         return memo[n];
//     }
// };

//剪枝 如果要判断的字符串长度比字典中最长的字符串都长，则跳过
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = wordDict.size();
        int n = s.size();
        //用来查找字符串是否在字典中
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for (int i = 0; i < wordDict.size(); i++)
            maxLen = max(maxLen, static_cast<int>(wordDict[i].size()));

        vector<bool> memo(n + 1, false); //memo[i]表示 0---i-1共i个字符是否能被字典中表示
        memo[0] = true;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++) {
                if (i - j > maxLen) //剪枝，如果要判断的字符串长度比字典中最长的字符串都长，则跳过
                    continue;
                if (memo[j] && wordDictSet.find(s.substr(j, i - 1 - j + 1)) != wordDictSet.end()) {

                    memo[i] = true;
                    break;
                }
            }
        return memo[n];
    }
};

int main() {

	system("pause");
	return 0;
}