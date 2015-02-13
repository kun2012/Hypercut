CPP = g++
CFLGA = -g

hypercut: hypercut.c trie.c dheap.c list.c hypercut.h trie.h dheap.h list.h stdinc.h
	${CPP} ${CFLGA} -o hypercut hypercut.c trie.c dheap.c list.c  

all: hypercut


