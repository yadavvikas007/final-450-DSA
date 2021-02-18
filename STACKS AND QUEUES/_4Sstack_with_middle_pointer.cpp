#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
        Node* prev;
		int data;
		Node *next;
};
class Stack
{
	private:
		Node *top;
        Node* mid;
	public:
        int size;
		Stack(){top=NULL; size=0; mid=NULL;}
		void push(int x){
            Node* newnode=new Node();
            newnode->data=x;
            newnode->next=top;
            newnode->prev=NULL;
            size++;
            if(size==1)mid=newnode;
            else{
                top->prev=newnode;
                if((size&1))       //odd
                    mid=mid->prev;
            }
            top=newnode;
        }
		int pop(){
            if(size==0){cout<<"stack is empty\n"; return -1;}
            Node* temp=top;
            int item=top->data;
            top=top->next;
            if(top)top->prev=NULL;
            size--;
            if(!(size&1))   //even
                mid=mid->next;
            delete(temp);
            return item;
        }
        int middle(){
            if(size==0)return -1;
            return mid->data;
        }
        int topvalue(){
            if(size==0)return -1;
            return top->data;
        }
        int deletemiddle(){
            if(!mid)return -1;
            int item=mid->data;
            mid->prev->next=mid->next;
            if(mid->next) mid->next->prev=mid->prev;
            if(top==mid)top=NULL;
            delete mid;
            return item;
        }
};

int main(){
    Stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.size<<"\n";
    cout<<s.middle()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.middle()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.topvalue()<<"\n";
    cout<<s.middle()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.topvalue()<<"\n";
    cout<<s.middle()<<"\n";
    cout<<s.pop()<<"\n";
    cout<<s.middle()<<"\n";
}