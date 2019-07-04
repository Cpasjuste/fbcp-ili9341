//
// Created by cpasjuste on 03/07/19.
//

#include <cstdio>
#include <cstdlib>
#include <csignal>

#include "../libfbcp/fbcp.h"

static bool quit = false;
static bool exited = false;

const char* SignalToString(int signal)
{
  if (signal==SIGINT) return "SIGINT";
  if (signal==SIGQUIT) return "SIGQUIT";
  if (signal==SIGUSR1) return "SIGUSR1";
  if (signal==SIGUSR2) return "SIGUSR2";
  if (signal==SIGTERM) return "SIGTERM";
  return "?";
}

void ProgramInterruptHandler(int signal)
{
  printf("Signal %s(%d) received, quitting\n", SignalToString(signal), signal);
  static int quitHandlerCalled = 0;
  if (++quitHandlerCalled>=5)
  {
    printf(
        "Ctrl-C handler invoked five times, looks like fbcp-ili9341 is not gracefully quitting - performing a forcible shutdown!\n");
    exit(1);
  }

  if (!exited)
  {
    exited = true;
    FBCPExit();
  }
}

int main()
{
  signal(SIGINT, ProgramInterruptHandler);
  signal(SIGQUIT, ProgramInterruptHandler);
  signal(SIGUSR1, ProgramInterruptHandler);
  signal(SIGUSR2, ProgramInterruptHandler);
  signal(SIGTERM, ProgramInterruptHandler);

  FBCPInit();

  while (!quit)
  {
    FBCPProcessFrame();
  }

  if (!exited)
  {
    FBCPExit();
  }

  return 0;
}
