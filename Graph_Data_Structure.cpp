/* The purpose of this program is to create a simple Adjacency List Graph data structure with 3 distinct classes
nested within each other. The Graph class contains a list of Vertices of type vertex. The Vertex 
class contains an ID, name of the Vertex, and a list of edges that connect it to different vertices.
Lastly there is an Edge class that contains the ID of vertices it is connected to and the weight
between each connection. 

Tests:
1) 
Input: User creates 4 vertices and connects the three vertices
Output: Print Graph: 
Monmouth (55) >>>[65(2) --> 45(20) --> ]
Independence (65) >>>[55(2) --> 75(15) -->45(25) ]
Salem (75) >>>[65(15) --> ]
Corvallis (45) >>>[55(20) --> ]
Tests:

2)
Input: User Enters Duplicate Vertices
Output:
Add Vertex: 
Enter Town ID:
45
 Enter Town Name: 
Monmouth
New Vertex Added!

Add Vertex: 
Enter Town ID:
45
Enter Town Name: 
Duplicate Monmouth
This ID already exists... Try a different ID

3)
Input: User Enters Duplicate Edges
Output:
Add Edge:
Enter ID of Source Vertex (Town)45
Enter ID of Destination Vertex (Town)55
Enter Weight of Edge: 2
Edge between 45 and 55 added successfully!

Add Edge: 
Enter ID of Source Vertex (Town)45
Enter ID of Destination Vertex (Town)55
Enter Weight of Edge: 222
Edge between Monmouth(45) and Independence(55) Already Exists

Note: Unable to build functional code of algorithms SPT and MST. Psuedocode provided in folder containing this file.

*/

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;


class Edge
{
    public: //data members would generally be in private, methods in public
        int dest_vertex_id;
        int weight;

    Edge()
    {

    }

    Edge(int dest_vID, int w)
    {
        dest_vertex_id = dest_vID;
        weight = w;
    }

    //gttr and sttr methods
    void set_edge_values(int dest_vID, int w)
    {
        dest_vertex_id = dest_vID;
        weight = w;
    }
    //Sets weight of edge
    void set_weight(int w)
    {
        weight = w;
    }

    int get_weight()
    {
        return weight;
    }
    //Gets ID of Vertex edge is connected to 
    int get_dest_vert_id()
    {
        return dest_vertex_id;
    }
};

class Vertex
{
    public:
        int town_id;
        string town_name;
        //list of edges of type (user created type) Edge 
        list<Edge> edge_list;
    
    Vertex()
    {
        town_id = 0;
        town_name = "";
    }

    Vertex(int id, string tname)
    {
        town_id = id;
        town_name = tname;
    }

    //gttr and sttr methods
    int get_town_id()
    {
        return town_id;
    }
    //returns town name
    string get_town_name()
    {
        return town_name;
    }
    //sets vertex ID
    void set_id(int id)
    {
        town_id = id;
    }
    //sets name of town
    void set_town_name(string tname)
    {
        town_name = tname;
    }
    //returns list of edges apart of each vertex
    list<Edge> get_edge_list()
    {
        return edge_list;
    }
    //prints list of edges
    void printEdgeList() 
    {
    cout << "[";
    for (auto it = edge_list.begin(); it != edge_list.end(); it++) {
      cout << it -> get_dest_vert_id() << "(" << it -> get_weight() << ") --> ";
    }
    cout << "]";
    cout << endl;
    }
};





class Graph
{   
    public:
        //vector (dynamic array) of (user created type) Vertex
        vector<Vertex> vertices; 
        //method gets a particular vertex through ID search (iterative)
        Vertex get_vertex_by_id(int vid)
        {   
            //comb the vertex desert
            Vertex temp;
            for (int i = 0; i < vertices.size(); i++)
            {   
                //if temp id == vertex id then return vertex.
                temp = vertices.at(i);
                if (temp.get_town_id() == vid)
                {
                    return temp;
                }
            }
            return temp;
        }

        // The purpose of this function is to add a vertex to add new vertex to 
        // end of vector
        void add_vertex(Vertex new_vertex)
        {   
            //bool checks if user entered ID already exists
            bool check = check_if_id_exists(new_vertex.get_town_id());
            if (check == true)
            {
                //inform user to retry entry
                cout << "This ID already exists... Try a different ID" << endl;
            }
            else
            {
                //if new ID, add new vertex to back of vector
                vertices.push_back(new_vertex);
                cout << "New Vertex Added! " << endl;
            }
        }

        //check if vertex exists by id
        //used in add_new vertex function
        bool check_if_id_exists(int VID) 
        {
            //iterate through vertices
            for (int i = 0; i<vertices.size(); i++)
            {   //if the search ID and real ID match, return true
                if (vertices.at(i).get_town_id() ==VID)
                {
                    return true;
                }
            }
            //else return false
            return false;
        }

        bool check_if_edge_exists(int from_vertex, int to_vertex)
        {
            //go to list of edges in vertex
            Vertex v = get_vertex_by_id(from_vertex);
            list < Edge > e;
            //create temp var containing list of edges
            e = v.get_edge_list();
            //from beging of list to the end
            for (auto it = e.begin(); it != e.end(); it++) // auto i = 5.7f i = float auto i = 4 i = int
            {   
                //if the id is connected with vertex going to, return true
                if (it -> get_dest_vert_id() == to_vertex)
                {
                    return true;
                    break;
                }
            }
            return false;
        }

        void add_edge_by_id(int from_vertex, int to_vertex, int weight) //(id1,id2,weight)
        {   //check if to and from vertex exist
            bool check_1 = check_if_id_exists(from_vertex);
            bool check_2 = check_if_id_exists(to_vertex);
            if ((check_1 && check_2 == true))
            {
                //check if edge already exists to avoid duplicate edges
                bool check_3 = check_if_edge_exists(from_vertex,to_vertex);
                if (check_3 == true)
                {
                    cout << "Edge between " << get_vertex_by_id(from_vertex).get_town_name() << "(" << from_vertex << ") and " << get_vertex_by_id(to_vertex).get_town_name() << "(" << to_vertex << ") Already Exists" << endl;
                }
                else
                {
                    for (int i = 0; i < vertices.size(); i++)
                    {
                        if (vertices.at(i).get_town_id() == from_vertex)
                        {
                            //add edge to source edge list in vertex class
                            Edge e(to_vertex, weight);
                            vertices.at(i).edge_list.push_back(e);
                        }else if (vertices.at(i).get_town_id() == to_vertex)
                        {
                            //add edge to destination vertex
                            Edge e(from_vertex, weight);
                            vertices.at(i).edge_list.push_back(e);
                        }
                    
                    }
                    cout << "Edge between " << from_vertex << " and " << to_vertex << " added successfully!" << endl;
                }
            }else {
                cout << "Invalid Vertex ID entered";
            }
        }

        void print_graph()
        {
            //iterate through all vertices in graph
            for(int i = 0; i < vertices.size(); i++)
            {
                //print the town name and id of each vertex in graph and its list of edges
                Vertex temp;
                temp = vertices.at(i);
                cout << temp.get_town_name() << " (" << temp.get_town_id() << ") >>>";
                temp.printEdgeList();
            }
        }

        

};


//brrrrrr...
int main()
{
    int option;
    int ID1;
    int ID2;
    int W;
    Graph g;
    string tname;
    Vertex V1;


    do {
    cout << "What operation would you like to perform? " 
    << " Select a number. Enter 0 to exit. " << endl;
    cout << "1) Add Vertex" << endl;
    cout << "2) Add Edge" << endl;
    cout << "3) Print Graph" << endl;
    cout << "0) Exit Program" << endl;

    cin >> option;

    switch (option)
    {
        case 0:
            break;
        
        case 1:
            cout << "Add Vertex: " << endl;
            ////////////////////////////////
            cout << "Enter Town ID: " << endl;
            cin >> ID1;
            cout << " Enter Town Name: " << endl;
            cin >> tname;

            V1.set_id(ID1);
            V1.set_town_name(tname);
            g.add_vertex(V1);

            break;
        case 2:
            cout << "Add Edge: " << endl;
            ///////////////////////////////
            cout << "Enter ID of Source Vertex (Town)";
            cin >> ID1;
            cout << "Enter ID of Destination Vertex (Town)";
            cin >> ID2;
            cout << "Enter Weight of Edge: ";
            cin >> W;
            g.add_edge_by_id(ID1,ID2,W);
            break;
        case 3:
            cout << "Print Graph: " << endl;
            //////////////////////////////////
            g.print_graph();
            
            
            break;
        default:
            cout << "Enter Proper Input: " << endl;

    }
    cout<<endl;
    } while (option != 0);


    return 0;
};