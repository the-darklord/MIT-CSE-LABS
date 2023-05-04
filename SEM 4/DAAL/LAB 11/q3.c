#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;

struct node
{
    char c;
    unsigned freq;
    Node left,right;
};

typedef struct MinHeap* Heap;

struct MinHeap
{
    unsigned size;
    unsigned capacity;
    Node* heap;
};

Node newNode(char c,unsigned freq)
{
    Node temp=(Node)malloc(sizeof(struct node));
    temp->c=c;
    temp->freq=freq;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void swap(Node *a, Node *b)
{
    Node t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Heap minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heap[left]->freq < minHeap->heap[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->heap[right]->freq < minHeap->heap[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->heap[smallest], &minHeap->heap[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node extractMin(Heap minHeap)
{
  Node temp = minHeap->heap[0];
  minHeap->heap[0] = minHeap->heap[minHeap->size - 1];

  --(minHeap->size);
  minHeapify(minHeap, 0);

  return temp;
}

void buildMinHeap(Heap minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

void insertMinHeap(Heap minHeap, Node minHeapNode)
{
    ++(minHeap->size);
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->heap[(i - 1) / 2]->freq)
    {
        minHeap->heap[i] = minHeap->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->heap[i] = minHeapNode;
}

Heap createMinH(unsigned capacity)
{
    Heap minHeap = (Heap )malloc(sizeof(struct MinHeap));

    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->heap = (Node*)malloc(minHeap->capacity * sizeof(Node));
    return minHeap;
}

Heap createAndBuildMinHeap(char item[], int freq[], int size)
{
    Heap minHeap = createMinH(size);

    for (int i = 0; i < size; ++i)
    {
        minHeap->heap[i] = newNode(item[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

int checkSizeOne(Heap minHeap)
{
    return (minHeap->size == 1);
}


Node buildHuffmanTree(char item[], int freq[], int size)
{
    Node left,right,top;
    Heap minHeap = createAndBuildMinHeap(item, freq, size);

    while (!checkSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

int isLeaf(Node root)
{
    return !(root->left) && !(root->right);
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void printHCodes(Node root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("  %c   | ", root->c);
        printArray(arr, top);
    }
}

void HuffmanCodes(char item[], int freq[], int size)
{
    Node root = buildHuffmanTree(item, freq, size);

    int arr[50], top = 0;

    printHCodes(root, arr, top);
}

void main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf(" Char | Huffman code ");
    printf("\n--------------------\n");

    HuffmanCodes(arr, freq, size);
    
}
