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

#if !defined __VTCP_HAVE_DEAMON_HPP__
#define __VTCP_HAVE_DEAMON_HPP__

#include <map>
#include <set>

class daemon_t
{
public:

    daemon_t ();
    ~daemon_t ();

    int run (int port_);

private:

    //  The data structure to hold all the connections from the local apps.
    typedef std::set <int> connections_t;
    connections_t connections;

    //  The data structure to hold all the subport registrations.
    typedef std::map <int, int> registrations_t;
    registrations_t registrations;

    //  Disable copying of the class.
    daemon_t (const daemon_t&);
    const daemon_t &operator = (const daemon_t&);
};

#endif
