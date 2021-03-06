# -*- coding: utf-8 -*-
#
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

from framework.lwm2m.tlv import TLVType
from framework.lwm2m_test import *


class SecurityObjectDmOperationsBySingleServer(test_suite.Lwm2mSingleServerTest,
                                               test_suite.Lwm2mDmOperations):
    def runTest(self):
        # Every security instance action on nonexistent instance shall return NOT_AUTHORIZED to not disclose
        # any information.
        for i in range(3):
            self.read_instance(server=self.serv, oid=OID.Security, iid=i,
                               expect_error_code=coap.Code.RES_UNAUTHORIZED)
            self.delete_instance(server=self.serv, oid=OID.Security, iid=i,
                                 expect_error_code=coap.Code.RES_UNAUTHORIZED)
            self.write_instance(server=self.serv, oid=OID.Security, iid=i,
                                expect_error_code=coap.Code.RES_UNAUTHORIZED)
            self.execute_resource(server=self.serv, oid=OID.Security, iid=i,
                                  rid=RID.Security.Bootstrap,
                                  expect_error_code=coap.Code.RES_UNAUTHORIZED)
            self.write_attributes(server=self.serv, oid=OID.Security, iid=i,
                                  rid=RID.Security.Bootstrap, query=['pmax=1'],
                                  expect_error_code=coap.Code.RES_UNAUTHORIZED)
