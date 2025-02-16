/*
    Copyright (c) 2007-2016 Contributors as noted in the AUTHORS file

    This file is part of libzmq, the ZeroMQ core engine in C++.

    libzmq is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    As a special exception, the Contributors give you permission to link
    this library with independent modules to produce an executable,
    regardless of the license terms of these independent modules, and to
    copy and distribute the resulting executable under terms of your choice,
    provided that you also meet, for each linked independent module, the
    terms and conditions of the license of that module. An independent
    module is a module which is not derived from or based on this library.
    If you modify this library, you must extend this exception to your
    version of the library.

    libzmq is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
    License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_IPC_ADDRESS_HPP_INCLUDED__
#define __ZMQ_IPC_ADDRESS_HPP_INCLUDED__

#if defined ZMQ_HAVE_IPC

#include <string>

#if defined _WIN32
#include <afunix.h>
#else
#include <sys/socket.h>
#include <sys/un.h>
#endif

#include "macros.hpp"

namespace zmq
{
class ipc_address_t
{
  public:
    ipc_address_t ();
    ipc_address_t (const sockaddr *sa_, socklen_t sa_len_);
    ~ipc_address_t ();

    //  This function sets up the address for UNIX domain transport.
    int resolve (const char *path_);

    //  The opposite to resolve()
    int to_string (std::string &addr_) const;

    const sockaddr *addr () const;
    socklen_t addrlen () const;

  private:
    struct sockaddr_un _address;
    socklen_t _addrlen;

    ZMQ_NON_COPYABLE_NOR_MOVABLE (ipc_address_t)
};
}

#endif

#endif
