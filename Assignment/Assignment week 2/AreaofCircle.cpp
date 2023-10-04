#include <iostream>
using namespace std;
#include<math.h>

void areaOfCircle(){
cout<<"Enter the radius: ";
float radius;
cin>>radius;

float area = (radius*radius)*M_PI;
cout<<area<<endl;
// cout<<M_PI;

}

void factorial(int n){
    int fact = 1;
for (int i = 1; i <= n; i++)
{
   fact *= i;
}
cout<<"The factorial of "<<n<<" is: "<<fact;
}

// All primes number form 1 to N
//1. check the number is prime or not

bool CheckPrime(int n){
    // int i = 2;
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
          
    }
    return true;
  
    
}

//2. Printing the prime numbers.
// 1 is not a prime number.
void PrintPrime(int n){
    for (int i = 2; i <= n; i++)
    {
        bool prime = CheckPrime(i);
        if(prime){
            cout<<i<<" ";
        }
    }
    
}

void printAllDigit(int n){
    int a[10];
    int i = 0;
    while (n!=0)
    {
        a[i++] = n%10;
        n /=10;
        
    }
   
    for (int j = i-1; j >= 0; j--)
    {
        cout<<a[j]<<" ";
        i--;
    }
    
}

// Decimal to Binary conversion

void DecToBin(int n){
    int i = 0;
    int ans = 0;
    while (n>0)
    {
        int bit = n%2;
        ans = bit*pow(10,i++)+ans;
       n = n/2;
    }
    printf("%d", ans);
    
}

void KMtoMiles(int n){
 cout<<"The miles is: "<<n*0.6213;
}
void countAllsetbit(int n){
int count=0;
int count1=0;
while (n>0)
{
    int bit = n%2;
    if (bit==1)
    {
        count++;
    }
    if (bit==0)
    {
        count1++;
    }
    
    n /=2;
}
cout<<"The number of set bit is: "<<count;
cout<<"\nThe number of off bit is: "<<count1;

}

// NO. is even or odd using bit wise
// as we know lsb bit is 1 then odd and 0 it is even.
void CheckEven(int n){
    if ((n&1)==0)
    {
        printf("%d is Even number",n);
    }
    else
        printf("%d is Odd number",n);
    
}
using namespace std;
int main()
{
// areaOfCircle();
// factorial(5); 

// PrintPrime(50);
// printAllDigit(3021);
// DecToBin(10);
// KMtoMiles(10);
// countAllsetbit(220);
CheckEven(1);
return 0;
}