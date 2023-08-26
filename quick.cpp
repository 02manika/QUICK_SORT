#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
      int pivot= arr[s];
      int count=0;
      for (int i=s+1;i<=e;i++)
      {
        if(pivot>=arr[i])
        {
             count++;
        }
      }

      int pivotindex = s+count;

      swap(arr[pivotindex],arr[s]);

      int i=s , j=e;
      while(i<pivotindex && j>pivotindex)
      {
           while(arr[i]<pivot)
           {
              i++;
           }
           while(arr[j]>pivot)
           {
              j--;
           }
           if(i<pivotindex && j>pivotindex)
           {
               swap(arr[i++] , arr[j--]);
           }
      }
      return pivotindex;
}

void quicksort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);

    quicksort(arr,s,p);
    quicksort(arr,p+1,e);
}
int main()
{
    int arr[6]={3,5,1,8,2,4};
    int n =6;

    quicksort(arr,0,5);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}