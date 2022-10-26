#pragma once

#include <graph_utils_export.h>

#include <string_view>

namespace GRAPH_UTILS_EXPORT tester {
  void printCurrentFileName(std::string_view filename);

  void boolTest(std::string_view indicator_name,
    bool indicator_value,
    bool assertion);

  void intTest(std::string_view indicator_name,
    int indicator_value,
    int assertion);
}
