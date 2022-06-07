#include <iostream>
using namespace std;

//node structure
struct Node{
    int data;
    Node* next;
};

Node* head;

//Inserts new node at a given position
void add_node(int new_data, int position){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    //int position must be greater than 0
    if(position < 1) {
        cout << "\nOne of your new nodes has position error\n";
        cout << "\nNode with value: " << new_node->data << " has position less than 1\n";
    } else if (position == 1){
        //if position is 1, make that node the head
        new_node->next = head;
        head = new_node;
    } else {
        //create temp ptr
        //temp points to head
        Node* temp = head;
        //for as long as i < position-1, add one to i
        for(int i = 1; i < position-1; i++) {
            //as long as temp isn't NULL
            if(temp != NULL) {
                //temp is now pointing to the position of next node
                temp = temp->next;
            }
        }
        //as long as temp isn't NULL
        if(temp != NULL) {
            //new node now points to position of next node
            new_node->next = temp->next;
            //next node points to new node
            temp->next = new_node;
        } else {
            cout << "\nThe previous node is NULL...";
        }
    }
}

//Deletes node at given position
void delete_node(struct Node **head_ref, int position) {
    //if list empty, return
    if (*head_ref == NULL) {
        cout << "\nWhat is this? A dead fish?\n"<< endl;
        return;
    }
    //create node called temp, point to head
    struct Node*temp = *head_ref;
    //if position is position 1
    //point head to next
    //delete temp
    if (position == 1) {
        *head_ref = temp->next;
        delete(temp);
        return;
    }
    for (int i = 2; temp != NULL && i < position - 1; i++) {
        return;
    }
    //if temp and next node NULL, return
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    //create next node equal to temp
    //delete temp->next
    struct Node *next = temp->next->next;
    delete(temp->next);
    temp->next = next;
}
//Prints full list
void print_list() {
    Node* temp = head;
    if(temp != NULL) {
        cout <<"\nContents of list: ";
        //while temp not NULL
        //print data of each node until reach NULL
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n"<< endl;
    }else {
        cout << "The list is empty.\n";
    }
}

void get_value_at(struct Node **head_ref, int position) {
    Node* current = *head_ref;

    // position of node we're looking at
    int count = 0;
    //itterate through list until count is equal to 
    //position input in main.
    while (current != NULL) {
        if (count == position)
            cout << "\nThe position input holds the value: " << current->data << "\n" <<endl;
        count++;
        current = current->next;
    } 
    
}

int main() {
    
    
    //Should print error exception
    add_node(00,0);

    //Add 3 ints to a list at positions
    add_node(10,1);
    add_node(20,2);
    add_node(30,3);

    //Print list
    print_list();

    //Delete node data from list at position 2
    delete_node(&head, 2);

    //Print list after deletion
    print_list();

    //Get value at position 2
    get_value_at(&head,1);



};
