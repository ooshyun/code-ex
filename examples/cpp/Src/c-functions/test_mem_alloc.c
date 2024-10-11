#include <stdio.h>
#include <stdlib.h>

// Helper function to check if a pointer is NULL and free it
void safe_free(void** ptr) {
  if (ptr != NULL && *ptr != NULL) {  // Check if the pointer and its content are not NULL
      printf("Freeing memory at address %p\n", *ptr);
      free(*ptr);  // Free the memory
      *ptr = NULL; // Set the pointer to NULL to avoid dangling pointers
  } else {
      printf("Pointer is NULL, nothing to free.\n");
  }
}

void test_mem_alloc(void) {
  // Allocate memory for an integer array
  int* ptr = (int*)malloc(5 * sizeof(int));

  // Use the memory (example)
  if (ptr != NULL) {
    for (int i = 0; i < 5; ++i) {
        ptr[i] = i;
        printf("%d ", ptr[i]);
    }
    printf("\n");
  }

  // Use the helper function to safely free the memory
  safe_free((void**)&ptr);  // Cast to void** for the helper function

  // Now ptr is NULL, and memory is safely freed.
  if (ptr == NULL) {
      printf("Memory successfully freed and pointer set to NULL.\n");
  }

  safe_free((void**)&ptr);  // Cast to void** for the helper function
}