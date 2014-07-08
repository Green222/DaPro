#include "flat_set.hh"
#include <iostream>

int main()
{
  flat_set<int>* f = new flat_set<int>();

  std::cout << "insert 3 expected : 1 result : " << (f->insert(3)).second << '\n';
  std::cout << "insert 4 expected : 1 result : " << (f->insert(4)).second << '\n';
  std::cout << "insert 5 expected : 1 result : " << (f->insert(5)).second << '\n';
  std::cout << "insert 3 expected : 0 result : " << (f->insert(3)).second << '\n';

  flat_set<int>* f2 = new flat_set<int>(*f);
  flat_set<int>* f3 = new flat_set<int>(f2->begin(), f2->end());
  std::cout << "find 3 expected : 3 result : " << *(f2->find(3)) << '\n';
  std::cout << "find 4 expected : 4 result : " << *(f2->find(4)) << '\n';
  std::cout << "find 3 expected : 3 result : " << *(f3->find(3)) << '\n';
  std::cout << "find 4 expected : 4 result : " << *(f3->find(4)) << '\n';

  std::cout << "empty expected : 0 result : " << f->empty() << '\n';
  std::cout << "find 3 expected : 3 result : " << *(f->find(3)) << '\n';
  std::cout << "find 4 expected : 4 result : " << *(f->find(4)) << '\n';

  f->clear();
  std::cout << "empty expected : 1 result : " << f->empty() << '\n';
  std::cout << "size expected : 0 result : " << f->size() << '\n';

  return 0;
}
