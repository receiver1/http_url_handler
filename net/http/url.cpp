#include "url.h"
#include "url_parser.h"

net::http::url::url(const std::string url) {
  url_parser parser{url};
  if (parser.has_schema())
    schema_ = parser.schema();
  if (parser.has_host())
    host_ = parser.host();
  if (parser.has_port())
    port_ = parser.port();
  if (parser.has_path())
    path_ = parser.path();
  if (parser.has_query())
    query_ = parser.query();
  if (parser.has_fragment())
    fragment_ = parser.fragment();
  if (parser.has_user_info())
    user_info_ = parser.user_info();
}

std::string net::http::url::str() {
  std::string out{};
  if (this->has_schema())
    out += schema_ + "://";
  if (this->has_user_info())
    out += user_info_ + "@";
  out += host_;
  if (this->has_port())
    out += ":" + std::to_string(port_);
  if (this->has_path()) {
    if (path_[0] != '/')
      out += "/";
    out += path_;
  }
  if (this->has_query())
    out += "?" + query_;
  if (this->has_fragment())
    out += "#" + fragment_;
  return out;
}
