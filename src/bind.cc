#include <boost/python.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(flat_set_str)
{
  std::pair<typename std::vector<std::string, typename std::allocator<string>>, bool>
    (flat_set::*insertx1)(const std::string&) = &flat_set::insert;

  std::pair<typename std::vector<std::string, typename std::allocator<string>>, bool>
    (flat_set::*insertx2)(std::string&) = &flat_set::insert;

  typename std::vector<std::string, typename std::allocator<string>>
    (flat_set::*insertx3)
    (typename std::vector<std::string, typename std::allocator<string>>,
      const std::string&) = &flat_set::insert;

  typename std::vector<std::string, typename std::allocator<string>>
    (flat_set::*insertx4)
    (typename std::vector<std::string, typename std::allocator<string>>,
      std::string&) = &flat_set::insert;

  class_<flat_set<string>>("flat_set_str")
    .def_readwrite("key_comp", &flat_set<string>::key_compare)
    .def_readwrite("value_comp", &flat_set<string>::key_compare)
    .def_readwrite("get_allocator", &flat_set<string>::allocator_type)
    .def("begin", &flat_set<string>::begin)
    .def("end", &flat_set<string>::end)
    .def("rbegin", &flat_set<string>::rbegin)
    .def("rend", &flat_set<string>::rend)
    .def("cbegin", &flat_set<string>::cbegin)
    .def("cend", &flat_set<string>::cend)
    .def("crbegin", &flat_set<string>::crbegin)
    .def("crend", &flat_set<string>::crend)
    .def("empty", &flat_set<string>::empty)
    .def("size", &flat_set<string>::size)
    .def("max_size", &flat_set<string>::max_size)
    .def("swap", &flat_set<string>::swap)
    .def("insert", insertx1)
    .def("insert", insertx2)
    .def("insert", insertx3)
     .def("insert", insertx4);
}
