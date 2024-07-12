#include <iostream>
using namespace std;
// program for hollow rectangle
int main(int argc, char const *argv[])
{
    int row;
    int colu;
    cout << "Enter the row";
    cin >> row;
    cout << "Enter colmn";
    cin >> colu;
    for (int rows = 0; rows < row; rows++)
    {
        for (int col = 0; col < colu; col++)
        {
            if(rows == 0 || rows == row-1){
                cout<<"*"<<" ";
            } 
            else
            {
                if (col==0 || col == colu-1)
                {
                    cout<<"*"<<" ";
                } 
                else
                {
                    cout<<"  "; // two space need to print(I print only one spcae)
                }
                
            }
         }
        cout<< endl;
    }
    
   
    return 0;
}
