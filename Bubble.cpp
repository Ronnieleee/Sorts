// #############################################################################
// # FileName:  Bubble.cpp
// # Author:    Lonely, CS0901, HUST
// #############################################################################
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// # sorting algorithm begin
// #############################################################################
template<typename DataType> class BubbleSorter
{
public:
    static void sort(vector<DataType>& elements)
    {
        int i, sorted = 0, noswap = 0;

        while(!noswap)
        {
            for(noswap = 1, i = 1; i < elements.size() - sorted; i++)
                if(elements.at(i - 1) > elements.at(i))
                    swap(elements.at(i - 1), elements.at(i)), noswap = 0;
            sorted++;
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
    BubbleSorter<int>::sort(elements);

    // write sorted data to output stream
    for(int i = 0; i < n; i++)
        printf("%d\n", elements.at(i));;

    return 0;
}
// #############################################################################
// # EOF
