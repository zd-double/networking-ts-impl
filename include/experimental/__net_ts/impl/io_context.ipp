//
// impl/io_context.ipp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef NET_TS_IMPL_IO_CONTEXT_IPP
#define NET_TS_IMPL_IO_CONTEXT_IPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <experimental/__net_ts/detail/config.hpp>
#include <experimental/__net_ts/io_context.hpp>
#include <experimental/__net_ts/detail/limits.hpp>
#include <experimental/__net_ts/detail/scoped_ptr.hpp>
#include <experimental/__net_ts/detail/service_registry.hpp>
#include <experimental/__net_ts/detail/throw_error.hpp>

#if defined(NET_TS_HAS_IOCP)
# include <experimental/__net_ts/detail/win_iocp_io_context.hpp>
#else
# include <experimental/__net_ts/detail/scheduler.hpp>
#endif

#include <experimental/__net_ts/detail/push_options.hpp>

namespace std {
namespace experimental {
namespace net {
inline namespace v1 {

io_context::io_context()
  : impl_(add_impl(new impl_type(*this)))
{
}

io_context::io_context(int concurrency_hint)
  : impl_(add_impl(new impl_type(*this, concurrency_hint)))
{
}

io_context::impl_type& io_context::add_impl(io_context::impl_type* impl)
{
  std::experimental::net::detail::scoped_ptr<impl_type> scoped_impl(impl);
  std::experimental::net::add_service<impl_type>(*this, scoped_impl.get());
  return *scoped_impl.release();
}

io_context::~io_context()
{
}

io_context::count_type io_context::run()
{
  std::error_code ec;
  count_type s = impl_.run(ec);
  std::experimental::net::detail::throw_error(ec);
  return s;
}

#if !defined(NET_TS_NO_DEPRECATED)
io_context::count_type io_context::run(std::error_code& ec)
{
  return impl_.run(ec);
}
#endif // !defined(NET_TS_NO_DEPRECATED)

io_context::count_type io_context::run_one()
{
  std::error_code ec;
  count_type s = impl_.run_one(ec);
  std::experimental::net::detail::throw_error(ec);
  return s;
}

#if !defined(NET_TS_NO_DEPRECATED)
io_context::count_type io_context::run_one(std::error_code& ec)
{
  return impl_.run_one(ec);
}
#endif // !defined(NET_TS_NO_DEPRECATED)

io_context::count_type io_context::poll()
{
  std::error_code ec;
  count_type s = impl_.poll(ec);
  std::experimental::net::detail::throw_error(ec);
  return s;
}

#if !defined(NET_TS_NO_DEPRECATED)
io_context::count_type io_context::poll(std::error_code& ec)
{
  return impl_.poll(ec);
}
#endif // !defined(NET_TS_NO_DEPRECATED)

io_context::count_type io_context::poll_one()
{
  std::error_code ec;
  count_type s = impl_.poll_one(ec);
  std::experimental::net::detail::throw_error(ec);
  return s;
}

#if !defined(NET_TS_NO_DEPRECATED)
io_context::count_type io_context::poll_one(std::error_code& ec)
{
  return impl_.poll_one(ec);
}
#endif // !defined(NET_TS_NO_DEPRECATED)

void io_context::stop()
{
  impl_.stop();
}

bool io_context::stopped() const
{
  return impl_.stopped();
}

void io_context::restart()
{
  impl_.restart();
}

io_context::service::service(std::experimental::net::io_context& owner)
  : execution_context::service(owner)
{
}

io_context::service::~service()
{
}

void io_context::service::shutdown()
{
#if !defined(NET_TS_NO_DEPRECATED)
  shutdown_service();
#endif // !defined(NET_TS_NO_DEPRECATED)
}

#if !defined(NET_TS_NO_DEPRECATED)
void io_context::service::shutdown_service()
{
}
#endif // !defined(NET_TS_NO_DEPRECATED)

void io_context::service::notify_fork(io_context::fork_event ev)
{
#if !defined(NET_TS_NO_DEPRECATED)
  fork_service(ev);
#else // !defined(NET_TS_NO_DEPRECATED)
  (void)ev;
#endif // !defined(NET_TS_NO_DEPRECATED)
}

#if !defined(NET_TS_NO_DEPRECATED)
void io_context::service::fork_service(io_context::fork_event)
{
}
#endif // !defined(NET_TS_NO_DEPRECATED)

} // inline namespace v1
} // namespace net
} // namespace experimental
} // namespace std

#include <experimental/__net_ts/detail/pop_options.hpp>

#endif // NET_TS_IMPL_IO_CONTEXT_IPP