#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <sstream>
#include <string>

void parse_tree(const boost::property_tree::ptree& pt,
                std::string key,
                std::string prev_key) {
  std::string nkey;
  if (!key.empty())
    nkey = key + ".";

  boost::property_tree::ptree::const_iterator end = pt.end();
  for (boost::property_tree::ptree::const_iterator it = pt.begin();
                                                   it != end; ++it) {
    std::cout << "key " << key
              << " - " << prev_key
              << " - " << it->first
              << " - " << it->second.get_value<std::string>()
              << std::endl;
    parse_tree(it->second, nkey + it->first, it->first);
  }
}

void test_xml_parse(void) {
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

  std::cout<< "Parseing tree...\n";
  std::cout<< "===========================\n";
  parse_tree(pt, "", "");
  std::cout<< "===========================\n";

  auto str = pt.get<std::string>("root.str");
  std::cout << str << std::endl;

  auto childs = pt.get_child("root.values");
  for (auto &child : childs) {
    std::cout << child.first << " : "
              << child.second.get_value<std::string>() << std::endl;
    if (child.second.size() > 0) {
      std::cout << child.second.get_child("<xmlattr>.test")
                               .get_value<std::string>()
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

  std::cout<< "Parseing tree...\n";
  std::cout<< "===========================\n";
  parse_tree(pt, "", "");
  std::cout<< "===========================\n";

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

std::string parse_xml_test(const std::string& xml_str,
                           const std::string& xml_key,
                           const std::string& key,
                           const std::string& child_key,
                           const std::vector<
                              std::pair<std::string, std::string>>& condition
                              = {}) {
  // std::cout << "parse_xml_test...\n";
  std::cout << xml_str << std::endl;
  boost::property_tree::ptree pt;
  std::string result;

  std::istringstream iss(xml_str);
  try {
    read_xml(iss, pt);
  // } catch (boost::wrapexcept<boost::property_tree
  //     ::xml_parser::xml_parser_error>& e) {
  } catch (const boost::property_tree
      ::xml_parser::xml_parser_error& e) {
    // libc++abi: terminating due to uncaught exception of
    // type boost::wrapexcept<boost::property_tree::xml_parser
    // ::xml_parser_error>: <unspecified file>(10): expected =
    // zsh: abort      ./Release/bin/cppexample
    std::cout << "error: " << e.what() << std::endl;
    return result;
  }

  // std::cout << "get child...";
  boost::property_tree::ptree childs;
  if (!pt.get_child_optional(xml_key)) {
    std::cout << "no \"" << xml_key << "\" feature" << std::endl;
    return result;
  } else {
    childs = pt.get_child(xml_key);
  }

  // std::cout << childs.data() << " size: " << childs.size() << std::endl;

  uint8_t cond_true_count = 0;
  for (boost::property_tree::ptree::value_type const& child : childs) {
    // // Debug
    // std::cout << "\n===============\n Debug\n";
    // std::cout << child.first
    //           << ": " << child.second.get_value<std::string>()
    //           << " size: " << child.second.size() << std::endl;

    // std::cout << "get grandchild! ";
    // std::string grandchild_key = "<xmlattr>";
    // if (child.second.get_child_optional(grandchild_key)) {
    //   auto grandchilds = child.second.get_child(grandchild_key);
    //   std::cout << "size: " << grandchilds.size() << std::endl;

    //   if (grandchilds.size() == 0) {
    //     std::cout << grandchilds.data() << std::endl;
    //   } else {
    //     for (auto &grandchild : grandchilds) {
    //       auto tmpStr = grandchild.second.get_value<std::string>();
    //       std::cout << grandchild.first
    //                 << ": " << tmpStr
    //                 << " size: " << tmpStr.size() << std::endl;
    //     }
    //   }
    // } else {
    //   std::cout << "no \"" << grandchild_key << "\" feature" << std::endl;
    // }
    // std::cout << "\n===============\n";

    if (child.first != key) continue;

    for (std::pair<std::string, std::string> const& cond : condition) {
      std::string key = cond.first;
      std::string val = cond.second;
      std::cout << "cond: " << key << ": " << val << std::endl;
      if (child.second.get_child_optional(key) &&
          child.second.get_child(key).data() == val) {
            cond_true_count++;
      } else {
        cond_true_count = 0;
        break;
      }
    }

    if ( cond_true_count == condition.size() ) {
      std::cout << "found!" << std::endl;
      if (child_key.empty()) {
          if (child.second.get_value_optional<std::string>())
            result = child.second.get_value<std::string>();
      } else if (child.second.get_child_optional(child_key)) {
        result = child.second.get_child(child_key).data();
      }
      break;
    }
  }
  return result;
}

void test_xml_parse_api(void) {
  /*
    xml format
    <key_1>
      <key_2 attr_1 attr_val attr_2 attr2_val>
        <key_3>value</key_3>
      </key_2>
      <key_4 attr_1 attr_val attr_2 attr2_val>
      <key_5>
        <key_6>value</key_6>
      </key_5>
      // X (key_1).get_child -> size is 0 and cannot find key_7's value
      // X (key_1).data()    -> size is 0 and can get key_7's value by using data
      <key_7> value </key_7> 
    </key_1>
  */
  std::string result;
  char* info =
      "<?xml version=\"1.0\"encoding=\"utf-8\"?>\n"
      "<main_info>\n"
      "  <feature id=\"0\">\n"
      "    <license>\n"
      "      <license_type>perpetual</license_type>\n"
      "    </license>\n"
      "    <info id=\"319609403760179228\" type=\"type 1\" />\n"
      "  </feature>\n"
      "  <feature id=\"2\">\n"
      "    <alphabet>\n"
      "       <name>\"alpha\"</name>\n"
      "    </alphabet>\n"
      "    <license>\n"
      "      <license_type>expiration</license_type>\n"
      "      <exp_date>1695340799</exp_date>\n"
      "    </license>\n"
      "    <info id=\"319609403760179228\" type=\"type 2\" />\n"
      "  </feature>\n"
      "  <feature id=\"3\">\n"
      "    <info id=\"319609403760179228\" type=\"type 2\" />\n"
      "  </feature>\n"
      "  <feature id=\"3\" name=\"hello\">\n"
      "  </feature>\n"
      "</main_info>";

  std::cout << "\n====================\n"
               "Parsing xml exmple 0...\n";
  result = parse_xml_test(info,
              "no",
              "no",
              "no");

  std::cout << "result : " << result << std::endl;

  std::cout << "\n====================\n"
               "Parsing xml exmple 1...\n";
  result = parse_xml_test(info,
              "main_info",
              "feature",
              "license.exp_date",
              {{"<xmlattr>.id", "2"},
               {"license.license_type", "expiration"}});
  std::cout << "result : " << result << std::endl;

  info =
      R"(<main_info>
    <host_fingerprint type="mode-1" crc="7777777777">
        MXhJSYMR8AXJjAAAp8WOBJiW4OwCJgTuVNpFpQAIMyAPAGQpcAK
        3qzvTfqy7RBj6BaMAGAoADB0d3bQJsu4cNgATZNaTCMAKpMTQao
        IRIOFOEgAYkG0ChJqG3YKRZAQO9ZsnAyC8KWIBoGWBEkDMgjsTg
        JQaDgiAwRoAUAqAlwimzbRtpYaJAjiXihqGBMBAdwJEbYIN8pHD
        AgSZxgECsBowTI6C"
    </host_fingerprint>"
    <host_fingerprint type="mode-2" vendorid="12345" "
        crc="987665432">"
        MnhJSavAoX7zZAAELXYkwLQEZxcwETsTgJQZDggMyAMAWQqcwO
        1qpm0rNUEUwAlGATAUABg6OrqbYIN87LAAQWZ9iQCsQEoMreYI"
        +IJkRgAAyDYBQk3DbsFIArhTadeVAqCmiAWAlgVKADHLZNqPdZ"
        MIQzNYAwBKAfASwbS5CbLuADYAk4oahgTAQHcCRBGMAAkHkgDA"
        NA4QgNWAYXIUVA=="
    </host_fingerprint>
</main_info>)";

  std::cout << "\n====================\n"
               "Parsing xml exmple 2 (exceptional)...\n";
  result = parse_xml_test(info,
              "main_info",
              "feature",
              "license.exp_date",
              {{"<xmlattr>.id", "2"},
               {"license.license_type", "expiration"}});

  // expect exception at read_xml
  std::cout << "result : " << result << std::endl;

  info =
      "<main_info>\n"
      "   <host_fingerprint type=\"mode-1\" crc=\"7777777777\">"
      "MXhJSYMR8AXJjAAAp8WOBJiW4OwCJgTuVNpFpQAIMyAPAGQpcAK3qzvTfqy"
      "7RBj6BaMAGAoADB0d3bQJsu4cNgATZNaTCMAKpMTQaoIRIOFOEgAYkG0ChJ"
      "qG3YKRZAQO9ZsnAyC8KWIBoGWBEkDMgjsTgJQaDgiAwRoAUAqAlwimzbRtp"
      "YaJAjiXihqGBMBAdwJEbYIN8pHDAgSZxgECsBowTI6C</host_fingerprint>\n"
      "   <host_fingerprint type=\"mode-2\" vendorid=\"12345\" "
      "crc=\"987665432\">MnhJSavAoX7zZAAELXYkwLQEZxcwETsTgJQZDggMy"
      "AMAWQqcwO1qpm0rNUEUwAlGATAUABg6OrqbYIN87LAAQWZ9iQCsQEoMreYI"
      "+IJkRgAAyDYBQk3DbsFIArhTadeVAqCmiAWAlgVKADHLZNqPdZMIQzNYAwB"
      "KAfASwbS5CbLuADYAk4oahgTAQHcCRBGMAAkHkgDANA4QgNWAYXIUVA=="
      "</host_fingerprint>\n"
      "</main_info>\n";

  std::cout << "\n====================\n"
               "Parsing xml exmple 3...\n";
  result = parse_xml_test(info,
             "main_info",
             "host_fingerprint",
              "<xmlattr>.vendorid",
             {{"<xmlattr>.type", "mode-1"}});

  // expect empty
  std::cout << "result : " << result << std::endl;

  std::cout << "\n====================\n"
               "Parsing xml exmple 3...\n";
  result = parse_xml_test(info,
             "main_info",
             "host_fingerprint",
              "<xmlattr>.crc",
             {{"<xmlattr>.type", "mode-1"}});

  // expect 7777777777
  std::cout << "result : " << result << std::endl;


  std::cout << "\n====================\n"
               "Parsing xml exmple 4...\n";
  result = parse_xml_test(info,
              "main_info",
              "host_fingerprint",
              "",
              {{"<xmlattr>.type", "mode-1"}});

  // expect host_fingerprint data
  std::cout << "result : " << result << std::endl;
}
