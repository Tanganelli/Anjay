# Copyright 2017-2019 AVSystem <avsystem@avsystem.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

target_sources(anjay PRIVATE
               ${CMAKE_CURRENT_SOURCE_DIR}/src/mod_security.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/security_transaction.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/security_utils.h
               ${CMAKE_CURRENT_SOURCE_DIR}/include_public/anjay/security.h
               ${CMAKE_CURRENT_SOURCE_DIR}/src/mod_security.c
               ${CMAKE_CURRENT_SOURCE_DIR}/src/security_persistence.c
               ${CMAKE_CURRENT_SOURCE_DIR}/src/security_transaction.c
               ${CMAKE_CURRENT_SOURCE_DIR}/src/security_utils.c)
target_include_directories(anjay PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_public>)

install(DIRECTORY include_public/anjay
        DESTINATION include
        FILES_MATCHING REGEX "[.]h$")
