/**
*The purpose of th program is to show my own representation of a 
*bag of marbles. I did so by creating vars that represent the marbles
*and an array that acts as the bag of marbles. 
*User will be shown the amount of marbles they have to start.
*The user will then be prompted to add a marble and remove a marble.
*After doing so the program will show the updated amount of marbles
*and cease to exist.
*/


#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;

int main(){
    //vars representing marbles
    int red = 5;
    int green = 5;
    int blue = 5;

    //list representing bag of marbles
    int bag_marbles[] = {red,green,blue};
    //user will input single character for selection
    char user_input = 'a'; 
    
    //printing contents of bag before user input
    cout << "Amount of Red Marbles: " << bag_marbles[0] << endl;
    cout << "Amount of Green Marbles: " << bag_marbles[1] << endl;
    cout << "Amount of Blue Marbles: " << bag_marbles[2] << endl;

    // add a marble...
    cout << "Please choose a color of marble to put in bag (r,g,b): "<< endl;
    cin >> user_input;
    if(user_input == 'r'){
        bag_marbles[0] += 1;
        cout << "Amount of Red Marbles: " << int(bag_marbles[0]) << endl;
    }else if(user_input == 'g'){
        bag_marbles[1] += 1;
        cout << "Amount of Green Marbles: " << bag_marbles[1] << endl;
    }else {
        bag_marbles[2] += 1;
        cout << "Amount of Blue Marbles: " << bag_marbles[2] << endl;
    }

    // remove a marble...
    cout << "Please choose a color of marble to remove from the bag (r,g,b): "<< endl;
    cin >> user_input;
    
    if(user_input == 'r'){
        bag_marbles[0] -= 1;
        cout << "Amount of Red Marbles: " << bag_marbles[0] << endl;
    }else if(user_input == 'g'){
        bag_marbles[1] -= 1;
        cout << "Amount of Green Marbles: " << bag_marbles[1] << endl;
    }else {
        bag_marbles[2] -= 1;
        cout << "Amount of Blue Marbles: " << bag_marbles[2] << endl;
    }

    //this cout prints memory location of array
    //i can't figure out how to print the list of vars as chars
    cout << "Bag of Marbles memory location: " << bag_marbles <<endl; //prints memory location of bag
    
    //marble count after user input
    cout << "Amount of Red Marbles: " << int(bag_marbles[0]) << endl;
    cout << "Amount of Green Marbles: " << bag_marbles[1] << endl;
    cout << "Amount of Blue Marbles: " << bag_marbles[2] << endl;
}
