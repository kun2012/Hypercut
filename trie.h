class trie {
	struct nodeItem {
		int isleaf;             //is a leaf node if 1
		int nonemptylist;       //
		int lengthoflist;       //
		int *rulelist;
  		int nrules;             //number of rules in this node
        int *ruleid;            //rule ids in this node
  		struct range field[MAXDIMENSIONS];      
  		int dim[MAXDIMENSIONS];   //dimensions to cut
  		int ncuts[MAXDIMENSIONS]; //number of cuts
  		//int child[MAXCUTS];       //child pointers
        int *child;             //child pointer
	};
	int	N;			// max number of nodes in trie
	int	n;			// current number of nodes in trie
	int     pass;                   // max trie depth
	int     n2;                     // removed rules during preprocessing
	int     n3;                     // stored rules
	float   n4;                     // number of memeory access
	int     n5;                     // internally stored rules
    float   worstcost;
	int     bucketSize;                 
	float   spfac;
	int     redun;
	int     push;
    int     pushthresh;
	int     numrules;
	struct  pc_rule *rule;
	int 	root;			// root of trie
	int 	freelist;		// first nodeItem on free list
	nodeItem *nodeSet;		// base of array of NodeItems
	
	void    choose_np_dim(nodeItem *v);
	void    remove_redundancy(nodeItem *v); 
	void    pushing_rule(nodeItem *v);
	void    createtrie();

public:	        trie(int, int, int, float, struct pc_rule*, int, int, int);
		~trie();
		
	int     trieLookup(int*);
	int	    trieSize();
	int     trieDepth();
	int     trieRedun();
	int     trieRule();
	float   trieMemAccess();
	int     trieInRule();
    float   trieWorstcost();
};

inline int trie::trieSize() {return n;}
inline int trie::trieDepth() {return pass;}
inline int trie::trieRedun() {return n2;}
inline int trie::trieRule() {return n3;}
inline float trie::trieMemAccess() {return n4;}
inline int trie::trieInRule() {return n5;}
inline float trie::trieWorstcost() {return worstcost;}

