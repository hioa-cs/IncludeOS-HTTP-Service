// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015-2016 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef HTTP_STATUS_CODES_HPP
#define HTTP_STATUS_CODES_HPP

#include <unordered_map>

#include "status_code_constants.hpp"

namespace http {
//------------------------------------------------
using Code              = int;
using Description       = const char*;
using Status_code_table = std::unordered_map<Code, Description>;
//------------------------------------------------
const Status_code_table status_codes {
  //< 1xx: Informational - Request received, continuing process
  {100, "Continue"},
  {101, "Switching Protocols"},
  {102, "Processing"},

  //< 2xx: Success - The action was successfully received, understood, and accepted
  {200, "OK"},
  {201, "Created"},
  {202, "Accepted"},
  {203, "Non-Authoritative Information"},
  {204, "No Content"},
  {205, "Reset Content"},
  {206, "Partial Content"},
  {207, "Multi-Status"},
  {208, "Already Reported"},
  {226, "IM Used"},

  //< 3xx: Redirection - Further action must be taken in order to complete the request
  {300, "Multiple Choices"},
  {301, "Moved Permanently"},
  {302, "Found"},
  {303, "See Other"},
  {304, "Not Modified"},
  {305, "Use Proxy"},
  {307, "Temporary Redirect"},
  {308, "Permanent Redirect"},

  //< 4xx: Client Error - The request contains bad syntax or cannot be fulfilled
  {400, "Bad Request"},
  {401, "Unauthorized"},
  {402, "Payment Required"},
  {403, "Forbidden"},
  {404, "Not Found"},
  {405, "Method Not Allowed"},
  {406, "Not Acceptable"},
  {407, "Proxy Authentication Required"},
  {408, "Request Timeout"},
  {409, "Conflict"},
  {410, "Gone"},
  {411, "Length Required"},
  {412, "Precondition Failed"},
  {413, "Payload Too Large"},
  {414, "URI Too Long"},
  {415, "Unsupported Media Type"},
  {416, "Range Not Satisfiable"},
  {417, "Expectation Failed"},
  {421, "Misdirected Request"},
  {422, "Unprocessable Entity"},
  {423, "Locked"},
  {424, "Failed Dependency"},
  {426, "Upgrade Required"},
  {428, "Precondition Required"},
  {429, "Too Many Requests"},
  {431, "Request Header Fields Too Large"},

  //< 5xx: Server Error - The server failed to fulfill an apparently valid request
  {500, "Internal Server Error"},
  {501, "Not Implemented"},
  {502, "Bad Gateway"},
  {503, "Service Unavailable"},
  {504, "Gateway Timeout"},
  {505, "HTTP Version Not Supported"},
  {506, "Variant Also Negotiates"},
  {507, "Insufficient Storage"},
  {508, "Loop Detected"},
  {510, "Not Extended"},
  {511, "Network Authentication Required"}
}; //< status_codes

inline Description code_description(const Code code) noexcept {
  auto iter = status_codes.find(code);
  return (iter not_eq status_codes.end()) ? iter->second : "Internal Server Error";
}

inline bool is_informational(const status_t status_code) noexcept {
  return (status_code >= Continue) && (status_code <= Processing);
}

inline bool is_success(const status_t status_code) noexcept {
  return (status_code >= OK) && (status_code <= IM_Used);
}

inline bool is_redirection(const status_t status_code) noexcept {
  return (status_code >= Multiple_Choices) && (status_code <= Permanent_Redirect);
}

inline bool is_client_error(const status_t status_code) noexcept {
  return (status_code >= Bad_Request) && (status_code <= Request_Header_Fields_Too_Large);
}

inline bool is_server_error(const status_t status_code) noexcept {
  return (status_code >= Internal_Server_Error) && (status_code <= Network_Authentication_Required);
}

} //< namespace http

#endif //< HTTP_STATUS_CODES_HPP
