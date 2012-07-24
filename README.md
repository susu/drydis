drydis
======

DRY-DIS ("Don't Repeat Yourself" Double Interface Stubbing)

The problem:
============

Given the following three interface:
```
class BaseInterface
{
  public:
    virtual void base() = 0;
};

class FooInterface : public BaseInterface
{
  public:
    virtual void foo() = 0;
};

class BarInterface : public BaseInterface
{
  public:
    virtual void bar() = 0;
};
```
Limitation
-----------
 * the three class above cannot be modified

Goals
-----
 * give only one (stub)implementation of BaseInterface (DRY)
 * stub out the Foo- and BarInterface's methods
