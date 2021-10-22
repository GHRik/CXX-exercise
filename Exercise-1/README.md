# Exercise-1

## Description
This project present how to using smart pointers.
In comment in code is description which smart pointer is which.

To properly deploy this app cmake file was created.

## Design assumptions

Exercise-1

- [x] Create interface "Animal" with one virtual fuction.
- [x] Create few class like "dog" , "cat" etc. which will be inheritance interface "Animal".
- [x] Create vector of (smart)pointers to interface "Animal".
- [x] Insert classes from above (dog, cats etc.) to vector.
- [x] Call virtual function from interface "Animal" on all elements of vector.
- [x] Create new virtual function in interface "Animal" which name will be "crash".
- [x] In function "crash" create throw block.
- [x] Call new virtual function on only one object in main function.
- [x] Write unit tests to covering your code.
