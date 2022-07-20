#include <iostream>
using namespace std;

// print the number and its binary representation
void print_bitwise(int x, int len = 8);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int a = 0b00101101;
    int b = 0b01001110;
    print_bitwise(a);
    print_bitwise(b);
    cout << endl;
    
    cout << "== bitwise and & ==" << endl;
    print_bitwise(a & b);
    cout << "== bitwise or | ==" << endl;
    print_bitwise(a | b);
    cout << "== bitwise xor ^ ==" << endl;
    print_bitwise(a ^ b);

    cout << endl;

    cout << "== right shift << ==" << endl;
    print_bitwise(a);
    print_bitwise(a << 1);
    print_bitwise(a << 2);
    cout << "== left shift >> ==" << endl;
    print_bitwise(a);
    print_bitwise(a >> 1);
    print_bitwise(a >> 2);
    
    cout << "== bitwise not ~ ==" << endl;
    print_bitwise(~a);

    return 0;
}

void print_bitwise(int x, int len) {
    cout << x << "\t";
    len--;
    while (len >= 0) {
        if ( (x & (1<<len)) > 0) cout << 1;
        else cout << 0;
        if (len % 4 == 0) cout << ' ';
        len--;
    }
    cout << endl;
}

/*
45      0010 1101 
78      0100 1110 

== bitwise and & ==
12      0000 1100 
== bitwise or | ==
111     0110 1111 
== bitwise xor ^ ==
99      0110 0011 

== right shift << ==
45      0010 1101 
90      0101 1010 
180     1011 0100 
== left shift >> ==
45      0010 1101 
22      0001 0110 
11      0000 1011 
== bitwise not ~ ==
-46     1101 0010 
*/