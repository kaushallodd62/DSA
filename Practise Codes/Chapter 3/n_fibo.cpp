#include<iostream>
using namespace std;
#define MAX_SIZE (int)1e06

int main()
{
    int n;
    cin >> n;
    int fn, fnp1, fnp1sq;
    int f2n, f2np1;
    fn = 0;
    fnp1 = 1;
    int bin[MAX_SIZE];
    int i = 0;
    while(n > 0)
    {
        bin[i] = n % 2;
        n /= 2;
        i++;
    }
    i--;
    while(i--)
    {
        
    }
}