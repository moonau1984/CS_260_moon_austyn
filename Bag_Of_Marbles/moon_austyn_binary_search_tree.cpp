#include<iostream>

using namespace std;

// class for nodes on tree and constructors
class Tree_Node{
    //dynamic node
    public:
        int value; //data
        Tree_Node* left; //pointers to left and right child
        Tree_Node* right;

        Tree_Node() // default constructor
        {
            value = 0;
            left = NULL;
            right = NULL;
        }
        Tree_Node(int v) // parameterized constructor (initialize data elements)
        {
            value = v;
            left = NULL;
            right = NULL;
        }
};  

// class for binary search tree and its methods
class BST{
    public:
        Tree_Node* root;

        BST()
        {
            root = NULL;
        }

        bool is_empty() // method checks if tree is empty
        {
            if(root==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    void insert_Node(Tree_Node *new_node)
    {
        // base case for empty tree
        if(root==NULL)
        {
            root = new_node;
            cout << "Value Inserted is the root node" << endl;
        }
        else
        {
            Tree_Node *temp = root;
            while(temp != NULL)
            {
                // case keeps user from entering duplicate values
                if(new_node->value == temp->value)
                {
                    cout << "Value already exists, insert a different value" << endl;
                    return;
                }
                // for child node creation if new_node val is less than root and doesn't already have left child node
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout <<"Value Inserted" << endl;
                    break;
                }
                // if new_node is less than temp = root
                // point temp to child node to left of root and rerun new_node through loop
                // at that new temp = temp->left (new root)
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                // if new_node is greater than root, and node space to right is empty
                // new_node become right child node to root
                else if((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the the right!" << endl;
                    break;
                }
                // if right side of root node is full
                // point temp down a level and rerun new_node value through loop
                else
                {
                    temp = temp->right;
                }
                
                
            }
        }
    }

    void print_Preorder(Tree_Node *r) // print rules: (Root, Left, Right)
    {
        if (r == NULL)
            return;
        // print data of node
        cout << r->value << " ";
        // recur on left node
        print_Preorder(r->left);
        // recur on right node
        print_Preorder(r->right);
    }

    void print_Inorder(Tree_Node *r)
    {
        if (r == NULL)
            return;
        // recur (traverse) on left node
        print_Inorder(r->left);
        // print data of node
        cout << r->value << " " << endl;
        // recur (traverse) on right node
        print_Inorder(r->right);
    }

    void print_Postorder(Tree_Node *r)
    {
        if (r == NULL)
            return;
        // recur (traverse) on left node
        print_Postorder(r->left);
        // recur (traverse on right node)
        print_Postorder(r->right);
        // print data of node
        cout << r->value << " " << endl;
    }

    Tree_Node* iterative_Search(int val)
    {
        if(root == NULL)
        {
            return root;
        }
        else
        {
            Tree_Node *temp = root;
            while(temp != NULL)
            //check if node val matches temp, recur until NULL return
            {
                if(val < temp->value)//if value equals temp, return match
                {
                    return temp;
                }
                else if(val<temp->value)//if val is less than temp, go left and recur
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;//if val is greater than temp, go right and recur
                }
                return NULL;
            }
        }

        
        
    }

    // used in delete_Node method
    Tree_Node* min_Value_Node(Tree_Node* node)
    {
        Tree_Node* current = node;
        // loop down to find the leftmost child node
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    // deletes node, uses iterative search
    Tree_Node* delete_Node(Tree_Node* r, int v)
    {
        //base case
        if (r == NULL)
        {
            return NULL;
        }
        // if value smaller, go left subtree
        else if (v < r->value)
        {
            r->left = delete_Node(r->left, v);// recur
        }
        // if value larger, go right subtree
        else if (v > r->value)
        {
            r->right = delete_Node(r->right, v);// recur
        }
        // if same as root then this is node to be deleted
        else
        {
            // node with one child
            if (r->left == NULL)
            {
                Tree_Node* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                Tree_Node* temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                // node with 2 children
                Tree_Node* temp = min_Value_Node(r->right);
                // copy inorder sucessor content to this node
                r->value = temp->value;
                // delete inorder successor
                r->right = delete_Node(r->right, temp->value);
            }
            
        }
        return r;
        
    }


};

// vroom vroom
int main()
{
    // Main is menu driven
    BST obj;
    int option,val;

    do // does without parameter being checked. Always run at start, do until parameter met
    {
        cout << "Make a selection: " << endl; 
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print Binary Search Tree" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        // creates global var on heap
        // needed to run switch case repetedly
        // Node n1; is another way of doing, but would go out of scope once ran through loop
        Tree_Node *new_node = new Tree_Node();
        switch(option) // used to select one of many code blocks to be executed
        {
            case 0:
                break;
            case 1:
            // if selection 1 insert given value at node per written BST rules
                cout << "Insert Node" << endl;
                cout << "Enter Value of Node" << endl;
                cin >> val;
                new_node->value = val;
                obj.insert_Node(new_node);
                cout << endl;
                break;
            case 2:
            // using iterative search find given value if exists
                cout << "Search Node" << endl;
                cout << "Enter Value of Node" << endl;
                cin >> val;
                new_node = obj.iterative_Search(val);
                if(new_node != NULL)
                {
                    cout << "Value Found!" << endl;
                }
                else
                {
                    cout << "Value NOT Found!" << endl;
                }
                break;
            case 3:
            // if selection 3 delete nodes if it exists
                cout << "Delete Node" << endl;
                cout << "Enter Value of Tree Node to be deleted: ";
                cin >> val;
                //new_node = obj.iterativeSearch(val);/////////////////////////////////////////
                if(new_node!=NULL)
                {
                    obj.delete_Node(obj.root, val);
                    cout << "Value Deleted" << endl;
                }
                else
                {
                    cout << "Value NOT Found" << endl;
                }
                break;
            case 4:
            // if selection 4 print BST with 3 traversal methods
                cout << "Pre-Order: " << endl;
                obj.print_Preorder(obj.root);
                cout << "\n" << endl;
                
                cout << "In-Order: " << endl;
                obj.print_Inorder(obj.root);
                cout << "\n" << endl;

                cout << "Post-Order: " << endl;
                obj.print_Postorder(obj.root);
                cout << "\n" << endl;
                break;
            default:
                cout << "Please Enter Valid Input: " << endl;
        }   
    } 
    while (option != 0);
    
    


    return 0;
}
