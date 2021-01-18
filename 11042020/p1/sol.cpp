#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
       int val;
       ListNode*  next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode * next) : val(x), next(next) {}
   };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
               ListNode* head = new ListNode();
               ListNode* tmp = head;
               int carry = 0;
               while(l1 != nullptr && l2 != nullptr){
                   int res = (l1->val + l2->val + carry);
                   tmp->next = new ListNode(res % 10, nullptr);
                   carry = res /= 10;
                   l1 = l1->next;
                   l2 = l2->next;
                   tmp = tmp->next;
               }
               while(l1 != nullptr){
                   int res = (l1->val + carry);
                   tmp->next = new ListNode(res % 10, nullptr);
                   carry = res /= 10;
                   l1 = l1->next;
                   tmp = tmp->next;
               }
               while(l2 != nullptr){
                   int res = (l2->val + carry);
                   tmp->next = new ListNode(res % 10, nullptr);
                   carry = res /= 10;
                   l2 = l2->next;
                   tmp = tmp->next;
               }
               if(carry){
                   tmp->next = new ListNode(carry, nullptr);
               }
               return head->next;
    }
};

Solution sol;

int main()
{
    //[9,9,9,9,9,9,9], l2 = [9,9,9,9]
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    ListNode* a = new ListNode(2,new ListNode(4 , new ListNode(3)) );
    ListNode* b = new ListNode(5,new ListNode(6 , new ListNode(4)) );
    a = new ListNode(0);
    b = new ListNode(0);
    a = new ListNode(9 , new ListNode(9 , new ListNode(9 , new ListNode(9 , new ListNode(9 , new ListNode ( 9 , new ListNode(9 )))))));
    b = new ListNode(9 , new ListNode(9 , new ListNode(9 , new ListNode(9) ) ) ); 
    ListNode* c=  sol.addTwoNumbers(a,b);
    while(c != nullptr){
        cout << c->val <<endl;
        c = c->next;
    }
    return 0;
}