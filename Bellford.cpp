#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Bellford {
public:
  vector<vector<int>> Matrix; //Adjacency matrix to be analyzed
  vector<int> Distance;       //Distance vector for storage of min distance values
  vector<int> Previous_Nodes; //Vector that stores each node's previous node
  int Source;                 //Source node value (starting value)
  int size;                   //Size storage for easy traversal
  string BuildingNames[19];  //List of building names for console output

  Bellford(vector<vector<int>> O_Matrix, int Sauce) : BuildingNames{"Math-Comp", "Lewis Science", "Prince Center", "Burdick", "Torreyson", "College Square", "Police Department",
  "Old Main", "Speech Language", "Maintenance", "Fine Art", "McAlister", "Student Center", "Student Health","Wingo", "Oak Tree",
  "New Business", "Brewer-Hegema", "Bear Village"}
  {
    Matrix.swap(O_Matrix);  //Sets parameter matrix to usable matrix
    Source = Sauce;         //Sets parameter source node to usable node
    size = Matrix.size();   //Gets size of matrix
    for(int i=0;i<size;i++) //Sets distance and previous nodes to default values (inf, nil)
      {Distance.push_back(INT_MAX); Previous_Nodes.push_back(-1);}
    Distance[Source] = 0;   //Sets starting node to 0
  }

  void Update(int i, int j) { //Update method
    if((Distance[i] > (Matrix[i][j] + Distance[j])) && (Matrix[i][j] != 0)) { //Compares for smallest number
      Distance[i] = (Matrix[i][j] + Distance[j]); //If found, sets appropriate values
      Previous_Nodes[i] = j;  //Sets previous node
    }
  }

  void Bellford_Run() { //Main Bellford Algorithm
      for(int j=0;j<size;j++) //Runs through each edge of each node
        for(int i=0;i<size;i++)
          {Update(i,j);}  //Calls update function
    }

  void toString() { //ToString to print results to console
    cout << "Bellford" << endl
      << endl;

    for(int k=0;k<size;k++) {
      cout << BuildingNames[k] << " [" << Distance[k]
          << "," << Previous_Nodes[k] << "] " << endl;  //Outputs data in readable format
    }
  }

  vector<int> getDist() {return Distance;}  //Getter for Distance vector
  vector<int> getPNodes() {return Previous_Nodes;}  //Getter for Previous Node vector
};
