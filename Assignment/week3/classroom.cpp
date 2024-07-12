#include<iostream>
using namespace std;

// count zero and one in array
void countzero(int arr[],int size){
int count0 = 0;
int count1=0;
for (int i = 0; i < size; i++)
{
    if (arr[i]==0)
    {
        count0++;
    } else{
        count1++;
    }
    
}
    printf("The no of zero is: %d\n The number of One is: %d",count0,count1);
}
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
     cout<<arr[i]<<" ";   
    }
    
}
 // Reverse an array;
void Reverse(int arr[], int size){

    int left = 0;
    int right = size-1;
    while (left<=right)
    {
        swap(arr[left],arr[right]);
        left++; right--;
    }
    
}


//Extreme print in array 
//eg. i/p -> 10,20,30,40,50,60
//o/p-> 10,60,20,50,30,40
void extremePrint(int arr[], int size){
    int i = 0; int j = size-1;
    while (i<=j)
    {
        if (i==j)
        {
            cout<<arr[i];
        }
        else{
        cout<<arr[i]<<" ";
        cout<<arr[j]<<" ";
       
        }
         i++; j--;
    }
    
}

void findunique(int arr[], int size){
    int ans = 0;
    int i = 0;
    for (; i < size; i++)
    {
        ans = ans^arr[i];
    }
    printf("The unique element  is %d", ans);
    
}

// i/p -> print all pairs of element given in array
// eg. arr->{10,20,30}
//o/p - > (10,10), (10,20),...

void printPair(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            printf("(%d,%d), ",arr[i],arr[j]);
           
    }
        
    }
    
}
/*
Sort zero and one
method1 -> Counting method... 2-> two pointer approach
*/
void sortCount(int arr[], int size)
{
    int count0=0;
    int count1=0;
    int k = 0;
    for (int i =0; i < size; i++)
    {
        if(arr[i]==0){
            count0++;
        }
        else{
            count1++;
        }
    }
    
    while (count0>0)
    {
        arr[k] = 0;
        count0--;
        k++;
    }

    while (count1>0)
    {
        arr[k] = 1;
        count1--;
        k++;
    }
    
    
    
}
void sortZero1(int arr[], int size){
    int left = 0; //index
    int right = size-1; //index

    while (left<=right)
    {
    while (arr[left]==0)
    {
        left++;
    }
    while (arr[right]==1)
    {
       right--;
    }

    swap(arr[left],arr[right]);
    left++;
    right--;
    }
    
}
// shift element by k in array
//shifting of one element
void shift(int arr[], int size,int k){
    int temp[k];
    int counter =size-1;
    int arcount= counter;
    for (int i = 0; i <k; i++)
    {
    temp[i] = arr[arcount]; // storing the last k element;
    // cout<<arr[arcount]<<" " ;
    arcount--;
    }
    // cout<<temp[0]<<" "<<temp[1];
    for (int i = counter; i >= k; i--)   
    {
        arr[i] = arr[i-k];
    }
    int j = 0;
    for (int i = k-1; i >= 0; i--)
    {
        // cout<<endl<<temp[j]<<" ";
        
        arr[j]= temp[i];
        j++;
    }
    // cout<<arr[0]<<" "<<arr[1];
    
}
void countsetBit(int n){
    int count=0;
  

  /*
    while (n!=0)
    {
        
        int bit = n&1;
        if (bit==1)
        {
            count++;
        }
        // n>>=1; 
        //or
        n = n>>1;
    }
*/
while (n)
{
    n = n&(n-1);
    count++;
}



    cout<<"The no. of set bit is: "<<count;


}
int main()
{
int arr4[] = {1,1,1,1,0,0,1,0,1,0};
int size4 = 10;
// countzero(arr,size);
int arr[] = {20,30,40,50,60,70,80};
int size = 7;
int arr2[] = {20,20,12,12,33,11,33,44,44};
int size1 = 9;
int arr3[]={10,20,30};
int size3 = 3;
// Reverse(arr,size);
// printArray(arr,size);
// extremePrint(arr,size);
// findunique(arr2,size1);
// printPair(arr3,size3);
// sortCount(arr4,size4);
// sortZero1(arr4,size4);
// shift(arr,size,5);
// printArray(arr,size);
countsetBit(10);
return 0;
}