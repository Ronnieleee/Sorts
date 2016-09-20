// #############################################################################
// # FileName:  Merge.cpp
// # Author:    Lonely, CS0901, HUST
// #############################################################################
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// # sorting algorithm begin
// #############################################################################
template<typename DataType> class MergeSorter
{
public:
    static void sort(vector<DataType>& elements)
    {
        recursiveMergeSort(elements, 0, elements.size() - 1);
        return;
    }
private:
    static void recursiveMergeSort(vector<DataType>& elements, int left, int right)
    {
        vector<DataType> sortedList;
        int middle, leftScanPos, rightScanPos;

        if(left < right)
        {
            middle = (left + right) / 2;
            recursiveMergeSort(elements, left, middle);
            recursiveMergeSort(elements, middle + 1, right);

            leftScanPos = left, rightScanPos = middle + 1;
            sortedList.reserve(right - left + 1);

            while(leftScanPos <= middle && rightScanPos <= right)
                if(elements.at(leftScanPos) < elements.at(rightScanPos))
                    sortedList.push_back(elements.at(leftScanPos++));
                else
                    sortedList.push_back(elements.at(rightScanPos++));
            while(leftScanPos <= middle)
                sortedList.push_back(elements.at(leftScanPos++));
            while(rightScanPos <= right)
                sortedList.push_back(elements.at(rightScanPos++));

            for(int i = left; i <= right; i++)
                elements.at(i) = sortedList.at(i - left);
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
    MergeSorter<int>::sort(elements);

    // write sorted data to output stream
    for(int i = 0; i < n; i++)
        printf("%d\n", elements.at(i));;

    return 0;
}
// #############################################################################
// # EOF
