/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.27%)
 * Total Accepted:    217.4K
 * Total Submissions: 824.2K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int i=0;
        int n=s.size();
        int res=0;
        while(i<n){
            if(s[i]==')' && !st.empty() && s[st.top()]=='('){
                st.pop();
                if(st.empty())
                    res=i+1;
                else if (i-st.top()>res)
                    res=i-st.top();
            }
            else 
                st.push(i);
            i++;
        }
        return res;
    }
};
