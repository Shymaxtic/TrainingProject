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
#include "manager/base_manager.h"
#include <iostream>
#include "service/message_service.h"
#include <unistd.h>

int main() {
    BaseManager base_manager(0);
    base_manager.execute();

    BaseManager base_manager2(1);
    base_manager2.execute();
    int i = 100;
    while (i--)
    {
        message_t dummy;
        // printf("sending message %d\n", i);
        MessageService::send_msg(i%2, dummy);
        usleep(1000000);
    }
    
    getchar();
    
    return 0;
}