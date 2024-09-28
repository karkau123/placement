#include <bits/stdc++.h>
using namespace std;
struct Node
{
  Node *links[26];
  bool flag = false;
};
class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      if (!node->links[ch - 'a'] != NULL)
      {
        Node *newnode = new Node();
        node->links[ch - 'a'] = newnode;
      }
      node = node->links[ch - 'a'];
    }
    node->flag = true;
  }

  bool search(string word)
  {
    Node *node = root;

    for (int i = 0; i < word.size(); i++)
    {
      char ch = word[i];
      if (node->links[ch - 'a'] == NULL)
        return false;
      node = node->links[ch - 'a'];
    }
    return node->flag;
  }

  bool startswith(string prefix)
  {
    Node *node = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      char ch = prefix[i];
      if (node->links[ch - 'a'] == NULL)
        return false;
      node = node->links[ch - 'a'];
    }
    return true;
  }
};
int main()
{

  return 0;
}
