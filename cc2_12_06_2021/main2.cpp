#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node();
    Node(int);
    void print();
};
class List{
private:
    Node* m_head;
    Node* m_end;
public:
    List();
    ~List();
    void add_head(int);
    void add_end(int);
    void imprimir();
    Node* findAnt(int);
    void del(int);
};

Node::Node(){
    data = NULL;
    next = NULL;
}
Node::Node(int d){
    data = d;
    next = NULL;
}

List::List(){
    m_head = NULL;
    m_end = NULL;
}

List::~List(){//Liberamos toda la memoria utilizada
    Node* temp;
    while(m_head){
        temp = m_head->next;
        delete m_head;
        m_head = temp;
    }
}
//funciones
void Node::print(){
    cout<<data<<",";
}
////////
void List::add_head(int d){//añadir al inicio
    Node* new_node = new Node(d);
    if(!m_head){//vacia
        m_head = new_node;
        m_end = new_node;
    }else{//con elementos
        new_node -> next = m_head;// aputa al anterior pirmero
        m_head = new_node;
    }
}
void List::add_end(int d){//añadir al final
    Node* new_node = new Node(d);
    if(!m_head){//vacia
        m_head = new_node;
        m_end = new_node;
    }else{//con elementos
        m_end -> next = new_node;// apunta al nuevo nodo
        m_end = new_node;
    }
}

void List::imprimir(){
    cout<<"Head->";
    for(Node* p = m_head;p;p = p->next)
        p->print();
    cout <<"NULL"<<endl;
}

Node* List::findAnt(int d){// buscar un elemento 
    Node* ant=m_head;
    Node* p = NULL;
    for(p = m_head;p;p = p->next){
        if(p->data != d)
            ant = ant->next;
        break;
    }
    if(!p)// no encontrado
        return NULL;
    return ant;
}

void List::del(int d){// eliminar un nodo
    Node* ant;
    Node* tmp;
    if(m_head ->data == d){//Dato esta con el primer nodo
        Node* tmp = m_head;
        m_head = tmp -> next;
        delete tmp;
        if(m_head)// un elemento
            m_end = NULL;
    }else{//el dato esa a partir del segundo elemento
        if(m_head->next != NULL){
            ant = findAnt(d);
            if(ant == NULL)
                cout<<"No encontrado";
            else
                tmp = ant;
                ant = ant ->next;
                delete tmp;
        }else{cout<<"No encontrado";}
    }
}


int main(){
    List l;
    l.add_head(8);
    l.imprimir();
    l.add_end(3);
    l.imprimir();
    l.add_head(8);
    l.imprimir();
    
    return 0;
}