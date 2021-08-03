#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H
#include <stdint.h>
#include "common/message.h"
#include <vector>

namespace MessageService {
    int send_msg(uint8_t msg_id, const message_t& msg); // TODO
    std::vector<message_t> wait_msgs(uint8_t msg_id);
}

#endif