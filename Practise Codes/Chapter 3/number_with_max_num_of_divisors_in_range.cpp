#include"smallest_number_with_n_factors.cpp"
#include<iostream>
using namespace std;

int main()
{
    int n, l, r;
    cout << "Enter range: " << endl;
    cin >> l >> r;
    n = 1;
    while (solve(n) <= r)
    {
        n++;
    }
    cout << --n << endl;
    return 0;
}