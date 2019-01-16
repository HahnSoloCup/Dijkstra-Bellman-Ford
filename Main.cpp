#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include "Dijkstra.cpp"
#include "Bellford.cpp"
using namespace std;

vector<vector<int>> ReadIn() {    //Reads in CSV matrix for storage
  ifstream in("CSV Files/Building_Matrix.csv");  //Reads in CSV file
  vector<vector<int>> fields;     //Declares 2d vector for storage
  string buffer;                  //Generates buffer
  getline(in, buffer);            //Reads line into buffer to remove first line (Header data)
    if (in) {
        string line;              //Generates temporary storage for each line
        while (getline(in, line)) { //Loops through data
            stringstream sep(line); //Generates stringstream
            string field;           //Generates temporary string
            fields.push_back(vector<int>()); //Pushes blank vector value onto 2d vector
            while (getline(sep, field, ',')) {  //Reads in data to temporary string using stringstream, seperated by comma (CSV files seperate using commas)
                if(!isalpha(field[0]))  //Removes y first value
                  fields.back().push_back(atoi(field.c_str())); //Sets field to integer value and pushes onto last value of 2d vector
        }}
      }
  in.close();                     //Closes file
  return fields;                  //Returns 2d vector
}

void PrintMat(vector<vector<int>> Matrix) { //Prints matrix in full for visual or debugging purposes
  for(int i = 0; i < Matrix.size(); i++) {cout << endl;
    for(int j = 0; j < Matrix.size(); j++) {cout << Matrix[i][j] << " ";} //Matrix[y][x]
  }
}

int main() {
  vector<vector<int>> Matrix = ReadIn();  //Reads 2d matrix from CSV file into 2d Matrix value

  cout << "Building Name [Distance, Previous Node]"
       << endl << endl; //Key for user to interpret data

  Djikstra DTester(Matrix, 0);  //Creates Dijkstra object
  DTester.Djikstra_Run();       //Calls main method
  DTester.toString();           //Prints Results

  cout << endl;

  Bellford BTester(Matrix,0);   //Creates Bellford object
  BTester.Bellford_Run();       //Runs Bellford method
  BTester.toString();           //Prints Results

  cout << endl << endl << "Finished!" << endl; //Notifies user of success
  return 0;
}
