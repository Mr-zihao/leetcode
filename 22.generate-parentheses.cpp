/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (56.92%)
 * Total Accepted:    392.4K
 * Total Submissions: 687.9K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0,0,n,res,"");
        return res;
    }
    void helper(int left,int right,int n,vector<string>& res,string temp){
        if(left<right)
            return;
        else if(left==right && left==n)
            res.push_back(temp);
        else if(left==right)
            helper(left+1,right,n,res,temp+'(');
        else if (left==n)
            helper(left,right+1,n,res,temp+')');
        else {
            helper(left+1,right,n,res,temp+'(');
            helper(left,right+1,n,res,temp+')');
        }
    }

};
