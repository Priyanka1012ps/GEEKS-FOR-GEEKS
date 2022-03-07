// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/ 
Node* reverse(Node *head) 
{
 Node* prev=NULL;
 Node* next=NULL;
 Node* curr=head;
while(curr!=NULL)
{
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
return prev;
}

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry=0;
        Node* newhead =reverse(head);
        Node * curr=newhead;
         Node* prev=NULL;
        while(curr!=NULL)
        {
            int sum=0;
            if(prev == NULL)
            {
                sum=curr->data+1;
                
            }
            else
            {
                sum=curr->data +carry;
            }
            carry=sum/10;
            curr->data=sum%10;
            prev=curr;
            curr=curr->next;
    }
    if(carry==1)
    {
        Node* newnode = new Node(1);
        prev->next=newnode;
    }
    return reverse( newhead );
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends