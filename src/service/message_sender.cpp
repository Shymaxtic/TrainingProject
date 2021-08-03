// Copyright (C) 2021 Shymaxtic
// 
// This file is part of TrainingProject.
// 
// TrainingProject is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// TrainingProject is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with TrainingProject.  If not, see <http://www.gnu.org/licenses/>.
#include "message_sender.h"
#include <unistd.h>
#include "message_service.h"

MessageSender::MessageSender()
{

}

MessageSender::~MessageSender()
{
}

int MessageSender::send_message(const message_t& msg, const int& msg_id) {
    MessageService::send_msg(msg_id, msg);
    return 0;
}