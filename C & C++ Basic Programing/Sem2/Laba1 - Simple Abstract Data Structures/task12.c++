#include <iostream>
using namespace std;

template <typename T>
class TypeList {
public:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    TypeList() : head(nullptr) {}

    void append(T data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void print_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~TypeList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
};

int main() {
    TypeList<int> int_list;
    int_list.append(11);
    int_list.append(22);
    int_list.append(33);
    int_list.print_list();

    TypeList<float> float_list;
    float_list.append(22.2f);
    float_list.append(44.4f);
    float_list.print_list();

    TypeList<string> string_list;
    string_list.append("Hello");
    string_list.append("World");
    string_list.print_list();

    return 0;
}
