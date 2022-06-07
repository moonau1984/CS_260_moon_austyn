#include <iostream>
using namespace std;

//hash table contains 128 indices for [key:value] pairs
const int TABLE_SIZE = 128;

class Linked_Hash_Entry
// basically nodes for indices of hashtable
//entries contain first element of a linkedlist
{
    private:
        //linked list components
        int key;
        int value;
        Linked_Hash_Entry *next;
    public:
        Linked_Hash_Entry(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->next = NULL;
        }

        int get_key() 
        {
            return key;
        }

        int get_value()
        {
            return value;
        }

        void set_value(int value)
        {
            this->value = value;
        }

        Linked_Hash_Entry *getNext()
        {
            return next;
        }

        void set_next(Linked_Hash_Entry *next)
        {
            this->next = next;
        }

};

class HashTable
{
    private:
        Linked_Hash_Entry **table;
    public:
        HashTable()
        {
            table = new Linked_Hash_Entry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                table[i] = NULL;
        }

        //function checks if key is in hash table
        //prints if doesn't exist
        //prints if value exists, prints value
        int get(int key)
        {
            //hash functions uses remainder div to determine index
            int hash = (key % TABLE_SIZE);
            //if result of hash points to list that is NULL
            if (table[hash] == NULL)
            {
                //print empty
                cout << "Index Empty At Key: " << key << endl;
                return -1;
            }
            else
            {
                //create pointer entry to hashed table index
                Linked_Hash_Entry *entry = table[hash];
                while (entry != NULL && entry->get_key() != key)
                    entry = entry->getNext();
                if (entry == NULL)
                    return -1;
                else
                    //if keys match, print value of that entry
                    cout << "Value: " << entry->get_value() << " exists at key: " << key << endl;
                    return entry->get_value();
            }
        }
        //function takes [key:value] pair and inserts at index
        //determined by hash calculation
        void put(int key, int value)
        {
            int hash = (key % TABLE_SIZE);
            //if index empty, insert [key:value] pair
            //as linked list entry at hashed index
            if (table[hash] == NULL)
                table[hash] = new Linked_Hash_Entry(key, value);
            else
            {
                //if index not empty
                //insert [key:value] node at next in specified hashed index
                Linked_Hash_Entry *entry = table[hash];
                while (entry->getNext() != NULL)
                    entry = entry->getNext();
                if (entry->get_key() == key)
                    entry->set_value(value);
                else    
                    entry->set_next(new Linked_Hash_Entry(key, value));
            }
        }

        void remove (int key)
        {
            int hash = (key % TABLE_SIZE);
            //if index is not empty
            if (table[hash] != NULL)
            {
                //prev entry is NULL
                //entry is now pointing to hashed index
                Linked_Hash_Entry *prev_entry = NULL;
                Linked_Hash_Entry *entry = table[hash];
                while (entry->getNext() != NULL && entry->get_key() != key)
                {
                    //prev entry is now hashed index
                    prev_entry = entry;
                    entry = entry->getNext();
                }
                if (entry->get_key() == key)
                {   
                    //if entry key is key in index
                    if (prev_entry == NULL)
                    {
                        //linked list next entry is now next of entry
                        Linked_Hash_Entry *nextEntry = entry->getNext();
                        //delete [key:value] at that entry
                        cout << "Value at Key: " << key << " DELETED" << endl;
                        delete entry;
                        table[hash] = nextEntry;
                    }
                    else
                    {   
                        Linked_Hash_Entry *next = entry->getNext();
                        cout << "Value at Key: " << key << " DELETED" << endl;
                        delete entry;
                        prev_entry->set_next(next);
                    }
                }
            }
        }
};

int main ()
{
    HashTable hm;
    //show hm is empty before inserts
    hm.get(404);
    hm.get(500);
    hm.get(505);

    // insert key value pairs
    hm.put(404,444);
    hm.put(500,555);
    hm.put(505,606);

    // check to see hash table contains said pairs with key lookup
    hm.get(404);
    hm.get(500);
    hm.get(505);

    // add value at key 505 with the number of the beast B)
    hm.put(505,666);
    // confirm additional insertion
    hm.get(505);
    //remove inserted [key:value]
    hm.remove(505);
    //confirm removal
    hm.get(404);
    hm.get(500);
    hm.get(505);
};
