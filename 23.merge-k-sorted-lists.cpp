/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.97%)
 * Total Accepted:    451.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*bool operator < (ListNode* a,ListNode* b){
        return a->val > b->val;
    }
*/

class Solution {
public:
struct cmp{
    bool operator() (ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        priority_queue<ListNode* , vector<ListNode*>,cmp> q;
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                q.push(lists[i]);
        }
        ListNode* temp;
        while(!q.empty()){
            temp=q.top();
            q.pop();
            if(temp->next)
                q.push(temp->next);
            head->next=temp;
            head=head->next;
        }
        return dummy->next;
    }
};
