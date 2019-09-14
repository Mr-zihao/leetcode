/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.88%)
 * Total Accepted:    650.9K
 * Total Submissions: 2.3M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
/*     method 1    */
//  /*
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int max_L=0;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(i==j || (i==j+1 && s[i]==s[j]))
                    dp[j][i]=true;
                else 
                    dp[j][i]=(s[j]==s[i]) && dp[j+1][i-1];
                if(dp[j][i] && (i-j+1)>max_L){
                    max_L=i-j+1;
                    start=j;
                }
            }
        }
        return s.substr(start,max_L);
// */
/*   methon 2    */
/*
        int max_L=0;
        int start=0;
        int n=s.size();
        for(float i=0;i<n;i+=0.5){
            int b=int(i),e=int(i+0.5);
            while(b>=0 && e<n && s[b]==s[e]){
                if(e-b+1>max_L){
                    max_L=e-b+1;
                    start=b;
                }
                b--;
                e++;
            }
        }
        return s.substr(start,max_L);
*/        
    }
};
