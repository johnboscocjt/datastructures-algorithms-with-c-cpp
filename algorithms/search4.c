#include <stdio.h>
#include <string.h>

typedef struct {
    string name;
    string number;
}person; 


int main(void){
    person people[3];

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++){
        if(strcmp(names[i], name) == 0){
            printf("found %s\n",numbers[i]);

            return 0;
        }
        printf("not found\n");
        // return 1 by convention to indicate failure
    }
}