#include <iostream>
using namespace std;

typedef unsigned short int USHORT;       //typedef defined

int main(int argc, char *argv[]){

	USHORT Width = 5;
	USHORT Length;

	Length = 10;

	USHORT Area = Width * Length;

	cout << "Width: " << Width << "\n";
	cout << "Length: " << Length << endl;
	cout << "Area: " << Area << endl;

return 0;

} 

