#include <iostream>

using namespace std;

struct Node
{
    Node *links[26];
    int countPrefix = 0;
    int countEndsWith = 0;
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

    void increaseEnd()
    {
        countEndsWith++;
    }
    void increasePrefix()
    {
        countPrefix++;
    }
    void deleteEnd()
    {
        countEndsWith--;
    }
    void reducePrefix()
    {
        countPrefix--;
    }

    int getEnd()
    {
        return countEndsWith;
    }

    int getPrefix()
    {
        return countPrefix;
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
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])!=true)
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
       
    }

    int countWordsEqualTo(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])!=true)
            {
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])!=true)
            {
                return 0;
            }
            node=node->get(word[i]);

        }
        return node->getPrefix();
    }


    void erase(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])!=true)
            {
                return;
            }
            else 
            {
                node=node->get(word[i]);
                node->reducePrefix();
            }
        }
        node->deleteEnd();
    }

   
};

int main()
{
    Trie t;
    t.insert("apple");
    t.insert("apple");
    t.insert("appxl");
    t.insert("a");


    cout << t.countWordsEqualTo("abc") << endl;


    cout << t.countWordsEqualTo("apple") << endl;
    
    // 1 apple erase 
    t.erase("apple");
    
    cout << t.countWordsEqualTo("apple") << endl;
    cout << t.countWordsStartingWith("a") << endl;
    
    // cout << t.search("abc") << endl;
    
    // cout << t.search("abc") << endl;
    // cout << t.search("abc") << endl;
    return 0;
}