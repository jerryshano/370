/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw9/challenges/max-heap-1-2/submissions/code/1317692124
 * Title: hw9_1.cpp
 * Abstract: Heap implementation using numerous instructions
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 11/14/19
 */

#include<iostream> 
#include<climits> 
using namespace std;
  
void swap(int *x, int *y); 
  
// A class for Min Heap 
class MinHeap 
{ 
    int *harr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap 
public: 
    // Constructor 
    MinHeap(int capacity); 
  
    // to heapify a subtree with the root at given index 
    void MinHeapify(int ); 
  
    int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
  
    // Returns the minimum key (key at root) from min heap 
    int getMax() { return harr[0]; } 

    void decreaseKey(int i, int new_val);

    void extractMin();
  
    // Deletes a key stored at index i 
    void deleteKey(int i); 
  
    // Inserts a new key 'k' 
    void insertKey(int k); 

    bool comp (int index);

    //print function
    void display();
}; 
  
// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap]; 
} 

void MinHeap::extractMin() 
{ 
    for(int i = 0; i < heap_size-1; i++)
    {
        harr[i] = harr[i+1];
    } 
    heap_size--;
    MinHeapify(0);
} 
 
  
// Inserts a new key 'k' 
void MinHeap::insertKey(int k) 
{ 
    // First insert the new key at the end 
    heap_size++; 
    int i = heap_size - 1; 
    harr[i] = k; 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && harr[parent(i)] < harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 

void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int largest = i; 
    if (l < heap_size && harr[l] > harr[i]) 
        largest = l; 
    if (r < heap_size && harr[r] > harr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(&harr[i], &harr[largest]); 
        MinHeapify(largest); 
    } 
}

void MinHeap::display()
{
    for(int i = 0; i <  heap_size; i++)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

bool MinHeap::comp (int index)
{
    if (heap_size == 0) 
        return (true); 
  
    // If index assigned to current node is more than 
    // number of nodes in tree, then tree is not complete 
    if ((2)%(heap_size-1) <= 1) 
        return false;
    else 
    return true;
}

void MinHeap::deleteKey(int i) 
{ 
    for(int j = 0; j < heap_size; j++)
    {
        if(harr[j] == i)
        {
            for(int z = j; z < heap_size-1; z++)
            {
                harr[z] = harr[z+1];
            }
            heap_size--;
        }
    } 
    MinHeapify(0);
}



void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int main() {

  int n;
  cin >> n;
  MinHeap h(n);
  int num;
  for(int i = 0; i < n; i++)
  {
      cin >> num;
      h.insertKey(num);
  }
  //
  int options;
  cin >> options;
  string ans[options];
  for(int i = 0; i < options; i++)
  {
      cin >> ans[i];
      if(ans[i] == "insert")
      {
          cin >> num;
          h.insertKey(num);
      }
      if(ans[i] == "delete")
      {
          cin >> num;
          h.deleteKey(num);
      }
  }
if (h.comp(0) == true) 
        printf("This is a heap.\n"); 
else
        printf("This is NOT a Heap.\n");

  for(int i = 0; i < options; i++)
  {
     if(ans[i] == "displayMax")
     cout << h.getMax() << endl;

     if(ans[i] == "display")
     h.display();

     if(ans[i] == "deleteMax")
     h.extractMin();
  }
  return 0;
}