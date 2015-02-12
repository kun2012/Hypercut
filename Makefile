CPP = g++
CFLGA = -g

hypercut: hypercut.c trie.c dheap.c list.c 
	${CPP} ${CFLGA} -o hypercut hypercut.c trie.c dheap.c list.c  

all: hypercut


