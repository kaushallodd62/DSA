#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n)
{
    int i, prime = 1;
    if (n == 2)
        return prime;
    if(n%2 == 0) 
    {
        prime = 0;
    }
    else 
    {
        i = 3;
        while(i <= sqrt(n) && prime) 
        {
            if (n%i == 0)
                prime = 0;
            else
               i += 2;
        }
    }
    return prime;
}

int main()
{
    int n;
    cin >> n;
    if(n < 2)
        cout << "No primes!" << endl;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (isPrime(i))
                cout << i << "\t";
        }
    }
    cout << "\n";
    return 0;    
}