#include <iostream>
using namespace std;

class Matrix{
    public:
        int mat[100][100];
        int r,c;
        Matrix(){}
        ~Matrix(){}
        Matrix(int r,int c,int[])
        {
            this->r = r;
            this->c = c;
            int curr = 0;
            for(int i=1 ; i<=r ; i++){
                for(int j=  1 ;j<=c ; j++){
                    this->mat[i][j] = mat[curr++];
                }
            }
        }
        Matrix(Matrix & m)
        {
            Matrix newm1;
            newm1.r = r;
            newm1.c = c;
            for(int i= 1 ; i<=r ; i++){
                for(int j=1; j<=c  ; j++){
                    newm1.mat[i][j] = mat[i][j];
                }
            }
        }
        void getMatrix()
        {
            cout << "enter the number of rows: " ;
            cin >> r;
            cout << "enter the number of columns: ";
            cin >> c;
            for(int i = 1 ; i <= r ; i++){
                for(int j = 1 ; j<= c ; j++){
                    cout << "enter the ( "<< i <<" , "<<j<<" )th entry: ";
                    cin >> mat[i][j];
                }
            }
        }
        Matrix operator + (Matrix & m)
        {
            Matrix newm1;
            newm1.r = r;
            newm1.c = c;
            for(int i=1 ; i<=r ; i++){
                for(int j=1 ; j<=c ; j++){
                    newm1.mat[i][j] = mat[i][j]+m.mat[i][j];
                }
            }
            return newm1;
        }
        Matrix operator -(Matrix & m)
        {
            Matrix newm1;
            newm1.r = r;
            newm1.c = c;
            for(int i=1 ; i<=r ; i++){
                for(int j=1 ; j<=c ; j++){
                    newm1.mat[i][j] = mat[i][j]-m.mat[i][j];
                }
            }
            return newm1;
        }
        void operator - ()
        {
            for(int i = 1 ; i<=r  ; i++){
                for(int j=1 ; j<=c ; j++){
                    mat[i][j] = -mat[i][j];
                }
            }
        }
        Matrix operator*(Matrix & m){
        Matrix newm1;
        newm1.r = this->r;
        newm1.c = m.c;
        for(int i = 1 ; i<= newm1.r ; i++){
            for(int j = 1 ; j<= newm1.c ; j++){
                int sum = 0;
                for(int k = 1 ; k<=this->c ; k++){
                    sum += (this->mat[i][k] * m.mat[k][j]);
                }
                newm1.mat[i][j] = sum;
            }
        }
        return newm1;
    }
    Matrix transpose(){
        Matrix newm1;
        newm1.r = this->c;
        newm1.c = this->r;
        for(int i = 1 ; i <= newm1.r  ; i++){
            for(int j=1 ; j<=newm1.c ; j++){
                newm1.mat[i][j] = this->mat[j][i];
            }
        }
        return newm1;
    }
    // void Matrix operator+=(int a){
    void  operator+=(int a){
        for(int i=1 ; i<=r ; i++){
            for(int j=1 ; j<=c ; j++){
                mat[i][j]+=a;
            }
        }
    }
    void operator-= (int a){
    // void Matrix operator-= (int a){
        for(int i=1 ; i<=r ; i++){
            for(int j=1 ; j<=c ; j++){
                mat[i][j]-=a;
            }
        }
    }
    int operator()(int a , int b){
    //int Matrix operator()(int a , int b){
        return mat[a][b];
    }
    friend ostream & operator << (ostream & out , Matrix & m){
        out << endl;
        for(int i=1 ; i<=m.r ; i++){
            for(int j=1 ; j<=m.c ; j++){
                out << m.mat[i][j]<<" ";
            }
            out << endl;
        }
        return out;
    }
    friend istream & operator >> (istream & in , Matrix & m){
    cout << "enter the number of rows: " ;
    in >> m.r;
    cout << "enter the number of columns: ";
    in >> m.c;
    for(int i = 1 ; i <= m.r ; i++){
        for(int j = 1 ; j<= m.c ; j++){
            cout << "enter the ( "<< i <<" , "<<j<<" )th entry: ";
            in >> m.mat[i][j];
        }
    }
    return in;
};
int main()
{
    Matrix m,n,result;
    cin >> m;
    cin >> n;
    result  = m+n;
    cout <<"Addition is: "<< result;
    result = m-n;
    cout <<"Subtraction is: "<< result;
    -m;
    cout << m;
    result = m*n;
    cout << "Multiplication is: "<<result;
    result = m.transpose();
    cout <<"Transpose is: " <<result;
    m+=3;
    cout << m;
    n+=3;
    cout << n;
    cout << m(1,2)<<endl;
    return 0;
}




































































































/*#include <iostream>
using namespace std;

class Matrix
{
    public:
        int i,j;
        int m,n,s,t,s1;
        int mat1[100][100];
        int mat2[100][100];
        int mul[100][100];
        int transpose1[100][100];
        int transpose2[100][100];
        Matrix(){};
        Matrix(int s,int t)
        {
            mat1[s+1][t+1];
        }
        // Matrix(const Matrix &s1)
        // {
        //     this.s1=s1;
        // }
        ~Matrix(){};
        
        
        void getInput1()
        {
            cout<<"Enter the value of rows"<<endl;
            cin>>m;
            cout<<"Enter the value of column"<<endl;
            cin>>n;
            cout<<"Enter the values of matrix:"<<endl;
            for(int i=0;i<m;i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout<<"mat1["<<i<<"]"<<"["<<j<<"]"<<endl;
                    cin>>mat1[i][j];
                }
                
            }
        }
        void printMatrix1()
        {
            cout<<"Print the Matrix"<<endl;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    
                    cout<<mat1[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void getInput2()
        {
            cout<<"Enter the value of rows"<<endl;
            cin>>s;
            cout<<"Enter the value of column"<<endl;
            cin>>t;
            cout<<"Enter the values of matrix:"<<endl;
            for(int i=0;i<s;i++)
            {
                for (int j = 0; j < t; j++)
                {
                    cout<<"mat2["<<i<<"]"<<"["<<j<<"]"<<endl;
                    cin>>mat2[i][j];
                }
                
            }
        }
        void printMatrix2()
        {
            cout<<"Print the Matrix"<<endl;
            for(int i=0;i<s;i++)
            {
                for(int j=0;j<t;j++)
                {
                    
                    cout<<mat2[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void addTwoMatrix()
        {
            if(m==s&&n==t)
            {
                cout<<"Addition is:"<<endl;
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout<<mat1[i][j]+mat2[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else
                cout<<"Addition is not possible"<<endl;
            
        }
        void subtractTwoMatrix()
        {
            if(m==s&&n==t)
                {
                    cout<<"Subtract is:"<<endl;
                    for (int i = 0; i < m; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cout<<mat1[i][j]-mat2[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                }
                else
                    cout<<"Subtraction is not possible"<<endl;
            
        }
        void mulmatrix()
        {
            cout<<"Multiplication is:"<<endl;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; i < n; j++)
                {
                    for(int k=0;k<m;k++)
                    {
                        mul[i][j]+=mat1[i][k]*mat2[k][j];
                        cout<<mul[i][j]<<" ";
                    }
                }
                
            }
            
        }
        void transposeMatrix()
        {
            
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    transpose1[j][i]=mat1[i][j];
                }
                cout<<endl;
            }
            
            for(int i=0;i<s;i++)
            {
                for(int j=0;j<t;j++)
                {
                    
                    transpose2[j][i]=mat2[i][j];
                }
                cout<<endl;
            }
        }
        void printtransposeMatrix()
        {
            cout<<"Transpose of first matrix is:"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<transpose1[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Transpose of second matrix is:"<<endl;
            for(int i=0;i<t;i++)
            {
                for(int j=0;j<s;j++)
                {
                    
                    cout<<transpose2[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void incrementanddecrementofmatrix()
        {
            cout<<"Decremented first matrix is:"<<endl;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat1[i][j]-=1;
                    cout<<mat1[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Decremented second matrix is:"<<endl;
            for(int i=0;i<s;i++)
            {
                for(int j=0;j<t;j++)
                {
                    mat2[i][j]-=1;
                    cout<<mat2[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Incremented first matrix is:"<<endl;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat1[i][j]+=1;
                    cout<<mat1[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Incremented second matrix is:"<<endl;
            for(int i=0;i<s;i++)
            {
                for(int j=0;j<t;j++)
                {
                    mat2[i][j]+=1;
                    cout<<mat2[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        // void decrementofmatrix()
        // {
        //     // mat1[i][j]=0;
        //     // mat2[i][j]=0;
        //     cout<<"Decremented first matrix is:"<<endl;
        //     for(int i=0;i<m;i++)
        //     {
        //         for(int j=0;j<n;j++)
        //         {
        //             mat1[i][j]-=1;
        //             cout<<mat1[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<"Decremented second matrix is:"<<endl;
        //     for(int i=0;i<s;i++)
        //     {
        //         for(int j=0;j<t;j++)
        //         {
        //             mat2[i][j]-=1;
        //             cout<<mat2[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }
        // void determinantOfMatrix()
        // {
        //     bool flag;
        //     int i,j;
        //     for(int i=0;i<2;i++)
        //     {
        //         for(int j=0;j<2;j++)
        //         {
        //             cout<<mat1[i][j];
        //             cout<<mat2[i][j];
        //         }
                
        //     }
        //     // if(flag==true)
        //     // {
        //         int s;
        //         cout<<"Determinant of First matrix is"<<endl;
        //         s=((mat1[i][i]*mat1[j][j])-(mat1[i][j]*mat1[j][i]));
        //         cout<<s<<endl;
        //     // }
            
        // }

};
int main()
{
    Matrix m;
    m.getInput1();
    m.printMatrix1();
    m.getInput2();
    m.printMatrix2();
    m.addTwoMatrix();
    m.subtractTwoMatrix();
    m.transposeMatrix();
    //m.decrementofmatrix();
    m.incrementanddecrementofmatrix();
    
    //m.mulmatrix();
    
    m.printtransposeMatrix();
    //m.determinantOfMatrix();


    return 0;
}*/