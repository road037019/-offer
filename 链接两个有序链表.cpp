#include <iostream>
#include <list>
using namespace std; 

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};      
	
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        list<int> s1;
        ListNode *temp = pHead1;
        for( ; temp != NULL; temp = temp->next){
            s1.push_back(temp->val);
            cout << temp->val << " ";
            if(temp->next == NULL){ //通过这一步将两个链表链接起来，并且意味着链表读到了末尾，需要break，否则的话就死循环了！ 
            	temp->next = pHead2;
            	break;
            }
            	
        }
        //temp = pHead2; //将两个链表链接起来；想法错误！ 
        temp = pHead2;
        for( ; temp != NULL; temp = temp->next){
        	cout << temp->val<< " "; 
            s1.push_back(temp->val);
        }

        std::list<int>::iterator it;
        s1.sort();
        for (it=s1.begin(); it!=s1.end(); ++it)
			std::cout <<  *it << " ";
        temp = pHead1;
        for( ; temp != NULL; temp = temp->next){
            temp->val = *s1.begin();
            cout << temp->val << ' ';
            s1.pop_front();
        }
        return pHead1;

    }
};

int main(){
	ListNode LN1(1),LN2(2),LN3(3);
	ListNode *pListHead1 = &LN1;
	LN1.next = &LN2;
	LN2.next = &LN3;
	
	ListNode LN12(1),LN22(2),LN32(3);
	ListNode *pListHead2 = &LN12;
	LN12.next = &LN22;
	LN22.next = &LN32;
	Solution s;
	s.Merge(pListHead1, pListHead2);
	
	return 0;
} 