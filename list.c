#include "stdinc.h"
#include "list.h"

list::list(int N1) {
	N = N1; next = new int[N+1];
	first = last = Null;
	for (int i = 1; i <= N; i++) next[i] = -1;
	next[Null] = Null;
}

list::~list() { delete [] next; }

// Change size of list. Discard old value.
void list::reset(int N1) {
	delete [] next; N = N1; next = new int[N+1];
	first = last = Null;
	for (int i = 1; i <= N; i++) next[i] = -1;
	next[Null] = Null;
}
	
// Remove all elements from list.
void list::clear() {
	while (first != Null) {
		int i = first; first = next[i]; next[i] = -1;
	}
}

// Return the i-th element, where the first is 1.
int list::operator()(int i) {
	int j;
	if (i == 1) return first;
	for (j = first; j != Null && --i; j = next[j]) {}
	return j;
}

// Add i to the end of the list.
void list::operator&=(int i) {
	if (next[i] != -1) fatal("list::operator&=: item already in list");
	if (first == Null) first = i;
	else next[last] = i;
	next[i] = Null; last = i;
}

// Remove the first i items.
void list::operator<<=(int i) {
	while (first != Null && i--) {
		int f = first; first = next[f]; next[f] = -1;
	}
}

// Assign value of right operand to left operand.
void list::operator=(list& L) {
	if (N < L.N) {
		N = L.N;
		delete [] next; next = new int[L.N+1];
		first = last = Null;
		for (int i = 1; i <= N; i++) next[i] = -1;
		next[Null] = Null;
	} else clear();
	for (int i = L(1); i != Null; i = L.suc(i))
		(*this) &= i;
}

// Add i to the front of the list.
void list::push(int i) {
	if (next[i] != -1) fatal("list::push: item already in list");
	if (first == Null) last = i;
	next[i] = first;
	first = i;
}

// Return true if i in list, else false.
bit list::mbr(int i) {
	return next[i] != -1;
}

// Return the successor of i.
int list::suc(int i) {
	if (next[i] == -1) fatal("list::suc: item not on list");
	return next[i];
}

// Print the contents of the list.
void list::print() {
	for (int i = first; i != Null; i = next[i])
		printf("%d ",i);
}
