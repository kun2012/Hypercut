#include "stdinc.h"
#include "dheap.h"

// parent of item, leftmost and rightmost children
#define p(x) (((x)+(d-2))/d)
#define left(x) (d*((x)-1)+2)
#define right(x) (d*(x)+1)

dheap::dheap(int N1, int d1) {
// Initialize a heap to store items in {1,...,N}.
	static int x = 0; x++;
	N = N1; d = d1; n = 0;
	h = new item[N+1];
	pos = new int[N+1];
	kvec = new keytyp[N+1];
	for (int i = 1; i <= N; i++) pos[i] = Null;
}

dheap::~dheap() { delete [] h; delete [] pos; delete [] kvec; }

void dheap::insert(item i, keytyp k) {
// Add i to heap.
	kvec[i] = k; n++; siftup(i,n);
}

void dheap::remove(item i) {
// Remove item i from heap. Name remove is used since delete is C++ keyword.
	int j = h[n--];
	     if (i != j && kvec[j] <= kvec[i]) siftup(j,pos[i]);
	else if (i != j && kvec[j] >  kvec[i]) siftdown(j,pos[i]);
	pos[i] = Null;
}

int dheap::deletemin() {
// Remove and return item with smallest key.
	if (n == 0) return Null;
	item i = h[1];
	remove(h[1]);
	return i;
}

void dheap::siftup(item i, int x) {
// Shift i up from position x to restore heap order.
	int px = p(x);
	while (x > 1 && kvec[h[px]] > kvec[i]) {
		h[x] = h[px]; pos[h[x]] = x;
		x = px; px = p(x);
	}
	h[x] = i; pos[i] = x;
}

void dheap::siftdown(item i, int x) {
// Shift i down from position x to restore heap order.
	int cx = minchild(x);
	while (cx != Null && kvec[h[cx]] < kvec[i]) {
		h[x] = h[cx]; pos[h[x]] = x;
		x = cx; cx = minchild(x);
	}
	h[x] = i; pos[i] = x;
}

// Return the position of the child of the item at position x
// having minimum key.
int dheap::minchild(int x) {
	int y, minc;
	if ((minc = left(x)) > n) return Null;
	for (y = minc + 1; y <= right(x) && y <= n; y++) {
		if (kvec[h[y]] < kvec[h[minc]]) minc = y;
	}
	return minc;
}

void dheap::changekey(item i, keytyp k) {
// Change the key of i and restore heap order.
	keytyp ki = kvec[i]; kvec[i] = k;
	     if (k < ki) siftup(i,pos[i]);
	else if (k > ki) siftdown(i,pos[i]);
}

// Print the contents of the heap.
void dheap::print() {
	int x;
	printf("   h:");
	for (x = 1; x <= n; x++) printf(" %2d",h[x]);
	printf("\nkvec:");
	for (x = 1; x <= n; x++) printf(" %8x",kvec[h[x]]);
	printf("\n pos:");
	for (x = 1; x <= n; x++) printf(" %2d",pos[h[x]]);
	putchar('\n');
}
