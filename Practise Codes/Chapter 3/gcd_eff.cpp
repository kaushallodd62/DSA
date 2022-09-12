#include<iostream>
using namespace std;

int gcd (int m, int n)
{
    if (m != 0)
        return gcd(n % m, m);
    else
        return n;
}

int main()
{
    int m, n;
    cin >> m >> n;
    //int large = n; int small = m;
    //int rem = large % small;
    //while (rem) 
    //{
    //    large = small;
    //    small = rem;
    //    rem = large % small;
    //}
    cout << "gcd(" << m << ", " << n << ") = " << gcd(m, n) << endl;
    return 0;
}

