#ifndef MY_MESSAGE_H
#define MY_MESSAGE_H

#include <stdint.h>
#include <mutex>
#include <deque>
#include <condition_variable>

typedef struct message_t
{
    uint8_t msg_len;
    uint8_t* msg_data;
} message_t;

typedef struct message_queue_t
{
    std::mutex my_locker;
    std::condition_variable my_cv;
    std::deque<message_t> msg_queue; 
} message_queue_t;

#define MSG_COMMONAPI_ID     0
#define MSG_SOMEIP_ID        1
#define MSG_POOL_LEN         2

extern message_queue_t MSG_POOL[MSG_POOL_LEN];

#endif