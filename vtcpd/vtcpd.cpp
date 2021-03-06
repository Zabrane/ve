/*
    Copyright (c) 2011 Martin Sustrik

    This file is part of vtcp project.

    vtcp is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "daemon.hpp"

int main (int argc, char *argv [])
{
    //  Determine the port number to mutliplex.
    int port;
    if (argc == 1)
        port = 9220;
    else if (argc == 2)
        port = atoi (argv [1]);
    else {
        printf ("usage: vtcpd [port]\n");
        return 1;
    }

    //  Start the daemon.
    daemon_t daemon;
    int rc = daemon.run (port);
    if (rc != 0) {
        printf ("Error: %s\n", strerror (errno));
        return 1;
    }
    return 0;
}
