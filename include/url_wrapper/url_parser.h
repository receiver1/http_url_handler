#ifndef URL_WRAPPER_URL_PARSER_H
#define URL_WRAPPER_URL_PARSER_H

#include <string>

struct http_parser_url;

namespace net {
namespace http {
class url_parser {
 public:
  url_parser(url_parser &&other) noexcept;
  url_parser(const url_parser &other) noexcept;  // copy construct
  url_parser(const std::string &url);
  ~url_parser();

  // getters
  std::string schema() const;
  std::string host() const;
  std::uint16_t port() const;
  std::string path() const;
  std::string query() const;
  std::string fragment() const;
  std::string user_info() const;

  std::string str() const { return url_; }
  operator std::string() { return url_; }
  operator const char *() { return url_.c_str(); }

  // checkers
  bool has_schema() const;
  bool has_host() const;
  bool has_port() const;
  bool has_path() const;
  bool has_query() const;
  bool has_fragment() const;
  bool has_user_info() const;

  // setters
  void swap(url_parser &other) noexcept;
  url_parser &operator=(url_parser &&other) noexcept;       // move assign
  url_parser &operator=(const url_parser &other) noexcept;  // copy assign

 private:
  std::string url_{};
  http_parser_url *parser_{nullptr};
};
}  // namespace http
}  // namespace net

#endif  // URL_WRAPPER_URL_PARSER_H
