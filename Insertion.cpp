// #############################################################################
// # FileName:  Insertion.cpp
// # Author:    Lonely, CS0901, HUST
// #############################################################################
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// # sorting algorithm begin
// #############################################################################
template<typename DataType> class InsertionSorter
{
public:
    static void sort(vector<DataType>& elements)
    {
        int insertPos;

        for(int i = 1; i < elements.size(); i++)
        {
            DataType temp = elements.at(i);
            for(insertPos = i; insertPos > 0 && temp < elements.at(insertPos - 1); insertPos--)
                elements.at(insertPos) = elements.at(insertPos - 1);
            elements.at(insertPos) = temp;
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
    InsertionSorter<int>::sort(elements);

    // write sorted data to output stream
    for(int i = 0; i < n; i++)
        printf("%d\n", elements.at(i));;

    return 0;
}
// #############################################################################
// # EOF
