#include <bits/stdc++.h>
using namespace std;
typedef uintptr_t ut;


struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    
    // Should reverse list and return new head.
    Node* reverseList(struct Node *head)             //iterative method
{
    if (head == NULL || head->next == NULL)
            return head;
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
    // return head of reversed list
}

    Node* reverseList2(Node* head)                  //recursive method
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put 
          the first element at the end */
        Node* rest = reverseList2(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
 
    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }


    Node* reverse(struct Node** head_ref)                //USING XOR OPERATION
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
 
    // at last prev points to new head
    while (current != NULL) {
        // This expression evaluates from left to right
        // current->next = prev, changes the link fron
        // next to prev node
        // prev = current, moves prev to current node for
        // next reversal of node
        // This example of list will clear it more 1->2->3->4
        // initially prev = 1, current = 2
        // Final expression will be current = 1^2^3^2^1,
        // as we know that bitwise XOR of two same
        // numbers will always be 0 i.e; 1^1 = 2^2 = 0
        // After the evaluation of expression current = 3 that
        // means it has been moved by one node from its
        // previous position
        current = (struct Node*)((ut)prev ^ (ut)current ^ (ut)(current->next) ^ (ut)(current->next = prev) ^ (ut)(prev = current));
    }
 
    *head_ref = prev;
    return *head_ref;
}
Node* reverseList3(Node* head) {             //iterative 2 pointers only
        Node* newhead=NULL;
        while(head){
            Node* Next=head->next;
            head->next=newhead;
            newhead=head;
            head=Next;
        }
        return newhead;
    }
};
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(2);
    ll.push(4);
    ll.push(6);
    ll.push(8);
 
    cout << "Given linked list\n";
    ll.print();
    Node** ref=&ll.head;
    ll.head = ll.reverse(ref);
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}

