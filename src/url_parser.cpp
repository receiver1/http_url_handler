#include "url_parser.h"

#include <http_parser.h>

static bool has_field(http_parser_url* const parser, const http_parser_url_fields field) {
  return static_cast<bool>(parser->field_set & (1 << field));
}

static std::string get_field(http_parser_url* const parser, const http_parser_url_fields field,
                             const std::string& url_parser) {
  auto it = url_parser.begin() + parser->field_data[field].off;
  return std::string{it, it + parser->field_data[field].len};
}

net::http::url_parser::url_parser(const std::string& url_parser)
    : url_{url_parser}, parser_{new http_parser_url} {
  http_parser_url_init(parser_);
  const auto error = http_parser_parse_url(url_parser.c_str(), url_parser.size(), false, parser_);
  if (error) throw http_errno_name(http_errno(error));
}

net::http::url_parser::~url_parser() { delete parser_; }

std::string net::http::url_parser::schema() const { return get_field(parser_, UF_SCHEMA, url_); }

std::string net::http::url_parser::host() const { return get_field(parser_, UF_HOST, url_); }

std::uint16_t net::http::url_parser::port() const { return parser_->port; }

std::string net::http::url_parser::path() const { return get_field(parser_, UF_PATH, url_); }

std::string net::http::url_parser::query() const { return get_field(parser_, UF_QUERY, url_); }

std::string net::http::url_parser::fragment() const {
  return get_field(parser_, UF_FRAGMENT, url_);
}

std::string net::http::url_parser::user_info() const {
  return get_field(parser_, UF_USERINFO, url_);
}

bool net::http::url_parser::has_schema() const { return has_field(parser_, UF_SCHEMA); }

bool net::http::url_parser::has_host() const { return has_field(parser_, UF_HOST); }

bool net::http::url_parser::has_port() const { return has_field(parser_, UF_PORT); }

bool net::http::url_parser::has_path() const { return has_field(parser_, UF_PATH); }

bool net::http::url_parser::has_query() const { return has_field(parser_, UF_QUERY); }

bool net::http::url_parser::has_fragment() const { return has_field(parser_, UF_FRAGMENT); }

bool net::http::url_parser::has_user_info() const { return has_field(parser_, UF_USERINFO); }
