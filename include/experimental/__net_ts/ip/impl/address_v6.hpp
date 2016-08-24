//
// ip/impl/address_v6.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef NET_TS_IP_IMPL_ADDRESS_V6_HPP
#define NET_TS_IP_IMPL_ADDRESS_V6_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#if !defined(NET_TS_NO_IOSTREAM)

#include <experimental/__net_ts/detail/throw_error.hpp>

#include <experimental/__net_ts/detail/push_options.hpp>

namespace std {
namespace experimental {
namespace net {
inline namespace v1 {
namespace ip {

#if !defined(NET_TS_NO_DEPRECATED)

inline address_v6 address_v6::from_string(const char* str)
{
  return std::experimental::net::ip::make_address_v6(str);
}

inline address_v6 address_v6::from_string(
    const char* str, std::error_code& ec)
{
  return std::experimental::net::ip::make_address_v6(str, ec);
}

inline address_v6 address_v6::from_string(const std::string& str)
{
  return std::experimental::net::ip::make_address_v6(str);
}

inline address_v6 address_v6::from_string(
    const std::string& str, std::error_code& ec)
{
  return std::experimental::net::ip::make_address_v6(str, ec);
}

#endif // !defined(NET_TS_NO_DEPRECATED)

template <typename Elem, typename Traits>
std::basic_ostream<Elem, Traits>& operator<<(
    std::basic_ostream<Elem, Traits>& os, const address_v6& addr)
{
  return os << addr.to_string().c_str();
}

} // namespace ip
} // inline namespace v1
} // namespace net
} // namespace experimental
} // namespace std

#include <experimental/__net_ts/detail/pop_options.hpp>

#endif // !defined(NET_TS_NO_IOSTREAM)

#endif // NET_TS_IP_IMPL_ADDRESS_V6_HPP