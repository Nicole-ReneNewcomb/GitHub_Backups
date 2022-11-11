/*Nicole-Rene's code modifications for Assignment: Stack*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isDyckWord(vector<int> w);

int main()
{
    // vector<int> w({ +1,-1,+1,-1 }); //Sample 1
    // vector<int> w({+1,-1,-1,+1 }); //sample 2

    // program seems to be working based on my sample testing
    vector<int> nicolesVector({ +1, +1, +1, -1, -1, -1, +1, -1, +1, +1, -1, -1 });

    if (isDyckWord(nicolesVector))
        cout << " The given input is a Dyck word\n";
    else
        cout << "... The given input is not a Dyck word\n";
}

bool isDyckWord(vector<int> w)
{
    stack<int> theStack;
    int number = int();
    bool theTruth = bool();
    int accumulator = 0;

    while (w.size() > 0)
    {
        number = w[w.size() - 1];
        theStack.push(number);
        w.pop_back();
    }

    while (!theStack.empty())
    {
        accumulator += theStack.top();

        if (accumulator < 0)
        {
            theTruth = false;
            return theTruth;
        }

        theStack.pop();
    }

    theTruth = true;
    return theTruth;
}