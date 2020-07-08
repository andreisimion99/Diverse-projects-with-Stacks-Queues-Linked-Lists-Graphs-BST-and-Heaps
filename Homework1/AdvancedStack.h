#ifndef ADVANCEDSTACK_H_INCLUDED
#define ADVANCEDSTACK_H_INCLUDED
#define NMAX 10

using namespace std;

template<typename T>    ///typename==class
class AdvancedStack     ///OBIECTUL STIVA
{
    private:        ///ELEMENTELE OBIECTULUI STIVA
		T stackArray[NMAX];     ///VECTORUL CU ELEMENTELE STIVEI
		int topLevel;           ///NR DE ELEMENTE ALE STIVEI
        T minim[NMAX];          ///VECTOR CE CONTINE PE ULTIMUL ELEMENT MINIMUL CORESPUNZATOR ORICAREI ACTUALIZARI A STIVEI (STIVA SE ACTUALIZEAZA LA PUSH SI POP )
        T maxim[NMAX];          ///VECTOR CE CONTINE PE ULTIMUL ELEMENT MAXIMUL .......

    public:         ///METODE

        AdvancedStack();    ///CONSTRUCTOR
        ~AdvancedStack();   ///DESTRUCTOR

        void push(T x);     ///ADAUGA IN STIVA
        int isEmpty();      ///VERIFICA DACA STIVA E GOALA
        T pop();            ///SCOATE DIN STIVA
        T peek();           ///RETURNEAZA VARFUL
        T getMin();      ///RETURNEAZA MINIMUL
        T getMax();      ///RETURNEAZA MAXIMUL
};

template<typename T>        ///ADAUGA IN STIVA
void AdvancedStack<T>::push(T x)
{
	if (topLevel>=NMAX-1)       ///verifica daca mai e loc in stiva
    {
		cout<<"STIVA ESTE GOALA, NU ARE MAXIM!"<<endl;
        return;
    }

    topLevel++;                ///creste numarul de elemente din stiva
	stackArray[topLevel]=x;    ///pune in stiva

    if(x<minim[topLevel-1] || minim==NULL)  ///daca stiva este goala sau x e mai mic decat minimul curent
        minim[topLevel]=x;                  ///atunci minimul(elementul de la sfarsitul vectorului minim) devine x
    else minim[topLevel]=minim[topLevel-1]; ///altfel minimul ramane acelasi(doar se copiaza fostul ultim element in ultimul element din vector)

    if(x>maxim[topLevel-1] || maxim==NULL)  ///la fel ca la minim, doar ca se verifica daca x e mai mare decat maximul curent
        maxim[topLevel]=x;
    else maxim[topLevel]=maxim[topLevel-1];

}

template<typename T>        ///VERIFICA DACA STIVA ESTE GOALA
int AdvancedStack<T>::isEmpty()
{
	return (topLevel<0);    ///initial topLevel=-1 si deci daca stiva e goala atunci -1 < 0 => true
}

template<typename T>
T AdvancedStack<T>::pop()       ///SCOATE DIN STIVA
{
	if (isEmpty())          ///stiva trebuie sa aibe cel putin un element pentru a se putea scoate din ea
    {
        cout<<"STIVA ESTE GOALA!"<<endl;
        return 0;
    }

    return stackArray[topLevel--];  ///returneaza elementul scos si se scade numarul de elemnte din stiva

}

template<typename T>
T AdvancedStack<T>::peek()          ///RETURNEAZA VARFUL STIVEI
{
    if (isEmpty())         ///stiva trebuie sa aibe cel putin un element pentru a avea un varf
    {
        cout<<"STIVA ESTE GOALA, NU ARE VARF!"<<endl;
        return 0;
    }
    return stackArray[topLevel];    ///returneaza ultimul element din stiva == varful stivei
}

template<typename T>        ///CONSTRUCTOR
AdvancedStack<T>::AdvancedStack()
{
    topLevel=-1;    ///stiva construita este vida
}

template<typename T>        ///DESTRUCTOR
AdvancedStack<T>::~AdvancedStack()
{
    ///cout<<endl<<"SE DISTRUGE STIVA"<<endl;
}

template<typename T>
T AdvancedStack<T>::getMin()    ///MINIMUL
{
    if(isEmpty())       ///stiva trebuie sa aibe cel putin un element pentru a avea un minim
    {
        cout<<"STIVA ESTE GOALA, NU ARE MINIM!"<<endl;
        return 0;
    }
    return minim[topLevel];     ///returneaza ultimul element din vectorul minim == minimul curent din stiva

}

template<typename T>        ///MAXIMUL
T AdvancedStack<T>::getMax()
{
    if(isEmpty())       ///stiva trebuie sa aibe cel putin un element pentru a avea un maxim
    {
        cout<<"STIVA ESTE GOALA, NU ARE MAXIM!"<<endl;
        return 0;
    }
    return maxim[topLevel];     ///returneaza ultimul element din vectorul maxim == maximul curent din stiva

}


#endif // ADVANCEDSTACK_H_INCLUDED
