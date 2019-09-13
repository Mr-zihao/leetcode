/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.83%)
 * Total Accepted:    1.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        unsigned int sta[256];
        memset(sta,-1,sizeof(sta));
        int start=0;
        int max_L=0;
        int i;
        for(i=0;i<n;i++){
            if(sta[s[i]]==-1)
                sta[s[i]]=i;
            else if (sta[s[i]]<start)
                sta[s[i]]=i;
            else{
                if(i-start>max_L)
                    max_L=i-start;
                start=sta[s[i]]+1;
                sta[s[i]]=i;
            }
        }
        if(i-start>max_L){
            max_L=i-start;
        }
        return max_L;


























    }
};
