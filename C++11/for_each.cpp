#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
 
struct Sum
{
    Sum(): sum{0} { }
    void operator()(int n) { sum += n; }
    int sum;
};
 
int main(int argc, char *argv[]){
	
    vector<int> nums{3, 4, 2, 8, 15, 267};
 
    cout << "before:";
    for (auto const &n : nums)
    {
        cout << ' ' << n;
    }
    cout << '\n';
 
    for_each(nums.begin(), nums.end(), [](int &n){ n++; });
 
    // calls Sum::operator() for each number
    Sum s = for_each(nums.begin(), nums.end(), Sum());
 
    cout << "after: ";
    for (auto const &n : nums)
    {
        cout << ' ' << n;
    }
    cout << '\n';
    cout << "sum: " << s.sum << '\n';
}