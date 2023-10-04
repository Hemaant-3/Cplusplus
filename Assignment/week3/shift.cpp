#include<iostream>
#include<vector>
using namespace std;
// shift k vector or array.
void shiftk(vector<int>&v, int k){
    int size = v.size();
    vector<int>vNew(size,-1);
    int newIndex = 0;
    for (int i = 0; i < size; i++)
    {
        newIndex = (i+k)%size;
        vNew[newIndex] = v[i];
    }
    v = vNew;
}

 // given number 1-n find the missing number

void missingNo(vector<int>&v){
    //we assume the largest no. is at last pos
    int lNum = v.size()-1;
    int  n = v[lNum];
    // cout<<v[lNum];
    int sum1 = 0;
    int sum2 = ((n*n)/2)+(n/2);
    for (int i = 0; i <v.size(); i++)
    {
        sum1 = sum1+v[i];
    }
    // cout<<sum2<<"  "; cout<<sum1<<"  ";
    cout<<"The missing number is: "<<sum2-sum1;
}
int main()
{
vector<int>v(5,-1);
// cout<<v.size();
v[0]= 1;
v[1]= 3;
v[2]= 4;
v[3]= 5;
v[4]= 6;
missingNo(v);
// shiftk(v,2);
// for (int i = 0; i < v.size(); i++)
// {
//     cout<<v[i]<<" ";
// }

return 0;
}