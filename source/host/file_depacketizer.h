//
// PROJECT:         Aspia
// FILE:            host/file_depacketizer.h
// LICENSE:         GNU General Public License 3
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_HOST__FILE_DEPACKETIZER_H
#define _ASPIA_HOST__FILE_DEPACKETIZER_H

#include <QFile>
#include <QPointer>
#include <memory>

#include "protocol/file_transfer_session.pb.h"

namespace aspia {

class FileDepacketizer
{
public:
    ~FileDepacketizer() = default;

    static std::unique_ptr<FileDepacketizer> create(const QString& file_path, bool overwrite);

    // Reads the packet and writes its contents to a file.
    bool writeNextPacket(const proto::file_transfer::Packet& packet);

private:
    FileDepacketizer(QPointer<QFile>& file_stream);

    QPointer<QFile> file_;

    qint64 file_size_ = 0;
    qint64 left_size_ = 0;

    Q_DISABLE_COPY(FileDepacketizer)
};

} // namespace aspia

#endif // _ASPIA_HOST__FILE_DEPACKETIZER_H
