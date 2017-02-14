// Listing 20.8. using typedef 
#include <iostream>
using namespace std; 
 
void Square (int&,int&);
void Cube (int&, int&);
void Swap (int&, int &);
void GetVals(int&, int&);
 
typedef  void (*VPF) (int&, int&) ;
void PrintVals(VPF,int&, int&);

int main(int argc, char *argv[]){
	 

     int valOne=1, valTwo=2;
     int choice;
     bool fQuit = false;

     VPF pFunc;

     while (fQuit == false)
     {

         cout << "(0)Quit (1)Change Values"
             << "(2)Square (3)Cube (4)Swap: ";

         cin >> choice;

         switch (choice)
         {
         case 1:
             pFunc = GetVals;
             break;
         case 2:
             pFunc = Square;
             break;
         case 3:
             pFunc = Cube;
             break;
         case 4:
             pFunc = Swap;
             break;
         default:
             fQuit = true;
             break;

         }

         if (fQuit == true)
             break;

         PrintVals ( pFunc, valOne, valTwo);
     }
     return 0;
 }

void PrintVals( VPF pFunc,int& x, int& y){
     cout << "x: " << x << " y: " << y << endl;
     pFunc(x,y);
     cout << "x: " << x << " y: " << y << endl;
}

void Square (int & rX, int & rY){

     rX *= rX;
     rY *= rY;

}

void Cube (int & rX, int & rY){

     int tmp;

     tmp = rX;
     rX *= rX;
     rX = rX * tmp;

     tmp = rY;
     rY *= rY;
     rY = rY * tmp;
}

void Swap(int & rX, int & rY){

     int temp;

     temp = rX;
     rX = rY;
     rY = temp;
}

void GetVals (int & rValOne, int & rValTwo){

     cout << "New value for ValOne: ";
     cin >> rValOne;
     cout << "New value for ValTwo: ";
     cin >> rValTwo;
}