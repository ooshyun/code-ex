
#include <iostream>
#include "curl/curl.h"
CURL *_curl_request = curl_easy_init();

template <typename T>
void add_option(CURLoption option, T option_value) {
  if (_curl_request) curl_easy_setopt(_curl_request, option, option_value);
}

static size_t response_header_parser(void *ptr, size_t size, size_t n_memb,
                                     std::string *userdata) {

}

static size_t default_write_cb(void *ptr, size_t size, size_t n_memb,
                               std::string *userdata) {
  std::string res(static_cast<char *>(ptr), n_memb);
  res.push_back('\0');
  return n_memb;
}

void test_client_http(void) {
  
  if (_curl_request == nullptr) return false;

  std::string header_buffer;
  std::string error_buffer;
  std::string body_buffer;

  add_option<const char *>(CURLOPT_URL, "http://localhost:8080");
  add_option(CURLOPT_HEADERFUNCTION, response_header_parser);
  add_option(CURLOPT_HEADERDATA, &header_buffer);
  add_option(CURLOPT_SSL_VERIFYPEER, false);
  add_option(CURLOPT_FAILONERROR, true);
  add_option(CURLOPT_ERRORBUFFER, error_buffer);
  add_option(CURLOPT_WRITEFUNCTION, default_write_cb);
  add_option(CURLOPT_WRITEDATA, &body_buffer);

}