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

#ifndef HTTP_ROUTER_HPP
#define HTTP_ROUTER_HPP

#include <functional>
#include <request.hpp>
#include <response.hpp>
#include <unordered_map>

namespace std {

template <>
class hash<std::pair<std::string, std::string>> {
public:
  size_t operator()(const std::pair<std::string, std::string>& key) const {
    return std::hash<std::string>{}(key.first + key.second);
  }
};

} // namespace std

namespace http {

//-------------------------------
// This class is used to provide
// route resolution
//-------------------------------
class Router {
private:
  //-------------------------------
  // Internal class type aliases
  //-------------------------------
  using Method      = std::string;
  using URI         = std::string;
  using Route       = std::pair<Method, URI>;
  using Result      = std::function<void(const Request&, Response&)>;
  using Route_Table = std::unordered_map<Route, Result>;
  //-------------------------------
public:
  //-------------------------------
  // Default constructor to set up
  // default routes
  //-------------------------------
  explicit Router();

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_options(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_get(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_head(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_post(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_put(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_delete(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_trace(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_connect(Routee&& route, Result result);

  //-------------------------------
  // Add a route mapping for route
  // resolution upon request
  //
  // @tparam (std::string) route - The route to map unto a
  //                               resulting destination
  //
  // @param result - The route mapping
  //
  // @return - The object that invoked this method
  //-------------------------------
  template <typename Routee>
  Router& on_patch(Routee&& route, Result result);
  
  //-------------------------------
  // Send route informaton to retrieve
  // result
  //
  // @param route - The route information
  //
  // @result - The result from sending the route
  //           information
  //-------------------------------
  Result& operator [] (const Route& route) const;

  //-------------------------------
  // Check to see if a route exist
  // in the router's route table
  //
  // @param route - The route to search for
  //
  // @return - true is route exist, false otherwise
  //-------------------------------
  bool route_exist(const Route& route) const noexcept;
  //-------------------------------
private:
  //-------------------------------
  // Class data members
  //-------------------------------
  static Route_Table route_table_;

  //-----------------------------------
  // Deleted move and copy operations
  //-----------------------------------
  Router(const Router&) = delete;
  Router(Router&&) = delete;

  //-----------------------------------
  // Deleted move and copy assignment operations
  //-----------------------------------
  Router& operator = (const Router&) = delete;
  Router& operator = (Router&&) = delete;

  //-----------------------------------
  // This method initializes the route
  // table with default route resolutions
  //-----------------------------------
  void initialize_default_configuration();
}; //< class Router

Router::Route_Table Router::route_table_;

inline Router::Router() {
  initialize_default_configuration();
}

template <typename Routee>
inline Router& Router::on_options(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::OPTIONS, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_get(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::GET, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_head(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::HEAD, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_post(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::POST, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_put(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::PUT, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_delete(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::DELETE, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_trace(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::TRACE, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_connect(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::CONNECT, std::forward<Routee>(route)), result);
  return *this;
}

template <typename Routee>
inline Router& Router::on_patch(Routee&& route, Result result) {
  route_table_.emplace(std::make_pair(http::method::PATCH, std::forward<Routee>(route)), result);
  return *this;
}

inline Router::Result& Router::operator [] (const Route& route) const {
  static Route route404 {http::method::GET, "404"};
  //-------------------------------
  if (route_exist(route)) return route_table_[route];
  //-------------------------------
  return route_table_[route404];
}

inline bool Router::route_exist(const Route& route) const noexcept {
  return route_table_.find(route) not_eq route_table_.end();
}

inline void Router::initialize_default_configuration() {
  using namespace std;
  //-----------------------------------
  route_table_.emplace(std::make_pair(http::method::GET, "404"), [](const Request&, Response& res) {
    res.reset()
       .set_status_code(Not_Found)
       .add_header(header_fields::Response::Server, "IncludeOS/v0.7.0"s)
       .add_header(header_fields::Entity::Content_Type, "text/html"s)
       .add_body("<h1>PAGE NOT FOUND</h1>"s);
  });
}

} //< namespace http

#endif //< HTTP_ROUTER_HPP
