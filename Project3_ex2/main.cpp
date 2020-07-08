#include <iostream>
#include <fstream>

using namespace std;

//clasa Heap
class Heap
{
private:
	//elementele Heap-ului
	int* _elem;  // pointer la vectorul de elemente
	int _dimensiuneHeap; // nr elemente existente in structura

public:
	Heap(int* elemente, int nrElem) : _dimensiuneHeap(nrElem)
	{
		_elem = new int[nrElem]; //alocam memorie pt vectorul din heap
		for (int i = 0; i < _dimensiuneHeap; i++)
		{
			_elem[i] = elemente[i];
		}
		for (int i = (_dimensiuneHeap - 2) / 2; i >= 0; i--)
		{
			Filtrare(i);
		}
	}

	~Heap()
	{
		delete[] _elem;
	}
};

void Filtrare(int index)
{
    int indexMax = index;
    int indexStanga = 2 * index + 1;
    int indexDreapta = 2 * index + 2;
    if (index < _dimensiuneHeap)
    {
        if (indexStanga < _dimensiuneHeap && _elem[indexStanga] >= _elem[indexMax])
            indexMax = indexStanga;
        if (indexDreapta < _dimensiuneHeap && _elem[indexDreapta] >= _elem[indexMax])
            indexMax = indexDreapta;
        if (index != indexMax)
        {
            //se face o interschimbare
            Interschimbare(indexMax, index);
            if (indexMax <= (_dimensiuneHeap - 2) / 2)
            {
                Filtrare(indexMax);
            }
        }
    }
}

//FUNCTIE de interschimbare intre parinte si copil
void Interschimbare(int index1, int index2)
{
    int temp;
    temp = _elem[index1];
    _elem[index1] = _elem[index2];
    _elem[index2] = temp;
}

//extragere
int extractValue()
{
    int result = _elem[0];
    int* temp = new int[_dimensiuneHeap - 1];
    int i;

    for (i = 1; i < _dimensiuneHeap; i++)
    {
        temp[i - 1] = _elem[i];
    }
    delete[] _elem;
    _elem = temp;
    _dimensiuneHeap--;
    for (i = (_dimensiuneHeap - 2) / 2; i >= 0; i--)
    {
        Filtrare(i);
    }
    return result;
}
