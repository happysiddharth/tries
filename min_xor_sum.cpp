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

int find_min_xor(trie *head,int element){
    int current_xor = INT_MIN;
    int xor_ = 0;
    for(int i=31;i>=0;i--){
        int a = (element >> i) & 1;
        if(a==1){
            if(head->right!=NULL){
                head=head->right;
            }else{
                 xor_ += (int)pow(2,i);
                head = head->left;
            }
        }else{
            if(head->left!=NULL){
                head = head->left;
            }else{
                xor_+=(int)pow(2,i);
                head = head->right;
            }
        }
    }
    return max(current_xor,xor_);
}

int main()
{

    int ar[3] = {3,7,2};
    trie * head = new trie();
    int result=INT_MIN;
    insert_in_trie(head,ar[0]);
    for(int i=1;i<3;i++){

         int newres = find_min_xor(head,ar[i]);
         insert_in_trie(head,ar[i]);
         result = newres > result ? newres:result;
    }
    cout<<result;
}
