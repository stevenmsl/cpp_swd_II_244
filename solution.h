
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
namespace sol244
{
    class Solution
    {
    private:
        unordered_map<string, vector<int>> indexes;

    public:
        Solution(vector<string> &dict);
        int find(string w1, string w2);
    };
}
#endif