// Listing 21.6 Debugging Levels
#include <iostream>
#include <string.h>
using namespace std;

enum LEVEL { NONE, LOW, MEDIUM, HIGH };
#define DEBUGLEVEL HIGH

#if DEBUGLEVEL < LOW  // must be low, medium or high
#define ASSERT(x)
#else
#define ASSERT(x) \
     if (! (x)) \
     { \
         cout << "ERROR!! Assert " << #x << " failed\n"; \
         cout << " on line " << __LINE__  << "\n"; \
         cout << " in file " << __FILE__ << "\n";  \
     }
#endif

#if DEBUGLEVEL < MEDIUM
#define EVAL(x)
#else
#define EVAL(x) \
    cout << #x << ":\t" << x << endl;
#endif

#if DEBUGLEVEL < HIGH
#define PRINT(x)
#else
#define PRINT(x) \
    cout << x << endl;
#endif

 class String
 {
 public:
     // constructors
     String();
     String(const char *const);
     String(const String &);
     ~String();

     char & operator[](int offset);
     char operator[](int offset) const;

     String & operator= (const String &);
     int GetLen()const { return itsLen; }
     const char * GetString() const
         { return itsString; }
     bool Invariants() const;

 private:
     String (int);         // private constructor
     char * itsString;
     unsigned short itsLen;
 };

 bool String::Invariants() const
 {
     PRINT("(String Invariants Checked)");
     return ( (bool) (itsLen && itsString) ||
         (!itsLen && !itsString) );
 }

 class Animal
 {
 public:
     Animal():itsAge(1),itsName("John Q. Animal")
     {ASSERT(Invariants());}

     Animal(int, const String&);
     ~Animal(){}

     int GetAge()
     {
         ASSERT(Invariants());
         return itsAge;
     }

     void SetAge(int Age)
     {
         ASSERT(Invariants());
         itsAge = Age;
         ASSERT(Invariants());
     }
     String& GetName()
     {
         ASSERT(Invariants());
         return itsName;
     }

     void SetName(const String& name)
     {
         ASSERT(Invariants());
         itsName = name;
         ASSERT(Invariants());
     }

     bool Invariants();
 private:
     int itsAge;
     String itsName;
 };

 // default constructor creates string of 0 bytes
 String::String()
 {
     itsString = new char[1];
     itsString[0] = '\0';
     itsLen=0;
     ASSERT(Invariants());
 }

 // private (helper) constructor, used only by
 // class methods for creating a new string of
 // required size.  Null filled.
 String::String(int len)
 {
     itsString = new char[len+1];
     for (int i = 0; i<=len; i++)
         itsString[i] = '\0';
     itsLen=len;
     ASSERT(Invariants());
 }

 // Converts a character array to a String
 String::String(const char * const cString)
 {
     itsLen = strlen(cString);
     itsString = new char[itsLen+1];
     for (int i = 0; i<itsLen; i++)
         itsString[i] = cString[i];
     itsString[itsLen]='\0';
     ASSERT(Invariants());
 }

 // copy constructor
 String::String (const String & rhs)
 {
     itsLen=rhs.GetLen();
     itsString = new char[itsLen+1];
     for (int i = 0; i<itsLen;i++)
         itsString[i] = rhs[i];
     itsString[itsLen] = '\0';
     ASSERT(Invariants());
 }

 // destructor, frees allocated memory
 String::~String ()
 {
     ASSERT(Invariants());
     delete [] itsString;
     itsLen = 0;
 }

 // operator equals, frees existing memory
 // then copies string and size
 String& String::operator=(const String & rhs)
 {
     ASSERT(Invariants());
     if (this == &rhs)
         return *this;
     delete [] itsString;
     itsLen=rhs.GetLen();
     itsString = new char[itsLen+1];
     for (int i = 0; i<itsLen;i++)
         itsString[i] = rhs[i];
     itsString[itsLen] = '\0';
     ASSERT(Invariants());
     return *this;
 }

 //non constant offset operator, returns
 // reference to character so it can be
 // changed!
 char & String::operator[](int offset)
 {
     ASSERT(Invariants());
     if (offset > itsLen)
         return itsString[itsLen-1];
     else
         return itsString[offset];
     ASSERT(Invariants());
 }

 // constant offset operator for use
 // on const objects (see copy constructor!)
 char String::operator[](int offset) const
 {
     ASSERT(Invariants());
     if (offset > itsLen)
         return itsString[itsLen-1];
     else
         return itsString[offset];
     ASSERT(Invariants());
 }

 Animal::Animal(int age, const String& name):
 itsAge(age),
 itsName(name)
 {
     ASSERT(Invariants());
 }

 bool Animal::Invariants()
 {
     PRINT("(Animal Invariants Checked)");
     return (itsAge > 0 && itsName.GetLen());
 }

int main(int argc, char *argv[]){
	
     const int AGE = 5;
     EVAL(AGE);
     Animal sparky(AGE,"Sparky");
     cout << "\n" << sparky.GetName().GetString();
     cout << " is ";
     cout << sparky.GetAge() << " years old.";
     sparky.SetAge(8);
     cout << "\n" << sparky.GetName().GetString();
     cout << " is ";
     cout << sparky.GetAge() << " years old.";
     return 0;
 }
