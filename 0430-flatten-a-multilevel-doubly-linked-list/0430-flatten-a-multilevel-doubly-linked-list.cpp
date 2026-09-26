/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if (head == NULL)
            return NULL;

        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                Node* next = curr->next;
                Node* child = curr->child;


                Node* childHead = flatten(child);

                curr->next = childHead;
                childHead->prev = curr;

                Node* tail = childHead;

                while (tail->next != NULL) {
                    tail = tail->next;
                }

                tail->next = next;

                if (next != NULL) {
                    next->prev = tail;
                }

                curr->child = NULL;
            }

            curr = curr->next;
        }

        return head;
    }
};