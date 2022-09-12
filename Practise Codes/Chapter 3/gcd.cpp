#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int gcd = (n > m)? m : n;
    while((n%gcd) || (m%gcd))
    {
        gcd--;
    }
    cout << gcd << endl;
    return 0;
}