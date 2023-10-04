#include<iostream>
using namespace std;
void printArr(int arr[][3], int row, int col){
for (int i = 0; i < row; i++)
{
    for (int j  = 0; j < col; j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

}


void printCol(int arr[3][3], int row, int col){
for (int i = 0; i < col; i++)
{
    for (int j  = 0; j < row; j++)
    {
        cout<<arr[j][i]<<" ";
    }
    cout<<endl;
}

}
void rowwiseSum(int arr[][3],int row, int col){
for (int i = 0; i < col; i++)
{
    int sum=0;
    for (int j = 0; j < row; j++)
    {
        sum = sum+arr[j][i];
    }
    cout<<sum<<" ";
}

}

void trnanspose(int arr[][3],int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
         swap(arr[i][j],arr[j][i]);
        }
        
    }
    
}
int main()
{
int arr[4][3]={
    {12,43,56},
    {34,54,19},
    {90,56,30}
};
// printCol(arr,4,3);
// rowwiseSum(arr,4,3);
trnanspose(arr,3,3);
printArr(arr,3,3);
return 0;
}