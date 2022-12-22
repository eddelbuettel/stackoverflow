#include <R.h>
#include <Rinternals.h>
#include "uthash.h"

typedef struct
{
  // a pointer to the allocated memory
  void * ptr;
  // used by the hash table
  UT_hash_handle hh;
} AllocatedMemory;

// map that stores all allocated memory pointers
// to free them on interrupt
extern AllocatedMemory * memoryMap;


static inline void* CALLOC(size_t n, size_t sz)
{
  void * ptr = calloc(n, sz);

  if (ptr == NULL)
    error("Out of memory!");

  AllocatedMemory * m = calloc(1, sizeof(AllocatedMemory));
  m->ptr = ptr;
  HASH_ADD_PTR(memoryMap, ptr, m);
  return ptr;
}

SEXP example_R(SEXP vec_R) {
    unsigned int n = length(vec_R);
    unsigned int * v = CALLOC(n, sizeof(unsigned int));
}
