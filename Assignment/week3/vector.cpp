#include<iostream>
#include <vector>
using namespace std;
void printVect(vector<int>&v){
    // for (auto &&i : v)
    // {
    //     cout<<i<<" ";
    // }
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}
void takeInp(vector<int>&v, int size){
   for (int i = 0; i < size; i++)
   {
    int a;
    cout<<"Enter the number to push into vector: "<<"  ";
    cin>>a;
    v.push_back(a);
   }
   
    
}
int main()
{
// vector<int>v;
// vector<int>v(5,-101); // size of vector and intial values of vector.
// takeInp(v,5);
vector<int>a = {12,35,6,5,32,65,90,10,11}; 
vector<int>v(a);//copy vector
a.clear();
cout<<"The size of vector is: "<<a.size()<<endl;
cout<<"The capacity of vector is: "<<a.capacity();
// printVect(v);
return 0;
}