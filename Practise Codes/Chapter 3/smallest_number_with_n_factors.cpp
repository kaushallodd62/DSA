#include<iostream>
#include<cmath>
using namespace std;
#define LIMIT 1e07+1

int solve(int n)
{
    if (n==1)
        return 1;
    if (n==2)
        return 2;
    int x = 4, count; 
    bool found = 0;
    while (!found && x < LIMIT)
    {
        count = 2;
        int limit = sqrt(x);
        for (int i = 2; i <= limit; i++)
        {
            if(x % i == 0) {
                count += 2;
                if (i == x/i)
                    count--;
            }
        }
        if(count >= n)
            found = 1;
        x++;
    }
    return --x;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}