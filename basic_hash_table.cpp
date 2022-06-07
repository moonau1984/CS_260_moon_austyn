/* This program is a hash table that stores key/value pairs of type int.
 Hash table allows the storage of up to 128 key/value pairs
 Hash function used utilizes remainder of division by 128. (modulos)
*/

#include <iostream>

using namespace std;

//able to store 128 key value pairs
const int TABLE_SIZE = 128;

class HashEntry 
{
    private:
        int key;
        int value;
    
    public:
        HashEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }

        int get_key() 
        {
            return key;
        }

        int get_value()
        {
            return value;
        }
};


class HashMap
{
    private:
        HashEntry **table;
    public:
        HashMap()
        {
            //create new table w/key value pair of size [table_size]
            table = new HashEntry*[TABLE_SIZE];
            for (int i = 0; i <TABLE_SIZE; i++)
                table[i] = NULL;
        }
        int get (int key) //contains func
        {
            //hashing with modulos
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->get_key() != key)
                hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] == NULL)
            {
                cout << "TABLE IS EMPTY" << endl;
                return -1;
            }
            else
                cout << "Value: " << table[hash]->get_value() << " is in Hash Table" << endl;
                return table[hash]->get_value();

        }

        void put (int key, int value) //insert func
        {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->get_key() != key)
                hash = (hash +1) % TABLE_SIZE;
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
        }
        
};

int main()
{
    HashMap hm;
    hm.get(505);

    // insert key value pairs
    hm.put(404,444);
    hm.put(500,555);
    hm.put(505,606);
    // check to see hash table contains said pairs with key lookup
    hm.get(404);
    hm.get(500);
    hm.get(505);

    // replace value at key 505 with the number of the beast B)
    hm.put(505,666);
    // confirm replacement
    hm.get(505);
    hm.get(505);
}