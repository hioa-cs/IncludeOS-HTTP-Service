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

#ifndef HTTP_HEADER_FIELDS_HPP
#define HTTP_HEADER_FIELDS_HPP

#include <string>

namespace http {
namespace header_fields {
//------------------------------------------------
using Field = const std::string;
//------------------------------------------------
//------------------------------------------------
namespace Request {
Field Accept              {"Accept"};
Field Accept_Charset      {"Accept-Charset"};
Field Accept_Encoding     {"Accept-Encoding"};
Field Accept_Language     {"Accept-Language"};
Field Authorization       {"Authorization"};
Field Connection          {"Connection"};
Field Cookie              {"Cookie"};
Field Expect              {"Expect"};
Field From                {"From"};
Field Host                {"Host"};
Field HTTP2_Settings      {"HTTP2-Settings"};
Field If_Match            {"If-Match"};
Field If_Modified_Since   {"If-Modified-Since"};
Field If_None_Match       {"If-None-Match"};
Field If_Range            {"If-Range"};
Field If_Unmodified_Since {"If-Unmodified-Since"};
Field Max_Forwards        {"Max-Forwards"};
Field Proxy_Authorization {"Proxy-Authorization"};
Field Range               {"Range"};
Field Referer             {"Referer"};
Field TE                  {"TE"};
Field Upgrade             {"Upgrade"};
Field User_Agent          {"User-Agent"};
} //< namespace Request
//------------------------------------------------
//------------------------------------------------
namespace Response {
Field Accept_Ranges       {"Accept-Ranges"};
Field Age                 {"Age"};
Field Connection          {"Connection"};
Field ETag                {"ETag"};
Field Location            {"Location"};
Field Proxy_Authenticate  {"Proxy-Authenticate"};
Field Retry_After         {"Retry-After"};
Field Server              {"Server"};
Field Set_Cookie          {"Set-Cookie"};
Field Upgrade             {"Upgrade"};
Field Vary                {"Vary"};
Field WWW_Authenticate    {"WWW-Authenticate"};
} //< namespace Response
//------------------------------------------------
//------------------------------------------------
namespace Entity {
Field Allow               {"Allow"};
Field Content_Encoding    {"Content-Encoding"};
Field Content_Language    {"Content-Language"};
Field Content_Length      {"Content-Length"};
Field Content_Location    {"Content-Location"};
Field Content_MD5         {"Content-MD5"};
Field Content_Range       {"Content-Range"};
Field Content_Type        {"Content-Type"};
Field Expires             {"Expires"};
Field Last_Modified       {"Last-Modified"};
} //< namespace Entity
//------------------------------------------------
//------------------------------------------------
} //< namespace header_fields
} //< namespace http

#endif //< HTTP_HEADER_FIELDS_HPP
