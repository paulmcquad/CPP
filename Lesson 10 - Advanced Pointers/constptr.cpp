// Listing 10.5
// Using pointers with const methods
#include <iostream>
using namespace std;

class Rectangle
{
public:
 Rectangle();
 ~Rectangle();
 void SetLength(int length) { itsLength = length; }
 int GetLength() const { return itsLength; }

 void SetWidth(int width) { itsWidth = width; }
 int GetWidth() const { return itsWidth; }

private:
 int itsLength;
 int itsWidth;
};

 Rectangle::Rectangle():
 itsWidth(5),
 itsLength(10)
 {}

 Rectangle::~Rectangle()
 {}

int main(int argc, char *argv[]){
     Rectangle* pRect =  new Rectangle;
     const Rectangle * pConstRect = new Rectangle;
     Rectangle * const pConstPtr = new Rectangle;

     cout << "pRect width: \t\t"
					<< pRect->GetWidth() << " feet" << endl;
     cout << "pConstRect width: \t"
               << pConstRect->GetWidth() << " feet" << endl;
     cout << "pConstPtr width: \t"
				<< pConstPtr->GetWidth() << " feet" << endl;

     pRect->SetWidth(10);
     // pConstRect->SetWidth(10);
     pConstPtr->SetWidth(10);

     cout << "pRect width: \t\t"
					<< pRect->GetWidth() << " feet" << endl;
     cout << "pConstRect width: \t"
               << pConstRect->GetWidth() << " feet" << endl;
     cout << "pConstPtr width: \t"
				<< pConstPtr->GetWidth() << " feet" << endl;
     return 0;
 }