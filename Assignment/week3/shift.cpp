#include<iostream>
#include<vector>
#include <limits.h>
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

// given 2d vector give the row which contain max no. of 1. given ->
 /*
0   0   1   0   1
1   0   1   1   1
0   0   0   0   1
*/

void maxNo(vector<vector<int>>&v){
   
    int max = INT_MIN;
    int rowNo= 0;
    for(int i = 0; i<v.size();i++){
        int count = 0;
        for(int j = 0; j<v[0].size(); j++){
            if(v[i][j]==1){
                count++;
            }
        }
        if(count>max){
            max = count;
        rowNo = i;
        }
    }
    cout<<"The max count is: "<<max<<" and row no. is: "<<rowNo;
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
// missingNo(v);
// shiftk(v,2);
// for (int i = 0; i < v.size(); i++)
// {
//     cout<<v[i]<<" ";
// }
vector<vector<int>> v1 = {
    {1,0,0,0,1},
    {0,0,0,0,0},
    {1,1,1,1,1},
    {1,0,1,0,1}
};
// maxNo(v1);


return 0;
}