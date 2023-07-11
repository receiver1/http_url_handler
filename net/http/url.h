#pragma once

#include <string>

namespace net {
namespace http {
class url {
  std::string schema_{}, host_{}, path_{}, query_{}, fragment_{}, user_info_{};
  std::uint16_t port_{};

public:
  url() = default;
  url(const std::string url);

  std::string schema() const { return schema_; }
  std::string host() const { return host_; }
  std::uint16_t port() const { return port_; }
  std::string path() const { return path_; }
  std::string query() const { return query_; }
  std::string fragment() const { return fragment_; }
  std::string user_info() const { return user_info_; }

  bool has_schema() const { return !schema_.empty(); }
  bool has_host() const { return !host_.empty(); };
  bool has_port() const { return port_ > 0; }
  bool has_path() const { return !path_.empty(); }
  bool has_query() const { return !query_.empty(); }
  bool has_fragment() const { return !fragment_.empty(); }
  bool has_user_info() const { return !user_info_.empty(); }

  void schema(std::string value) { schema_ = value; }
  void host(std::string value) { host_ = value; }
  void port(std::uint16_t value) { port_ = value; }
  void path(std::string value) { path_ = value; }
  void query(std::string value) { query_ = value; }
  void fragment(std::string value) { fragment_ = value; }
  void user_info(std::string value) { user_info_ = value; }

  std::string str();
  operator std::string() { return this->str(); }
};
} // namespace http
} // namespace net