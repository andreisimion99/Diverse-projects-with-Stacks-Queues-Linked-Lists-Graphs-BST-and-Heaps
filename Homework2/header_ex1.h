#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
using namespace std;

struct S
{
    char nume[20];
    int id;
}student[100];

struct P
{
    char titlu[20];
    int id;
}proiect[100];

struct Nod
{
    Nod *next;
    S student;
    P proiect;
};

template<typename T>
class LinkedList
{
    Nod *prim,*ultim;
    int length;
public:
    LinkedList(){};         ///CONSTRUCTOR
    ~LinkedList(){};        ///DESTRUCTOR
    T Add(S s,P p);
    int getLength();
    T StergereStudent(S s);
    T InlocuireProiect(P pvechi,P pnou);
    T Print();
};

template<typename T>
T LinkedList<T>::Add(S s, P p)  /// adaugarea unui nod la finalul listei
{
    if(!ultim)  ///daca lista e vida
    {
        Nod *nod=new Nod;
        nod->student=s;
        nod->proiect=p;
        nod->next=NULL;     ///nu mai exista alt nod
        prim=ultim=nod;
        length++;
    }
    else
    {
        Nod* nod=new Nod();
        nod->student=s;
        nod->proiect=p;
        nod->next=NULL;
        ultim->next=nod;
        ultim=nod;
        length++;
    }
}

template<typename T>
int LinkedList<T>::getLength()      ///GETTER CARE RETURNEAZA NR POSIBILITATILOR
{
    return length;
}

template<typename T>
T LinkedList<T>::StergereStudent(S s)       ///STERGE UN STUDENT DIN LISTA
{
    Nod *p=prim;
    Nod *last=NULL;

    while(p!=NULL && p->student.nume!=s.nume && p->student.id!=s.id)
    {
        last=p;
        p=p->next;
    }
    if(p==NULL)
    {
        cout<<"nu exista";
    }else
    {
        if(p==prim)
        {
            prim=prim->next;
            delete p; //distruge nodul p
        }
        else if(p==ultim)
        {
            last->next=NULL;
            ultim=last;
            delete p;
        }
        else
        {
            last->next=p->next;
            delete p;
        }
    }
}

template<typename T>
T LinkedList<T>::InlocuireProiect(P pvechi,P pnou)      ///INLOCUIESTE UN PROIECT VECHI CU UNUL NOU
{
    Nod *p=prim;

    while(p!=NULL && p->proiect.titlu!=pvechi.titlu && p->proiect.id!=pvechi.id)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        cout<<"nu exista";
    }else
    {
        p->proiect=pnou;
    }
}

template<typename T>
T LinkedList<T>::Print()        ///AFISEAZA POSIBILIATILE RETINUTE IN LISTA
{
    Nod *p=prim;
    if(p==NULL)
        cout<<"lista vida";
    while(p!=NULL)
    {
        cout<<p->student.nume<<" - "<<'"'<<p->proiect.titlu<<'"'<<endl;
        p=p->next;
    }
    cout<<endl;
}


#endif // HEADER_H_INCLUDED
