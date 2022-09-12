#include<iostream>
using namespace std;

int main()
{
    int i, n, ans, fact;
    cin >> n;
    ans = 1;
    fact = 1;
    i = 2;
    while(fact < n)
    {
        fact = fact * i;
        if(n%fact == 0)
            ans = fact;
        i++;
    }
    cout << ans << endl;
    return 0;
}