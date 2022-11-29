## Computer Programming semester III exercise III
In this exercise I created my own implementation of a one-way linked list template equipped with said methods:
* default constructor - creates an empty list,
* parametric constructor - creates a list containing the set number of elements, whose values are given by a lambda expression,
* destructor
* two begin() methods - returning const_iterator and iterator,
* two end() methods - returning const_iterator and iterator,
* a size() method returning the number of elements in the list,
* push_back(new element), a method for adding an element to the end of a list,
* insert(iterator, new element) - inserting a new element at the position pointed by the iterator,
* erase(iterator) - removing the element pointed to by the iterator

In addition, the iterator and const_iterator templates are implemented to allow browsing through the list and are equipped with:
* pre-increment operator (++),
* post-increment operator (++),
* dereference operator, chunking operator (*),
* indirect access operator for list components (->),
* comparison operator (!=)
