struct Node {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

// Min-Heap node definition
struct HeapNode {
    struct ListNode* node;  // Pointer to the actual ListNode
    int val;                // Value of the node (used for comparison in the heap)
};

// Min-Heap compare function
int compare(struct HeapNode* a, struct HeapNode* b) {
    return a->val - b->val;
}

// Function to merge k sorted linked lists
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    if (k == 0) return NULL;

    // Min-Heap initialization
    struct HeapNode* heap = (struct HeapNode*)malloc(sizeof(struct HeapNode) * k);
    int heapSize = 0;

    // Initialize heap with the first node of each list
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            heap[heapSize].node = lists[i];
            heap[heapSize].val = lists[i]->val;
            heapSize++;
        }
    }

    // Build the initial heap
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        int j = i;
        while (2 * j + 1 < heapSize) {
            int leftChild = 2 * j + 1;
            int rightChild = 2 * j + 2;
            int minChild = leftChild;

            if (rightChild < heapSize && heap[rightChild].val < heap[leftChild].val) {
                minChild = rightChild;
            }

            if (heap[j].val <= heap[minChild].val) break;

            // Swap
            struct HeapNode temp = heap[j];
            heap[j] = heap[minChild];
            heap[minChild] = temp;

            j = minChild;
        }
    }

    // Create a dummy node to form the result list
    struct ListNode* result = createNode(0);
    struct ListNode* current = result;

    // Extract nodes from the heap and build the result list
    while (heapSize > 0) {
        // Pop the smallest node from the heap
        struct HeapNode smallest = heap[0];

        // Move to the next node in the same list
        if (smallest.node->next != NULL) {
            heap[0].node = smallest.node->next;
            heap[0].val = smallest.node->next->val;
        } else {
            // If the list is exhausted, remove the heap root by swapping with the last element
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        // Reheapify after modifying the heap root
        int j = 0;
        while (2 * j + 1 < heapSize) {
            int leftChild = 2 * j + 1;
            int rightChild = 2 * j + 2;
            int minChild = leftChild;

            if (rightChild < heapSize && heap[rightChild].val < heap[leftChild].val) {
                minChild = rightChild;
            }

            if (heap[j].val <= heap[minChild].val) break;

            // Swap
            struct HeapNode temp = heap[j];
            heap[j] = heap[minChild];
            heap[minChild] = temp;

            j = minChild;
        }

        // Append the smallest node to the result list
        current->next = smallest.node;
        current = current->next;
    }

    // Return the merged sorted list (skipping the dummy node)
    return result->next;
}
