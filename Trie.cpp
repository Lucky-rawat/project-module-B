#include <iostream>
#include <unordered_map>
using namespace std;
struct Trie
{    bool isLeaf;
    unordered_map<char, Trie*> map;
};
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isLeaf = false;

    return node;
}
void insert(Trie*& head, char* str)
{
    if (head == nullptr) {
        head = getNewTrieNode();
    }
    Trie* curr = head;
    while (*str)
    {
        if (curr->map.find(*str) == curr->map.end()) {
            curr->map[*str] = getNewTrieNode();
        }
        curr = curr->map[*str];
        str++;
    }
    curr->isLeaf = true;
}
bool haveChildren(Trie const* curr)
{    for (auto it: curr->map)
    {if (it.second != nullptr) {
            return true;
        }
    }
    return false;
}
bool deletion(Trie*& curr, char* str)
{
    if (curr == nullptr) {
        return false;
    }
    if (*str)
    {        if (curr != nullptr && curr->map.find(*str) != curr->map.end() &&
            deletion(curr->map[*str], str + 1) && curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
    if (*str == '\0' && curr->isLeaf)
    {        if (!haveChildren(curr))
        {
            delete curr;
            curr = nullptr;
            return true;
        }
        else {
            curr->isLeaf = false;
            return false;
        }
    }
    return false;
}
bool search(Trie* head, char* str)
{    if (head == nullptr) {
        return false;
    }
    Trie* curr = head;
    while (*str)
    {   curr = curr->map[*str];
        if (curr == nullptr) {
            return false;
        }
        str++;
    }
    return curr->isLeaf;
}
int main()
{
    Trie* head = nullptr;

    insert(head, "hello");
    cout << search(head, "hello") << " ";

    insert(head, "helloworld");
    cout << search(head, "helloworld") << " ";

    cout << search(head, "helow") << " ";
    insert(head, "hell");
    cout << search(head, "hell") << " ";

    insert(head, "h");
    cout << search(head, "h") << endl;

    deletion(head, "hello");
    cout << search(head, "hello") << " ";
    cout << search(head, "helloworld") << " ";
    cout << search(head, "hell") << endl;

    deletion(head, "h");
    cout << search(head, "h") << " ";
    cout << search(head, "hell") << " ";
    cout << search(head, "helloworld") << endl;

    deletion(head, "helloworld");
    cout << search(head, "helloworld") << " ";
    cout << search(head, "hell") << " ";

    deletion(head, "hell");
    cout << search(head, "hell") << endl;

    if (head == nullptr) {
        cout << "Trie empty!!\n";
    }

    cout << search(head, "hell");

    return 0;
}


