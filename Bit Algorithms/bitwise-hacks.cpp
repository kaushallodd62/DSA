#include<bits/stdc++.h>
using namespace std;

// setting the nth bit in a num
int set(int num, int pos) {
    return num | (1 << pos);
}

// clearing the nth bit in a num
int clear(int num, int pos) {
    return num & (~(1 << pos));
}

// complement the nth bit
int toggle(int num, int pos) {
    return num ^ (1 << pos);
}

// check if nth bit is set or clear
bool at_position(int num, int pos) {
    return num & (1 << pos);
}

// one's complement
int ones_compliment(int num) {
    return ~num;
}

// two's compliment
int twos_compliment(int num) {
    return ~num + 1; // or return -n;
}

// stripping the lowest set bit
int strip_last_set_bit(int num) {
    return num & num-1;
}

// getting lowest set bit
int lowest_set_bit(int num) {
    return num & -num;
}

// most significant set bit (method 1)
int setBitNumber(int num) {
    int k = log2(num);
    return 1 << k;
}

// most significant set bit (method 2)
int setBitNumber2(int n) {
    // we one by one set bits, then add 1 and then right shift by 1
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n = (n+1 >> 1) | (n & (1 << (sizeof(n) * CHAR_BIT) - 1));
    return n;
}

// you can divide and multiply by 2 by using right shift operator and left shift operator resp.

void swap(int& a, int& b) {
    if(a == b)
        return;
    a = a^b;
    b = a^b;
    a = a^b;
}

// compute xor of all numbers from 1 to n
int computeXOR(int n) {
    if(n%4 == 0)
        return n;
    if(n%4 == 1)
        return 1;
    if(n%4 == 2)
        return n+1;
    return 0;
}

// we can find number of leading, trailing zeros and number of set bits by doing:
void fun(int x) {
    cout << "Numner of leading zeros: " << __builtin_clz(x) << endl;
    cout << "Number of trailing zeros: " << __builtin_ctz(x) << endl;
    cout << "Number of set bits: " << __builtin_popcount(x) << endl;
}

// converting binary code into integer in C++
void binToInt() {
    int num = 0b1010;
    cout << 0b111 << endl;
    cout << num << endl;
}

// checking if the number has alternative set bits. 101010
bool bitsAreInAltOrder(unsigned int x) {
    unsigned int n = x ^ (x>>1);
    return n & ~0 == n;
}

// checking if all the bits in the number are set
bool allBitsAreSet(unsigned int n) {
    return !(n+1 & n);
    // return n & ~0 == n;
}

// count number of values between 1 and n such that n+i = n^i
int countValues(int n) {
    // n+i == n^i when n&i == 0
    int count = 0;
    while(n) {
        if(!(n&1))
            count++;
        n >>= 1;
    }
    return 1 << count;
}

// find xor of the xor's of all subsets of a vector.
int findXOR(vector<int> arr) {
    int n = arr.size();
    if(n > 1) return 0;
    else return arr[0];
}