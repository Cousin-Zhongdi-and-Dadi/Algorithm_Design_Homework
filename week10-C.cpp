#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int l, r, fa;
}tree[100005];

void preorder(int t){
    printf("%d ", t);
    if(tree[t].l != 0){
        preorder(tree[t].l);
    }
    if(tree[t].r != 0){
        preorder(tree[t].r);
    }
}

void inorder(int t){
    if(tree[t].l != 0){
        inorder(tree[t].l);
    }
    printf("%d ", t);
    if(tree[t].r != 0){
        inorder(tree[t].r);
    }
}   

void postorder(int t){
    if(tree[t].l != 0){
        postorder(tree[t].l);
    }
    if(tree[t].r != 0){
        postorder(tree[t].r);
    }
    printf("%d ", t);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        tree[i].l = l;
        tree[i].r = r;
        if(l != 0){
            tree[l].fa = i;
        }
        if(r != 0){
            tree[r].fa = i;
        }
    }
    preorder(1);
    printf("\n");
    inorder(1);
    printf("\n");
    postorder(1);
    printf("\n");
    return 0;
}