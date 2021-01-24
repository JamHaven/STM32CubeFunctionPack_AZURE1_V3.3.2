/**
  ******************************************************************************
  * @file    az_tcpsocketconnection.c
  * @author  MCD Application Team
  * @brief   Azure mbed socket abstraction implementation.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>  /* Required by tcpsocketconnection_c.h */
#include "azure_c_shared_utility/tcpsocketconnection_c.h"
#include "net.h"
#include "msg.h"
extern void *hnet;
#include <string.h>

/* Private defines -----------------------------------------------------------*/
#define AZ_TSC_REMOVE_NOT_USED  /**< Remove the unused - and not properly implemented - functions. */

/* Exported functions --------------------------------------------------------*/
TCPSOCKETCONNECTION_HANDLE tcpsocketconnection_create(void)
{
  net_sockhnd_t sockhnd = NULL;
  if (net_sock_create(hnet, &sockhnd, NET_PROTO_TCP) == NET_OK)
  {
    return sockhnd;
  }
  else
  {
    return NULL;
  }
}

void tcpsocketconnection_set_blocking(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, bool blocking, unsigned int timeout)
{
  net_sockhnd_t sockhnd = tcpSocketConnectionHandle;
  char * option = (blocking == true) ? "sock_blocking" : "sock_noblocking";
  
  if (net_sock_setopt(sockhnd, option, NULL, 0) != NET_OK)
  {
    msg_error("Could not set the socket option %s\n", option);
  }
  
  char value[6];
  snprintf(value, sizeof(value), "%u", timeout);
  if ( (net_sock_setopt(sockhnd, "sock_read_timeout", (uint8_t *) value, strlen(value) + 1) != NET_OK)
      || (net_sock_setopt(sockhnd, "sock_write_timeout", (uint8_t *)value, strlen(value) + 1) != NET_OK) )
  {
    msg_error("Could not set the timeout socket option.\n");
  }
}

void tcpsocketconnection_destroy(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle)
{
  net_sock_destroy(tcpSocketConnectionHandle);
}

int tcpsocketconnection_connect(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, const char* host, const int port)
{
  int rc = 0;
  
  if (net_sock_open(tcpSocketConnectionHandle, host, port, 0) != NET_OK)
  {
    msg_error("Could not connect to %s:%d\n", host, port);
    rc = -1;
  }
  
  return rc;
}

#ifndef AZ_TSC_REMOVE_NOT_USED
bool tcpsocketconnection_is_connected(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle)
{
  // TODO: Need to extend the NET API?
  return true;
}
#endif /* AZ_TSC_REMOVE_NOT_USED */

void tcpsocketconnection_close(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle)
{
  net_sock_close(tcpSocketConnectionHandle);
}

int tcpsocketconnection_send(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, const char* data, int length)
{
  // TODO: Check the return code
  return net_sock_send(tcpSocketConnectionHandle, (uint8_t *) data, length);
}

#ifndef AZ_TSC_REMOVE_NOT_USED
int tcpsocketconnection_send_all(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, const char* data, int length)
{
  // TODO: Check the return code
  // TODO: May need to loop until everything is sent, or the timeout is reached
  return net_sock_send(tcpSocketConnectionHandle, (uint8_t *) data, length);
}
#endif /* AZ_TSC_REMOVE_NOT_USED */

int tcpsocketconnection_receive(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, char* data, int length)
{
  // TODO: Check the return code
  return net_sock_recv(tcpSocketConnectionHandle, (uint8_t *)data, length);
}

#ifndef AZ_TSC_REMOVE_NOT_USED
int tcpsocketconnection_receive_all(TCPSOCKETCONNECTION_HANDLE tcpSocketConnectionHandle, char* data, int length)
{
  // TODO: Check the return code
  // TODO: May need to loop until everything is received, or the timeout is reached
  return net_sock_recv(tcpSocketConnectionHandle, (uint8_t *) data, length);
}
#endif /* AZ_TSC_REMOVE_NOT_USED */

