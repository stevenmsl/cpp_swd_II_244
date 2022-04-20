#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol244;
using namespace std;

/*takeaways
  - comparing to 243, the main difference is that
    the find method will be called many times
    which means we need to come up the data
    structures that will speed up the find
    method
  - use map with value being a vector
    that stores the indexes of the
    occurrences of a word in ascending
    order

*/

Solution::Solution(vector<string> &dict)
{
  for (auto i = 0; i < dict.size(); i++)
    /* store the indexes in descending order
       for a given word
    */
    indexes[dict[i]].push_back(i);
}

int Solution::find(string w1, string w2)
{
  auto dist = INT_MAX;
  auto w1Indxs = indexes[w1];
  auto w2Indxs = indexes[w2];

  for (auto i = 0, j = 0; i < w1Indxs.size() && j < w2Indxs.size();)
  {
    dist = min(dist, abs(w1Indxs[i] - w2Indxs[j]));
    /* w1 is on the left of w2
       - picking another w2 index that is larger
         than the current one won't help shorten
         the distance
       - we need to move on to try the next w1 index
    */
    if (w1Indxs[i] < w2Indxs[j])
      i++;
    /* w1 is on the right of w2
       - try the next index of w2
         - it might come closer to w1
           or walk pass the current
           w1 index - we need to find
           out if this can yield a
           shorter distance
    */
    else
      j++;
  }

  return dist;
}