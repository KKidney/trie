#include <iostream>
#include <unordered_set>

using namespace std;


struct Node
{
public:
  Node(): mChar('~'), mCount(0){}
  Node(char ch): mChar(ch), mCount(1){}

  Node* find(char ch)
  {
    cout << "mSet Size " << mSet.size() << endl;
    for(auto it = mSet.begin(); it != mSet.end(); ++it)
    {
        cout << "find " << ch << " Looking at " << (*it)->mChar << endl;
        if ((*it)->mChar == ch)
          return *it;
    }
    return (Node*)0;
  }

  Node* add(char ch)
  {
    // First, see if the character exists
    Node* node = find(ch);
    if (node != 0)
    {
      cout << "found " << ch << endl;
      // Increment the count and return the same node
      node->mCount++;
      //printTrie();
      return node;
    }
    else
    {
      cout << "new Node for char " << ch << endl;
      Node* newNode = new Node(ch);
      mSet.insert(newNode);
      return newNode;
    }
  }

  void printTrie()
  {
    cout << "char " << mChar << " " << mCount << endl;
    for(auto it = mSet.begin(); it != mSet.end(); ++it)
    {
      (*it)->printTrie();
    }
  }


  unordered_set<Node*>  mSet;
  char mChar;
  int mCount;
};

// Add the string to the appropriate nodes and increment the counter for each instance
void addString(Node* root, string str)
{
  // For each char in the string, we either need to add another node or increase
  // the count of an existing nodes
  Node* nextNode = root;
  for (int i = 0; i < str.size(); i++)
  {
    nextNode = nextNode->add(str[i]);
  }
  root->printTrie();
}

int findString(string str)
{

}

int main()
{
  Node* root = new Node;
  // Input- N is the number of operations to follow
  //        add string adds a string to the trie
  //        find string search for the string

  // Input section
  int opCount;
  cin >> opCount;

  string action;
  string str;

  for (int i = 0; i < opCount; i++)
  {
    cin >> action >> str;
    if (action == "add")
      addString(root, str);
    else if(action == "find")
      cout << findString(str);
  }
}
