/*
 * Copyright 2017-2019 AVSystem <avsystem@avsystem.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef LOG
#    undef LOG
#endif

#ifdef WITH_AVS_COAP_LOGS
#    ifdef WITH_AVS_COAP_TRACE_LOGS
#        define AVS_LOG_WITH_TRACE
#    endif
#    include <avsystem/commons/log.h>
#    define LOG(...) avs_log(MODULE_NAME, __VA_ARGS__)
#else // WITH_AVS_COAP_LOGS
#    define LOG(...) ((void) 0)
// used by tcp_ctx
#    define avs_log_internal_l__(...) ((void) 0)
#endif // WITH_AVS_COAP_LOG
