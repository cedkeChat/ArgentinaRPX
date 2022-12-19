#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <coreinit/launch.h>
#include <coreinit/screen.h>
#include <coreinit/title.h>
#include <coreinit/exit.h>
#include <coreinit/debug.h>
#include <vpad/input.h>
#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <string.h>

const char *data = 0xDEADC0DE;
const char *version = "v1.0";

int Exiting() {
  WHBLogPrintf("Exiting...");
  OSReport("Exit final..");
  WHBLogConsoleDraw();
  OSSleepTicks(OSMillisecondsToTicks(1000));
  WHBLogConsoleFree();
  WHBLogCafeDeinit();
  WHBLogUdpDeinit();
  WHBProcShutdown();
  return 0;
}

int main(int argc, char **argv) {
  OSScreenInit();
  WHBProcInit();
  WHBLogCafeInit();
  WHBLogUdpInit();
  WHBLogConsoleInit();

  OSReport("Welcome!");
  OSSleepTicks(OSMillisecondsToTicks(2000));
  
  WHBLogPrintf("ArgentinaLoader %s - By cedkeChat", version);
  WHBLogPrintf("/Data/", data);
  WHBLogPrintf("Press Y to start ArgentinaLoader.");
  WHBLogPrintf("Press HOME to Exit the Argentina app.");
  WHBLogPrintf("");

  WHBLogConsoleDraw();

  VPADStatus vpad_data;
  VPADReadError error;

  while(1) {
    error = -1;
    VPADRead(0, &vpad_data, 1, &error);

    if(error == 0) {
      if(vpad_data.release & VPAD_BUTTON_Y) {
        WHBLogPrintf("Starting..");
        OSFatal("...");
        WHBLogConsoleDraw();
        OSSleepTicks(OSMillisecondsToTicks(1000));
        break;
      } else if(vpad_data.release) {
        Exiting();
        return 0;
        break;
      }
    }
  }
}