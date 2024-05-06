#include<iostream>
#include<vector>
using namespace std;
void checkEvenOdd(int n){
    if(n&1 == 1){
        cout<<"ODD NO."<<endl;
    } else{
        cout<<"EVEN NO."<<endl;
    }
}
void getIthBit(int n, int i){
    int mask = (1<<i);
    int ans = n & mask;

    if(ans==0){
        cout<<"bit: 0";
    } else{
        cout<<"bit: 1";
    }
}

void setIthbit(int n, int i){
    int mask = (1<<i) ;
    n = n | mask;
    cout<<"Updated number: "<<n<<endl;
    
    }

void clearithBit(int &n, int i){
    int mask = ~(1<<i);
    n = n & mask;
    // cout<<"updated numb: "<<n;
}

void updateIthBit(int n, int i, int target){
    // clear ith bit. passed by refernce coz changes in n should be reflected here

    clearithBit(n,i);
    // create mask 
    int mask = (target<<i);
    // update n
    n = n | mask;

    cout<<endl<<"updated number: "<<n<<endl;
}

void clearlastbit(int n, int i){
    int mask = (-1<<i);
     n = n & mask;
     cout<<"updated No. : "<<n<< endl;
}

bool checkpow2(int n){
    //count set bit
     int count = 0;
     while (n!=0)
     {
        int lastBit = n & 1;
        if(lastBit){
            count++;
        }
         n = n>>1;
     }
     if(count==1){
        return true;
     } else {
        return false;
     }
}
 bool fastcheckerpow2(int n){
    if((n & (n-1))==0){
        return true;
    } else {
        return false;
    }
 }
 int fastcountsetbit(int n){
    int count = 0;
    while(n!=0){
        count ++;
        n = (n & (n-1));
    }
    return count;
 }
 void clearbitrange(int n, int i, int j){
    int a = (-1<<(i+1));// here we do mistake 
    int b = ~(-1<<j);

    int mask = a|b;

    n = n & mask;

    cout<<"updated mask: "<<n;
 }
 // subsequence
 void subsequence(string str){
    int n = str.length();
    vector<string> ans;

    for(int num = 0; num<(1<<n); num++){
                     /*2 pow n*/
     //  number is ready
     // use num, to create subsequence
     /// num -> set bit -> index -> char -> inc
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            // i -> represent index
            char ch = str[i];
            // agar i index pr num ke ander set bit present hai to character ko include krenge
            int mask = (1<<i);
            if(num & mask){
                temp.push_back(ch);
            }
        }
        ans.push_back(temp);
        
    }

    cout<<"printing subsequence: "<<endl;
    for(auto i: ans){
        cout<<i<<endl;
    }
 }
int main()
{
// int n = 1023;
// int i = 8;
// int j = 1;

// clearbitrange(n, i, j);

string str = "abc";
subsequence(str);

// int m = fastcountsetbit(n);
// cout<<m<<endl;
// cout<<checkpow2(n)<<endl ;
// cout<<fastcheckerpow2(n)<<endl ;
// int i = 2;

// checkEvenOdd(n);
// getIthBit(n, i);
// clearlastbit(n, i);
// setIthbit(n,i);
// clearithBit(n,i);
// int target = 0;
// updateIthBit(n,i,target); 

return 0;
}