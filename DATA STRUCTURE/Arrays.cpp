#include <iostream>
using namespace std;
class Matrix
{
    public:
    int rows=0;
    int cols=0;
    int matrix[100][100];
    int fmatrix[100][100];
    Matrix()
    {
        matrix[0][0];
    }
    Matrix(int row, int col)
    {
        rows=row;
        cols=col;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<"Enter the element for ("<<i+1<<","<<j+1<<"):";
                cin>>matrix[i][j];
            }
        }
    }
    Matrix(Matrix& ob)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                ob.matrix[i][j]=matrix[i][j];
            }
        }
    }
    void operator+=(int n)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                matrix[i][j]=matrix[i][j]+n;
            }
        }
        cout<<endl;
    }
    void operator-=(int n)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                matrix[i][j]=matrix[i][j]-n;
            }
        }
        cout<<endl;
    }
    Matrix operator+(Matrix& ob)
    {
        Matrix fin;
        if(rows==ob.rows&&cols==ob.cols)
        {
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    fin.matrix[i][j]=matrix[i][j]+ob.matrix[i][j];
                }
            }
            cout<<endl;
        }
        return fin;
    }
    Matrix operator-(Matrix& ob)
    {
        Matrix fin;
        if(rows==ob.rows&&cols==ob.cols)
        {
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    fin.matrix[i][j]=matrix[i][j]-ob.matrix[i][j];
                }
            }
            cout<<endl;
        }
        return fin;
    }
    void operator-()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                matrix[i][j]=matrix[i][j]-1;
            }
        }
        cout<<endl;
    }
    Matrix operator*(Matrix& ob)
    {
        Matrix fin;
        if (cols==ob.rows)
        {
            cout<<"Product of Two Matrices is:"<<endl;
            for (int i=0;i<rows;i++)
            {
                for (int j=0;j<ob.cols;j++)
                {
                    int sum=0;
                    for (int k=0;k<cols;k++)
                    {
                        sum=sum + matrix[i][k]*ob.matrix[k][j];
                        fin.matrix[i][j]=sum;
                    }
                }
            }
        }
        return fin;
    }
    friend istream& operator>>(istream& is,Matrix& ob)
    {
        for(int i=0;i<ob.rows;i++)
        {
            for(int j=0;j<ob.cols;j++)
            {
                cout<<"Enter the element for ("<<i+1<<","<<j+1<<"):";
                is>>ob.matrix[i][j];
            }
        } 
        return is;
    }
    friend ostream& operator<<(ostream& os, Matrix& ob)
    {
        for(int i=0;i<ob.rows;i++)
        {
            for(int j=0;j<ob.cols;j++)
            {
                os<<ob.matrix[i][j];
                cout<<" ";
            }
            cout<<endl;
        } 
        return os;
    }
    int& operator()(int ro,int co)
    {
        return matrix[ro-1][co-1];
    }
    
};
int main()
{
    Matrix m(2,2);
    //cin>>m;
    cout<<m;
    m+=2;
    cout<<m<<endl;
    m-=1;
    cout<<m<<endl;
    Matrix c(m);
    cout<<m<<endl;
    -m;
    cout<<m<<endl;
    m(1,1)=6;
    cout<<m(1,1)<<endl;
    cout<<m<<endl;

    
    
}
