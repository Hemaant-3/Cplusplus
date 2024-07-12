#include<iostream>
using namespace std;
void solve(int arr[], int size){
// cout<<sizeof(arr)<<"\n";
arr[0] = 90;
cout<<arr<<"\n";
   cout<<&arr<<"  Solve \n";
}
void solve2(int *arr, int size){
    // cout<<sizeof(arr)<<"\n";
    // *arr[0] = 12; illegal error
    *arr = 92;
    cout<<*arr<<"\n";
    cout<<arr<<"\n";
    cout<<&arr<<"  Solve\n";
}
int main()
{
int arr[] = {1,2,3,4};
// cout<<sizeof(arr)<<"\n";
solve2(&arr[0],4);
for (int i = 0; i < 4; i++)
{
    cout<<arr[i]<<" ";
}
cout<<arr<<"\n";

char ch[] = "love";
char* cptr = &ch[0]; //or ch only;
ch[0] = 'M';
//*cptr[0] = "L" // either cptr[0] = 'h' is not possible
cout<<cptr[0]<<"\n";
return 0;
}