class Solution
{
    public:
    vector<int> levelOrder(Node* node)
    {
      vector <int> retVector;
      queue <Node*> contain;
      contain.push (node);
      Node* temp;
      while (!contain.empty())
      {
        temp = contain.front();
        retVector.push_back (temp -> data);
        if (temp -> left)
            contain.push (temp -> left);
        if (temp -> right)
            contain.push (temp -> right);
        contain.pop();
      }
      return retVector;
    }
};