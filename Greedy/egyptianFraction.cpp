#include<bits/stdc++.h>
using namespace std;

void egyptianFraction(int nr, int dr) {
    if(nr == 0 || dr == 0)
        return;
    if(dr%nr == 0) {
        cout << "1/" << dr/nr;
        return;
    }
    if(nr%dr == 0) {
        cout << nr/dr;
        return;
    }
    if(nr > dr) {
        cout << nr/dr << " + ";
        egyptianFraction(nr%dr, dr);
        return;
    }
    int new_dr = dr/nr + 1;
    cout << "1/" << new_dr << " + ";
    egyptianFraction(nr*new_dr - dr, dr*new_dr);
}

int main() {
    int nr = 6, dr = 14;
    egyptianFraction(nr, dr);
    cout << endl;
    return 0;
}