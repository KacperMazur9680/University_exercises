## Computer Programming semester III exercise V
Write your own implementation of the smart pointer class template (equivalent to std::unique_ptr). 
<br />Template:
* you cannot create copies of smart pointer objects (via the copy constructor or copy assignment operator),
* you can only create smart pointers to already existing objects,
* must allow an ordinary pointer to be assigned to a smart pointer object (assignment operator or transfer constructor),
* must allow the transfer of a smart pointer between two smart pointers,
* must have the "*" (dereference) and -> (indirect access) operators implemented; their operation is to be analogous to that of ordinary pointers,
* must have implemented a conversion operator to a type compatible with that of a simple pointer 

The template is to be able to execute the following code `PK-zad5.cpp` and guarantee the release of all controlled resources.
