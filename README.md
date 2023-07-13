# http_url_handler

It is a parser and link builder.
This project uses https://github.com/nodejs/http-parser for link parsing. I use vcpkg to connect it.

Parsing URL:
```cpp
net::http::url url{"https://user@host:8080/path?query=value#fragment"};
std::cout << url.str() << std::endl;
```

Building URL from scratch:
```cpp
net::http::url url{};
url.schema("https");
url.user_info("user");
url.host("host");
url.port(8080);
url.path("/path");
url.query("query=value");
url.fragment("fragment");
std::cout << url.str() << std::endl;
```

Parsing URL query:
```cpp
auto query = net::http::parse_query(url.query());
for (auto& [key, value] : query) {
  // ...
}
```
