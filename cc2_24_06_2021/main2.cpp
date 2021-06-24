#include <iostream>
using namespace std;

template <class T>

class Node
{
public:
    T data;
    Node* next;
    Node* anter;

    Node() {
        data = 0;
        next = NULL;
        anter = NULL;
    }
    Node(T d) {
        data = d;
        next = NULL;
        anter = NULL;
    }
    void print() {
        cout << data << ",";
    }
};

template <class T>

class List
{
private:
    Node<T>* m_head;
    Node<T>* m_end;

public:
    List() {
        m_head = NULL;
        m_end = NULL;
    }
    ~List() {//Liberar toda la memoria utilizada
        Node<T>* sig;
        while (m_head) {
            sig = m_head->next;//segundo, tercero, cuarto
            delete m_head;//primero, segundo, tercero
            m_head = sig;//segundo, tercero, cuarto
        }
    }
    void add_head(T d) {//A�adir al inicio
        Node<T>* new_node = new Node<T>(d);

        if (!m_head) {//Vacia
            m_head = new_node;
            m_end = new_node;
        }
        else {//Con elementos
            new_node->next = m_head;//apunta al anterio primero
            m_head->anter = new_node;// apunta al anterior nuevo
            m_head = new_node;
        }
    }
    void add_end(T d) {//A�adir al final
        Node<T>* new_node = new Node<T>(d);

        if (!m_head) {//Vacia
            m_head = new_node;
            m_end = new_node;
        }
        else {//Con elementos
            m_end->next = new_node;
            new_node->anter = m_end;
            m_end = new_node;
        }
    }
    void print() {
        cout << "Head->";
        for (Node<T>* p = m_head; p; p = p->next)
            p->print();
        cout << endl;
/*
        cout << "End->";
        for (Node<T>* p = m_end; p; p = p->anter)
            p->print();
        cout << endl; cout << endl;*/
    }
    Node<T>* findAnt(T d) {//Cuando el dato a buscar esta desde la 2da
        //Node<T>* ant = m_head;
        Node<T>* p = NULL;
        for (p = m_head->next; p; p = p->next) {
            if (p->data == d) break;
        }
        if (!p)//No encontrado
            return NULL;
        return p;
    }

    void del(T d) {//Eliminar un nodo
        Node<T>* pos;
        Node<T>* tmp;
        if (!m_head) { cout << "No encontrado" << "\n"; return; }
        if (m_head && m_head->data == d) {//Dato est� en el primer nodo
            if (m_head->next == nullptr && m_head->anter == nullptr) {//solo hay un elemento 
                delete m_head;
                m_head = NULL;
                m_end = NULL;
            }
            else {//hay 2 o mas elementos
                tmp = m_head;
                m_head = tmp->next;
                m_head->anter = NULL;
                delete tmp;
            }
        }
        else {//El dato est� a partir del segundo elemento
            pos = findAnt(d);//Dos o mas elementos
            //tmp = ant->anter;
            if (pos == NULL)cout << "No encontrado" << "\n";
            else{
                if(m_end->data == d){//si esta al final
                    tmp = m_end;
                    m_end = tmp->anter;
                    m_end->next = NULL;
                    delete tmp;

                }
                else{//antes del final
                    tmp = pos->anter;
                    tmp->next=tmp->next->next;
                    tmp = pos->next;
                    tmp->anter= tmp->anter->anter;
                    delete pos;
                }
            }
        }
    }
    void insert(T newNode, T node) {
        Node<T>* ant =NULL;
        Node<T>* tmp =NULL;
        if (!m_head) { cout << "No encontrado" << "\n"; return; }
        if (m_head->data == node) {//INSERTAR AL INICIO
            add_head(newNode);
        }
        else {
            ant = findAnt(node);//Dos o mas elementos
            if (ant == NULL)cout << "No encontrado" << "\n";
            else {
                Node<T>* new_node = new Node<T>(newNode);
                tmp = ant->anter;
                ant->anter = new_node;
                new_node->anter = tmp;

                tmp->next = new_node;
                new_node->next = ant;
            }
        }
    }
};


int main() {
  List<float> l;//vacia
  l.insert(100, 4);
    l.print();
    l.add_head(4);
    l.print();
    l.add_head(19);
    l.print();
    l.add_end(22);
    l.print();
    l.add_end(1);
    l.print();
    l.add_end(10);
    l.print();
    l.add_end(5);
    l.print();

    l.insert(100, 4);
    l.print();
    l.insert(90, 100);
    l.print();
    l.insert(70, 19);
    l.print();
    l.insert(100, 455);
    l.print();
    l.insert(60, 70);
    l.print();
    l.insert(110, 5);
    l.print();
    l.insert(12, 22);
    l.print();
    cout << "DELETE " << endl;
    l.del(129);
    l.print();
    l.del(4);
    l.print();
    l.del(5);
    l.print();
    l.del(22);
    l.print();
    l.del(129);
    l.print();
    l.del(1);
    l.print();
    l.del(10);
    l.print();
    l.del(19);
    l.print();
    l.del(129);
    l.print();
    l.add_head(1);
    l.print();
    l.add_end(2);
    l.print();
}