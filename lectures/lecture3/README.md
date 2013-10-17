# Lecture 3 - C++ (II)

- C++ (II)
    - Rvalues and lvalues: 
      http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/
        - * gets a r-value and yields a l-value
        - & gets a l-value and yields a r-value
    - RAII: http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization


# Exercise

- write a RAIIFile wrapper class that closes the file when the object is destroyed.
- check that it works even with exceptions
