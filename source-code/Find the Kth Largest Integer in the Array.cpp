class Solution
{
public:
  string kthLargestNumber(vector<string> &nums, int k)
  {
    auto myComp = [](string s1, string s2) {
      if (s1.length() == s2.length())
      {
        return s1 > s2;
      }
      return s1.length() > s2.length();
    };
    priority_queue<string, vector<string>, decltype(myComp)> pq(myComp); // min heap
    for (const auto &num : nums)
    {
      pq.push(num);
      if (pq.size() > k)
      {
        pq.pop();
      }
    }
    return pq.top();
  }
};
