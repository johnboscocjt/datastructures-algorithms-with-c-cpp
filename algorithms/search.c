#include <stdio.h>

//not using any command line arguements
int main(void){
int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    //get user input
    int n = get_int("Number: ");
    
    for(int i = 0; i < 7; i++){
        if(numbers[i] == n){
            printf("Found\n");
        }else{
            printf("Not found\n");

            //to make the function primarily function
            return 0;
        }
    

    }
    printf("Not found\n");
    

}