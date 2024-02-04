#include<iostream>
using namespace std;
int main()
{
    /**
//creating a pointer
int a = 20;
int *ptr = &a;
// cout<<sizeof(&a)<<endl;
// cout<<sizeof(a)<<endl;
// cout<<sizeof(ptr)<<endl;
// cout<<sizeof(*ptr)<<endl;
// cout<<*ptr<<endl;
// cout<<ptr<<endl;

// cout<<sizeof(int)<<"\n";
// cout<<sizeof(int*);
// int *ptr1 = &a;
// cout<<ptr1<<endl;
// cout<<++ptr1;

// pointer with integer array
int arr[] = {10,20,30,40}; // arr is contant pointer
//cout<<arr<<endl; // both give base address but it is the fault of cout implmentation

//cout<<&arr<<endl;
//cout<<&arr[0]<<endl; // gives address of first element, base address
// cout<<arr<<"";
for (int i = 0; i < 4; i++)
{
// cout<<i[arr]<<" ";
cout<<*(arr+i)<<" ";
// cout<<arr+i<<"  ";
}
*/
//character array
char ch [50] = "Love";
char *cptr = ch; // or &ch
// cout<<"address of ch "<<&ch <<"\n";
// cout<<"Address stored in cptr "<<cptr; // not working it gives the love not address chutiya implementation of cout....
// cout<<endl<<ch<<""<<endl;

//cout<<*(cptr+2)<<" "; // gives 'v'
// char* cptr1 = &ch[0];
// cout<<*(cptr1+2)<<endl;
// cout<<cptr+2<<" ";
// cout<<endl<<ch+2;

// char *cptr2 = "Babbar"; //some compiler support
// pointer to an array

int arr[] = {1,2,3,4,5};
int *ptr = arr; // point an single element (first)
//int *ptr1 = &arr; // it try to point single int pointer to an array error
int (*ptr2) [5] = &arr; // arrray pointer to array
//cout<<ptr[3]<<""; // it is running
// cout<<(*ptr2)[1]<<""; 
char ch1[] = "Babbar";
char* ptrc1 = ch1;
// cout<<&ch1<<endl;
// cout<<*ptrc1<<endl; // pointing to first element
// cout<<*ch1+1<<"\n";
// char (*cptr2)[5] = &ch; // not possible 
char*cptr1 = &ch1[0];
//Array of pointer
int *arr3[3];
arr3[0] = &arr[0];
arr3[1] = &arr[1];
arr3[2] = &arr[2];
for (int i = 0; i < 3; i++)
{
    // cout<<*arr3[i]<<" ";
}







 

return 0;
}