
#define LIBRARY

#include "vtable.hpp"

#include <stdio.h>

class vt_impl : public vt_pure {
public:
  virtual int foo1() {
    printf("foo1\n");
    return 1;
  }
  virtual int blah() {
    printf("blah\n");
    return 0;
  }
  virtual int foo2() {
    printf("foo2\n");
    return 2;
  }
  virtual int foo3() {
    printf("foo3\n");
    return 3;
  }
  virtual int fooblah1() {
    printf("fooblah1\n");
    return -1;
  }
  virtual int fooblah2() {
    printf("fooblah2\n");
    return -2;
  }
  virtual int foo4() {
    printf("foo4\n");
    return 4;
  }
  virtual int foo5() {
    printf("foo5\n");
    return 5;
  }
};

std::unique_ptr<vt_pure> vt_create() {
  return std::make_unique<vt_impl>();
}
