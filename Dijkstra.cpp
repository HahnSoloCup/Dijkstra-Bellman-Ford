#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Djikstra {
public:
  vector<vector<int>> Matrix; //Adjacency matrix to be analyzed
  vector<pair<int,int>> Q;    //Pseudo-priority queue to determine order of nodes to run
  vector<int> Distance;       //Distance vector for storage of min distance values
  vector<int> Previous_Nodes; //Vector that stores each node's previous node
  int Source;                 //Source node value (starting value)
  int size;                   //Size storage for easy traversal
  string BuildingNames[19];

  Djikstra(vector<vector<int>> O_Matrix, int Sauce)  : BuildingNames{"Math-Comp", "Lewis Science", "Prince Center", "Burdick", "Torreyson", "College Square", "Police Department",
  "Old Main", "Speech Language", "Maintenance", "Fine Art", "McAlister", "Student Center", "Student Health","Wingo", "Oak Tree",
  "New Business", "Brewer-Hegema", "Bear Village"}
  {
    Matrix.swap(O_Matrix);  //Sets parameter matrix to usable matrix
    Source = Sauce;         //Sets parameter source node to usable node
    size = Matrix.size();   //Gets size of matrix
    for(int i=0;i<size;i++) //Sets distance and previous nodes to default values (inf, nil)
      {Distance.push_back(INT_MAX); Previous_Nodes.push_back(-1);}
    Distance[Source] = 0;   //Sets starting node to 0
    for(int j=0;j<size;j++) //Sets default values of the priority queue (default distance values/node values)
      {Q.push_back(make_pair(Distance[j],j));} //Distance values first, then node name values
  }

  void Update() {   //Update function for Q
    for(int i=Q.size();i>0;i--)
      Q[i].first = Distance[Q[i].second]; //Sets each node's shortest path value to that nodes distance value
  }

  void Djikstra_Run() { //Main method for class
    while(!Q.empty()) { //Checks if Q is empty
      sort(Q.rbegin(), Q.rend()); //Sorts Q in reverse
      int j = Q.back().second;    //Sets the back (or in this case, first) number to j
      Q.pop_back();               //Removes that removed value from Q
      for(int i=0;i<size;i++) {   //Runs through each y value of each j
        if((Distance[i] > (Matrix[i][j] + Distance[j]))&&(Matrix[i][j] != 0)) { //Checks for smaller value
          Distance[i] = (Matrix[i][j] + Distance[j]); //If smaller value found, sets minimum distance for that node to that value
          Previous_Nodes[i] = j;  //Sets that updated nodes new previous node value
          Update();               //Updates Q with new distance values
        }}}
      }

  void toString() { //ToString to print results to console
    cout << "Dijkstra" << endl
      << endl;

    for(int k=0;k<size;k++) {
      cout << BuildingNames[k] << " [" << Distance[k]
          << "," << Previous_Nodes[k] << "] " << endl;  //Outputs data in readable format
    }
  }

  vector<int> getDist() {return Distance;}  //Getter for Distance vector
  vector<int> getPNodes() {return Previous_Nodes;}  //Getter for Previous Node vector
};
