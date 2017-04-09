#include <cstdlib>

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compr) (const void*,const void*)) {
  const char* x = reinterpret_cast<const char*>(base);
  for (size_t i = 0; i < nmemb; i++) {
    if (!compr(key, reinterpret_cast<const void*>(&x[i * size]))) {
      return const_cast<void*>(reinterpret_cast<const void*> (&x[i * size]));
    }
  }
  return NULL;
}
