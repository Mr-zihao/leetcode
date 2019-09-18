/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.72%)
 * Total Accepted:    644.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        int temp;
        vector<vector<int>> out;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0)
                break;
            for(int j=i+1;j<n-1;j++){
                temp=nums[i]+nums[j];
                if(temp>0)
                    break;
                if(m.find(-temp)!=m.end())
                    if(m[-temp]>j)
                        out.push_back({nums[i],nums[j],-temp});
                j=m[nums[j]];

            }
            i=m[nums[i]];
        }
        return out;
    }
};
