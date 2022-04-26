#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct node {
    int data;
    //pointer to structure itself 
    struct node *next;
};
//declare vars/types
//store addresses of vars of node type
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp = NULL;

void Insert(int val) {
    //if rear is empty, create new node w/user specified value
    //in through the back
    if (rear == NULL){
        rear = new node;
        rear -> next = NULL;
        rear -> data = val;
        //front is rear
        front = rear;
    } 
    else {
        //if values exist in front and back
        //create new node
        temp = new node;
        rear -> next = temp;
        temp -> data = val;
        temp -> next = NULL;
        //rear is temp
        rear = temp;
    }
}

void Peek() {
    temp = front;
    if (front == NULL) {
        cout << "Queue is empty" << endl; }
    else if (temp -> next != NULL){
        //if something exists in the front of queue
        //print said value
        cout << ":::Peek:::Front = " << front -> data << endl;

    }
    else{
        //if you see this you f*&^%$ up
        //temp likely not reassigned to front
        cout << "yOu dIeD" << endl;
    }
}

void Delete() {
    //out through the front
    temp = front;
    //zero size
    if (front == NULL) {
        //if front empty, tell user.
        cout << "Queue is empty" << endl; }
    else if (temp -> next != NULL){
        //2 size
        //if next node not empty, tell user which value is being deleted
        //delete specified value from front.
        temp = temp -> next;
        cout << "Element deleted from queue is: " << front -> data << endl;
        delete(front);
        front = temp;
    }
    else{
        //1 size
        //else if only 1 value exists(at front, no rear)
        //delete said value and specify front and rear now NULL (empty).
        cout << "ELement deleted from queue is: " << front -> data << endl;
        delete(front);
        front = NULL;
        rear = NULL;
    }
}

void Display() {
    temp = front;
    //if the front and rear are empty, inform user of empty.
    if ((front == NULL) && (rear ==NULL)) {
        cout << "Queue is empty" << endl;
        return;
    }
    //while temp not empty, print data of queue
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
//driver function
int main() {
    
    
    //run time analysis start
    auto start = high_resolution_clock::now();
    cout << "Queue Created:" << endl;
    //create linked list w/values
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    Insert(50);
    //peek at top value and print value on top
    Peek();
    //display queue in its entirety
    Display();
    //delete value from front of queue, print value deleted
    Delete();
    //peek at top to see a new value at top after deletion
    Peek();

    //print queue post harvest
    cout << "Queue after one deletion: " << endl;
    Display();

    //stop timer, convert value to millisecond, inform user
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout <<"Time taken by function: " << duration.count() << " millisecond(s)" << endl;

    return 0;
}