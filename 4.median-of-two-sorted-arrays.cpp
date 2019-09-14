/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.25%)
 * Total Accepted:    502.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int k1=(n1+n2+1)/2;
        int k2=(n1+n2)/2+1;
        double out1=helper(nums1,nums2,0,n1-1,0,n2-1,k1);

        if((n1+n2)%2)
            return out1;
        else{
            double out2=helper(nums1,nums2,0,n1-1,0,n2-1,k2);
            return (out1+out2)/2;
        } 
    }
    int helper(vector<int>& nums1,vector<int>& nums2,int s1,int e1,int s2,int e2,int k){
        if(s1>e1)
            return nums2[s2+k-1];
        if(s2>e2)
            return nums1[s1+k-1];
        if(k==1)
            return min(nums1[s1],nums2[s2]);
        int index1=s1+k/2-1;
        int index2=s2+k-k/2-1;
        if(index1>e1)
            return helper(nums1,nums2,s1,e1,index2+1,e2,k/2);
        else if(index2>e2)
            return helper(nums1,nums2,index1+1,e1,s2,e2,k-k/2);
        else if(nums1[index1]>nums2[index2])
            return helper(nums1,nums2,s1,e1,index2+1,e2,k/2);
        else if(nums1[index1]<nums2[index2])
            return helper(nums1,nums2,index1+1,e1,s2,e2,k-k/2);
        else 
            return nums1[index1];
    }
};
