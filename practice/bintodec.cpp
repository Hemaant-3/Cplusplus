#include <iostream>
using namespace std;
void decToBin(int n)
{

    int sum = 0;
    
    int place = 1;
    while(n){
    int digit = n%2;
    // cout<<digit<<" ";
    sum = sum+place*digit;
    place = place*10; 
    n = n/2;
    }
    cout<<sum<<endl;
}

int main()
{
int n = 21;
decToBin(n);
    return 0;
}