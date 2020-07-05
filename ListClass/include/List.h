#ifndef LIST_H
#define LIST_H
template<typename T>
struct node {
  T data ;
  node * next ;
  node * prev;
};
template <class T>
class List
{
    public:
        List();
        List(int size,T default_value);
        List<T>& operator= (List<T>& copy_lisr);
        erase_all_elements();
        virtual ~List();

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
T front();
T back ();
///////////////////modifiers////////////////////////////////////
 assign(iterator first,iterator last);
 assign (int size ,T& val);
push_back (const T& val) ;
pop_back();
 insert (iterator position, const T& val);
int erase (iterator position);
swap (List& x);
 clear() noexcept;
push_front (const T& val) ;
pop_front ();
 //////////////////////print function////////////////
 print();
    protected:

    private:
         node<T> *head;
         node<T> *tail;
        int curr_size;

};


#endif // LIST_H
