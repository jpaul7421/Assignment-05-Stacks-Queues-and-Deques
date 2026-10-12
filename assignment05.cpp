    int front() const {
        if (empty()) throw underflow_error("ArrayDeque is empty");
        return data[frontIndex];
    }
    int back() const {
        if (empty()) throw underflow_error("ArrayDeque is empty");
        return data[(frontIndex + count - 1) % CAP];
    }
};

class LinkedDeque {
    struct Node { int value; Node* previous; Node* next; };
    Node* frontNode = nullptr;
    Node* backNode = nullptr;
public:
    ~LinkedDeque() { while (!empty()) popFront(); }
    bool empty() const { return frontNode == nullptr; }
    void pushFront(int x) {
        Node* node = new Node{x, nullptr, frontNode};
        if (frontNode) frontNode->previous = node;
        else backNode = node;
        frontNode = node;
    }
    void pushBack(int x) {
        Node* node = new Node{x, backNode, nullptr};
        if (backNode) backNode->next = node;
        else frontNode = node;
        backNode = node;
    }
    int popFront() {
        if (empty()) throw underflow_error("LinkedDeque is empty");
        Node* old = frontNode;
        int value = old->value;
        frontNode = old->next;
        if (frontNode) frontNode->previous = nullptr;
        else backNode = nullptr;
        delete old;
        return value;
    }
    int popBack() {
        if (empty()) throw underflow_error("LinkedDeque is empty");
        Node* old = backNode;
        int value = old->value;
        backNode = old->previous;
        if (backNode) backNode->next = nullptr;
        else frontNode = nullptr;
        delete old;
        return value;
    }
    int front() const {
        if (empty()) throw underflow_error("LinkedDeque is empty");
        return frontNode->value;
    }
    int back() const {
        if (empty()) throw underflow_error("LinkedDeque is empty");
        return backNode->value;
    }
};

template <typename T>
void testStack(const char* name, int start) {
    cout << "\n" << name << "\n";
    T s;
    try { s.pop(); } catch (const underflow_error&) { cout << "empty removal: handled\n"; }
    s.push(start); s.push(start + 10); s.push(start + 20);
    s.push(start + 30); s.push(start + 40);
    cout << "peek=" << s.peek() << '\n';
    cout << "pop=" << s.pop() << '\n';
    s.push(start + 50);
    while (!s.empty()) cout << "pop=" << s.pop() << '\n';
    cout << "empty=true\n";
}

template <typename T>
void testQueue(const char* name, int start) {
    cout << "\n" << name << "\n";
    T q;
    try { q.dequeue(); } catch (const underflow_error&) { cout << "empty removal: handled\n"; }
    q.enqueue(start); q.enqueue(start + 10); q.enqueue(start + 20);
    q.enqueue(start + 30); q.enqueue(start + 40);
    cout << "front=" << q.front() << '\n';
    cout << "dequeue=" << q.dequeue() << '\n';
    cout << "dequeue=" << q.dequeue() << '\n';
    q.enqueue(start + 50); q.enqueue(start + 60);
    while (!q.empty()) cout << "dequeue=" << q.dequeue() << '\n';
    cout << "empty=true\n";
}

template <typename T>
void testDeque(const char* name) {
    cout << "\n" << name << "\n";
    T d;
    try { d.popFront(); } catch (const underflow_error&) { cout << "empty removal: handled\n"; }
    d.pushBack(20); d.pushFront(10); d.pushBack(30); d.pushFront(5); d.pushBack(40);
    cout << "front=" << d.front() << ", back=" << d.back() << '\n';
    cout << "popFront=" << d.popFront() << '\n';
    cout << "popBack=" << d.popBack() << '\n';
    d.pushFront(1); d.pushBack(50);
    while (!d.empty()) {
        cout << "popFront=" << d.popFront() << '\n';
        if (!d.empty()) cout << "popBack=" << d.popBack() << '\n';
    }
    cout << "empty=true\n";
}

int main() {
    cout << "Assignment 05: Stacks, Queues, and Deques\n";
    testStack<ArrayStack>("ArrayStack", 10);
    testStack<LinkedStack>("LinkedStack", 1);
    testQueue<ArrayQueue>("ArrayQueue", 10);
    testQueue<LinkedQueue>("LinkedQueue", 1);
    testDeque<ArrayDeque>("ArrayDeque");
    testDeque<LinkedDeque>("LinkedDeque");
}
