 // Listing 10.4
 // Using the this pointer
 #include <iostream>
 using namespace std;
 
 class Rectangle
 {
    public:
       Rectangle();
       ~Rectangle();
       void SetLength(int length) { this->itsLength = length; }
       int GetLength() const { return this->itsLength; }
       void SetWidth(int width) { itsWidth = width; }
       int GetWidth() const { return itsWidth; }

    private:
       int itsLength;
       int itsWidth;
};

Rectangle::Rectangle()
{
   itsWidth = 5;
   itsLength = 10;
}

Rectangle::~Rectangle()
{}

int main(int argc, char *argv[]){
	
   Rectangle theRect;
   cout << "theRect is " << theRect.GetLength()
        << " feet long." << endl;
   cout << "theRect is " << theRect.GetWidth()
        << " feet wide." << endl;

   theRect.SetLength(20);
   theRect.SetWidth(10);
   cout << "theRect is " << theRect.GetLength()
        << " feet long." << endl;
   cout << "theRect is " << theRect.GetWidth()
        << " feet wide." << endl;

   return 0;
}