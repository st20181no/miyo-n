#include <stdio.h>
#include <stdlib.h>

#define NUM 26
aaa
typedef struct node {
    struct node *next[NUM];
    int last;
} NODE;

NODE *create(){
    NODE * root = (NODE *)malloc(sizeof(NODE));
    root->last = 0;
    for(int i=0; i<NUM; i++){
        root->next[i] = NULL;
    } 
    return root;
}

void insert(NODE *root, char *str){
    NODE *node = root;
    int i = 0;
    while(str[i] != '\0'){
        int index_number = str[i] - 'a';
        if(node->next[index_number] == NULL){
            node->next[index_number] = create();
        }
        node = node->next[index_number];
        i++;
    }
    node->last = 1;
}

int search(NODE *root, char *kensaku){
    NODE *node = root;
    int index_number;
    for(int k = 0; kensaku[k]  != '\0'; k++){
        index_number = kensaku[k] - 'a';
        node = node->next[index_number];
        if(node == NULL){
            return 0;
        }
        if(kensaku[k + 1] =='\0' && node->last == 1){
            return 1;
        }
    }
}

void show(NODE* node, char* str, int dep) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < dep - 1; i++) {
        printf("|   ");
    }
    if (dep > 0) {
        printf("|---");
    }
    
    printf("%c\n", buffer[depth - 1]);

    for (int i = 0; i < 26; i++) {
        buffer[depth] = i + 'a';
        show(node->next[i], buffer, depth + 1);
    }
}

int main(void){
    NODE * root = create();
    int i;

    insert(root,"car");
    insert(root,"card");
    insert(root,"try");
    insert(root,"tried");
    insert(root,"cat");

    show(root,"buffer",0);

    i = search(root, "card");
    if(i == 1){
        printf("見つかりました\n");
    } else if(i == 0){
        printf("見つかりませんでした\n");
    }
    i = search(root, "carp");
    if(i == 1){
        printf("見つかりました\n");
    } else if(i == 0){
        printf("見つかりませんでした\n");
    }
    i = search(root, "trie");
    if(i == 1){
        printf("見つかりました\n");
    } else if(i == 0){
        printf("見つかりませんでした\n");
    }

    return 0;
}