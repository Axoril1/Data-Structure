#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
    node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class cdl{
    node* head;
public:
    cdl() : head(nullptr) {}
    ~cdl() { clear(); }

    void insert_front(int x){
        if(!head){
            head = new node(x);
            head -> next = head;
            head -> prev = head;
            return;
        }
        node* t = head -> prev;
        node* p = new node(x);
        p -> next = head;
        p -> prev = t;
        t -> next = p;
        head -> prev = p;
        head = p;
    }

    void insert_end(int x){
        if(!head){
            head = new node(x);
            head -> next = head;
            head -> prev = head;
            return;
        }
        node* t = head -> prev;
        node* p = new node(x);
        p -> prev = t;
        p -> next = head;
        t -> next = p;
        head -> prev = p;
    }

    void insert_pos(int k, int x){
        if(k <= 1 || !head){
            insert_front(x);
            return;
        }
        node* p = head;
        int i = 1;
        while(p -> next != head && i < k - 1){
            p = p -> next;
            i++;
        }
        node* q = new node(x);
        q -> next = p -> next;
        q -> prev = p;
        p -> next -> prev = q;
        p -> next = q;
    }

    void delete_front(){
        if(!head) return;
        if(head -> next == head){
            delete head;
            head = nullptr;
            return;
        }
        node* t = head -> prev;
        node* p = head;
        head = head -> next;
        head -> prev = t;
        t -> next = head;
        delete p;
    }

    void delete_end(){
        if(!head) return;
        if(head -> next == head){
            delete head;
            head = nullptr;
            return;
        }
        node* t = head -> prev;
        node* p = t -> prev;
        p -> next = head;
        head -> prev = p;
        delete t;
    }

    void delete_pos(int k){
        if(!head) return;
        if(k <= 1){
            delete_front();
            return;
        }
        node* p = head;
        int i = 1;
        while(p -> next != head && i < k - 1){
            p = p -> next;
            i++;
        }
        if(p -> next == head) return;
        node* q = p -> next;
        p -> next = q -> next;
        q -> next -> prev = p;
        delete q;
    }

    void delete_val(int x){
        if(!head) return;
        if(head -> val == x){
            delete_front();
            return;
        }
        node* p = head;
        while(p -> next != head && p -> next -> val != x){
            p = p -> next;
        }
        if(p -> next != head){
            node* q = p -> next;
            p -> next = q -> next;
            q -> next -> prev = p;
            delete q;
        }
    }

    int search(int x) const{
        if(!head) return -1;
        int i = 1;
        node* p = head;
        do{
            if(p -> val == x) return i;
            p = p -> next;
            i++;
        }while(p != head);
        return -1;
    }

    int kth(int k) const{
        if(k <= 0 || !head) return -1;
        int i = 1;
        node* p = head;
        do{
            if(i == k) return p -> val;
            p = p -> next;
            i++;
        }while(p != head);
        return -1;
    }

    int find_mid() const{
        if(!head) return -1;
        node* s = head;
        node* f = head;
        while(f -> next != head && f -> next -> next != head){
            s = s -> next;
            f = f -> next -> next;
        }
        if(f -> next -> next == head) s = s -> next;
        return s -> val;
    }

    void reverse_list(){
        if(!head || head -> next == head) return;
        node* p = head;
        do{
            node* q = p -> next;
            p -> next = p -> prev;
            p -> prev = q;
            p = p -> prev;
        }while(p != head);
        head = head -> next;
    }

    void sort_list(){
        if(!head || head -> next == head) return;
        int n = 1;
        node* p = head -> next;
        while(p != head){
            n++;
            p = p -> next;
        }
        for(int i = 0; i < n - 1; i++){
            p = head;
            for(int j = 0; j < n - 1 - i; j++){
                node* q = p -> next;
                if(p -> val > q -> val){
                    int t = p -> val;
                    p -> val = q -> val;
                    q -> val = t;
                }
                p = p -> next;
            }
        }
    }

    void print() const{
        if(!head){
            cout << endl;
            return;
        }
        node* p = head;
        do{
            cout << p -> val;
            if(p -> next != head) cout << " ";
            p = p -> next;
        }while(p != head);
        cout << endl;
    }

    void clear(){
        if(!head) return;
        node* p = head -> next;
        while(p != head){
            node* q = p -> next;
            delete p;
            p = q;
        }
        delete head;
        head = nullptr;
    }
};

int main(){
    cdl a;
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
