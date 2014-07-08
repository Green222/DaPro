#include <boost/python.hpp>
#include "flat_set.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(flat_set_str)
{
  std::pair<typename std::vector<std::string, typename std::allocator<std::string>>, bool>
    (flat_set::*insertx1)(const std::string&) = &flat_set::insert;

  std::pair<typename std::vector<std::string, typename std::allocator<std::string>>, bool>
    (flat_set::*insertx2)(std::string&) = &flat_set::insert;

  typename std::vector<std::string, typename std::allocator<std::string>>
    (flat_set::*insertx3)
    (typename std::vector<std::string, typename std::allocator<std::string>>,
      const std::string&) = &flat_set::insert;

  typename std::vector<std::string, typename std::allocator<std::string>>
    (flat_set::*insertx4)
    (typename std::vector<std::string, typename std::allocator<std::string>>,
      std::string&) = &flat_set::insert;

  typename std::vector<std::string, typename std::allocator<std::string>
    (flat_set::*findx1)(const std::string&) const = &flat_set::find;

  typename std::vector<std::string, typename std::allocator<std::string>
    (flat_set::*findx2)(const std::string&) = &flat_set::find;

  typename std::vector<std::string, typename std::allocator<std::string>
    (flat_set::*lower_boundx1)(const std::string&) = &flat_set::lower_bound;

  typename std::vector<std::string, typename std::allocator<std::string>
    (flat_set::*lower_boundx2)(const std::string&) const = &flat_set::lower_bound;

  typename std::vector<std::string, typename std::allocator<std::string>
    (flat_set::*upper_boundx1)(const std::string&) = &flat_set::upper_bound;

  typename std::vector<std::string, typename std::allocator<std::string>
    (flat_set::*upper_boundx2)(const std::string&) const = &flat_set::upper_bound;

  std::pair<typename std::vector<std::string, typename std::allocator<std::string>>, 
    typename std::vector<std::string, typename std::allocator<std::string>>>
    (flat_set::*equal_rangex1)(const std::string&) = &flat_set::equal_range;

  std::pair<typename std::vector<std::string, typename std::allocator<std::string>>, 
    typename std::vector<std::string, typename std::allocator<std::string>>>
    (flat_set::*equal_rangex2)(const std::string&) const = &flat_set::equal_range;

  class_<flat_set<std::string>>("flat_set_str")
    .def_readwrite("key_comp", &flat_set<std::string>::key_compare)
    .def_readwrite("value_comp", &flat_set<std::string>::key_compare)
    .def_readwrite("get_allocator", &flat_set<std::string>::allocator_type)
    .def("begin", &flat_set<std::string>::begin)
    .def("end", &flat_set<std::string>::end)
    .def("rbegin", &flat_set<std::string>::rbegin)
    .def("rend", &flat_set<std::string>::rend)
    .def("cbegin", &flat_set<std::string>::cbegin)
    .def("cend", &flat_set<std::string>::cend)
    .def("crbegin", &flat_set<std::string>::crbegin)
    .def("crend", &flat_set<std::string>::crend)
    .def("empty", &flat_set<std::string>::empty)
    .def("size", &flat_set<std::string>::size)
    .def("max_size", &flat_set<std::string>::max_size)
    .def("swap", &flat_set<std::string>::swap)
    .def("insert", insertx1)
    .def("insert", insertx2)
    .def("insert", insertx3)
    .def("insert", insertx4)
    .def("clear", &flat_set<std::string>::clear)
    .def("count", &flat_set<std::string>::count)
    .def("find", findx1)
    .def("find", findx2)
    .def("lower_bound", lower_boundx1)
    .def("lower_bound", lower_boundx2)
    .def("upper_bound", upper_boundx1)
    .def("upper_bound", upper_boundx2)
    .def("equal_range", equal_rangex1)
    .def("equal_range", equal_rangex2);
}
