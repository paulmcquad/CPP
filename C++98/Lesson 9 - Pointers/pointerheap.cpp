// Listing 9.4
// Allocating and deleting a pointer

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     int localVariable = 5;
     int * pLocal= &localVariable;
     int * pHeap = new int;

     if (pHeap == NULL)
     {
         cout << "Error! No memory for pHeap!!";
         return 1;
     }

     *pHeap = 7;

     cout << "localVariable: " << localVariable << "\n";
     cout << "*pLocal: " << *pLocal << "\n";
     cout << "*pHeap: " << *pHeap << "\n";

     delete pHeap;

     pHeap = new int;

     if (pHeap == NULL)

     {
         cout << "Error! No memory for pHeap!!";

         return 1;

     }

     *pHeap = 9;

     cout << "*pHeap: " << *pHeap << "\n";
     delete pHeap;

     return 0;
}

