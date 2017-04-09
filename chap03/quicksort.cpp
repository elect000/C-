#include <cstdlib>

using namespace std;

namespace {
  void memswap (void* x, void* y, size_t n) {
    unsigned char* a = reinterpret_cast<unsigned char*>(x);
    unsigned char* b = reinterpret_cast<unsigned char*>(y);
    for (; n--; a++, b++) {
      unsigned char c = *a;
      *a = *b;
      *b = c;
    }
  }
}

void quicksort (void* base, size_t nmemb, size_t size,
		int (*compr) (const void*, const void*)) {
  if (nmemb > 0) {
    const char* v = reinterpret_cast<const char*>(base);
    size_t pl = 0;
    size_t pr = nmemb - 1;
    size_t pv = nmemb;
    size_t pt = (pl + pr) / 2;
    do
      {
	const char* x;
	if (pv != pt) {
	  x = &v[(pv = pt) * size];
	}
	while (compr(reinterpret_cast<const void*>(&v[pl * size]), x) < 0) {
	  pl++;
	}
	while (compr(reinterpret_cast<const void*>(&v[pr * size]), x) > 0) {
	  pr--;
	}
	if (pl <= pr) {
	  pt = (pl == pv) ? pr : pv;
	  memswap(const_cast<void*>(reinterpret_cast<const void*>(&v[pl * size])),
		  const_cast<void*>(reinterpret_cast<const void*>(&v[pr * size])),
		  size);
	  pl++;
	  if (pr == 0) {
	    goto QuickRight;
	  }
	  pr--;
	}
      } while (pl <= pr);
    if (0 < pr) {
      quicksort(const_cast<void*>(reinterpret_cast<const void*>(&v[0])),
		pr + 1, size, compr);
    }
    QuickRight:
    if (pl < nmemb - 1) {
      quicksort(const_cast<void*>(reinterpret_cast<const void*>(&v[pl * size])),
		nmemb - pl, size , compr);
    }
  }
}
