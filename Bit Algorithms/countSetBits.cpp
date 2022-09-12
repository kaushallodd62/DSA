#include<bits/stdc++.h>
using namespace std;

// method 1 using a & a-1
int setBits(int a) {
    int count = 0; 
    while(a) {
        a &= a-1;
        count++;
    }
    return count;
}

// method 2
int setBits(int a) {
    int count = 0;
    for(int i=0; i<sizeof(int) * 8; i++) {
        if(a & (1 << i))
            count++;
    }
    return count;
}

// method 3
int setBits(int a) {
    int count = 0;
    while(a) {
        if(a & 1)
            count++;
        a >> 1;
    }
    return count;
}