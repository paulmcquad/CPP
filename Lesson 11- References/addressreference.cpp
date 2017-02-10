// Listing 11.2
// Demonstrating the use of References
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	
    int  intOne;
    int &rSomeRef = intOne;

    intOne = 5;
    cout << "intOne: " << intOne << endl;
    cout << "rSomeRef: " << rSomeRef << endl;

    cout << "&intOne: "  << &intOne << endl;
    cout << "&rSomeRef: " << &rSomeRef << endl;

    return 0;
}
