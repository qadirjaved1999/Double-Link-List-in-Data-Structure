#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* previou;
    Node* next;


 // Defualt Constructur
    Node(int value){
        this->data = value;
        this->previou = NULL;
        this->next = NULL;
    }

};

// Print function => Traversing Link List
void print(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
     cout<<endl;

}
    //  How to find the length of link list
   int getLength(Node* head){
       int len = 0;
       Node* temp = head;

    while (temp != NULL)
    {
       len++;
        temp = temp->next;
    }
    return len;
} 

// Node Insert At Starting / Intitial Position
   void insertAtHead(Node* &head, int d){

       Node* temp = new Node(d);
       temp->next = head;
       head->previou = temp;
       head = temp;
   }

// Node Insert At End/Last Position
   void insertAtTail(Node* &tail, int d){

       Node* temp = new Node(d);
       tail->next = temp;
       temp->previou = tail;
       tail = temp;
       
   }

   void insertAtAnyPosition(Node* &tail, Node* &head, int position, int d){
       //Insert At Start Position
       if(position == 1){
         insertAtHead(head, d);
         return;
       }

       Node* temp = head;
       int currentposition = 1;
       while (currentposition < position - 1)
       {
           temp = temp->next;
           currentposition++;
       }

       //Insert At Last / End Position
       if(temp -> next == NULL){
           insertAtTail(tail, d);
           return;
       }

       // Insert at Middle Position
       Node* nodeToInsert = new Node(d);

       nodeToInsert->next = temp -> next;
       temp->next->previou = nodeToInsert;
       temp->next = nodeToInsert;
       nodeToInsert->previou = temp;
   }


int main()
{
    Node* nodeOne = new Node(100);

    Node* head = nodeOne; // (Manay jo nodeOne banaya ha wo manay Node ka Head ma Add karna ya line ya kam kar rahi ha Got it)
    Node* tail = nodeOne; //  same Above

    print(head);
    // cout<<"The Lenght is = "<<getLength(head)<<endl;

    //Calling Insert at the start/Head function
    insertAtHead(head, 50);
     print(head);
//    cout<<"The Lenght is = "<<getLength(head)<<endl;


    insertAtHead(head, 40);
     print(head);
    // cout<<"The Lenght is = "<<getLength(head)<<endl;

    insertAtHead(head, 30);
     print(head);
    // cout<<"The Lenght is = "<<getLength(head)<<endl;

    insertAtHead(head, 20);
     print(head);
    // cout<<"The Lenght is = "<<getLength(head)<<endl;


    //Calling Insert at the end/tail function
    insertAtTail(tail, 200);
     print(head);
    // cout<<"The Lenght is = "<<getLength(head)<<endl;

     insertAtAnyPosition(tail, head, 3, 500);  //Insertion at 3red Position
     print(head);

     insertAtAnyPosition(tail, head, 1, 800);  //Insertion at 1st Position
     print(head);

     insertAtAnyPosition(tail, head, 9, 25000);  //Insertion at 9th Position
     print(head);

 return 0;
}