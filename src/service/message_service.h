#include <stdint.h>
#include "common/message.h"

namespace MessageService {
    int send_msg(uint8_t msg_id, const message_t& msg); // TODO
    message_t recv_msg(uint8_t msg_id);
}