// considering the sorting of the numbers
#include <stdio.h>
// to use malloc use the following library
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

// for command line
int main(int argc, char *argv[]){
    // memory for numbers
    node *list = NULL;

    // foreach command line argument
    for(int i = 1; i < argc; i++){
        // converting a string into an integer
        // conert the argument to int 
        int number = atoi(argv[i]); 
        // print("%i/n", number);

        // allocate node for the number
        node *n = malloc(sizeof(node));
        if(n == NULL){
            // free the memory so far
            return 1; 
        }
        // follow the pointer to the number field and set it to the actual number
        // number on the left and number on the right here are different
        n->number = number;
        // n is pointing at the chunk of memory that is big enough to fit a node 

        // initialize the null coz list=n; is potentially bad coz of memory leaks
        n->next = NULL; 

        // if the list is empty
        if(list == NULL){
            // this node is the whole list
            list = n;
        }
        // if number belongs at the beginning of the list
        elseif(n->number < list->number){
            n->next = list;

            // update the new linked list variable
            list = n;
        }
        // if list has numbers already
        else{
            // iterating over the available linked list
            // iterate over the nodes in the list
            // determining the postion of the node , if is at the end , middle or somewhere in the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next){
                // if at the end of the list
                if(ptr->next == NULL){
                    // append the node, which is currently null
                    ptr->next = n;

                    // makes sure we maintain sorted order even if the first one belongs to the middle of the list
                    break;
                }

                // if in the middle of the list
                if(n->number < ptr->next->number){
                    // update the new node next pointer to the curent node that is pointed at
                    n->next = ptr->next;

                    // update the pointer's next field to be equal to the new node
                    ptr->next = n;
                    break;
                }
            }
        }

    }

    // printing the whole list, point and print out
    node *ptr = list;
    // so long as the ptr is bnot equal to null/ at the end of the list
    while(ptr != NULL){
        // print out whatever you a re pointing at
        printf("%i\n", ptr->number);

        // update the point to point to the next value
        ptr = ptr->next;

    }

}