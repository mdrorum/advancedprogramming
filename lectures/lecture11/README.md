# Lecture: Programming paradigms

- Programming paradigms
    - [Functional](http://www.haskell.org/haskellwiki/Functional_programming)
        - many patterns, different languages use different subsets
        - referential transparency
        - purity
        - recursion
        - high order functions ...
        - [Functional](http://msdn.microsoft.com/en-us/magazine/jj553512.aspx) in C++11:
            - for_each
            - lambdas
            - better syntax for referring to functions...
    - [Logic programming](http://en.wikipedia.org/wiki/Logic_programming)
        - [Prolog](http://en.wikipedia.org/wiki/Prolog) - [SWI Prolog](http://www.swi-prolog.org/) is a free interpreter
        - [CLP](http://en.wikipedia.org/wiki/Constraint_logic_programming)
            - problem description. solution is automatically computed.
    - Event driven programming
        - SDL classical loop, for instance

# Extended bibliography

- [Event-Driven Programming: Introduction, Tutorial, History](http://eventdrivenpgm.sourceforge.net/)
- [Learn You a Haskell for Great Good](http://www.nostarch.com/lyah.htm)
- [The Art of Prolog](http://mitpress.mit.edu/books/art-prolog)

# Exercises

- reprogram your client with an event-driven pattern:
    - put messages from the server in an event queue
    - take the messages from the queue and dispatch them
    - use mutexes where needed
- optional
    - implement your search algorithm in Prolog
