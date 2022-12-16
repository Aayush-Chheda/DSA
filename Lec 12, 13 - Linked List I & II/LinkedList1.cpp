#include "Node.cpp"

using namespace std;

Node* takeInput() {

    Node *head, *temp;
    head = temp = NULL;
    int data;
    cin >> data;
    while(data != -1){
        if(head == NULL){
            head = new Node(data);
            temp = head;
        }
        else{
            temp->next = new Node(data);
            temp = temp->next;
        }
        cin >> data;
    }
    return head;
}

int lenll(Node* head) {

    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

int lenllr(Node* head){

    if(head == NULL)
        return 0;
    return 1 + lenllr(head->next);
}

Node* insertNodeI(Node* head, int i, int data){

    Node* temp = head;
    for(int j=1; j<i-1; j++)
        temp = temp->next;

    Node* newNode = new Node(data);
    if(i == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* insertNodeR(Node* head, int i, int data){

    if(i == 1){
        Node* newNode = new Node(data);
        newNode->next = head;
        return head = newNode;
    }
    head->next = insertNodeR(head->next, i-1, data);
    return head;
}

Node* deleteNodeI(Node* head, int i){

    Node* temp = head;
    for(int j=1; j<i-1; j++)
        temp = temp->next;

    Node* delNode = 0;
    if(i == 1){
        Node* delNode = head;
        head = head->next;
    }
    else{
        Node* delNode = temp->next;
        temp->next = delNode->next;
    }
    delete delNode;
    return head;
}

Node* deleteNodeR(Node* head, int i){
    if(i == 1){
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
    head->next = deleteNodeR(head, i-1);
    return head;
}

void printLL(Node* head){
    while(head){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = takeInput();
    printLL(head);

/*
    head = insertNodeI(head, 3, 9);
    printLL(head);

    head = insertNodeI(head, 7, 10);
    printLL(head);

    head = insertNodeI(head, 1, 11);
    printLL(head);
*/

/*
    head = deleteNodeI(head, 3);
    printLL(head);
    
    head = deleteNodeI(head, 1);
    printLL(head);
    
    head = deleteNodeI(head, 4);
    printLL(head);
*/

/*
    head = insertNodeR(head, 3, 9);
    printLL(head);

    head = insertNodeR(head, 7, 10);
    printLL(head);

    head = insertNodeR(head, 1, 11);
    printLL(head);
*/

/*
    head = deleteNodeI(head, 3);
    printLL(head);
    
    head = deleteNodeI(head, 1);
    printLL(head);
    
    head = deleteNodeI(head, 4);
    printLL(head);
*/
}
