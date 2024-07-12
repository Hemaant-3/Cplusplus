#include <iostream>
# include<cmath>
using namespace std;

float simpleInt(int prin,float intrest,float time){
    float sum;
sum = (prin*time*intrest)/100;
return sum;
}

float CompInterst(int prin, float intrest,float time){
float sum, amt;
sum = prin*pow((1+(intrest/100)),time);
amt = sum-prin;
return amt;
}

int main(){
int prin, intrest, time;
cout<<"Enter the principal amount"<<endl;
cin>>prin;
cout<<"Enter the interest rate"<<endl;
cin>>intrest;
cout<<"Enter the time in years"<<endl;
cin>>time;
// int myamt = simpleInt(prin,intrest,time);
// cout<<myamt;

float amt = CompInterst(prin,intrest,time);
cout<<amt<<" Rupees";
    return 0;
}