#include <iostream>

using namespace std;
typedef struct Node{
    string songName;
    Node *link;
}Node;

//Node *sample = new Node;;
//sample->songName = "Heaven Knows by Orange and Lemon";

//cout << sample->songName <<endl;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }

        temp = temp->link;
    }
}

Node *insertAtTheEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
        temp = temp->link;
    }

    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtTheBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" <<endl;
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node; 
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new mode has been added after " + after + "\n";
}

string deletedAtEnd(Node *head){
        if(head == NULL){
            return "The linked list is empty \n";
        }

        if(head->link == NULL){
            delete head;
            return "The head has been deleted \n";
        }

    Node *temp = new Node;
    temp = head;

    while(temp->link->link != NULL){
        temp = temp->link;
    }

    temp->link = NULL;

    return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" << endl;
        return NULL;
    }

    if(head->link == NULL){
        delete head;
    }

    head = head->link;

    cout <<"A node has been delete from the beginning \n" << endl;

    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n" << endl;
        return NULL;
    }

    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node " + givenNode + " has been deleted. \n" << endl;
        return head;
    }

    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;

    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" << endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }

    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted. \n" << endl;
    return head;
}

int main(){
    Node *head = createNode ("Sanctuary by JOJI");
    head = insertAtTheEnd("Sunday Morning by Maroon 5", head);
    
    head = insertAtTheEnd("Seven by Jungkook", head);
   
    head = insertAtTheEnd("Tonight (I Wish I Was Your Boy) by The 1975", head);
    
    head = insertAtTheEnd("Gabi by Nameless Kids", head);
   


    head = insertAtTheBeginning("Heartbreak Girl by 5 Seconds of Summer", head);

    head = insertAtTheBeginning("I Ain't Perfect by IV Of Spades", head);
   

    head = insertAtTheBeginning("This Must Be My Dream by The 1975", head);
    
    head = insertAtTheBeginning("WE (Warm Embrace) by Chris Brown", head);
    traverse(head);



    string result = insertAfter("Heartbreak Girl by 5 Seconds of Summer", "Unti-Unti by UDD", head);
    cout << result;

    string result1 = insertAfter("This Must Be My Dream by The 1975", "Truth by Bamboo", head);
    cout << result1;

    string result2 = insertAfter("WE (Warm Embrace) by Chris Brown", "Gayuma by Abra feat. Thyro Alfaro", head);
    cout << result2;

    string END = deletedAtEnd(head);
    cout << END << endl;
    head = deleteFromBeginning(head);
    head = deleteFromGivenNode("WE (Warm Embrace) by Chris Brown", head);
    traverse(head);

    return 0;
}