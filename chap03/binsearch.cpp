#include <cstdlib>

void* binserch(const void* key, const void* base, size_t nmemb, size_t size,
	       int (*compr) (const void* , const void*)) {
  if (nmemb > 0) {
    const char* x = reinterpret_cast<const char*>(base);
    size_t pl = 0;	
    size_t pr = nmemb - 1;
    size_t pc;
    while (true) {
      int comp = compr(key, reinterpret_cast<const void*>(&x[(pc = (pl + pr) / 2) * size]));
      if (comp == 0) {
	return	const_cast<void*>(reinterpret_cast<const void*>(&x[(pc * size)]));
      }
      else if (pl == pr) {
	break;
      }
      else if (comp > 0) {
	pl = pc + 1;
      }
      else {
	pr = pc - 1;
      }
    }
  }
  return NULL;
}	
