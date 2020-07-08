#include <iostream>
#include <string.h>

using namespace std;

struct arb
{
    char info;
    arb *st;
    arb *dr;
}*r;

int nrnoduri;

struct arb* inserare(arb *r,char x)
{
    if(r==NULL)
    {
        r=new arb;
        r->info=x;
        r->st=r->dr=NULL;
        return r;
    }
    else
    {
        if(x<=r->info)
            r->st=inserare(r->st,x);
        else r->dr=inserare(r->dr,x);
        return r;
    }
}

void citire()
{
    char C;

    cout<<"Introduceti literele: ";
    cin>>C;

    while(C!='0')
    {
        r=inserare(r,C);
        nrnoduri++;
        cin>>C;
    }
}

struct arb* cautare(arb *r,int x)
{
    if(r==NULL || r->info==x)
       return r;
    if (r->info<x)
       return cautare(r->dr,x);
    return cautare(r->st,x);
}

struct arb *maxim(arb *r)
{
    arb* temp=r;
    while (temp->dr!=NULL)
        temp=temp->dr;
    return temp;
}

struct arb *succesor(arb *r)
{
    arb* temp=r;
    while (temp->st!=NULL)
        temp=temp->st;
    return temp;
}
struct arb* stergere(arb*r,int x)
{
    if(r==NULL)
    {
        //cout<<"Arborele este vid!"<<endl;
        return r;
    }
    if(x<r->info)                   //daca se afla in subarborele stang
        r->st=stergere(r->st,x);
    else
        if(x>r->info)
        r->dr=stergere(r->dr,x);    //daca se afla in subarborele drept
    else                            //daca este chiar radacina
    {
        if (r->st==NULL)                //daca radacina are cel mult un fiu
        {
            arb *temp=r->dr;
            delete(r);
            return temp;
        }
        else if(r->dr==NULL)
        {
            arb *temp=r->st;
            delete(r);
            return temp;
        }
        arb *temp=succesor(r->dr);          //daca are 2 fii, se cauta cel mai mic nod din subarborele stang
        r->info=temp->info;
        r->dr=stergere(r->dr,temp->info); //sterge succesorul gasit de pe pozitia veche
    }
    return r;
}

void inordine(arb *r)
{
    if(r==NULL)
        return ;
    inordine(r->st);
    cout<<r->info<<' ';
    inordine(r->dr);
}

void postordine(arb *r)
{
    if(r==NULL)
        return;
    postordine(r->st);
    postordine(r->dr);
    cout<<r->info<<' ';
}

void preordine(arb *r)
{
    if(r==NULL)
        return;
    cout<<r->info<<' ';
    preordine(r->st);
    preordine(r->dr);
}
void afisare(arb*r)     ///RSD = PREORDINE
{
    if(r==NULL)
    {
        cout<<"Arborele este vid!"<<endl;
        return;
    }
    else
    {
        char metoda_afis[10];
        cout<<"Alege o metoda de afisare: preordine, inordine, postordine"<<endl;
        cin>>metoda_afis;

        if(strcmp(metoda_afis,"preordine")==0)
            preordine(r);
        else
            if(strcmp(metoda_afis,"inordine")==0)
                inordine(r);
            else
                if(strcmp(metoda_afis,"postordine")==0)
                    postordine(r);
    }
    cout<<endl;
}

arb *PredCom(arb *r,char n1,char n2)
{
    while (r!=NULL)
    {
        if(r->info>n1 && r->info>n2)
           r=r->st;
        else if(r->info<n1 && r->info<n2)
           r=r->dr;
        else break;
    }
    return r;
}

bool Bunic(arb *r,char b,char n)
{
    arb *bunic=cautare(r,b);
    arb *tata;
    if(n>bunic->info)
    {
        tata=bunic->dr;
        if(tata->st->info==n || tata->dr->info==n)
            return true;
        else return false;
    }
    else
    {
        tata=bunic->st;
        if(tata->st->info==n || tata->dr->info==n)
            return true;
        else return false;
    }
}

/*
void createLevelLinkedList(TreeNode root,ArrayList<LinkedList<TreeNode>> lists, int level) {
   if (root == null) return; // base case
   LinkedList<TreeNode> list = null;
   if (lists.size() == level) { // Level not contained in list
      list = new LinkedList<TreeNode>();
      /* Levels are always traversed in order. So., if this is the
      * first time we've visited level i, we must have seen levels
      * 0 through i - 1. We can therefore safely add the level at
      * the end.
      lists.add(list);
   } else {
      list = lists.get(level);
   }
   list.add(root);
   createLevelLinkedList(root.left, lists, level + 1);
   createLevelLinkedList(root.right, lists, level + 1);
}
ArrayList<LinkedList<TreeNode>> createLevelLinkedList(
                                             TreeNode root) {
   ArrayList<LinkedList<TreeNode>> lists =
                           new ArrayList<LinkedList<TreeNode>>();
   createLevelLinkedList(root, lists, 0);
   return lists;
}
*/

int lungimea(arb *r)
{
   int l=0;
   while(r!=NULL)
   {
      l++;
      r=r->st;
   }
   return l;
}

bool ArbPerfect(arb *r, int l, int level=0)
{
    if (r==NULL) //arbore gol
        return true;

    if (r->st==NULL && r->dr==NULL) //arbore cu un singur nod
        return (l==level+1);

    if (r->st==NULL || r->dr==NULL) //nu are nod si la dreapta si la stanga
        return false;

    //subarborele stang si drept trebuie sa fie si ei perfecti
    return ArbPerfect(r->st,l,level+1) && ArbPerfect(r->dr,l,level+1);
}

bool Perfect(arb *r)
{
   int l=lungimea(r);
   return ArbPerfect(r,l);
}

arb *RotDD(arb *r)
{
    arb *temp;
    temp=r->dr;
    r->dr=temp->st;
    temp->st=r;
    return temp;
}

arb *RotLL(arb *r)
{
    arb *temp;
    temp=r->st;
    r->st=temp->dr;
    temp->dr=r;
    return temp;
}
arb *RotDreapta(arb *r)
{
    arb *temp;
    temp=r->st;
    r->st=RotDD(temp);
    return RotLL(r);
}

int main()
{
    citire();   ///S,G,U,D,K,M,I
    afisare(r);
    cout<<"Nr de noduri al arborelui este "<<nrnoduri<<endl;

    arb *a;
/*
    char n1,n2;
    cout<<"Ascensorul comun al caror noduri vrei sa afli?"<<endl;
    cin>>n1>>n2;
    a=lca(r,n1,n2);
    cout<<a->info<<endl;
*/
    a=PredCom(r,'U','I');
    cout<<"Predecesorul comun al lui U si I este "<<a->info<<endl;

    a=PredCom(r,'M','G');
    cout<<"Predecesorul comun al lui M si G este "<<a->info<<endl;

    a=PredCom(r,'I','M');
    cout<<"Predecesorul comun al lui I si M este "<<a->info<<endl;


    if(Bunic(r,'G','I'))
        cout<<"G este bunicul lui I"<<endl;
    else
        cout<<"G nu este bunicul lui I"<<endl;

    if(Bunic(r,'G','K'))
        cout<<"G este bunicul lui K"<<endl;
    else
        cout<<"G nu este bunicul lui K"<<endl;

     if(Perfect(r))
        cout<<"Este arbore perfect."<<endl;
     else
        cout<<"Nu este arbore perfect."<<endl;

    r=RotDreapta(r);
    afisare(r);

    return 0;
}
