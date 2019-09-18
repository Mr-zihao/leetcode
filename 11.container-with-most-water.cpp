/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (46.58%)
 * Total Accepted:    446.2K
 * Total Submissions: 956K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
/*
        int res=0;
        int temp;
        for(int i=0;i<height.size()-1;i++){
            for(int j=i+1;j<height.size();j++){
                temp=min(height[i],height[j])*(j-i);
                if(temp>res)
                    res=temp;
            }
        }
        return res;
*/
        int i=0;
        int j=height.size()-1;
        int res=0;
        int temp;
        while(i<j){
            temp=min(height[i],height[j])*(j-i);
            if(temp>res)
                res=temp;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return res;
    }
};
