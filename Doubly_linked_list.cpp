#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
    node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class dl{
    node* head;
public:
    dl() : head(nullptr) {}
    ~dl() { clear(); }

    void insert_front(int x){
        node* p = new node(x);
        p -> next = head;
        if(head) head -> prev = p;
        head = p;
    }

    void insert_end(int x){
        if(!head){
            head = new node(x);
            return;
        }
        node* p = head;
        while(p -> next){
            p = p -> next;
        }
        node* q = new node(x);
        p -> next = q;
        q -> prev = p;
    }

    void insert_pos(int k, int x){
        if(k <= 1 || !head){
            insert_front(x);
            return;
        }
        node* p = head;
        int i = 1;
        while(p && i < k - 1){
            p = p -> next;
            i++;
        }
        if(!p){
            insert_end(x);
            return;
        }
        node* q = new node(x);
        q -> next = p -> next;
        q -> prev = p;
        if(p -> next) p -> next -> prev = q;
        p -> next = q;
    }

    void delete_front(){
        if(!head) return;
        node* p = head;
        head = head -> next;
        if(head) head -> prev = nullptr;
        delete p;
    }

    void delete_end(){
        if(!head) return;
        if(!head -> next){
            delete head;
            head = nullptr;
            return;
        }
        node* p = head;
        while(p -> next && p -> next -> next){
            p = p -> next;
        }
        node* q = p -> next;
        p -> next = nullptr;
        delete q;
    }

    void delete_pos(int k){
        if(!head) return;
        if(k <= 1){
            delete_front();
            return;
        }
        node* p = head;
        int i = 1;
        while(p && i < k - 1){
            p = p -> next;
            i++;
        }
        if(!p || !p -> next) return;
        node* q = p -> next;
        p -> next = q -> next;
        if(q -> next) q -> next -> prev = p;
        delete q;
    }

    void delete_val(int x){
        if(!head) return;
        if(head -> val == x){
            delete_front();
            return;
        }
        node* p = head;
        while(p -> next && p -> next -> val != x){
            p = p -> next;
        }
        if(p -> next){
            node* q = p -> next;
            p -> next = q -> next;
            if(q -> next) q -> next -> prev = p;
            delete q;
        }
    }

    int search(int x) const{
        int i = 1;
        node* p = head;
        while(p){
            if(p -> val == x) return i;
            p = p -> next;
            i++;
        }
        return -1;
    }

    int kth(int k) const{
        if(k <= 0) return -1;
        int i = 1;
        node* p = head;
        while(p){
            if(i == k) return p -> val;
            p = p -> next;
            i++;
        }
        return -1;
    }

    int find_mid() const{
        if(!head) return -1;
        node* s = head;
        node* f = head;
        while(f && f -> next){
            s = s -> next;
            f = f -> next -> next;
        }
        return s -> val;
    }

    void reverse_list(){
        node* p = head;
        node* r = nullptr;
        while(p){
            node* q = p -> next;
            p -> next = r;
            p -> prev = q;
            if(r) r -> prev = p;
            r = p;
            p = q;
        }
        head = r;
    }

    void sort_list(){
        if(!head || !head -> next) return;
        bool ch = true;
        while(ch){
            ch = false;
            node* p = head;
            while(p && p -> next){
                if(p -> val > p -> next -> val){
                    int t = p -> val;
                    p -> val = p -> next -> val;
                    p -> next -> val = t;
                    ch = true;
                }
                p = p -> next;
            }
        }
    }

    void print() const{
        node* p = head;
        while(p){
            cout << p -> val;
            if(p -> next) cout << " ";
            p = p -> next;
        }
        cout << endl;
    }

    void clear(){
        node* p = head;
        while(p){
            node* q = p -> next;
            delete p;
            p = q;
        }
        head = nullptr;
    }
};

int main(){
    dl a;
    a.insert_front(3);
    a.insert_front(1);
    a.insert_end(5);
    a.insert_pos(2, 2);
    cout << "list: "; a.print();
    a.delete_front();
    cout << "after delete_front: "; a.print();
    a.delete_end();
    cout << "after delete_end: "; a.print();
    a.insert_end(4);
    a.insert_end(6);
    a.insert_end(7);
    cout << "list: "; a.print();
    a.delete_pos(3);
    cout << "after delete_pos(3): "; a.print();
    a.delete_val(6);
    cout << "after delete_val(6): "; a.print();
    cout << "search 4: " << a.search(4) << endl;
    cout << "kth 2: " << a.kth(2) << endl;
    cout << "mid: " << a.find_mid() << endl;
    a.insert_front(9);
    a.insert_front(0);
    a.insert_end(8);
    cout << "list: "; a.print();
    a.sort_list();
    cout << "after sort: "; a.print();
    a.reverse_list();
    cout << "after reverse: "; a.print();
    return 0;
}
