#ifndef DEQUEUE_H
#define DEQUEUE_H

template <typename T>
struct node {
T data;
node* prev;
node* next;
};
template <class T>
class Dequeue
{
    public:
        Dequeue();
        virtual ~Dequeue();
        Dequeue(const Dequeue& other);
        Dequeue& operator=(const Dequeue& other);
      print();
      print_rev();
class iterator{
   private :
       node<T>* ptr;
   public:
    explicit iterator();
    explicit iterator(node<T>* p);

     bool operator== (const iterator& rptr);
    bool  operator!= (const iterator& rptr);
     iterator& operator++();
      iterator& operator--();
    T operator*();
    node<T>*  current_node();
 };
//////////////////iterators///////////////////////
 iterator begin();
 iterator end();
 iterator rbegin();
 iterator rend();
 iterator cbegin() const;
 iterator cend()const;
 iterator crbegin()const;
 iterator crend() const;
//////////////////////capacity//////////////////////
 int size();
 int max_size();
 bool empty();
////////////////////element access////////////////////////////////
T& operator[ ] (int index);
T at(int index);
T front();
T back ();

///////////////////modifiers////////////////////////////////////
 push_front(T val);
push_back(T val);
pop_front();
pop_back();
 assign(iterator first,iterator last);
 assign (int size ,T& val);
 insert (iterator position, const T& val);
int erase (iterator position);
swap (Dequeue& x);
 clear() noexcept;
    protected:

    private:
        node<T>* head;
         node<T>* tail;
         int curr_capacity;

};

#endif // DEQUEUE_H
