
// #pragma once
// #include <iostream>
// #include <string>

// class StaticComponentInClass {
//  public:
//   static std::string get_static_member() {
//     if (_static_member.empty()) {
//       return "none";
//     }
//     return "_static_member";
//   }
//   static void set_static_member(const std::string& value) {
//     if(value.empty()){
//       return;
//     }
//     _static_member = value;
//   }
//   static std::string get_install_path() {
//     return GetInstance().get_static_member();
//   }
//  private:
//   static StaticComponentInClass& GetInstance() {
//     static StaticComponentInClass instance;
//     return instance
//   }
//   static std::string _static_member;
// };


void test_static_component_in_class(void) {
//   // StaticComponentInClass obj;
//   StaticComponentInClass::set_static_member("test");
//   std::cout << StaticComponentInClass::get_static_member() << std::endl;
//   StaticComponentInClass::set_static_member("");
//   std::cout << StaticComponentInClass::get_static_member() << std::endl;
}