#include <iostream>
#include <list>
#include <queue>
using namespace std;
const int N = 8;                // liczba wierzcholkow
list <int> adj_list[N+1];       // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1
int label[N+1];

class Queue{
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue

public:
    Queue(int size = N+1);     // constructor
    ~Queue();                   // destructor

    int dequeue();
    void enqueue(int x);
    int size();
    bool isEmpty();
    bool isFull();
};

Queue::Queue(int size){
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

int Queue::dequeue(){
    if (isEmpty()){
        return 0;
    }
    int x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

void Queue::enqueue(int item){
    if (isFull()) return;
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == capacity);
}
void add_edge (int u,int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}
// Graf z zadania
void construct_graph(){
    add_edge(1,2); add_edge(2,3);add_edge(3,4);add_edge(4,1);
    add_edge(7,8); add_edge(8,5);add_edge(5,6);add_edge(6,7);
    add_edge(4,8); add_edge(1,5);add_edge(2,6);add_edge(3,7);
}
void show_labels(){
    for (int i=1;i<=N;++i)
        if (label[i] == 1)
            cout<<i<<" ";
    cout<<endl;
    for (int i=1;i<=N;++i)
        if (label[i] == 2)
            cout<<i<<" ";
}
bool is_bipartite() {
    Queue Q(N + 1); //create new queue
    int v = 1; //dowolny wierzcholek
    label[v] = 1; //oznaczamy go
    Q.enqueue(v); //wstawienie elementu do kolejki
    while (!Q.isEmpty()) {
        int u = Q.dequeue(); //pobranie elementu z kolejki wraz z jego usunięciem
        for (int v: adj_list[u]) { //all sasiadow u
            if (label[u] == label[v]) return false;
            if (label[v] == NULL) { // jezeli nie odwiedzony
                if (label[u] == 1) label[v] = 2; //przeciwny u
                else label[v] = 1;
                Q.enqueue(v); //wstawienie elementu do kolejki
            }
        }
    }
    return true;
}
int main(){
    construct_graph();
    if (is_bipartite()){
        cout<<"Graf jest dwudzielny. Podzial na klasy: " << endl;
        show_labels();
    }
    else
        cout<<"Nie jest dwudzielny!";
    return 0;
}