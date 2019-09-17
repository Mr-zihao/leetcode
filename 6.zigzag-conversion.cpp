/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.18%)
 * Total Accepted:    359.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4 
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1)
            return s;
        int g_num=numRows+numRows-2;
        vector<string> out(numRows,"");
        int groups=n/g_num;
        int remain=n%g_num;
        int internal;
        for(int i=0;i<groups;i++){
            for(int j=0;j<numRows;j++){
                out[j]+=s[g_num*i+j];
                if(j>0 && j<numRows-1)
                {
                    internal=numRows-1-j;
                    out[j]+=s[i*g_num+numRows-1+internal];
                }
            }
        }
        for(int i=0;i<remain;i++){
            if(i<numRows){
                out[i]+=s[groups*g_num+i];
            }
            else{
                out[(numRows-1)-(i-numRows+1)]+=s[groups*g_num+i];
            }
        }
        string res="";
        for(int i=0;i<out.size();i++){
            res+=out[i];
        }
        return res;


                     
    }
};
