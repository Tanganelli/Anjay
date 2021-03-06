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

#ifndef AVSYSTEM_COAP_ASYNC_H
#define AVSYSTEM_COAP_ASYNC_H

#include <avsystem/coap/config.h>

#include <stdint.h>

#include <avsystem/coap/async_client.h>
#include <avsystem/coap/async_exchange.h>
#include <avsystem/coap/async_server.h>
#include <avsystem/coap/ctx.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Receives some data from the socket associated with @p ctx and handles it as
 * appropriately.
 *
 * [TCP] If received data is not a complete CoAP message or if it doesn't
 * contain at least a part of payload, this function does nothing except of
 * buffering these data internally. It is considered as successfull call if
 * there is enough space in the buffer.
 *
 * [TCP] If more than one complete message is available on socket and will
 * fit into incoming buffer, all of them will be handled during single call to
 * this function.
 *
 * If the packet is recognized as part of a known ongoing exchange, such
 * message is handled internally without calling @p handle_request . Otherwise,
 * incoming message is passed to @p handle_request .
 *
 * This function should be called every time when user detect new data arrived
 * on the socket assigned to @p ctx .
 *
 * @param ctx                     CoAP context associated with the socket to
 *                                receive the message from.
 *
 * @param[in]  handle_request     Callback used to handle incoming requests. May
 *                                be NULL, in which case it will only handle
 *                                responses to asynchronous requests and ignore
 *                                incoming requests.
 *
 * @param[in]  handle_request_arg An opaque argument passed to
 *                                @p handle_request .
 *
 * @returns @ref AVS_OK for success, or an error condition for which the
 *          operation failed.
 */
avs_error_t avs_coap_async_handle_incoming_packet(
        avs_coap_ctx_t *ctx,
        avs_coap_server_new_async_request_handler_t *handle_request,
        void *handle_request_arg);

#ifdef __cplusplus
}
#endif

#endif // AVSYSTEM_COAP_ASYNC_H
