#include<iostream>
using namespace std;
fun(int n){
    fun(n-1);
}

void print(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    print(n-1);
}
int pow(int n){
    if(n==0){
        return 1;
    }
    int k = 2*pow(n-1);
    return k;
}
int main()
{
// fun(100);
// print(10);
cout<<pow(20)<<" ";
return 0;
}