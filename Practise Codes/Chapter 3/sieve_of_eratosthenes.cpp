/* Program to print the prime numbers till n using Eratostenes method */

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

void Eratosthenes(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    int limit = sqrt(n);

    for (int i = 2; i  <= limit; i++)
        if(prime[i] == true)
            for (int j = i*i; j <= n; j += i)
                prime[j] = false;

    for (int i = 0; i <= n; i++)
        if(prime[i])
            cout << i << " ";
    
    cout << endl;
}   

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >>  n;
    Eratosthenes(n);
    return 0;
}