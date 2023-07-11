#pragma once

#include <string>
#include <unordered_map>

namespace net {
namespace http {
inline std::unordered_map<std::string, std::string>
parse_query(const std::string query) {
  std::unordered_map<std::string, std::string> out{};

  bool pair_complete{false};
  auto beg_it = query.begin() + (query[0] == '?' ? 1 : 0);
  std::pair<std::string, std::string> pair{};
  for (auto it = query.begin(); it != query.end(); ++it) {
    if (*it == '=') {
      pair.first = std::string{beg_it, it};
      beg_it = it + 1;
    } else if (*it == '&') {
      pair.second = std::string{beg_it, it};
      beg_it = it + 1;
      pair_complete = true;
    } else if (it == (query.end() - 1)) {
      pair.second = std::string{beg_it, query.end()};
      pair_complete = true;
    }

    if (pair_complete) {
      out.emplace(pair);
      pair_complete = false;
    }
  }

  return out;
}
} // namespace http
} // namespace net
