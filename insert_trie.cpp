#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    string data;
    bool terminal;
    unordered_map<char,Node*> next;
    Node(char data){
        this->data = data;
        this->terminal = false;
    }
};
class Trie{
public:
    Node *root;
    int count_t;
    Trie(){
        this->root=new Node('\0');
    }
    void addString(string s){
        Node *temp = root;
        for(char a:s){
            if(temp->next.count(a)){
                temp = temp->next[a];
            }else{
                Node *t = new Node(a);
                temp->next[a] = t;
                temp = t;
            }
        }
        temp->terminal = true;
    }
    void searchTrie(string s){
        Node *temp = root;
        for(auto a:s){
            if(temp->next.count(a)){
                temp=temp->next[a];
            }else{
                cout<<"Not find"<<endl;
                return;
            }
        }
        if(temp->terminal == true){
            cout<<"Find "<<endl;
        }else{
            cout<<"Not found"<<endl;
        }

    }
    void print_trie_util(Node *node,string s,int level){
        s.insert(level,node->data);
        if(node->terminal){
            cout<<s<<endl;
        }
        unordered_map<char,Node*>::iterator it;
        for(it = node->next.begin();it!=node->next.end();it++){
            print_trie_util(it->second,s,level+1);
        }

    }
    void print_trie(){
        Node *temp=root;
        string s;
        unordered_map<char,Node*>::iterator it;
        for(it = temp->next.begin();it!=temp->next.end();it++){
            print_trie_util(it->second,s,0);

            cout<<endl;
        }
    }
};
int main()
{
    Trie t;

    t.addString("bhola");
    t.addString("gaurav");
    t.addString("rupendra");
    t.addString("siddharth");
    t.addString("ravi");
    t.addString("raju");
    t.addString("rajiv");
    t.addString("rahul rathi");
    //t.searchTrie("siddharthsss");
    t.print_trie();
}
