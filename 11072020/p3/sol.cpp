#include <iostream>
#include <vector>
#include <string>

#define MODN 1000000007

using namespace std;

class atom{
public:
    atom(){
     isLeaves = 0;
     sum = 0;   
    }
    
    atom(int label){
     sum = label;
     isLeaves = 1;
    }
    void apply(){
       
    } 
    int isLeaves;
    int sum; 
};

class node{
public:
    atom d;
    node * left,*right;
    node() : d(), left(nullptr), right(nullptr){
        
    }
    node(node *left, node * right) : d() {
        this->left = left;
        this->right = right;
        this->update();
    }
    node(int label) : d(label) , left(nullptr), right(nullptr) {
     
    }
    node(node *left, node * right, int label) : d(label) {
        this->left = left;
        this->right = right;

    }
    void passdown(){
    }
    void update(){
        if(this->d.isLeaves == 1)
            return;
        int sum = 0;
        if(this->left != nullptr)
            sum += this->left->d.sum;
        if(this->right != nullptr)
            sum += this->right->d.sum;
        this->d.sum = sum;
    }
};
vector<int> instructions;
node * build(int l, int r){
    if(l > r)
        return nullptr;
    if(l == r){
        return new node(0);
    }
    int mid = (l+r)>>1;
    node * nd = new node(build(l,mid), build(mid+1,r));
    return nd;
}


void inc(node * c, int l, int r, int x){
    if(l > r)   return;
    if(l == r){
        if(x == l){
            ++c->d.sum;
        }
        return;
    }
    c->passdown();
    int mid = (l+r)>>1;
    if(x <= mid)
        inc(c->left, l, mid, x);
    else
        inc(c->right, mid+1, r, x);
    c->update();
}

int get(node * c, int l, int r, int ll, int rr){
    if(l > r)
        return 0;
    if(l == r){
        if(ll <= l && r <= rr){
            return c->d.sum;
        }
        return 0;
    }
    c->passdown();
    if(ll <= l && r <= rr)
    {
        return c->d.sum;
    }
    int mid = (l+r)>>1;
    int sum = 0;
    if(mid >= ll)
        sum += get(c->left,l,mid,ll,rr);
    if(mid + 1 <= rr)
        sum += get(c->right,mid+1,r,ll,rr);
    return sum;
}


#define MODN 1000000007
int main()
{
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int wmax = 0;
    while(!cin.eof()){
        int x;
        cin >> x;
        instructions.push_back(x);
    }
    for(int i = 0; i<instructions.size(); ++i)
            wmax = max(wmax,instructions[i]);
    node * root = build(1,wmax);
    int ans = 0;
    for(int i = 0; i<instructions.size(); ++i){
        int x= instructions[i];
        int strictless = 0,strictgreater = 0;
        if(x-1 >= 1)
           strictless= get(root,1,wmax,1,x-1);
        if(x+1 <= wmax)
            strictgreater = get(root,1,wmax,x+1,wmax);
        cout << strictgreater << " "<<strictless<<endl;
        int mbetween = min(strictgreater,strictless);
        ans = (ans + mbetween)%MODN;
        inc(root,1,wmax, x);
    }
    cout << ans <<endl;
    return 0;
}