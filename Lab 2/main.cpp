#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Node {
    string songTitle;
    Node* next;
};

void addSong(Node*& head, string title) {
    Node* newNode = new Node();
    newNode->songTitle = title;
    newNode->next = head;
    head = newNode;
    cout << "Added to playlist.\n";
}

void listSongs(Node* head) {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << count << ". " << temp->songTitle << endl;
        temp = temp->next;
        count++;
    }
}

void searchSong(Node* head, string title) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->songTitle == title) {
            cout << "Found: " << title << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found.\n";
}

int main() {
    Node* head = nullptr;
    int choice;
    string title;

    while (true) {
        cout << "\n1. Add Song\n2. Search Song\n3. List Songs\n4. Exit\nChoice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            cout << "Enter title: ";
            getline(cin, title);
            addSong(head, title);
        } else if (choice == 2) {
            cout << "Enter title to search: ";
            getline(cin, title);
            searchSong(head, title);
        } else if (choice == 3) {
            listSongs(head);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
