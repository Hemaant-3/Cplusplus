#include <iostream>
using namespace std;
int factorial(int no)
{

    if (no == 1 || no==0)
    {
        return 1;
    }
    else
    {
        return (no * factorial(no - 1));
    }

}
int main(int argc, char const *argv[])
{
    int numb;
    cout << "Enter the number to get factorial \n";
    cin >> numb;
    int fact = factorial(numb);
    cout<<"Factorial of "<<numb<<" is "<<fact;
    return 0;
}
