#include <iostream>
using namespace std;
// half pyramid
void halfpyr(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// inverted half pyramid

void invertedPy(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
// inverted half numeric pyramid
void numericHalfpy(int n){
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
// inverted halfnumeric pyramid
void numericinv(int n){
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
// full pyramid

void fullpy(int n){
    for (int i = 0; i < n; i++)
    {
        //print space
        for (int j = 0; j <n-i; j++)
        {
            cout<<" ";
        }
        // print *
        for (int j = 0; j <i+1; j++)
        {
           cout<<"* ";
        }
        cout<<endl;
    }
    
}

// inverted full pyrmaid
void invefupy(int n){
    for (int  i = 0; i < n; i++)
    {
        // space print
        for (int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        // print *
        for (int j = 0; j < n-i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
}
// Hollow pyramid
void hollowpy(int n){
    for (int i = 0; i < n; i++)
    {
        // print space
        for (int j = 0; j < n-i; j++)
        {
            cout<<" ";
        }
        // print * and space
        for (int j = 0; j <= i+1; j++)
        {
            if (j==0 || j== i)
            {
                cout<<"* ";
            }
            else{
            cout<<"  "; //print two space coz we consider two character '*_'
            }
        }
        cout<<endl;
        
    }
    
}
// inverted hollow pryramid

void invHollpy(int n){

    for (int i = 0; i < n; i++)
    {
        // print space
        for (int j = 0; j <= i; j++)
        {
            cout<<" ";
        }

        // print star and space
        int lastcol = n-i;
        for (int j = 0; j < lastcol; j++)
        {
            
            if (j==0 || j== lastcol-1)
            {
                cout<<"* ";
            }
            else{
            cout<<"  ";
            }
        }
        
        cout<<endl;
    }
    
}
 // full hollow diamond
 void fulldia(int n){

    for (int row = 0; row < n; row++)
    {
        // upper part
        // inverted half pyramid

        for (int col = 0; col < n-row; col++)
        {
            cout<<"* ";
        }
        // cout<<endl;

        for (int col = 0; col < row+1; col++)
        {
               if (col==0)
        {
            cout<<"";
        }
        else
        cout<<"  ";
        }
        for (int col = 0; col < row; col++)
        {
            cout<<"  ";
        }
        for (int col = 0; col < n-row; col++)
        {
            cout<<"* ";
        }
        
        cout<<endl;

    }

    // lower part
    for (int row = 0; row < n; row++)
    {
         for (int col = 0; col < row+1; col++)
    {
        cout<<"* ";
    }

    for (int col = 0; col <= n-row-1; col++)
    {
        if (col==0)
        {
            cout<<"";
        }
        else
        cout<<"  ";
    }


    for (int col = 0; col <= n-row-2; col++)
    {
     
        cout<<"  ";
    }

    for (int col = 0; col <= row; col++)
    {
        cout<<"* ";
    }
    
    
    cout<<endl;
    }
    
   
    

 }
// inverted diamond

void invdia(int n){
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= n-row-2; col++)
        {
            cout<<"  ";
        }
        for (int col = 0; col <= row; col++)
        {
            if (row==0)
            {
                cout<<" *";
            }
            else
            cout<<"* ";
        }
        for (int col = 0; col <=row; col++)
        {
         if (row==0)
         {
            cout<<"";
         }
         else
            cout<<"* ";
        }
        
       

        cout<<endl;
    }
     // lower


    for (int row = 1; row < n; row++)
    {
       for (int col = 1; col <= row+1; col++)
       {
        if (col==1)
        {
            cout<<"";
        }
        else
        
        cout<<"  ";
       }

       for (int col = 0; col < n-row; col++)
       {
           if (row==n-1)
        {
            cout<<" *";
        }
        else
        cout<<"* ";
       }
       for (int col = 0; col < n-row; col++)
       {
        if (row==n-1)
        {
            cout<<"";
                }
        
     else
        cout<<"* ";
       }
       
       cout<<endl;
        
    }

}

void inverhollow(int n){
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n-row; col++)
        {
            if (row==0||row==n-1)
            {
                cout<<"* ";
            }
            else{
                if (col==0 || col==n-row-1)
                {
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
                
            }
        }
        cout<<endl;
        
    }
    
}

void numeric(int n){
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            if (row==n-1)
            {
                cout<<col+1<<" ";
            }
            else{
            if (col==0 || col==row)
            {
                cout<<row+1<<" ";
            }else{
                cout<<"  ";
            }
            }
        }
        cout<<endl;
        
    }
   
    
}

void alphabet(int n){
    for (int row = 0; row < n; row++)
    {
        char ch;
        for (int col = 0; col < row+1; col++)
        {
            int num = col+1;
            ch = num+'A'-1;
            cout<<ch<<" ";
        }
     // reverse loop
     for (char col = ch; col >= 'A'; col-- )
          {
                cout<<col<<" ";
     }
     
     
        cout<<endl;
    }
    
}

void hollowPalindrome(int n){
for (int row = 0; row < n; row++)
{
    int count=0;
    for (int j = 1; j <= row; j++)
    {
        cout<<j<<" ";
        count++;
    }
    for (int col = count-1; col >=0; col--)
    {
        if (col==0)
        {
            cout<<"";
        }
        else{
       cout<<col<<" ";
        }
    }
    
    cout<<endl;
    
}

}

void numstar(int n){
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<"* ";
        }

        for (int col = 0; col <= 2*row+1; col++)
        {
            if (col%2==0)
            {
                cout<<"* ";
            }
            else
            {
                cout<<row+1 <<" ";
            }
            
            
        }
        for (int col = 0; col < n-row; col++)
        {
            cout<<"* ";
        }
        
        cout<<endl;
        
    }
    
}

void butterfly(int n){

    for (int row = 0; row < n; row++)
    {
        // this is upper left star
        for (int col = 0; col <= row; col++)
        {
            cout<<"* ";
        }

        // this is upper mid upside down blank triangle
        for (int col = 0; col <= n-row-1; col++)
        {
            cout<<"  ";
        }

        //this is half upper mid upside blank triangle
        for (int col1 = n-row-1; col1 > 0; col1--)
        {
           cout<<"  ";
        }
        
        for (int col = 0; col <=row; col++)
        {
            cout<<"* ";
        }
        
        
        cout<<endl;
        
    }
    // lower part
    for (int row = 0; row < n; row++)
    {
        // lower half triangle left
        for (int col = n-row; col >0; col--)
        {
            cout<<"* ";
        }
        // lower part space triangle
        for (int i = 0; i <= row; i++)
        {
            cout<<"  ";
        }
        // half part of space triangle
        for (int col = 1; col < row+1; col++)
        {
            cout<<"  ";
        }

        // right side triangle
        for (int col = 0; col <n-row; col++)
        {
            cout<<"* ";
        }
        
        
        cout<<endl;
        
    }
    
    
}


int main()
{
    int row;
    cout << "enter the row";
    cin >> row;

    // halfpyr(row);
    // invertedPy(row);
    // numericHalfpy(row);
    // numericinv(row);
    // fullpy(row);
    // invefupy(row);
    // hollowpy(row);

    // invHollpy(row);
    //  fulldia(row);
    // invdia(row);
    // inverhollow(row);
    // numeric(row);
    // alphabet(row);

    // hollowPalindrome(row);
    // numstar(row);

    int &n = row;
    // butterfly(n);

    return 0;
}