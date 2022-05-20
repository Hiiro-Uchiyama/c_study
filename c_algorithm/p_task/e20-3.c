struct node {
    char name[20];
    int score;
    struct node *next;
}
struct node *root;

void deleteNode(const char *name){
    struct node *cur = root;
    struct node *prev = NULL;
    if(root == NULL){
        return;
    }
    while(cur != NULL){
        if (strcmp(cur->name, name) == 0){
            if (prev == NULL){
                root = cur->next;
            }
            else {
                prev->next = cur->next;
                return;
            }
        }
        prev = cur;
        cur = cur->next;
    }
}

int main(void){
    struct node all[] = {
        {"Alice", 49, NULL},
        {"Bob", 91, NULL},
        {"Curl", 82, NULL},
        {"Deb", 77, NULL}
    };
    root = &all[0];
    all[0].next = &all[1];
    all[1].next = &all[2];
    all[2].next = &all[3];
}