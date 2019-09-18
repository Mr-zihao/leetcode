/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.59%)
 * Total Accepted:    449.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0)
            return head;
        queue<ListNode*> q;
        ListNode* temp=head;
        ListNode* pre;
        ListNode* node_n;
        while(head){
            if(q.size()<n)
                q.push(head);
            else{
                pre=q.front();
                q.pop();
                q.push(head);
            }
            head=head->next;
        }
        node_n=q.front();
        if(node_n==temp)
            return temp->next;
        pre->next=node_n->next;
        return temp;
    }
};
