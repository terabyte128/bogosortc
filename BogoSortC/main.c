//
//  main.c
//  BogoSortC
//
//  Created by Sam Wolfson on 9/16/15.
//  Copyright (c) 2015 Sam Wolfson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool arrayIsSorted(int array[], int size);
void bogoSort(int array[], int size);
bool arrayContainsElement(int *array, int size, int element);
void printArray(int *array, int size);

int main(int argc, const char * argv[]) {
    
    time_t start_time = time(NULL);
    
    srand((unsigned int)time(NULL));
    
    int array_size = argc - 1;
    int int_array[array_size];
    
    for (int i = 0; i < array_size; i++) {
        int_array[i] = atoi(argv[i + 1]);
    }
    printf("------ BOGO-SORTER 3000 -----\n\n");
    printf("Was array initially sorted? --> %s\n\n", arrayIsSorted(int_array, array_size) ? "Yes" : "No");
    
    if(!arrayIsSorted(int_array, array_size)) {
        
        printf("OK, let's sort it!\n\n");
        
        long tracker = 0;

        while (!arrayIsSorted(int_array, array_size)) {
            bogoSort(int_array, array_size);
            
            tracker++;

            printf("\rAttempt: %li", tracker);
            fflush(stdout);
        }
        
        printf("\n## Sorting successful at attempt %li!\n\nSorted array = ", tracker);
        printArray(int_array, array_size);

    } else {
        printf("Array was already sorted!\n\nSorted array = ");
        printArray(int_array, array_size);
    }
    
    printf("\nOverall time taken = %i seconds\n", (int)(time(NULL) - start_time));
    
    printf("\n------ FINISHED -----");
    return 0;
}

bool arrayIsSorted(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] < array[i]) {
            return false;
        }
    }
    return true;
}

void bogoSort(int array[], int size) {
    // stores an array temporarily with a random sorting order
    int temp_array[size];
    // keeps track of the indices that have been used
    int used_indices[size];
    
    // for good measure
    for (int i = 0; i < size; i++) {
        used_indices[i] = -1;
    }
    
    // iterate over the original array
    for (int i = 0; i < size; i++) {
        // generate a random number from inside that array's index
        int randomIndex = rand() % size;
        
        // if the used_indices array already contains that index, generate a new one until it doesn't
        while (arrayContainsElement(used_indices, size, randomIndex)) {
            randomIndex = rand() % size;
        }
        
        used_indices[i] = randomIndex;
        
        temp_array[randomIndex] = array[i];
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = temp_array[i];
    }
}

bool arrayContainsElement(int array[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", *array);
        array++;
    }
    printf("\n");
}