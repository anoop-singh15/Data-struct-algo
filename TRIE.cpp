#include <iostream>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
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
        for (int i = 0; i < word.size(); i++)
        {
            // node does not contain letter
            if (node->containsKey(word[i]) != true)
            {
                node->put(word[i], new Node());
            }
            // if contain then
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])!=true)
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(node->containsKey(prefix[i]))
            {
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;

    }
};

int main()
{
    Trie t;
    t.insert("apple");
    t.insert("appxl");
    cout<<t.search("abc")<<endl;
    return 0;
}