# include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"Enter the row";
    int n;
    cin>>n;

    for (int row = 0; row < n; row++)
    {
        for (int colo = 0; colo < row+1; colo++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n-row; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}
