#include <iostream>
#include <vector>
using namespace std;

class trieNode
{
public:
    char value;
    trieNode *children[26];
    bool isTerminal;

    trieNode(char val)
    {
        this->value = val;
        // mistakes remeber 
        // for (int i = 0; i < 25; i++)
        for(int i = 0; i<26;i++)
        {
            children[i] = 0; // null
        }
        this->isTerminal = false;
    }
};




void insertWord(trieNode *root, string word)
{
    // cout<<"word is to be insert:" <<word<<endl;
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    trieNode *child;
    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // absent
        child = new trieNode(ch);
        root->children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1));
}








bool searchWord(trieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    trieNode *child;
    if (root->children[index] != NULL)
    {
        // child present
        child = root->children[index];
    }
    else
    {
        return false;
    }
    // recursion
    bool recursionAns = searchWord(child, word.substr(1));
    return recursionAns;
}

// do not erase just marks false terminal
void deletehWord(trieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }
    // 1 case mera
    char ch = word[0];
    int index = ch - 'a';
    trieNode *child;

    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // not present
        return;
    }
    // baki recursion
    deletehWord(child, word.substr(1));
}

void storeString(trieNode *root, vector<string> &ans, string &input, string &prefix)
{

    // base case
    if (root->isTerminal == true)
    {

        ans.push_back(prefix + input);

        // no need to return coz there might be more string is present to traverse
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {

        // phle index nikal lo
        int index = ch - 'a';
        // root ke children ke index pr chale jao
        trieNode *next = root->children[index];
        if (next != NULL)
        {
            // child exist------ non null child

            input.push_back(ch); // character store kr liye
            // baki recursion ko de diya

            storeString(next, ans, input, prefix);

            // backtrack krte hue aao

            input.pop_back();
        }
    }
}

void findprefix(trieNode *root, string input, vector<string> &ans, string &prefix)
{

    // base case
    if (input.length() == 0)
    {

        trieNode *lastchar = root;
        storeString(lastchar, ans, input, prefix);

        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    trieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }
    // recursive call
    findprefix(child, input.substr(1), ans, prefix);
}


int main()
{
    trieNode *root = new trieNode('-');
    

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    // cout<<"insertion is done"<<endl;

    // deletehWord(root,"lov");
    // string word = "lov";
    // if(searchWord(root,word)){
    //     cout<<"found"<<endl;
    // } else{
    //     cout<<"not found"<<endl;
    // }

    string input = "ca";
    string prefix = input;
    vector<string> ans;
    findprefix(root, input, ans, prefix);
    // cout<<"JHELLO";

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}