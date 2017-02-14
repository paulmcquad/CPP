//Listing 11.5 Demonstrates passing by reference
#include <iostream>
using namespace std;

void swap(int *x, int *y);   
 // the "*" says that the function expects to get pointers 
int main(int argc, char *argv[]){
	
     int x = 5, y = 10; 

     cout << "Main. Before swap, x: " << x 
                                 << " y: " << y << "\n"; 
     swap(&x,&y);
     cout << "Main. After swap, x: " << x
                                << " y: " << y << "\n";
     return 0;
}

void swap (int *px, int *py) {
      int temp;

      cout << "Swap. Before swap, *px: " << *px
                                  << " *py: " << *py << "\n";

      temp = *px;
      *px = *py;
      *py = temp;

      cout << "Swap. After swap, *px: " << *px
                                 << " *py: " << *py << "\n";
}