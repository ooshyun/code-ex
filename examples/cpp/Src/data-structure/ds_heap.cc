#include "iostream"
#include <random>

class MinIntHeap{
    public:
        MinIntHeap()
        {
            items = new int[capacity];
        };
        ~MinIntHeap()
        {
            delete[] items;
        };
        int *items;
        int peak()
        {
            if(size > 0) return items[0];
            else return 0;
        };
        int poll()
        {
            return 0;
        };
        int add(int item)
        {
            
            size++;
            return 0;
        };
        void heapifyUp(){};
        void heapifyDown(){};
    protected:
        int capacity = 10;
        int size = 0;
    private: // root index is 0
        int getLeftChildIndex(int parentIndex)
        {
            return 2*parentIndex+1;
        };
        int getRightChildIndex(int parentIndex)
        {
            return 2*parentIndex+2;
        };
        // int getParentChildIndex(int parentIndex);
        bool hasLeftChild(int index)
        {
            if(size >= 2*index+1)return true;
            return false;
        };
        bool hasRightChild(int index)
        {
            if(size >= 2*index+2)return true;
            return false;
        };
        bool hasParent(int index)
        {
            if((size < 2) || (size < index))return false;
            else return true;
        };
        int leftChild(int index)
        {
            if(hasLeftChild(index)) return items[2*index+1];
            else return 0;
        };
        int rightChild(int index)
        {
            if(hasRightChild(index)) return items[2*index+2];
            else return 0;
        }
        int parent(int index)
        {
            if(hasParent(index)) return items[index/2];
            else return 0;
        }        
        void swap(int indexOne, int indexOther)
        {
            int buf = items[indexOne];
            items[indexOne] = items[indexOther];
            items[indexOther] = buf;
        };
        void ensureExtraCapacity(){};        
};

void testMinHeap()
{
    std::cout << "Hello Min Heap World!\n";
    MinIntHeap minheap;
    std::vector<int> inArr;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);

    uint32_t i, n=10;
    int buf;
    for(i=0; i<n; i++)
    {
        buf = dis(gen);
        inArr.push_back(buf);

    }
    
    for(auto var : inArr)
    {
        std::cout<< "Push " << var << std::endl;
        // Add arr into heap
        // ...
    }

    // Print Peak in Heap
    // Poll a Peak in Heap as Heap Sort
}