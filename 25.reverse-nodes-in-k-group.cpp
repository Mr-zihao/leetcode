/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (37.80%)
 * Total Accepted:    206.2K
 * Total Submissions: 544.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* pre=dummy;
        ListNode* pre_t;
        dummy->next=head;
        ListNode* p;
        ListNode* h;
        int i;
        int count=0;
        while(head){
            count++;
            if(count==k){
                pre_t=pre->next;
                count=0;
                i=k;
                p=NULL;
                h=pre->next;
                ListNode* t;
                while(i>0){
                    t=h->next;
                    h->next=p;
                    p=h;
                    h=t;
                    i--;
                }
                pre->next=p;
                pre_t->next=h;
                pre=pre_t;
                head=h;
            }
            else
                head=head->next;
        }
        return dummy->next;
    }
};
