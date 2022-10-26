#include <iostream>
#include <tester.hpp>

void tester::printCurrentFileName(std::string_view filename) {
  std::cout << filename << std::endl;
}

void tester::boolTest(std::string_view indicator_name,
  bool indicator_value,
  bool assertion) {
    std::string_view test_result = (indicator_value == assertion) ? "success" : "failure";

    std::cout << indicator_name << " == " << std::boolalpha
    << assertion << " ... " << test_result << std::endl;
}

void tester::intTest(std::string_view indicator_name,
  int indicator_value,
  int assertion) {
    std::string_view test_result = (indicator_value == assertion) ? "success" : "failure";

    std:: cout << indicator_name << " == " << assertion << " ... "
    << test_result << std::endl;
}
