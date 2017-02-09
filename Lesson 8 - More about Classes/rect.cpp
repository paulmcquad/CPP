// Begin rect.cpp
#include "rect.hpp"

Rectangle::Rectangle(int top, int left, int bottom, int right)
{
    itsTop = top;
    itsLeft = left;
    itsBottom = bottom;
    itsRight = right;

    itsUpperLeft.SetX(left);
    itsUpperLeft.SetY(top);

    itsUpperRight.SetX(right);
    itsUpperRight.SetY(top);

    itsLowerLeft.SetX(left);
    itsLowerLeft.SetY(bottom);

    itsLowerRight.SetX(right);
    itsLowerRight.SetY(bottom);
}

void Rectangle::SetUpperLeft(Point Location)
{
    itsUpperLeft = Location;
    itsUpperRight.SetY(Location.GetY());
    itsLowerLeft.SetX(Location.GetX());
    itsTop = Location.GetY();
    itsLeft = Location.GetX();
}

void Rectangle::SetLowerLeft(Point Location)
{
    itsLowerLeft = Location;
    itsLowerRight.SetY(Location.GetY());
    itsUpperLeft.SetX(Location.GetX());
    itsBottom = Location.GetY();
    itsLeft = Location.GetX();
}

void Rectangle::SetLowerRight(Point Location)
{
    itsLowerRight = Location;
    itsLowerLeft.SetY(Location.GetY());
    itsUpperRight.SetX(Location.GetX());
    itsBottom = Location.GetY();
    itsRight = Location.GetX();
}

void Rectangle::SetUpperRight(Point Location)
{
    itsUpperRight = Location;
    itsUpperLeft.SetY(Location.GetY());
    itsLowerRight.SetX(Location.GetX());
    itsTop = Location.GetY();
    itsRight = Location.GetX();
}

void Rectangle::SetTop(int top)
{
    itsTop = top;
    itsUpperLeft.SetY(top);
    itsUpperRight.SetY(top);
}

void Rectangle::SetLeft(int left)
{
    itsLeft = left;
    itsUpperLeft.SetX(left);
    itsLowerLeft.SetX(left);
}

void Rectangle::SetBottom(int bottom)
{
    itsBottom = bottom;
    itsLowerLeft.SetY(bottom);
    itsLowerRight.SetY(bottom);
}

void Rectangle::SetRight(int right)
{
    itsRight = right;
    itsUpperRight.SetX(right);
    itsLowerRight.SetX(right);
}

int Rectangle::GetArea() const
{
    int Width = itsRight-itsLeft;
    int Height = itsTop - itsBottom;
    return (Width * Height);
}

// compute area of the rectangle by finding corners,
// establish width and height and then multiply
int main()
{
    //initialize a local Rectangle variable
    Rectangle MyRectangle (100, 20, 50, 80 );

    int Area = MyRectangle.GetArea();

    cout << "Area: " << Area << "\n";
    cout << "Upper Left X Coordinate: ";
    cout << MyRectangle.GetUpperLeft().GetX();
    return 0;
}
