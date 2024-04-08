#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;
    Heap(int capacity)
    {
        // curr  num of element in heap
        this->size = 0;
        this->capacity = capacity;
        this->arr = new int[capacity];
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "heap overflow" << endl;
            return;
        }
        // size increase

        size++;
        int index = size;
        arr[index] = val;

        // take the value to its current position
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break; // no updated needed inmax heap
            }
        }
    }
    void print()
    {
        cout << "printing heap: " << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    int deletee()
    {
        int ans = arr[1];

        // replacement
        arr[1] = arr[size];

        // last element ko delete krke uski original position pr replace kr se
        size--;
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            // find out which one is largest
            int largestKaIndex = index;
            // compare left child
            if (left <= size && arr[largestKaIndex] < arr[left])
            {
                largestKaIndex = left;
            }
            else if (right <= size && arr[largestKaIndex] < arr[right])
            {
                largestKaIndex = right;
            }
            // no change
            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return ans;
    }
};

void heapify(int *arr,int n,int index){
    int leftIndex = 2*index;
    int rightIndex = 2* index +1;
    int largestIndex = index;

    //teno me se max lekar aao
    if(leftIndex<=n && arr[leftIndex]>arr[largestIndex]){
        largestIndex = leftIndex;
    }
    //mistake else if.. nhi lagana hai else lagana hai////////
    /*
    else if me 3no me se koi 2 chek krega
    */
     if(rightIndex<=n && arr[rightIndex]>arr[largestIndex]){
        largestIndex = rightIndex;
    }
    // after two condn largestIndex pointing towards max element among 3
    if(index!=largestIndex){
        swap(arr[index],arr[largestIndex]);
        //update index
        index = largestIndex;
        // ab recursion sambhal lega
        heapify(arr,n,index);
    }
}

void buildHeap(int arr[], int n){
    for (int index= n/2; index >0; index--)
    {
        /* code */
        heapify(arr,n,index);
    }
    
}

void heapsort(int arr[], int n){
    while (n!=1)
    {
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
    
}
int main()
{
    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);
    // h.print();
    // cout<<endl<<h.deletee();
    // h.print();

    int arr[] = {-1,5,10,15,20,25,12}; // 1 based indexing
    int n = 6;
    buildHeap(arr,6);

    cout<<"Printing heap"<<endl;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;

   

    return 0;
}