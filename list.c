// data structures
// just learning the syntanxes and the way to actually write up the data structures
// queues
const int CAPACITY = 50;
typedef struct{
    person people[CAPACITY];
    int size;
}queue;

// stack
typedef struct{
    person people[CAPACITY];
    int size;
}stack;

// linked list
typedef struct{
    char *name;
    char *number;
}person;

typedef struct node{
    int number;
    node *next;
}node;