#include "recency_map.h"

namespace algorithms {
  void recency_map::set(const std::string& key, int value) {
    auto find = dict_.find(key);
    if (find == dict_.end()) {
      recent_keys_.push_front(key);
      dict_.insert(std::make_pair(key, std::make_pair(recent_keys_.begin(), value)));
    }
    else {
      find->second.second = value;
      auto itr = find->second.first;
      auto element = *itr;

      recent_keys_.erase(itr);
      recent_keys_.push_front(element);
      find->second.first = recent_keys_.begin();
    }
  }

  int recency_map::get(const std::string& key) {
    if (dict_.empty())
      throw "Invalid operation exception";

    auto find = dict_.find(key);
    if (find == dict_.end())
      throw "Key does not exists";

    auto itr = find->second.first;
    auto element = *itr;

    recent_keys_.erase(itr);
    recent_keys_.push_front(element);
    find->second.first = recent_keys_.begin();

    return find->second.second;
  }

  void recency_map::erase(const std::string& key) {
    auto find = dict_.find(key);
    if (find == dict_.end())
      throw "Key does not exists";

    recent_keys_.erase(find->second.first);
    dict_.erase(key);
  }

  std::string recency_map::mostRecentKey() {
    if (recent_keys_.empty())
      throw "Empty recency_map";

    return *recent_keys_.begin();
  }
}
