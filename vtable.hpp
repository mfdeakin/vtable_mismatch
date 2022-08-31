
#include <memory>

class vt_pure {
public:
  virtual int foo1() = 0;
#ifdef LIBRARY
  virtual int blah() = 0;
#endif
  virtual int foo2() = 0;
  virtual int foo3() = 0;
#ifndef LIBRARY
  virtual int fooblah1() = 0;
  virtual int fooblah2() = 0;
#endif
  virtual int foo4() = 0;
  virtual int foo5() = 0;
};

extern "C" std::unique_ptr<vt_pure> vt_create();
