bool search(node *tree, int number){
    if(tree == NULL){
        return false;
    }else if(number < tree->number){

        return search(tree->left, number)
    }
    // number is bigger 
    else if (number > tree->number){
        return search (tree->right, number);
    }
    // if the number you are looking for is equal
    else if (number == tree->number){
        return true;
    }
}