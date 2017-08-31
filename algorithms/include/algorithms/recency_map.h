#include "DLLDefines.h"
#include <string>
#include <unordered_map>
#include <list>
#include <utility>

namespace algorithms {
  class recency_map {
  public:
    MYLIB_EXPORT recency_map() = default;
    MYLIB_EXPORT ~recency_map() = default;
    MYLIB_EXPORT void set(const std::string& key, int value);
    MYLIB_EXPORT int get(const std::string& key);
    MYLIB_EXPORT void erase(const std::string& key);
    MYLIB_EXPORT std::string mostRecentKey();

  private:
    std::list<std::string> recent_keys_;
    std::unordered_map<std::string, std::pair<std::list<std::string>::iterator, int>> dict_;
  };
}