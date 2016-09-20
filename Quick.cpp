// #############################################################################
// # FileName:  Quick.cpp
// # Author:    Lonely, CS0901, HUST
// #############################################################################
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// # sorting algorithm begin
// #############################################################################
template<typename DataType> class QuickSorter
{
public:
    static void sort(vector<DataType>& elements)
    {
        if(!elements.empty())
            recursiveQuickSort(elements, 0, elements.size() - 1);
        return;
    }
private:
    static void recursiveQuickSort(vector<DataType>& elements, int left, int right)
    {
        DataType pivot;
        int leftPointer = left, rightPointer = right;
        int middle = (left + right) / 2;

        if(left < right)
        {
            (elements.at(left) > elements.at(middle)) && (swap(elements.at(left), elements.at(middle)), 0);
            (elements.at(left) > elements.at(right)) && (swap(elements.at(left), elements.at(right)), 0);
            (elements.at(middle) > elements.at(right)) && (swap(elements.at(middle), elements.at(right)), 0);

            pivot = elements.at((middle));
            while(leftPointer <= rightPointer)
            {
                while(elements.at(leftPointer) < pivot)
                    leftPointer++;
                while(elements.at(rightPointer) > pivot)
                    rightPointer--;
                if(leftPointer <= rightPointer)
                    swap(elements.at(leftPointer++), elements.at(rightPointer--));
            }
            recursiveQuickSort(elements, left, rightPointer);
            recursiveQuickSort(elements, leftPointer, right);
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
    scanf("%d", &n) == 1 || (exit(-1), 0);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data) != 1 && (exit(-1), 0);
        elements.push_back(data);
    }

    // sort elements
    QuickSorter<int>::sort(elements);

    // write sorted data to output stream
    for(int i = 0; i < n; i++)
        printf("%d\n", elements.at(i));

    return 0;
}
// #############################################################################
// # EOF
