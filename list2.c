#include <stdio.h>
// to use malloc use the following library
#include <stdlib.h>

int main(void){
    // array list, using mallloc and pointer
    int *list = malloc(3 * sizeof(int));

    // good practice for using malloc
    if(list == NULL){
        return 1;
    }

    // assigning values to the array
    list[0]=1;
    list[1]=2;
    list[2]=3;

// find the space else where for the given interger datatype, can reuse the garabage values
    int *tmp = malloc(4 *sizeof(int));
      if(list == NULL){
        // if sth goes wrong then exit
        // free the original list b'se u used the memoy above
        free(list);

        return 1;
    }

    // now replace the memory of previous one with the new one
    for(int i= 0; i < 3; i++){
        tmp[i] = list[i];
    }
    // manually putting the last element ot the new replaced array
    tmp[3] = 4;

    // freeing the list, b'se u dont need the allocated bytes anymore 
    free(list);

    // but you can actually update the values in the list after freeing the list above 
    list = tmp;

    // looping  and printing the values
    for(int i = 0; i < 3; i++){
        printf("%i\n", list[i]);
    }

    free(list);

    // now return 0 after having the full comnplete program
}
