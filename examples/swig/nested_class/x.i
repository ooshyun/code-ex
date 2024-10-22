%module nested_class

%{
#include "x.hpp"
%}

%include <std_map.i>
%include <std_string.i>


// Instantiate templates used in the interface
%template(StringIntMap) std::map<std::string, int>;

// Include the original C++ header
%include "x.hpp"

// Way 1. Add Python-specific code for the struct, but in cmake building, nested % is not working
// // Add Python-specific code for the struct
// %extend nestedClass {
//     %pythoncode %{
//     def __setattr__(self, name, value):
//         if name == "ex_map" and isinstance(value, dict):
//             self.ex_map.clear()
//             for k, v in value.items():
//                 self.ex_map[k] = v
//         else:
//             super().__setattr__(name, value)
//     %}
// }

// Way 2
%pythoncode %{
def nestedClass_setattr(self, name, value):
    if name == "ex_map" and isinstance(value, dict):
        self.ex_map.clear()
        for k, v in value.items():
            self.ex_map[k] = v
    else:
        super(nestedClass, self).__setattr__(name, value)

nestedClass.__setattr__ = nestedClass_setattr
%}
