//HUFFMAN CODE
//CREATED BY
            //21BCE232 :: RUSHIL PRAJAPATI
            //21BCE240 :: RAJ PARMAR
            //21BCE244 :: RAMOLIYA FENIL

//NIRMA UNIVERSITY B.TECH CSE (III) SEMESTER C DIVION (C3) 



#include <bits/stdc++.h>
using namespace std;

// Structure for the node of binary tree
struct Node_MinHeap
{
    // Each node has two info. part
    // one is data part (charcter)
    // another is frequency of that charcter
    char data;
    unsigned freq;

    // Self Referencing Structure
    // LEFT CHILD OF ROOT ND RIGFHT CHILD OF ROOT
    Node_MinHeap *left_child, *right_child;

    // Constructore in Object Oriented programming
    // THIS IS CONSTRUCTORE WITH PARAMETRE
    // Constructore intialize the variable
    Node_MinHeap(char d, unsigned f)
    {
        // At first right and left child initialized to NULL
        left_child = right_child = NULL;

        // Initializing data and frequency with passed variable d and f respectively
        this->data = d;
        this->freq = f;
    }
};

// As we're using the minHeap, so we have to check the wheather the value of root node will be less than value of child node
struct compare
{
    // Passing 2 parametre in here, left and right node
    bool operator()(Node_MinHeap *l, Node_MinHeap *r)
    {
        // return true is l>r
        // else return false
        return (l->freq > r->freq);
    }
};

// This function will help us to generate codes using a huffman tree
// Also help us to print that code accordingly
void printCodes(struct Node_MinHeap *root, string bit)
{
    //If no root, then return to parent function
    if (!root)
        return;

    // When the node contain some data than printing that data(charcter)  along which their variable length code(bits)
    if (root->data != '#')
        cout << root->data << ": " << bit << "\n";

    printCodes(root->left_child, bit + "0");

    printCodes(root->right_child, bit + "1");
}

// This function builds the Huffman Tree using Priority queue and MinHeap
// HuffmanCodes function take total 3 arguments
// 1. Charcter Array
// 2. Frequency array of that charcter array
// 3. Size of the array (needed for ceating total 'size' number of nodes)
void Huffman_Code(char data[], int freq[], int size)
{
    struct Node_MinHeap *left_child, *right_child, *top;

    // Create a min heap & inserts all characters of data[]

    // here created a priority queue which is an inbuild function in C++
    // this priority queue called minHeap which contains total 3 properties

    // 1-> MinHeapNode which create the MinHeapNode
    // 2-> Creating a vector of MinHeapNode, which acts as array but usses the push_back function in it
    // 3-> Calling Compare function, which we wrote above

    // as this is complete binary tree we can also store the values in ARRAY OR VECTOR rather than using linked list
    priority_queue<Node_MinHeap *, vector<Node_MinHeap *>, compare> minHeap;

    // Creating a Binary Tree which stores each charcter and respective frequency of that charcter in nodes
    // in minHeap manner
    // basically creating a complete binary tree of given data&frequency entry which has minHeap Tree property
    for (int i = 0; i < size; ++i)
    {
        // passing data and frequency of that data to minHeap
        // by using minHeap.Push it will automatially arrange the tree in minHeap manner
        minHeap.push(new Node_MinHeap(data[i], freq[i]));
    }

    // Itrating the entire tree while the size of heap become 1(up to last)
    while (minHeap.size() != 1)
    {

        // Extracting the two minimum according to steo 2

        // Extracting top node and stroing it in variable left
        left_child = minHeap.top();
        // deleteing that top most node (here called popping)
        minHeap.pop();

        // Extracting just next bigger node and stroing it in variable right_child
        right_child = minHeap.top();
        // deleteing that extracted node (here called popping)
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '#' is a special value
        // for internal nodes, not used

        // Creating a new internel node according to algo's step 3
        // that new internel node called top has the frequency equal to the sum of frequency of that 2 extracted nodes
        top = new Node_MinHeap('#', left_child->freq + right_child->freq);
        // setting left and right child of that internel node that extracted nodes
        top->left_child = left_child;
        top->right_child = right_child;

        // inserting this new internel node to minHeap
        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");
}

// main function
int main()
{

    cout << "Enter total number of charcters :" << endl;
    int size;
    cin >> size;

    char char_array[size];
    int freq[size];

    cout << "Enter your charcters one by one : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> char_array[i];
    }
    cout << "Enter your frequency of each charcter in order :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> freq[i];
    }

    Huffman_Code(char_array, freq, size);

    return 0;
}
