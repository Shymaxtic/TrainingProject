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

#include "base_manager.h"
#include <chrono>
#include <ctime>
#include <iostream>

void BaseManager::execute() {
    m_task_scheduler.run();
    m_msg_receiver.listen_msg();
}

void BaseManager::init_task_scheduler() {
    int result = m_task_scheduler.register_task([] (int){
        auto current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        std::cout  << std::ctime(&current_time) << "\n";

    });
    
}


void BaseManager::init_msg_receiver() {
    
}