#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    int wordend;
    TrieNode *childnode[26];
    TrieNode()
    {
        wordend = 0;
        for (int i = 0; i < 26; i++)
        {
            childnode[i] = NULL;
        }
    }
};

void insert(TrieNode *root, string str)
{
    TrieNode *temp = root;
    for (auto ch : str)
    {
        if (temp->childnode[ch - 'a'] == NULL)
        {
            TrieNode *newnode = new TrieNode();
            temp->childnode[ch - 'a'] = newnode;
        }
        temp = temp->childnode[ch - 'a'];
        temp->wordend += 1; // This is for Prefix count
    }
    // temp->wordend = 1; // This is for search and delete operation
}

bool search(TrieNode *root, string str)
{
    TrieNode *temp = root;
    for (auto ch : str)
    {
        if (temp->childnode[ch - 'a'] == NULL)
            return false;
        temp = temp->childnode[ch - 'a'];
    }
    return temp->wordend == 1;
}

void del(TrieNode* root, string str){
    TrieNode* temp = root;
    for(auto ch: str){
        if(temp->childnode[ch - 'a'] == NULL) return;
        temp = temp->childnode[ch - 'a'];
    }
    temp->wordend = 0;
}

int prefcnt(TrieNode* root, string str){
    TrieNode* temp = root;
    for(auto ch: str){
        if(temp->childnode[ch - 'a'] == NULL) return 0;
        temp = temp->childnode[ch - 'a'];
    }
    return temp->wordend;
}

int main()
{

    TrieNode *root = new TrieNode();
    vector<string> inputStrings = {"aand", "aandd", "aadd", "aannd", "aad", "a"};
    for (int i = 0; i < inputStrings.size(); i++)
        insert(root, inputStrings[i]);
    // if(search(root, "and")) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    // del(root, "and");
    // if(search(root, "and")) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    cout<<prefcnt(root, "aan")<<endl;
    return 0;
}
