// #############################################################################
// # FileName:  Selection.cpp
// # Author:    Lonely, CS0901, HUST
// #############################################################################
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// # sorting algorithm begin
// #############################################################################
template<typename DataType> class SelectionSorter
{
public:
    static void sort(vector<DataType>& elements)
    {
        int insertPos, minPos;

        for(insertPos = 0; insertPos < elements.size(); insertPos++)
        {
            minPos = insertPos;
            for(int i = insertPos + 1; i < elements.size(); i++)
                if(elements.at(i) < elements.at(minPos))
                    minPos = i;
            swap(elements.at(insertPos), elements.at(minPos));
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
    SelectionSorter<int>::sort(elements);

    // write sorted data to output stream
    for(int i = 0; i < n; i++)
        printf("%d\n", elements.at(i));;

    return 0;
}
// #############################################################################
// # EOF
