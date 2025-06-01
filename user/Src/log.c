#include "log.h"
#include "usbd_cdc_if.h"
#include <stdarg.h>
#include <stdio.h>


static uint8_t log_buffer[LOG_BUFFER_SIZE];

int usb_printf(const char *fmt, ...) {
  va_list args;
  int len;
  va_start(args, fmt);
  len = vsnprintf((char *)log_buffer, LOG_BUFFER_SIZE, fmt, args);
  va_end(args);
  CDC_Transmit_FS(log_buffer, len);
  return len;
}
