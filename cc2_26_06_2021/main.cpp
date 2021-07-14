#include <iostream>
using namespace std;
//lista doblemente enlazada circular
template <class T>

class Node
{
  public:
  T data;
  Node* next;
  Node* anter;

  Node(){
    data = 0;
    next = NULL;
  }
  Node(T d){
    data = d;
    next = NULL;
  }
  void print(){
    cout<<data<<",";
  }
};

template <class T>

class List
{
  private:
  Node<T>* m_head;

  public:
  List(){
    Node<T>* pNode = new Node<T>(-1);
    m_head = pNode;
    pNode->next = pNode;//a si mismo
  }
  ~List(){//Liberar toda la memoria utilizada
    Node<T>* act;
    Node<T>* sig;
    act = m_head->next;
    while (act->data != -1) {
      sig = act->next;
      delete act;//primero, segundo, tercero
      act = sig;//segundo, tercero, cuarto
    }
    delete m_head;//Elimina el nodo artificial 
  }
  void add(T d){//Añadir al inicio
    Node<T>*new_node = new Node<T>(d);
    new_node->next = m_head->next;//nuevo nodo apunta a lo que el nodo artificial apuntaba
    m_head->next = new_node;
  }
  
  void print(){
    cout << "Head->";
    for (Node<T>* p = m_head->next; p->data!=-1; p = p->next)
        p->print();
    cout << endl;
  }
  Node<T>* findAnt(T d){//Cuando el dato a buscar esta desde la 1ra
    Node<T>* ant = m_head;//Artificial
    Node<T>* p = NULL;
    for (p = m_head->next; p->data !=-1; p = p->next,ant = ant->next) {
        if (p->data == d) break;
    }
    if (p->data == -1)//No encontrado if (!p)
      return NULL;
    return ant;
  }
  void del(T d){//Eliminar un nodo
    Node<T>* ant;
    Node<T>* tmp;
    ant = findAnt(d);//Desde el primer elemento
    if(ant == NULL)cout<<"No encontrado"<<"\n";
    else{
      tmp = ant->next;
      ant->next = ant->next->next;
      delete tmp;
    }
  }
 
  void insert(T newNode,T node){
    Node<T>* ant;
    Node<T>* tmp;
           
    ant = findAnt(node);//Dos o mas elementos
    if(ant == NULL)cout<<"No encontrado"<<"\n";
    else{
      Node<T>*new_node = new Node<T>(newNode);
      tmp=ant->next;
      ant->next=new_node;
      new_node->next=tmp;
    }
    
  }
};

int main() {
  List<float> l;//vacia
  l.add(8);
  l.add(6);
  l.add(9);
  l.print();
  l.insert(4,9);
  l.print();
  l.insert(3,8);
  l.print();
}