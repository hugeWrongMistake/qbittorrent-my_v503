
#include <libtorrent/torrent.hpp>

namespace myutils
{
    ::libtorrent::peer_id lt_torrent_handle_get_peer_id(::libtorrent::torrent_handle th);

    void lt_torrent_handle_set_peer_id(::libtorrent::torrent_handle th, const char *strid);
    void lt_torrent_handle_set_peer_id(::libtorrent::torrent_handle th, const ::libtorrent::peer_id &id);

}