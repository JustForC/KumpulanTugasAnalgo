#include<iostream>
#include<time.h>
using namespace std;

void MergeSort(int [],int ,int );
void Merge(int [],int,int ,int );

int main()
{
    int n;
    cout<<"Masukan panjang array	:";
    cin>>n;
    int a[n];
    cout<<"Masukan isi array	:";
	clock_t t1,t2;
	t1=clock();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cout<<"Sorting dengan merge sort"<<endl;
    int p=1,r=n;

    MergeSort(a,p,r);

   cout<<"Bentuk terurut	:"<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<"a["<<i<<"]="<<a[i]<<endl;
   }
   t2=clock();
   float diff((float)t2-(float)t1);
   float second=diff/CLOCKS_PER_SEC;
   cout<<second<<" MS"<<endl;
   system("pause");
     return 0;
	 
}

void MergeSort(int a[],int p,int r)
    {
        int q;
        if(p<r)
        {
         q=(p+r)/2;
         MergeSort(a,p,q);
         MergeSort(a,q+1,r);
         Merge(a,p,q,r);
        }
    }

 void Merge(int a[],int p,int q,int r)
    {
        int n1=q-p+1;
        int n2=r-q;
        int L[n1+1];
        int R[n2+1];
        for(int i=1;i<=n1;i++)
        {
            L[i]=a[p+i-1];
        }
        for(int j=1;j<=n2;j++)
        {
            R[j]=a[q+j];
        }
        L[n1+1]=999;
        R[n2+1]=999;
        int i=1, j=1;
        for(int k=p;k<=r;k++)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i=i+1;
            }
            else
            {
                a[k]=R[j];
                j=j+1;
            }
        }
    }