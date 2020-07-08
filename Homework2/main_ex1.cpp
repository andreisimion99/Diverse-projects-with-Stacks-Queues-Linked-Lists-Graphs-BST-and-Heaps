#include <iostream>
#include <fstream>
#include <string.h>
#include "header.h"

using namespace std;

///    ex 1
int n, k, sol[20], nrsol;
LinkedList<Nod> Lista;

void citire()       ///CITIRE NR SI NUME STUDENTI SI NR SI DENUMIRI PROIECTE
{
    int i;
    cout<<"Nr studenti: ";
    cin>>n;
    cout<<"Nr proiecte: ";
    cin>>k;
    cout<<"Nume studenti: ";


    for(i=0; i<n; i++)
    {
        cin.get();
        cin.get(student[i].nume,20);
        student[i].id=i;
    }
    cout<<"Denumiri proiecte: ";

    for(i=0; i<k; i++)
    {
        cin.get();
        cin.get(proiect[i].titlu,20);
        proiect[i].id=i;
    }
}

void init()
{
	int i;
	for(i=0; i<n; i++)
		sol[i]=0;        ///solutiile
}

void CreareLista()
{
	int j;
	for(j=0; j<n; j++)
    {
        Lista.Add(student[j], proiect[sol[j]-1]);
        cout<<student[j].nume<<" - "<<'"'<<proiect[sol[j]-1].titlu<<'"';   ///afiseaza solutia
        if(j<n-1)
            cout<<", ";
	}
	nrsol++;
	cout<<endl;
}

int solutie(int p)
{
	return (p==n-1);
}

int valid()
{
    int i,ok,j;
    for(i=1; i<=k; i++)
    {
        ok=0;
        for(j=0; j<n; j++)
            if(sol[j]==i)
                ok=1;
        if(ok==0)
            return 0;
    }
    return 1;
}

void bkt(int poz)       ///REALIZAREA CU AJUTORUL BACKTRACKING-ULUI A POSIBILITATILOR
{
	int i;
	for (i=1; i<=k; i++)
	{
		sol[poz]=i;
            if(solutie(poz))
            {
                if(valid())
                    CreareLista();
            }
		else
			bkt(poz+1);
	}
}

int main()
{
    citire();
    init();
    bkt(0);
    cout<<"Pentru n="<<n<<"(studenti)"<<", k="<<k<<"(proiecte) sunt "<<Lista.getLength()/n<<" posibilitati."<<endl;
    //Lista.Print();

    cout<<endl<<"ELIMINARE STUDENT "<<student[1].nume<<endl;
    for(int i=0; i<nrsol; i++)
        Lista.StergereStudent(student[1]);
    Lista.Print();

    P pnou;
    cout<<"INLOCUIRE PROIECT "<<proiect[0].titlu<<endl;
    cout<<"Introduceti titlul si id ul noului proiect: "<<endl;
    cin.get();
    cin.get(pnou.titlu,20);
    cin>>pnou.id;
    for(int i=0; i<nrsol; i++)
        Lista.InlocuireProiect(proiect[0],pnou);
    Lista.Print();


    return 0;
}
