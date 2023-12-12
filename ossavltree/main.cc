#include <iostream>
#include "set.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--)
    {
        int t2;
        cin >> t2;
        Int_AVLtree_set set;
        string s;
        while (t2--)
        {
            cin >> s;
            int tmp;
            if (s == "insert")
            {
                cin >> tmp;
                set.Insert(tmp);
            }
            else if (s == "find")
            {
                cin >> tmp;
                set.Find(tmp);
            }
            else if (s == "minimum")
            {
                cin >> tmp;
                set.Minimum(tmp);
            }
            else if (s == "maximum")
            {
                cin >> tmp;
                set.Maximum(tmp);
            }
            else if (s == "empty")
            {
                set.Empty();
            }
            else if (s == "size")
            {
                set.Size();
            }
            else if (s == "rank")
            {
                cin >> tmp;
                set.Rank(tmp);
            }
            else if (s == "erase")
            {
                cin >> tmp;
                set.Erase(tmp);
            }
        }
    }
}