/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.49%)
 * Total Accepted:    803.4K
 * Total Submissions: 3.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        if(x==0)
            return 0;
        vector<int> bits;
        int flag=x>=0 ? 1 : -1;
        int c=0;
        int comp1=INT_MAX/10;
        int comp2=INT_MAX%10;
        if(x==INT_MIN){
            x++;
            c=1;
        }
        x=abs(x);
        while(x>0){
            bits.push_back(x%10);
            x/=10;
        }
        bits[0]+=c;
        int j;
        for(j=0;j<bits.size();j++)
            if(bits[j]!=0)
                break;
        int out=0;
        for(;j<bits.size();j++){
            if(out>comp1)
                return 0;
            else if(out==comp1 && bits[j]>comp2)
                return 0;
            else 
                out=out*10+bits[j];
        }
        return flag*out;
    }
};
