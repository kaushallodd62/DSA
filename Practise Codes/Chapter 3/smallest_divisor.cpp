#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int i, n, ans, limit;
    bool found = 0;
    cin>>n;
    limit = sqrt(n);
    if(n%2 == 0)
    {
        ans = 2;
        found = 1;
    }
    else
    {
        for (i = 3; i <= limit && !found; i=i+2)
        {
            if(n%i == 0)
            {
                ans = i;
                found = 1;
            }
        }
    }
    if (!found)
        ans = n;
    cout << ans <<endl;
    return 0;
}