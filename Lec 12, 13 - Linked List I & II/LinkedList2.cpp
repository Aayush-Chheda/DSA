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

void printLL(Node* head){
    while(head){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

void midpointLL(Node* head){

    Node *slow, *fast;
    slow = head;
    fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

void reverseLLR(Node* head, Node* &nH){

    if(head == 0 or head->next == 0){
        nH = head;
        return;
    }
    reverseLLR(head->next, nH);
    Node* newHead = head->next;
    head->next = 0;
    newHead->next = head;
}

Node* bubbleSort(Node* head){

    if(head == 0 or head->next == 0)
        return head;

    Node* i = head;
    while(i){
        Node* j = i;
        while(j and j->next){
            
        }
    }
}

int main() {

    Node* head = takeInput();
    printLL(head);

    Node* nH = 0;
    reverseLLR(head, nH);
    printLL(nH);
}
