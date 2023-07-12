#include "url.h"

#include "url_parser.h"

net::http::url::url(url &&other) noexcept { this->swap(other); }

net::http::url::url(const url &other) noexcept
    : schema_{other.schema_}, host_{other.host_}, port_{other.port_},
      path_{other.path_}, query_{other.query_}, fragment_{other.fragment_},
      user_info_{other.user_info_} {}

net::http::url::url(const url_parser &parser) noexcept { *this = parser; }

net::http::url::url(const std::string &url) { *this = url; }

void net::http::url::swap(url &other) noexcept {
  std::swap(schema_, other.schema_);
  std::swap(host_, other.host_);
  std::swap(port_, other.port_);
  std::swap(path_, other.path_);
  std::swap(query_, other.query_);
  std::swap(fragment_, other.fragment_);
  std::swap(user_info_, other.user_info_);
}

net::http::url &net::http::url::operator=(url &&other) noexcept {
  if (this != &other)
    this->swap(other);
  return *this;
}

net::http::url &net::http::url::operator=(const url &other) noexcept {
  if (this == &other)
    return *this;

  schema_ = other.schema_;
  host_ = other.host_;
  port_ = other.port_;
  path_ = other.path_;
  query_ = other.query_;
  fragment_ = other.fragment_;
  user_info_ = other.user_info_;
  return *this;
}

net::http::url &net::http::url::operator=(const url_parser &parser) noexcept {
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
  return *this;
}

net::http::url &net::http::url::operator=(const std::string &url) {
  const url_parser parser{url};
  *this = parser;
  return *this;
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
    if (path_.at(0) != '/')
      out += "/";
    out += path_;
  }
  if (this->has_query())
    out += "?" + query_;
  if (this->has_fragment())
    out += "#" + fragment_;
  return out;
}
