# Lecture 10: Programming patterns

- [Design patterns](http://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns)
    - You should know and know when to use these patterns:
        - Factory/abstract factory: building objects through polymorphism
        - Builder: proxy class for building objects
        - Singleton: class with a single instance
        - Prototype: class that can be cloned
        - Adapter: conversion of interface
        - Bridge: separate API from implementation
        - Composite: treat compositing and individual objects the same
        - Decorator: attach functionality dynamically
        - Facade: hide complexity
        - Flyweight: saving memory by sharing resources
        - Proxy
        - Mixins
        - Interface-based Programming: enforcing encapsulation
        - Chain of Responsibility: delegation
        - Command: commands as instances with a common interface
        - Interpreter: language/DSL
        - Iterator: STL is a good example
        - Mediator
        - Memento: serialization
        - Observer: letting objects know about changes
        - State: changing behavior when state changes (FSMs)
        - Strategy: several algorithms, single interface
        - Template Method: deferring particular behavior to subclasses
        - Visitor: when you let other class in
        - Model-View-Controller (MVC)

# Extended bibliography

- ["Gang of four"](http://en.wikipedia.org/wiki/Design_Patterns)

# Exercises

- Read, understand and learn all these patterns
- Make your frontend a singleton
- Create a facade class between your networking code and your client
- Clearly separate model and view in your program
- If you use any sort of tree search (and you should!), implement your operator using the command
  pattern
- Add methods to serialize and de-serialize your AI's state (you can use Boost)
- Any other application of a design pattern will be taken into consideration

