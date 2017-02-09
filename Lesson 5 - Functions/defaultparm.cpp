// Listing 5.6 - demonstrates use
// of default parameter values

#include <iostream>
using namespace std;
 
int AreaCube(int length, int width = 25, int height = 1);

int main(int argc, char *argv[]){

     int length = 100;
     int width = 50;
     int height = 2;
     int area;

     area = AreaCube(length, width, height);
     cout << "First time area equals " << area << "\n";


     area = AreaCube(length, width);
     cout << "Second time area equals " << area << "\n";
 

     area = AreaCube(length);
     cout << "Third time area equals " << area << "\n";
     return 0;
 }


int AreaCube(int length, int width, int height){
     return (length * width * height);
}

