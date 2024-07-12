#include <iostream>
#include <cmath>
using namespace std;

int decimalToBin(int n)
{
    // using devision method
    int binaryno = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n % 2;
        binaryno = bit * pow(10, i++) + binaryno;
        n = n / 2;
    }
    return binaryno;
}
int decimalToBinMeh2(int n)
{

    // using bitwise methods
    int binaryno = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n & 1;
        binaryno = bit * pow(10, i++) + binaryno;
        n = n >> 1;
    }
    return binaryno;
}

int binaryTodec(int n)
{
    int decimal = 0;
    int i = 0;
    while (n)
    {

        int bit = n % 1;
        decimal = decimal + bit * pow(2, i++);
        n /= 10;
    }
    return decimal;
}
int binaryTodec2(int n)
{
    ///usin bitwise but lengthy process
    int decimal = 0;
    int i = 0;
    while (n)
    {

        int bit = n & 1; //  it represent whole integer not digit of integer. (1010) it is 1 thousand ten not binary. 
        decimal = decimal + bit * pow(2, i++);
        n /= 10;
    }
    return decimal;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the no." << endl;
    cin >> n;

    // int binary = decimalToBin(n);
    // int binary = decimalToBinMeh2(n);
    // cout<<binary;
    int decimal = binaryTodec2(n);
    cout << decimal;
    return 0;
}
