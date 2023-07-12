#ifndef URL_WRAPPER_URL_PARSER_H
#define URL_WRAPPER_URL_PARSER_H

#include <string>

class http_parser_url;

namespace net {
namespace http {
class url_parser {
  std::string url_;
  http_parser_url *parser_;

 public:
  url_parser(const std::string& url_parser);
  ~url_parser();

  std::string schema() const;
  std::string host() const;
  std::uint16_t port() const;
  std::string path() const;
  std::string query() const;
  std::string fragment() const;
  std::string user_info() const;

  std::string str() const { return url_; }
  operator std::string() { return url_; }
  operator const char*() { return url_.c_str(); }

  bool has_schema() const;
  bool has_host() const;
  bool has_port() const;
  bool has_path() const;
  bool has_query() const;
  bool has_fragment() const;
  bool has_user_info() const;
};
}  // namespace http
}  // namespace net

#endif  // URL_WRAPPER_URL_PARSER_H
