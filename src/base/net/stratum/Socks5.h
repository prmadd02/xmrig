/* XMRig
 * Copyright 2018-2020 SChernykh   <https://github.com/SChernykh>
 * Copyright 2016-2020 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef XMRIG_SOCKS5_H
#define XMRIG_SOCKS5_H


#include "base/net/stratum/Client.h"


namespace xmrig {


class Client::Socks5
{
public:
    Socks5(Client *client);

    inline bool isReady() const     { return m_state == Ready; }

    bool read(const char *data, size_t size);
    void handshake();

private:
    enum State {
        Created,
        SentInitialHandshake,
        SentFinalHandshake,
        Ready
    };

    bool isIPv4(const String &host) const;
    bool isIPv6(const String &host) const;
    void connect();

    Client *m_client;
    size_t m_nextSize   = 0;
    State m_state       = Created;
};


} /* namespace xmrig */


#endif /* XMRIG_SOCKS5_H */
