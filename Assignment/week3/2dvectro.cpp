#include<iostream>
#include<vector>
using namespace std;
int main()
{
// vector<vector<int>> arr(5,vector<int>(10,0));

// cout<<arr.size()<<endl;
// cout<<arr[0].size()<<endl;
// for (int i = 0; i < arr.size(); i++)
// {
//     for (int j = 0; j < arr[0].size(); j++)
//     {
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }



vector<vector<int>> v(2,vector<int>(4));
// vector<int> temp;
// temp.push_back(2);
// temp.push_back(22);
// temp.push_back(23);
// temp.push_back(24);
vector<int>temp(10,11);
vector<int>temp1(12,13);
vector<int>temp2(30,91);
vector<int>temp3(40,81);
vector<int>temp4(60,71);
v.push_back(temp);
v.push_back(temp2);
v.push_back(temp3);
v.push_back(temp4);

for (int i = 0; i < v.size(); i++)
{
    for (int j = 0; j < v[0].size(); j++)
    {
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}