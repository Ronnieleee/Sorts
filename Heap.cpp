// #############################################################################
// # FileName:  Heap.cpp
// # Author:    Lonely, CS0901, HUST
// #############################################################################
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// # sorting algorithm begin
// #############################################################################
template<typename DataType> class HeapSorter
{
public:
    static void sort(vector<DataType>& elements)
    {
        if(elements.size() > 1)
        {
            for(int i = (elements.size() - 1) / 2; i >= 0; i--)
                heapify(elements, i, elements.size() - 1);

            for(int i = elements.size() - 1; i > 0; i--)
            {
                swap(elements[0], elements[i]);
                heapify(elements, 0, i - 1);
            }
        }
        return;
    }
private:
    static void heapify(vector<DataType>& elements, int root, int bottom)
    {
        int maxChild, currentRoot = root;

        while(currentRoot < bottom)
        {
            maxChild = currentRoot;

            for(int child = (currentRoot * 2 + 1); child <= (currentRoot * 2 + 2); child++)
                if(child <= bottom && elements.at(child) > elements.at(maxChild))
                    maxChild = child;
            if(maxChild != currentRoot)
            {
                swap(elements.at(maxChild), elements.at(currentRoot));
                currentRoot = maxChild;
            }
            else break;
        }
        return;
    }
};
// #############################################################################
// # sorting algorithm end

int main(int argc, char** argv)
{
    int n;
    int data;
    vector<int> elements;

    // read data from input stream
    scanf("%d", &n) != 1 && (exit(-1), 0);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data) != 1 && (exit(-1), 0);
        elements.push_back(data);
    }

    // sort elements
    HeapSorter<int>::sort(elements);

    // write sorted data to output stream
    for(int i = 0; i < n; i++)
        printf("%d\n", elements.at(i));;

    return 0;
}
// #############################################################################
// # EOF
