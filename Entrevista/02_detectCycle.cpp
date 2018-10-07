/*
@date:		October 6th, 2018.
@author:	Jesús Díaz
@problem:	Given a linked list, return the node where the cycle begins. 
			If there is no cycle, return null.
			
			      ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

@topic:		Floyd's Algorithms and Linked List.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::detectCycle(ListNode* A) {    
    /*Using the idea Floyd's Cycle Algorithm*/
    //I am considering 'A' as head of Linked List
    ListNode *tortoise = A; //Tortuga
    ListNode *hape = A;     //Liebre
    bool cycle = false;

    while( tortoise && hape && hape->next){
        tortoise = tortoise->next;
        hape = hape->next->next;
        
        if( tortoise = hape ){
            cycle = true;
            break;
        }
    }

    if(!cycle) return NULL;
    else{
    	ListNode *nodeCycle = A;
    	while( nodeCycle != tortoise ){
    		nodeCycle = nodeCycle->next;
    		tortoise = tortoise->next;
    	}
    	return nodeCycle;
    }    
}