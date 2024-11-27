#include <stdio.h>
#include <string.h>

int main(void){
    string names[] = {"Charles", "Bosco", "John"};
    string numbers[] = {"+255-717-112-187", "+255-717-112-187", "+255-717-112-187"};

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