#include<bits/stdc++.h>
using namespace std;
class trie{
public:
    trie *left;//to store 0
    trie *right;//to store 1
};

void insert_in_trie(trie *head,int element){
    for(int i=31;i>=0;i--){
        int a = (element>>i)&1;
        if(a==1){
            if(head->right==NULL){
                head->right = new trie();
            }
            head = head->right;
        }else{
            if(head->left == NULL){
                head->left = new trie();
            }
            head = head->left;
        }
    }
}

int find_max_xor(trie *head,int element){
    int current_xor = INT_MIN;
    int xor_ = 0;
    for(int i=31;i>=0;i--){
        int a = (element >> i) & 1;
        if(a==1){
            if(head->left!=NULL){
                xor_+=(int)pow(2,i);
                head=head->left;
            }else{
                head = head->right;
            }
        }else{
            if(head->right!=NULL){
                xor_+=(int)pow(2,i);
                head = head->right;
            }else{
                head = head->left;
            }
        }
    }
    return max(current_xor,xor_);
}

int main()
{

    int ar[5] = {1,2,3};
    trie * head = new trie();
    int result=INT_MIN;
    for(int i=0;i<3;i++){
        insert_in_trie(head,ar[i]);
         int newres = find_max_xor(head,ar[i]);
         result = newres > result ? newres:result;
    }
    cout<<result;
}
