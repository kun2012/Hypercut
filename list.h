// Header file for data structure representing list of small positive integers.

class list {
	int	N;			// list defined on ints in {1,...,N}
	int	first;			// beginning of list
	int	last;			// last element of the list
	int	*next;			// next[i] is successor of i in list
public:		list(int=100);
		~list();
	int	operator()(int);	// access item
	void	operator&=(int);	// append item
	void	operator<<=(int);	// remove initial items
	void	operator=(list&);	// list assignment
	void	push(int);		// push item onto front of list
	bit	mbr(int);		// return true if member of list
	int	suc(int);		// return successor
	int	tail();			// return last item on list
	void	clear();		// remove everything
	void	reset(int);		// re-initialize
	void	print();		// print the items on list
};

inline int list::tail() { return last; }
