#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Polygon {
protected:
    string name;
public:
    Polygon(string n) : name(n) {}
    virtual double area() const = 0;
    virtual double circumference() const = 0;
    virtual void print() const = 0;
    string getName() const { return name; }
    virtual ~Polygon() {}
};

class RightTriangle : public Polygon {
    double base, height;
public:
    RightTriangle(string n, double b, double h)
        : Polygon(n), base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    double circumference() const override {
        double hyp = sqrt(base * base + height * height);
        return base + height + hyp;
    }

    void print() const override {
        cout << "right-triangle " << name << " " << base << " " << height << endl;
    }
};
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Create a stack of integers
    stack<int>s;

    // Push 10,20,30 elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    
    #include <iostream>
#include <stack>

using namespace std;

int main() {
    // Create a stack of integers
    stack<int>s;

    // Push 10,20,30 elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    
    // Display the top element of the stack
    cout<<"top of element:"<<s.top()<<endl;
    
    // Pop the top element from the stack
    s.pop();
    
    // Check if the stack is empty, if not empty display size. else display stack is now empty.
    cout<<"After popping, top element:"<<s.top()<<endl;
    
    if(!s.empty()){
    cout<<"stack is not empty. Size: <<s.size()"<<endl;
    }
    
    // Pop remaining elements
    s.pop();
    s.pop();
    
    // Check again if the stack is empty
    if(s.empty()){
    cout<<"stack is now empty."<<endl;
    }
 
    return 0;
}
// Display the top element of the stack
    cout<<"top of element: "<<s.top()<<endl;
    
    // Pop the top element from the stack
    s.pop();
    
    // Check if the stack is empty, if not empty display size. else display stack is now empty.
    cout<<"After popping, top element: "<<s.top()<<endl;
    
    if(!s.empty()){
    cout<<"stack is not empty. Size: "<<s.size()<<endl;
    }
    
    // Pop remaining elements
    s.pop();
    s.pop();
    
    // Check again if the stack is empty
    if(s.empty()){
    cout<<"stack is now empty."<<endl;
    }
 
    return 0;
}

class Rectangle : public Polygon {
protected:
    double base, height;
public:
    Rectangle(string n, double b, double h)
        : Polygon(n), base(b), height(h) {}

    double area() const override {
        return base * height;
    }

    double circumference() const override {
        return 2 * (base + height);
    }

    void print() const override {
        cout << "rectangle " << name << " " << base << " " << height << endl;
    }
};

class Square : public Rectangle {
public:
    Square(string n, double side)
        : Rectangle(n, side, side) {}

    void print() const override {
        cout << "square " << name << " " << base << endl;
    }
};

struct Node {
    Polygon *data;
    Node *next;
    Node(Polygon *p) : data(p), next(nullptr) {}
};

class PolygonList {
    Node *head;
public:
    PolygonList() : head(nullptr) {}

    ~PolygonList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
    }

    void add(Polygon *p) {
        Node *node = new Node(p);
        node->next = head;
        head = node;
    }

    void remove(const string &n) {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr) {
            if (curr->data->getName() == n) {
                if (prev != nullptr)
                    prev->next = curr->next;
                else
                    head = curr->next;

                delete curr->data;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void printAll() const {
        Node *curr = head;
        while (curr != nullptr) {
            curr->data->print();
            curr = curr->next;
        }
    }

    double totalArea() const {
        double sum = 0;
        Node *curr = head;
        while (curr != nullptr) {
            sum += curr->data->area();
            curr = curr->next;
        }
        return sum;
    }

    double totalCircumference() const {
        double sum = 0;
        Node *curr = head;
        while (curr != nullptr) {
            sum += curr->data->circumference();
            curr = curr->next;
        }
        return sum;
    }
};

int main() {
    PolygonList inventory;
    string command;

    while (cin >> command) {
        if (command == "add") {
            string type, name;
            cin >> type >> name;

            if (type == "right-triangle") {
                double b, h;
                cin >> b >> h;
                inventory.add(new RightTriangle(name, b, h));
            }
            else if (type == "rectangle") {
                double b, h;
                cin >> b >> h;
                inventory.add(new Rectangle(name, b, h));
            }
            else if (type == "square") {
                double s;
                cin >> s;
                inventory.add(new Square(name, s));
            }
        }
        else if (command == "delete") {
            string name;
            cin >> name;
            inventory.remove(name);
        }
        else if (command == "print-all") {
            inventory.printAll();
        }
        else if (command == "print") {
            string what;
            cin >> what;
            if (what == "area")
                cout << inventory.totalArea() << endl;
            else if (what == "circumference")
                cout << inventory.totalCircumference() << endl;
        }
        else if (command == "done") {
            break;
        }
    }

    return 0;
}
