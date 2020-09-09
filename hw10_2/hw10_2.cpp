/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw10/challenges/closed-hashing/submissions/code/1323327218
 * Title: hw10_2.cpp
 * Abstract: simulate the operations of linear
 * probing covered in the class.
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 26APR20
 */


#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

class Hash{
private:
    int *table, size, count;
    void reHash();

public:
    void insert(int n);
    void displayStatus(int n);
    void tableSize();
    void search(int n);
    void deleteYeah(int n);
    ~Hash();

    Hash(int size);
};

Hash::Hash(int size) {
    count = 0;
    this->size=size;
    table = new int[size];
    for (int i = 0; i < size; ++i) {
        table[i]=0;
    }
}

Hash::~Hash() {
    delete []table;
}

void Hash::insert(int n) {
    int loca = n % size;
    //cout<<loca<<" trying to insert at loca"<<endl;
    while (true){
        if (table[loca] <= 0){
            table[loca] = n;
            count++;
            //cout<<loca<<" inserted at loca"<<endl;
            break;
        }
        //to check next slot
        loca++;
        //if your at the end, wrap back around
        if(loca==size){
            loca=0;
        }
    }
    //typecast to retain decimal precision
    if((double)count >= (double)size/2){
        reHash();
    }
}

void Hash::reHash() {
    int* oldTable = table;
    int oldSize = size;
    count = 0;
    int newSize = size * 2;
    while (!isPrime(newSize)){
        newSize++;
    }
    size = newSize;
    table = new int[size];
    for (int i = 0; i < size; ++i) {
        table[i]=0;
    }
    for (int j = 0; j < oldSize; ++j) {
        if (oldTable[j] > 0){
            insert(oldTable[j]);
        }
    }
    //free the memory
    delete[]oldTable;
}

void Hash::tableSize() {
    cout<<size<<endl;
}

void Hash::displayStatus(int n){
    if (n < 0 || n >= size){
        cout<< n << " Invalid"<<endl;
    } else if(table[n] == 0){
        cout <<"Empty"<<endl;
    } else if(table[n] < 0){
        cout << (table[n] * - 1) << " Deleted"<< endl;
    }
    else{
        cout<<table[n]<<" Active"<<endl;
    }
}

void Hash::deleteYeah(int n) {
    int loca = n % size;
    while (true){
        //find what we want
        if (table[loca] == n){
            table[loca] = n * -1;
            count--;
            break;
        }
        else if(table[loca]==0){
            break;
        }
        //to check next slot
        loca++;
        //if your at the end, wrap back around
        if(loca==size){
            loca=0;
        }
    }
}

void Hash::search(int n){
    int loca = n % size;
    while (true){
        //find what we want
        if (table[loca] == n){
            cout << n << " Found" << endl;
            break;
        }
        //nothing was ever here (= 0)
        else if(table[loca]==0){
            cout << n << " Not found" << endl;
            break;
        }
        //to check next slot
        loca++;
        //if your at the end, wrap back around
        if(loca==size){
            loca=0;
        }
    }
}

int main() {
    int tableSize, numberOfCommands;
    int temp, temp1, temp2;

    cin>>tableSize;

    string commands;

    Hash hash(tableSize);

    cin >> numberOfCommands;

    for (int j = 0; j < numberOfCommands; ++j) {

        cin >> commands;

        if (commands == "insert") {
            cin >> temp;
             hash.insert(temp);
        }
        else if (commands == "displayStatus") {
            cin >> temp;
            hash.displayStatus(temp);
        }
        else if (commands == "tableSize") {
            hash.tableSize();
        }
        else if (commands == "search") {
            cin >> temp;
            hash.search(temp);
        }
        else if (commands == "delete") {
            cin >> temp;
            hash.deleteYeah(temp);
        }
    }
    return 0;
}
