// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        isWord = false;
    }
};

class WordDictionary
{
private:
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];

            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }

            node = node->children[c];
        }

        node->isWord = true;
    }

    bool search(string word)
    {
        return searchHelper(root, word, 0);
    }

    bool searchHelper(TrieNode *node, string &word, int index)
    {
        if (index == word.length())
        {
            return node->isWord;
        }
        char c = word[index];
        if (c == '.')
        {
            for (auto &p : node->children)
            {
                if (searchHelper(p.second, word, index + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (node->children.find(c) == node->children.end())
            {
                return false;
            }
            TrieNode *child = node->children[c];
            return searchHelper(child, word, index + 1);
        }
    }
};

int main()
{

    WordDictionary *obj = new WordDictionary();

    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");

    bool param_1 = obj->search("pad");
    bool param_2 = obj->search("bad");
    bool param_3 = obj->search(".ad");
    bool param_4 = obj->search("b..");

    cout << param_1 << " " << param_2 << " " << param_3 << " " << endl;

    return 0;
}