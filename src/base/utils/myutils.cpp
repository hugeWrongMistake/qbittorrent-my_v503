// include system header before access hack !
#include <sstream>
#include <any>

#define private public
#define protected public
#include "myutils.h"
#undef private
#undef protected

#include "base/logger.h"

using ::libtorrent::peer_id;
using ::libtorrent::torrent_handle;

namespace myutils
{
    
peer_id lt_torrent_handle_get_peer_id(torrent_handle nativeHandle)
{
    auto t = nativeHandle.m_torrent.lock();
    auto ret = t->m_peer_id.to_string();
    LogMsg(QStringLiteral("read peer_id from torrent_handle : %1")
               .arg(QString::fromStdString(ret)),
           Log::NORMAL);
    return t->m_peer_id;
}

void lt_torrent_handle_set_peer_id(torrent_handle th, const char *strid)
{
    auto t = th.m_torrent.lock();
    if (strlen(strid) == (size_t)t->m_peer_id.size())
    {
        LogMsg(QStringLiteral("Change peer_id from %1 to %2")
                   .arg(QString::fromStdString(t->m_peer_id.to_string()))
                   .arg(QString::fromStdString(strid)),
               Log::NORMAL);
        memcpy(t->m_peer_id.data(), strid, t->m_peer_id.size());
    }
    else
    {
        LogMsg(QStringLiteral("No need to change peer_id from %1 ")
                   .arg(QString::fromStdString(t->m_peer_id.to_string())),
               Log::NORMAL);
    }
}

void lt_torrent_handle_set_peer_id(torrent_handle th, const peer_id &id)
{
    lt_torrent_handle_set_peer_id(th, id.to_string().c_str());
}

    
} // namespace myutils

