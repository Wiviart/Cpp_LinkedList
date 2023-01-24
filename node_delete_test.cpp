#include <iostream>
using namespace std;

struct node{
    int data;
    struct node * next;
};

struct node * head;

void print ();
int  count ();
void bgnIn (int data);
void anyIn (int data, int place);
void endIn (int data);
void delPl (int place);
void delVa (int value);
void sortA_bubble ();
void findN (int value);

int main(){

    print();


        anyIn(5, 1); print();
        anyIn(43, 1); print();
        anyIn(3, 2); print();
        anyIn(9, 5); print();
        delVa(13); print();
        anyIn(13, 5); print();
        findN(13); print();
        delVa(13); print();
        anyIn(6, 3); print();
        anyIn(32, 2); print();
        sortA_bubble(); print();
        findN(13); print();
        delPl(3); print();
        delPl(1); print();
        delPl(7); print();
        delPl(5); print();
        delPl(2); print();
        delPl(1); print();
        delPl(1); print();
        delPl(1); print();
        delPl(1); print();
        endIn(13); print();
        sortA_bubble(); print();
        delVa(1); print();
        delVa(13); print();
        sortA_bubble(); print();

}
// Printing linked list
void print (){
    struct node * ptr = head;
    
    cout << endl << "---------------------------------------------";
    printf("\nList [%02d]: ", count());
    while (ptr != NULL){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
    cout << "---------------------------------------------" << endl;
}
// Count the number of node in the linked list
int  count (){
    struct node *tmp = head;
    int count = 0;

    while (tmp != NULL){
        tmp = tmp->next;
        count++;
    }

    return count;
    free(tmp);
}
// Insert node in linked list from beginning
void bgnIn (int data){
    struct node * ptr = (struct node*) malloc(sizeof(struct node));
    // Thieu khai bao malloc se bi infinity loop

    // if (ptr == NULL){
    //     cout << "Over";
    // }else{
        cout << endl << "Input node: ";
        cin >> data;

        ptr->data = data;
        ptr->next = head;
        head = ptr;
    //}
}
// Insert node in linked list from ending
void endIn (int data){
    struct node * tmp = (struct node*) malloc(sizeof(struct node));
    struct node * lst = head;

    tmp->data = data;
    tmp->next = NULL;

    if (lst == NULL){
        head = tmp;
        return;
    }

    while (lst->next != NULL){
        lst = lst->next;
    }

    lst->next = tmp;
}
// Insert node from any place in linked list
void anyIn (int data, int place){
    struct node * tmp = (struct node*) malloc(sizeof(struct node));

    tmp->data = data;
    tmp->next = NULL;

    if (place == 1){
        tmp->next = head;
        head = tmp;
        cout << endl << "# Node " << data << " will be inserted at the place " << place << "." << endl;
        return;
    }

    if (place > count()){
        cout << endl << "# Can NOT insert node " << data << " to place " << place << "." << endl;
        cout << "# Node " << data << " will be inserted at the last place." << endl;
        endIn(data);
        return;
    }

    struct node * ptr = head;
    for (int i=1; i < place-1; i++){
        ptr = ptr->next;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
    cout << endl << "# Node " << data << " will be inserted at the place " << place << "." << endl;

}
// Delete node in linked list from any place
void delPl (int place){
    struct node * ptr = head;
    int del_node;
    
    if (ptr == NULL) {
        cout << endl << "# Can NOT delete an empty list." << endl; 
        return;
    }
    if (place == 1 || ptr->next == NULL){
        del_node = head->data;
        head = head->next;
        goto delete_announce;
    }
    if (place > count()){
        cout << endl << "# Can NOT delete the node at place " << place << "." << endl;

        while (ptr->next->next != NULL){
            ptr = ptr->next;
        }
        del_node = ptr->next->data;
        ptr->next = NULL;

        cout << "# Node " << del_node << " at the end of the list will be deleted." << endl;
        return;
    }
    
    for (int i=1; i < place -1; i++){
        ptr = ptr->next;
    }
    del_node = ptr->next->data;
    ptr->next = ptr->next->next;

delete_announce:
    cout << endl << "# Node " << del_node << " at place " << place << " has been deleted." << endl;
    return;

}
// Delete node in linked list have the value
void delVa (int value){
    struct node * ptr = head;
    int place = 1;

    if (head->next == NULL && head->data == value){
        cout << endl << "# Node " <<  value << " at the beginning has been deleted." << endl;
        head = NULL;
        return;
    }
    while (ptr->next != NULL && ptr->next->data != value){
        ptr = ptr->next;
        place++;
    } 
    if (ptr->next == NULL){
        cout << endl << "# Node " << value << " is not appearing in the list." << endl;
        return;
    }
    if (ptr->next->data == value){
        place++;
        cout << endl << "# Node " <<  ptr->next->data << " at place " << place << " has been deleted." << endl;
        ptr->next = ptr->next->next;
        return;
    }
}
// Sort all node in linked list by ascending
void sortA_bubble (){

    if (head == NULL){
        cout << endl << "# Can NOT sort an empty list." << endl;
        return;
    }
    if (head->next == NULL){
        cout << endl << "# Can NOT sort a list with only node." << endl;
        return;
    }

    struct node *ptr;
    int tmp;
    for (int i=0; i < count(); i++){
        ptr = head;
        while (ptr->next != NULL){
            if (ptr->data > ptr->next->data){
                tmp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tmp;
            }
            ptr = ptr->next;
        }
    }
    
    // int x = count();
    // for (int i=1; i < x; i++){
        // if (ptr == NULL) break;
        // if (ptr->data > ptr->next->data){
        //     tmp = ptr->data;
        //     ptr->data = ptr->next->data;
        //     ptr->next->data = tmp;
        // }
        // ptr = ptr->next;
    // }
    cout << endl << "# List will be sorted." << endl;
}
// Find place of a node in linked list
void findN (int value){
    struct node *ptr = head;
    int place = 0;

    while (ptr != NULL){
        place++;
        if (ptr->data == value){
            cout << endl << "# Node " << value << " stay at place " << place << "." << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << endl << "# Can NOT find node " << value << " in the list." << endl;
}