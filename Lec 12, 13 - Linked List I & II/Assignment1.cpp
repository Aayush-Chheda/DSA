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

void swapNodes(Node* &head, int i, int j){

    if(i == j)
        return;

    Node *prev1, *curr1, *prev2, *curr2;
    prev1 = prev2 = 0;
    curr1 = curr2 = head;

    for(int k=1; k<max(i,j); k++){
        if(k == min(i,j)){
            prev1 = prev2;
            curr1 = curr2;
        }
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if(prev1 == 0)
        head = curr2;
    else
        prev1->next = curr2;
    prev2->next = curr1;
    swap(curr1->next, curr2->next);
}

void kReverse(Node* &head, int k){

    Node *prev, *curr, *next;
    prev = 0;
    curr = head;

    for(int i=1; i<=k; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;    
    }

    head->next = curr;
    head = prev;
}

void evenAfterOdd(Node* &head){

    Node *currE, *currO, *temp = head;
    Node *currEh, *currOh;
    currE = currO = currEh = currOh = 0;
    while(temp){
        if(temp->data % 2){
            if(currOh == 0)
                currOh = currO = temp;
            else{
                currO->next = temp;
                currO = currO->next;
            }
        }
        else{
            if(currEh == 0)
                currEh = currE = temp;
            else{
                currE->next = temp;
                currE = currE->next;
            }
        }
        temp = temp->next;
    }

    if(currEh == 0 or currOh == 0)
        return;
    head = currOh;
    currO->next = currEh;
    currE->next = 0;
}

int main() {

    Node* head = takeInput();
    printLL(head);

    //swapNodes(head, 1, 2);
    //printLL(head);

    // kReverse(head, 4);
    // printLL(head);

    evenAfterOdd(head);
    printLL(head);
}