#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

void bestFit(int blockSizes[], int blockCount, int processSizes[], int processCount) {
    int allocation[MAX_PROCESSES];

    // Initialize all allocations to -1 (not allocated)
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }

    // Process each request
    for (int i = 0; i < processCount; i++) {
        int bestIndex = -1;

        for (int j = 0; j < blockCount; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                if (bestIndex == -1 || blockSizes[j] < blockSizes[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSizes[bestIndex] -= processSizes[i];
        }
    }

    // Display results
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSizes[MAX_BLOCKS] = {200, 300, 400, 100, 150};
    int processSizes[MAX_PROCESSES] = {120, 250, 50};
    int blockCount = 5;
    int processCount = 3;

    printf("Initial Block Sizes:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: %d KB\n", i + 1, blockSizes[i]);
    }

    bestFit(blockSizes, blockCount, processSizes, processCount);

    printf("\nFinal Block Sizes:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: %d KB\n", i + 1, blockSizes[i]);
    }

    return 0;
}