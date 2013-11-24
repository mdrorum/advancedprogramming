# Lecture 9: Pointers

- Pointers
    - Pointers and references
        - 'pointers to pointers' exist
        - 'reference to pointer' exists
        - 'pointer to reference' doesn't exist
        - 'reference to reference' doesn't exist (it's a r-value reference)
    - Smart pointers
        - `auto_ptr` (deprecated): http://en.wikipedia.org/wiki/Auto_ptr
        - `unique_ptr` (C++11, replaces `auto_ptr` in most cases)
        - `shared_ptr`, with reference counting
        - Boost
            - http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/smart_ptr.htm
            - `scoped_ptr`/`scoped_array` for dynamic RIIA, no special semantics
            - `shared_ptr`/`shared_array` (like std::shared_ptr)
              (http://stackoverflow.com/questions/13061979/shared-ptr-to-an-array-should-it-be-used)
            - `intrusive_ptr` for object providing their own reference counting:
              http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/intrusive_ptr.html
        - smart pointers are thread safe, but the objects they point can be unsafe
    - Opaque pointers
        - .h file includes the _declaration_ of a pointer type to a struct that is declared in the
          .c[pp] file.

# Exercises

- there's no specific exercise for this lecture, but "correct" use of pointers and references will
  be required from now on.
