#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        memset(child,NULL,sizeof(child));
    }
};
void insert(string &s,TrieNode* root){
    TrieNode* curr = root;
    for(char c : s){
        int indx = c-'a';
        if(curr->child[indx] == NULL){
            curr->child[indx] = new TrieNode();
        }
        curr = curr->child[indx];
    }
    curr->isEnd = true;
}
bool search(string &s,TrieNode* root){
    TrieNode* curr = root;
    for(char x : s){
        int indx = x -'a';
        if(curr->child[indx] == NULL)
            return false;
        curr = curr->child[indx];
    }
    return curr->isEnd;

}
int main(){
    int n,q; cin>>n>>q;
    TrieNode* root = new TrieNode;
    while(n--){
        string s; cin>>s;
        insert(s,root);}
    while(q--){
        string q; cin>>q;
        if(search(q,root)) cout<<1<<endl;
        else cout<<0<<endl;

    }    
}


  
