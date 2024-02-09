#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        
        int arr[100];
        int size;
        
        heap(){
            arr[0]=-1;
            size=0;
        }
        
        void insert(int x){
            size++;
            int i=size;
            arr[size]= x;
            
            while(i>1){
                int parent= i/2;
                if(arr[parent]<arr[i]){
                    swap(arr[parent],arr[i]);
                    i= parent;
                }
                else
                    return;
            }
        }

        void deleteFromHeap(){
            if(size==0){
                cout<<"Nothing to return";
                return;
            }
            arr[1]= arr[size];
            size--;
            int i=1;
            while(i<=size){
                int left= 2*i;
                int right= 2*i;
                if(arr[left]>arr[i] && i<size){
                    swap(arr[left], arr[i]);
                    i=left;
                }
                else if(arr[right]>arr[i] && i<size){
                    swap(arr[right], arr[i]);
                    i=left;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
void heapify(int arr[], int n, int i){
    int l= 2*i;
    int r=2*i+1;
    int largest=i;

    if(l<=n && arr[largest]<arr[l])
        largest=l;

    if(r<=n && arr[largest]<arr[r])
        largest=r;

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }    
}

void heapSort(int arr[], int n){

    int t =n;
    while(t>1){
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
    }
}

int main(){
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[6]= {-1,34,56,12,98,71};
    int n=5;
    for(int i=n/2;i>0;i--)
        heapify(arr,n,i);

    heapSort(arr,n);

    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"Priority Queue here: "<<endl;

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Top: "<<pq.top()<<endl;
    
    return 0;


}