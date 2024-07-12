
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
void reverse(queue<int> &q){
stack<int> st;
while(!q.empty()){
    int frontElemt= q.front();
    q.pop();
    st.push(frontElemt);
}


// empty stack
while(!st.empty()){
    int elemt = st.top();
    st.pop();
    q.push(elemt);
}


}

void reverseRec(queue<int> &q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();

    reverseRec(q);

    q.push(temp);
}

void reverseK(queue<int> &q, int k){


    stack<int> s;
    int n = q.size();
    if(k>n || k==0){
        return;
    }
    // pushing firt k element in stack 
    for(int i =0; i<k; i++){
        int temp = q.front();
        q.pop();
        s.push(temp);
    }
    // pushing first k element again in queue
    for( int i = 0; i<k; i++){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // now pushing firt n-k element in queue agian
    for(int i = 0; i<n-k;i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}

void interleaved(queue<int> &first){
    queue<int>second;
int size = first.size();
    //push first half to second queue

    for(int i = 0; i<size/2; i++){
        int temp =first.front();
        first.pop();

        second.push(temp);


            }

            // merge both the halves
            // into orginal  queue.
            for(int i = 0; i<size/2; i++){
                int temp = second.front();
                second.pop();

                first.push(temp);

                temp = first.front();
                first.pop();
                first.push(temp);
            }
}

void printFirstNeg(int arr[],int n, int k){
    deque<int> dq;

    // process first k element
    for (int i = 0; i < k; i++)
    {
       int element = arr[i];
       if(element < 0){
        dq.push_back(i);
       }
    }
    // proccess remaning windows
    // Removal and addition
    for(int i = k; i<n;i++){
        // aage badhne se phle purani window ka ans nikal lo
           if(dq.empty()){
    cout<<"0"<<endl;
    } else{
        cout<<arr[dq.front()]<<" ";
    }
      

        //removal -> jo out of range hai, usko remove kr do
        if(i - dq.front()>=k){
            dq.pop_front();
        }
        //addition
        if(arr[i]<0){
            dq.push_back(i);
        }
    }
    //last wale ka window print kr len
    if(dq.empty()){
    cout<<"0"<<endl;
    } else{
        cout<<arr[dq.front()]<<" ";
    }
}

void findNonRepeatingchar(){
    /// find non repeating character
string str = "ababc";
queue<char> q;
int freq[26] = {0};

for (int i = 0; i < str.length(); i++)
{
    char ch = str[i];
    freq[ch-'a']++;
    q.push(ch);


    // ans find
    while (!q.empty()){
        char frontchar = q.front();
        if(freq[frontchar-'a']>1){
            q.pop();
        } else{
            // ==1 wala case unique char
            cout<<frontchar<<"->";
            break;
        }
    }
    if(q.empty()){
        // koi ans nhi mila
        cout<<"#"<<"->";
    }
     
}
}

int main()
{
// queue<int> q;

// q.push(10);
// q.push(20);
// q.push(30);
// q.push(40);
// q.push(50);
// q.push(60);

// interleaved(q);
// int arr[] = {2,-5,4,-1,-2,0,5};
// int size = 7; 
// int k= 3;
// printFirstNeg(arr,size,k);
// // reverseRec(q);
//reverseK(q,4);
// while (!q.empty())
// {
//  cout<<q.front()<<" ";
// q.pop();
// }


findNonRepeatingchar();

return 0;
}