#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "AdvancedStack.h"
#include "PriorityQueue.h"

using namespace std;

struct node
{
    int x,y,dir;
};
bool vizitat[50][50];
bool GasireCamera()
{
    ifstream fin("date.in");

    char cod[10],camera[10];
    int codCamera,m,n,i,j,cladire[50][50],fx,fy;
  //  bool vizitat[50][50];
    AdvancedStack<int> sx,sy,sd;
    node temp,temp1;

    fin>>cod>>m>>n;

    strcpy(camera,cod+2);
    codCamera=atoi(camera);

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            fin>>cladire[i][j];
            if(cladire[i][j]==codCamera)
            {
                fx=i;
                fy=j;
            }
        }
    i=0;
    j=0;    ///se incepe de la (0,0)

    temp.x=i;
    temp.y=j;
    temp.dir=0;

    sx.push(temp.x);
    sy.push(temp.y);
    sd.push(temp.dir);

    while(!sx.isEmpty())    ///si !sy.isEmpty()
    {
        temp.x=sx.peek();
        temp.y=sy.peek();
        temp.dir=sd.peek();

        int d=temp.dir;
        i=temp.x;
        j=temp.y;

        temp.dir++;

        sx.pop();
        sy.pop();
        sd.pop();

        sx.push(temp.x);
        sy.push(temp.y);
        sd.push(temp.dir);

        if (i==fx && j==fy)
            return true;

        if (d==0)       ///CAUTA IN SUS
        {
            if(i-1>=0 && cladire[i-1][j]==0 && vizitat[i-1][j])
            {
                temp1.x=i-1;
                temp1.y=j;
                temp.dir=0;

                vizitat[i-1][j]=false;

                sx.push(temp1.x);
                sy.push(temp1.y);
                sd.push(temp1.dir);
            }
        }

        else if (d==1)      ///CAUTA LA STANGA
            {
                if (j-1>=0 && cladire[i][j- 1]==0 && vizitat[i][j-1])
                {
                    temp1.x=i;
                    temp1.y=j-1;
                    temp.dir=0;

                    vizitat[i][j-1]=false;

                    sx.push(temp1.x);
                    sy.push(temp1.y);
                    sd.push(temp1.dir);
                }
            }

        else if(d==2)       ///CAUTA IN JOS
            {
                if (i+1<n && cladire[i+1][j]==0 && vizitat[i+1][j])
                {
                    temp1.x=i+1;
                    temp1.y=j;
                    temp.dir=0;

                    vizitat[i+1][j]=false;

                    sx.push(temp1.x);
                    sy.push(temp1.y);
                    sd.push(temp1.dir);
                }
            }
        else if(d==3)       ///CAUTA LA DREAPTA
            {
                if (j+1<m && cladire[i][j+1]==0 && vizitat[i][j+1])
                {
                    temp1.x=i;
                    temp1.y=j+1;
                    temp.dir=0;

                    vizitat[i][j+1]=false;

                    sx.push(temp1.x);
                    sy.push(temp1.y);
                    sd.push(temp1.dir);
                }
            }

        else
        {
            vizitat[temp.x][temp.y]=true;

            sx.pop();
            sy.pop();
            sd.pop();
        }
    }
    return false;
}

int main()
{
    /*
    AdvancedStack<double> myStack;
	myStack.peek();
	myStack.push(4);
	myStack.push(3);
	myStack.push(5);
	myStack.push(2);

	cout<<"Minimul este "<<myStack.getMin()<<endl;
	cout<<"Maximul este "<<myStack.getMax()<<endl;

	cout<<"Varful stivei este "<<myStack.peek()<<endl;
	cout<<"Scot din stiva "<<myStack.pop()<<endl;
    cout<<"Minimul devine "<<myStack.getMin()<<endl;
    cout<<"Maximul devine "<<myStack.getMax()<<endl;

    cout<<"Varful stivei este "<<myStack.peek()<<endl;
    cout<<"Scot din stiva "<<myStack.pop()<<endl;
    cout<<"Minimul devine "<<myStack.getMin()<<endl;
    cout<<"Maximul devine "<<myStack.getMax()<<endl;
    cout<<endl;

    */
    if (GasireCamera())
        cout<<"S-a gasit drumul catre camera!"<<endl;
    else
        cout<<"Nu s-a gasit drumul catre camera!"<<endl;

    /*
    PriorityQueue<int> q;
    q.enQueue(2);
    q.enQueue(5);
    q.enQueue(1);
    q.enQueue(3);
    cout<<endl<<q.deQueue();
    cout<<endl<<q.deQueue();
    cout<<endl<<q.deQueue();
    cout<<endl<<q.deQueue();
    */

    return 0;
}
