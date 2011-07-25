/*
    Copyright (c) 2011 Martin Sustrik

    This file is part of vtcp project.

    vtcp is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __VTCP_H_INCLUDED__
#define __VTCP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <arpa/inet.h>

typedef uint32_t vtcp_subport_t;

/*  To start connecting call vtcp_connect function. When the returned file    */
/*  descriptor becomes writeable the connection has became established and    */
/*  you can acceipt it using vtcp_acceptc function. Note that vtcp_acceptc    */
/*  doesn't produce new file descriptor, you are meant to use the one         */
/*  returned by vtcp connect function to pass data. If vtcp_acceptc is called */
/*  without waiting for the file descriptor to become writeable the function  */
/*  blocks until the connection is established.                               */
int vtcp_connect (in_addr_t address, in_port_t port);
int vtcp_acceptc (int fd, vtcp_subport_t subport);

/*  To start listening on a specific subport use vtcp_bind function. When     */
/*  the returned file descriptor becomes readable you can get the file        */
/*  descriptor for the new connection using vtcp_acceptb function. This can   */
/*  be done arbitrary number of times. If vtcp_acceptb is called without      */
/*  waiting for the file descriptor to become readable the function blocks    */
/*  until there's a new incoming connection.                                  */
/*  Note that vtcp_bind always binds to all the available network interfaces. */
int vtcp_bind (in_port_t port, vtcp_subport_t subport);
int vtcp_acceptb (int fd);

#ifdef __cplusplus
}
#endif

#endif

