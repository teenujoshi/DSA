#include <iostream>
#include <stdlib.h>
using namespace std;


int InsertionSort(int size) 
{ 
    int array[size];

    for(int i=0; i<size; i++)
        array[i] = rand();

    int count=0;
    int j, key; 
    for (int i = 1; i < size; i++)
    { 
        key = array[i]; 
        j = i - 1; 
        count++;  
        
        while (j >= 0 && array[j] > key)
        { 
            array[j + 1] = array[j]; 
            j = j - 1; 
            count++;
        } 
        array[j + 1] = key; 
    } 

    cout<<"The Insertion sorted array generated from random elements are: \n";
    for(int i=0; i<size; i++ )
        cout<<array[i]<<"\n";
        return count;
} 
int main() 
{
    int array[100];
    for(int i=0;i<20;i++)
    {
        array[i]=InsertionSort(i);
        cout<<i<<"    "<<array[i]<<endl;
    }

  
  InsertionSort(5);

  return 0;
}






































































// #include <bits/stdc++.h>
// using namespace std;
  
// // Function to sort an array using 
// // insertion sort
// int insertionSort(int arr[], int n) 
// { 
//     int key,j; 
//     for (int i = 1; i < n; i++)
//     { 
//         key = arr[i]; 
//         j = i - 1; 
  
//         // Move elements of arr[0..i-1],  
//         // that are greater than key, to one 
//         // position ahead of their 
//         // current position
//         while (j >= 0 && arr[j] > key)
//         { 
//             arr[j + 1] = arr[j]; 
//             j = j - 1; 
//         } 
//         arr[j + 1] = key; 
//     }
//     return insertionSort(arr, n); 
// } 
  
// // A utility function to print an array 
// // of size n 
// void printArray(int arr[], int n) 
// { 
     
//      for (int i = 0; i < n; i++) 
//      arr[i]=rand();
//     //    cout << arr[i] << " "; 
//     // cout << endl;
// } 
  
// // Driver code
// int main() 
// { 
//     int arr[100];
//     //int arr[] = { 12, 11, 13, 5, 6 }; 
//     //int N = sizeof(arr) / sizeof(arr[0]); 
  
//     //insertionSort(arr, N); 
//     //printArray(arr, N); 
  
//     return 0; 
// } 























































// #include <iostream>
// using namespace std;

// int insertionsort(int *arr,int n)
// {
//    // int arr[n];
//     for(int i=0;i<n;i++)
//         arr[i]=rand();
//     int count=0;
//     //int i=1;
//     // ans++;
//     int j,temp;
//     for(int i=0;i<n;i++)
//         arr[i]=rand();
//     for(int i=0;i<n-1;i++)
//     {
//         //ans++
//         j=i+1;
//         // cout<<endl;
//         // cout<<i+1<<" pass"<<endl; 
//         while (arr[j]<arr[j-1]&&j>0)
//         {
//             temp=arr[j];
//             arr[j]=arr[j-1];
//             arr[j-1]=temp;
//             count++;
//             j--;
//         }
//         count++;
//     }
//     // cout<<"Sorted array is:" <<endl;
//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<arr[j]<<"      "<<endl;
//     // }
   
        
//     return count;
//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<arr[i]<<" ";
//     // }
// }
// int main()
// {
    
//    int arr[100];
 
//     for(int i=0;i<15;i++)
//     {
//         cout<<i<<"    "<<arr[i]<<endl;
         
//     }

// cout<<insertionsort(arr,10);
    
    
     
//     return 0;
    
// }
// for(int k=0;k<n-i-1;k++)
        // {
        //     //ans++;
        //     if(arr[j]>arr[i])
        //     {
        //         i=i+1;
        //         swap(arr[j],arr[j+1]);
        //         count++;
        //     }
        // }
    
// int n;
       
    // cout<<"Enter the array size"<<endl;
    // cin>>n;
    // cout<<"Enter the elements of array"<<endl;

// cout<<"Array elements are: ";
// for(int i=0;i<n;i++)
    // {
        
    //     cout<<arr[i]<<" ";
    //     //cout<<endl;
    // }
    
    // cout<<endl;
    //  cout<<"Sorted array is:";
    //  insertionsort(arr,n);



// #include<iostream>
// using namespace std;
// //void display(int array[], int size) {
// //    for(int i = 0; i<size; i++)
// //    array[i]=rand();
// //       cout << array[i] << " ";
// //    cout << endl;
// //}
// int insertionSort(int *array, int size) {
//    int key, j;
//    int count=0;
//    for(int i = 0; i<size; i++)
//    array[i]=rand();
//    for(int i = 1; i<size; i++) {
//       key = array[i];//take value
//       j = i;
//       while(j > 0 && array[j-1]>key) {
//          array[j] = array[j-1];
//          j--;
//          count++;
//       }
//       array[j] = key;   //insert in right place
//    }
//    return count;
// }
// int main() {
//     int n;
// //    cout << "Enter the number of elements: ";
// //    cin >> n;
//     int arr[n];    //create an array with given number of elements
// //    cout << "Enter elements:" << endl;
// //    for(int i = 0; i<n; i++) {
// //       cin >> arr[i];
// //    }
//    //cout << "Array before Sorting: ";
//    //display(arr, n);
//    insertionSort(arr, n);
//    //cout << "Array after Sorting: ";
//   // display(arr, n);
// }






// #include<iostream>
// using namespace std;
// void display(int *array, int size) {
//    for(int i = 0; i<size; i++)
//       cout << array[i] << " ";
//    cout << endl;
// }
// void insertionSort(int *array, int size) {
//    int key, j;
//    for(int i = 1; i<size; i++) {
//       key = array[i];//take value
//       j = i;
//       while(j > 0 && array[j-1]>key) {
//          array[j] = array[j-1];
//          j--;
//       }
//       array[j] = key;   //insert in right place
//    }
// }
// int main() {
//    int n;
//    cout << "Enter the number of elements: ";
//    cin >> n;
//    int arr[n];    //create an array with given number of elements
//    cout << "Enter elements:" << endl;
//    for(int i = 0; i<n; i++) {
//       cin >> arr[i];
//    }
//    cout << "Array before Sorting: ";
//    display(arr, n);
//    insertionSort(arr, n);
//    cout << "Array after Sorting: ";
//    display(arr, n);
// }