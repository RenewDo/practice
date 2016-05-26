//Nested List Weight Sum
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
         int res =0;
         int level = 1;
         for(auto p : nestedList)
         {
                res += levelSum(p, level);
         }
         return res;
    }
    int levelSum(NestedInteger p, int level)
    {
         int res =0;
         if(p.isInterger()) return level*p.getInterger();
         for(auto i :p.getList())
         {
                 res += levelSum(i, level+1); 
         }
         return res;
    }
    
};

//Flatten Nested List Iterator
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    void dfs(NestedInteger p)
    {
         if(p.isInteger())
              list.push_back(p.getInteger());
         for(auto i : p.getList())
            dfs(i);
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i : nestedList)
             dfs(i);
        iter = 0;
    }

    int next() {
        return list[iter++];
    }

    bool hasNext() {
        if(iter<list.size())
        return true;
        else return false;
    }
private:
    vector<int> list;
    int iter;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
