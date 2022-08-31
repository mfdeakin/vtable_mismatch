
#include <stdio.h>

#include <dlfcn.h>

#include "vtable.hpp"

int main(int argc, char **argv) {
  auto vtt = dlopen("/home/mfdeakin/so_test/build/libvt_test.so", RTLD_NOW | RTLD_LOCAL);
  if(!vtt) {
    printf("Could not open libvt_test.so\n!");
    return 1;
  }
  auto vtc = (std::unique_ptr<vt_pure> (*)())dlsym(vtt, "vt_create");
  if(!vtc) {
    printf("Could not find vt_create\n!");
    return 2;
  }
  auto obj = vtc();
  printf("calling foo1\n");
  obj->foo1();
  printf("calling foo2\n");
  obj->foo2();
  printf("calling foo3\n");
  obj->foo3();
  printf("calling foo4\n");
  obj->foo4();
  printf("calling foo5\n");
  obj->foo5();
  dlclose(vtt);
  return 0;
}
