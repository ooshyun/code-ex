#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <sstream>
#include <string>

void test_xml_parse(void)
{
  std::string data =
      "<? xml version=\"1.0\" encoding=\"utf-8\"?>"
      "<root>"
      " <str>Hello</str>"
      " <values>"
      "   <value>1</value>"
      "   <value test=\"A\">2</value>"
      "   <value>3</value>"
      " </values>"
      "</root>";

  std::istringstream iss(data);
  boost::property_tree::ptree pt;
  read_xml(iss, pt);

  auto str = pt.get<std::string>("root.str");
  std::cout << str << std::endl;

  auto childs = pt.get_child("root.values");
  for (auto &child : childs)
  {
    std::cout << child.first << " : " << child.second.get_value<std::string>() << std::endl;
    if (child.second.size() > 0)
    {
      std::cout << child.second.get_child("<xmlattr>.test").get_value<std::string>()
                << std::endl;
    }
  }
}

void test_xml_parse_complicate(void) {
  char *info =
      "<?xml version=\"1.0\"encoding=\"utf-8\"?>"
      "<main_info>"
      "  <feature id=\"0\">"
      "    <license>"
      "      <license_type>perpetual</license_type>"
      "    </license>"
      "    <info id=\"319609403760179228\" type=\"type 1\" />"
      "  </feature>"
      "  <feature id=\"2\">"
      "    <license>"
      "      <license_type>expiration</license_type>"
      "      <exp_date>1695340799</exp_date>"
      "    </license>"
      "    <info id=\"319609403760179228\" type=\"type 2\" />"
      "  </feature>"
      "</info>";

  std::istringstream iss(info);
  boost::property_tree::ptree pt;
  read_xml(iss, pt);

  auto childs = pt.get_child("main_info");
  for (auto &child : childs) {
    std::cout << "first: " << child.first << std::endl;
    std::cout << "-----------\n";
    if (child.second.size() > 0) {
      std::cout
          << child.second.get_child("<xmlattr>.id")
                        .get_value<std::string>()
          << std::endl;
      std::cout
          << child.second.get_child("license.license_type")
                        .get_value<std::string>()
          << std::endl;
      auto grandchilds = child.second.get_child("license");
      for (auto &grandchild : grandchilds) {
        std::cout << grandchild.first << std::endl;
        std::cout << grandchild.second.get_value<std::string>() << std::endl;
      }
      grandchilds = child.second.get_child("info.<xmlattr>");
      for (auto &grandchild : grandchilds) {
        std::cout << grandchild.first << std::endl;
        std::cout << grandchild.second.get_value<std::string>() << std::endl;
        std::string tmpStr = grandchild.second.get_value<std::string>();

        std::cout << "size: " << tmpStr.size() << std::endl;
        if (tmpStr[0] == '\0')
          std::cout << "NULL";
        std::cout << std::endl;
      }
      std::cout
          << child.second.get_child("info.<xmlattr>.id")
                        .get_value<std::string>()
          << std::endl;
      std::cout
          << child.second.get_child("info.<xmlattr>.type")
                        .get_value<std::string>()
          << std::endl;
    }
  }
}