#include <iostream>
using namespace std;

int bubblesort(int arr[],int n)
{
 
    for(int i=0;i<n;i++)
        arr[i]=rand();
    int ans=0; 
    for (int i = 0; i < n-1; i++)
    {
        ans++;
        for(int j=0;j<n-i-1;j++)
        {
            ans++;
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                ans++;
            }
            
        }
       
        
    }
   
    cout<<"Sorted array is:" <<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"      "<<endl;
    }
   
       
        return ans;
}
int main()
{
    
    int array[100];
    for(int i=0;i<20;i++)
    {
        array[i]=bubblesort(array,i);
        cout<<i<<"    "<<array[i]<<endl;
    }
    

     
        return 0;
    
}










/*
//int n=0;
       
    // cout<<"Enter the array size"<<endl;
    // cin>>n;
    // int arr[n];
 
    // for(int i=0;i<n;i++)
    //     arr[i]=rand();

    //cout<<"Array elements are: ";
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
        
    
    // cout<<"Array elements are: ";
    // for(int j=0;j<n;j++)
    //     cout<<arr[j]<<" ";
     
    //cout<<endl;
    //int arraysize=2;
*/