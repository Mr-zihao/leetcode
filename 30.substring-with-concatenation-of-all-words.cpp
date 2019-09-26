/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.10%)
 * Total Accepted:    146.3K
 * Total Submissions: 606.2K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.size()==0 || words.size()==0)
            return {};

        unordered_map<string,int> m,mt;
        int total=0;
        for(int i=0;i<words.size();i++){
            if(!words[i].empty()){
                if(m.find(words[i])==m.end())
                    m[words[i]]=1;
                else 
                    m[words[i]]+=1;
                total++;
            }
        }
        vector<int> res;
        unordered_map<string,int>::iterator iter=m.begin();
        int l= (*iter).first.size();
        if(s.size()<total*l)
            return {};
         int cnt;
        for (int i=0;i<=s.size()-total*l;i++){
            cnt=0;
            mt=m;
            if(helper(s,i,mt,l,cnt,total))
                res.push_back(i);
        }
        return res;
        
    }
    bool helper(string& s ,int beg,unordered_map<string,int>& m,int& l,int& cnt,int& total){
        if(cnt==total)
            return true;
        else if(beg>s.size()-l)
            return false;
        else if (m.find(s.substr(beg,l))!=m.end() && m[s.substr(beg,l)]!=0)
        {   
            cnt++;
            m[s.substr(beg,l)]--;
            return helper(s,beg+l,m,l,cnt,total);
        }
        return false;


    }
};
