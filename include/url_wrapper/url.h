#ifndef URL_WRAPPER_URL_H
#define URL_WRAPPER_URL_H

#include <string>

namespace net {
namespace http {
class url_parser;

class url {
public:
  url() = default;
  url(url &&other) noexcept;              // self move construct
  url(const url &other) noexcept;         // self copy construct
  url(const url_parser &parser) noexcept; // parser copy construct
  url(const std::string &url);

  // getters
  std::string schema() const { return schema_; }
  std::string host() const { return host_; }
  std::uint16_t port() const { return port_; }
  std::string path() const { return path_; }
  std::string query() const { return query_; }
  std::string fragment() const { return fragment_; }
  std::string user_info() const { return user_info_; }

  // checkers
  bool has_schema() const { return !schema_.empty(); }
  bool has_host() const { return !host_.empty(); };
  bool has_port() const { return port_ > 0; }
  bool has_path() const { return !path_.empty(); }
  bool has_query() const { return !query_.empty(); }
  bool has_fragment() const { return !fragment_.empty(); }
  bool has_user_info() const { return !user_info_.empty(); }

  // setters
  void swap(url &other) noexcept;
  url &operator=(url &&other) noexcept;              // self move assign
  url &operator=(const url &other) noexcept;         // self copy assign
  url &operator=(const url_parser &parser) noexcept; // parser copy assign
  url &operator=(const std::string &url);
  void schema(const std::string &value) { schema_ = value; }
  void host(const std::string &value) { host_ = value; }
  void port(const std::uint16_t value) { port_ = value; }
  void path(const std::string &value) { path_ = value; }
  void query(const std::string &value) { query_ = value; }
  void fragment(const std::string &value) { fragment_ = value; }
  void user_info(const std::string &value) { user_info_ = value; }

  // builders
  std::string str();
  operator std::string() { return this->str(); }

private:
  std::string schema_{}, host_{}, path_{}, query_{}, fragment_{}, user_info_{};
  std::uint16_t port_{};
};
} // namespace http
} // namespace net

#endif // URL_WRAPPER_URL_H
