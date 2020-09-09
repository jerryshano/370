/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/max-heap-1-2/submissions/code/1323139362
 * Title: hw9_1
 * Abstract: displays the alphabetical order of
 * characters for an alien language.
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 26APR20
 */

#include <iostream>
#include <vector>

using namespace std;

class Heap{

public:
    Heap(){};

    bool insert(int item);
    int displayMax() const;
    int deleteMax();
    void heapSort();
    void display();
    void deleteNode(int remove);
    void update(int index, int item);

private:

    //represent the data structure with an array
    int heap[1000];
    //track the size (number of items in the heap) its the counter
    int heapSize = 0;

    int capacity=1000;

    // consider the last item in the heap
    // and check if swap needed
    /// int i or int index ?
    bool fixUp(int i);
    // given a heap item, check below it and see if
    // heap rules are violated
    void fixDown(int i);

};

void Heap::update(int index, int item) {
    if (index > 0 && index <= heapSize){
        heap[index] = item;
        fixDown(1);
        // fixUp(heapSize);
    }
}

bool Heap::insert(int item) {
    // store the value with the given index into item
    heap[heapSize + 1] = item;
    ++heapSize;

    // we insert the item to the last position of the array.
    // heap rules may be violated so we may need to fix it
    return fixUp(heapSize);
}

int Heap::deleteMax() {

    int max = displayMax();

    swap(heap[1], heap[heapSize]);
    --heapSize;

    fixDown(1);

    return max;
}

void Heap::deleteNode(int remove){

    for (int i = 1; i <= heapSize; ++i){
        if (heap[i] == remove){
            swap(heap[i], heap[heapSize]);
            --heapSize;
            fixDown(i);
            return;
        }
    }
}

void Heap::display()
{
    for (int i = 1; i <= heapSize; ++i)
        cout << heap[i] << " ";
    cout << "\n";
}

void Heap::fixDown(int index) {

    int leftChild = 2*index;
    int rightChild = 2*index+1;
    //parent node is always bigger, max heap
    int largestIndex = index;
    // if the left child is bigger than parent,
    // left child is largest
    if(leftChild <= heapSize && heap[leftChild] > heap[index]){
        largestIndex = leftChild;
    }
    // if the right child is greater than the left child,
    // largest is the right child
    if (rightChild <= heapSize && heap[rightChild] > heap[largestIndex]){
        largestIndex = rightChild;
    }
    // we do not swap items with themselves
    if (index!=largestIndex){
        swap(heap[index], heap[largestIndex]);
        fixDown(index);
    }
}

bool Heap::fixUp(int index) {

    bool check = false;
    // operation to find parent index
    int parentIndex = (index)/2;

    //swap if !P>=C (heap property)
    if (index > 1 && heap[index] > heap[parentIndex]){
        swap(heap[index], heap[parentIndex]);
        check = true;
        fixUp(parentIndex);
    }
    return check;
}


// peek operation for a max heap
int Heap::displayMax() const {
    if (heapSize==0){
        throw length_error("heap is empty");
    }
    return heap[1];
}

void Heap::heapSort() {
    int size = heapSize;

    for (int i = 0; i < size; ++i) {
        int max = deleteMax();
        cout << max << " ";
    }
    cout << "\n";
}

int main(){

    Heap heap;

    int numberOfNodes, nodeNumbers, numberOfCommands;
    int temp, temp1, temp2;

    cin>>numberOfNodes;

    string commands;

    bool isHeap = true;
    for (int i = 0; i < numberOfNodes; ++i) {

        cin >> nodeNumbers;

        if(heap.insert(nodeNumbers)){
            isHeap = false;
        }
    }

    if (isHeap == false){
        cout << "This is NOT a heap." << endl;
    }
    else {
        cout << "This is a heap." << endl;
    }

    cin >> numberOfCommands;


    for (int j = 0; j < numberOfCommands; ++j) {

        cin >> commands;

        if (commands == "displayMax") {
            cout << heap.displayMax() << endl;
        }
        else if (commands == "deleteMax") {
            heap.deleteMax();
        }
        else if (commands == "update") {
            cin >> temp1 >> temp2;
            heap.update(temp1, temp2);
        }
        else if (commands == "delete") {
            cin >> temp;
            heap.deleteNode(temp);
        }
        else if (commands == "display") {
            heap.display();
        }
        else if (commands == "insert") {
            cin >> temp;
            heap.insert(temp);
        }
    }

    return 0;
}