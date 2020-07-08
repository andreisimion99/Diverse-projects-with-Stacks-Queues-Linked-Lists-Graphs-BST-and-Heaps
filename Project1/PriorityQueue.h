#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

using namespace std;

template<typename T>
class PriorityQueue
{
    AdvancedStack<T> s1, s2;

public:
    void enQueue(T x);
    T deQueue();
};

template<typename T>
void PriorityQueue<T>::enQueue(T x)
{
    s1.push(x);
}

template<typename T>
T PriorityQueue<T>::deQueue()
{
    if (s1.isEmpty() && s2.isEmpty())
    {
        cout<<"COADA ESTE GOALA"<<endl;
        return 0;
    }
    if (s2.isEmpty())
    {
        while(!s1.isEmpty())
        {
            s2.push(s1.peek());
            s1.pop();
        }
    }
    int x=s2.peek();
    s2.pop();
    return x;
}


#endif // PRIORITYQUEUE_H_INCLUDED
