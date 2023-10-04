#include<iostream>
using namespace std;

/*
given i/p -> 23,-4,12,-10,-11,40,60;
sort the array where positive number should be right side of array
*/
//two pointer approcah
void sortmy(int arr[], int size){
    int i  = 0;
    int j = size-1;
while (i<j)
{
    
    while(arr[i]<0){
        i++;
        
    }

    while (arr[j]>0)
    {
       
        j--;
    }

    swap(arr[i],arr[j]);
    i++;
    j--;
    
    
    }

}

// dutch national flag 0,1,2 sort.
void dutch(int arr[],int size){
     int i = 0;
     int j = size-1;
     int pointer = 0;
     while (pointer<j){
        if (arr[pointer]==1)
        {
            pointer++;
        }
        else if(arr[pointer]==0){
        swap(arr[pointer],arr[i]);
        i++; pointer++; // left side me traverse kr chuka hai 0 ya to 1 hi milega
     }
     else if (arr[pointer]==2)
     {
        swap(arr[pointer],arr[j]);
      j--;  
     }
     
     
     }
}


int main()

{
// int arr[] = {23,-7,12,-10,-11,40,60};

// sortmy(arr,7);

int arr2[] = {1,2,2,0,1,0,2,1};
int size = 8;
dutch(arr2,size);
for (int i = 0; i < size; i++)
{
    
    cout<<arr2[i]<<" ";
}


return 0;
}