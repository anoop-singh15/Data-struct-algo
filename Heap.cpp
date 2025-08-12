#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        size++;
        arr[size] = val;

        int i = size;
        int rootInd = i / 2;
        while (i > 1 && arr[i] > arr[rootInd])
        {
            swap(arr[i], arr[rootInd]);
            i = rootInd;
            rootInd = i / 2;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteHeap()
    {
        if(size==0)
        {
            cout<<"Heap Empty"<<endl;
            return;
        }
        swap(arr[1],arr[size]);
        size--;

        int i=1;
        while(i<size)
        {
            int rightInd=2*i+1;
            int leftInd=2*i;
            if(leftInd<=size && arr[i]<arr[leftInd])
            {
                swap(arr[i],arr[leftInd]);
                i=leftInd;
            }
            else if(rightInd<=size && arr[i]<arr[rightInd])
            {
                swap(arr[i],arr[rightInd]);
                i=rightInd;
            }
            else 
            {
                return;
            }
        }

    }
};

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<=n && arr[largest]<arr[l])
    {
        largest=l;
    }
    if(r<=n && arr[largest]<arr[r])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

// For min heap
void heapifyMin(int arr[],int n,int i)
{
    int smallest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<=n && arr[smallest]>arr[l])
    {
        smallest=l;
    }
    if(r<=n && arr[smallest]>arr[r])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        heapifyMin(arr,n,smallest);
    }
}

int main()
{
    heap h;

    // insert and delete TC: O(logn)

    // h.print();
    // h.insert(9);
    // h.insert(16);
    // h.insert(2);
    // h.insert(17);
    // h.insert(20);
    // h.print();


    // h.deleteHeap();

    // h.print();


    // Heapify O(logn)
    int arr[6]={-1,54,53,55,52,50};
    int n=5;

    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }

    cout<<"Heapified array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
        


    // Heap Sort O(nlogn)

    int size=n;
    
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }

     for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }




    return 0;
}