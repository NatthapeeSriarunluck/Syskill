struct node{
	int data;
	struct node *next;
};
typedef struct node Node;


Node *first;

void insert(int num);
void print();

/* deleteNode will get rid of the first occurence of num from my list. If found, return 1, if not return 0*/
int deleteNode(int num);

/* insert a new node at [location] instead of at the end. If location is > the size of the list, insert at the end*/
void insertAt(int location, int num);

