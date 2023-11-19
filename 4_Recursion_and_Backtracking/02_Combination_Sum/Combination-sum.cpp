class Solution {
  public:
    //TC : O(2^t * k) where t is the target, k is the average length
    //SC : O(k*x), k is the average length and x is the no. of combinations
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds); // takes linear time complexity
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) { //pick only when its less than target
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();//backtrack because if we don't take element out for not pick we will get wrong answer
      }

      //not pick
      findCombination(ind + 1, target, arr, ans, ds);
    }
    
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};