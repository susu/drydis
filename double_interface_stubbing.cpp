#include <iostream>

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

// the three class above cannot be modified

// give only one (stub)implementation of BaseInterface (DRY)
// and stub out the Foo- and BarInterface's methods

template<class T>
class BaseInterfaceStub : public T // maybe looks odd...
{                                  // its base class's type postponed, will be defined later
  public:
    virtual void base() // override if T has a concept: virtual void base()
    {
      std::cout << "BaseInterfaceStub::base: STUB!" << std::endl;
    }
};

// multiple inheritance avoided...

//   - FooInterfaceStub ISA BaseInterfaceStub and
//   - BaseInterfaceStub ISA FooInterface and
//   - FooInterface ISA BaseInterface
class FooInterfaceStub : public BaseInterfaceStub< FooInterface >
{ 
  public:
    virtual void foo() // override
    { 
      std::cout << "FooInterfaceStub::foo: STUB!" << std::endl;
    }
};

class BarInterfaceStub : public BaseInterfaceStub< BarInterface >
{ 
  public:
    virtual void bar() // override
    {
      std::cout << "BarInterfaceStub::bar: STUB!" << std::endl;
    }
    // still have the opportunity to override methods from BaseInterface:
    virtual void base()
    {
      std::cout << "BarInterfaceStub::base: custom STUB!" << std::endl;
    }
};

void fooCaller( FooInterface * f )
{
  f->foo();
  f->base();
}

void barCaller( BarInterface * b )
{
  b->bar();
  b->base();
}

int main()
{
  FooInterfaceStub fooIfStub;
  BarInterfaceStub barIfStub;

  fooCaller( &fooIfStub );
  barCaller( &barIfStub );

  BaseInterface & b1 = fooIfStub;
  BaseInterface & b2 = barIfStub;

  b1.base();
  b2.base();
}

