   ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(slow && fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return fast ? slow : prev;
    }
    
    ListNode* mergeLists(ListNode* h1, ListNode* h2) {
        ListNode *dummy_head = new ListNode(-1), *tail = dummy_head;
        
        while(h1 && h2) {
            if(h1->val < h2->val) {
                tail->next = h1;
                h1 = h1->next;
            }    
            else {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        
       
        ListNode *curr = h1 ? h1 : h2;
        while(curr) {
            tail->next = curr;
            tail = tail->next;
            curr = curr->next;    
        }
        
        ListNode *head = dummy_head->next;
        delete dummy_head;
        
        return head;
    }
    
    ListNode* mergeSortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
       
        ListNode * mid = findMiddle(head);
        
     
        ListNode *right_head = mid->next;
        
        mid->next = nullptr;
       
        ListNode *left = mergeSortList(head);
        ListNode *right = mergeSortList(right_head);
        
        ListNode *merged_head = mergeLists(left, right);
        
        return merged_head;
    }
      
    ListNode* sortList(ListNode* head) {
        return mergeSortList(head);
    }