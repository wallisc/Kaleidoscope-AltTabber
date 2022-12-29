// Kaleidoscope-AltTabber - A AltTabber plugin for Kaleidoscope.

#pragma once

#include "Kaleidoscope-LEDControl.h"

namespace kaleidoscope {
namespace plugin {

class AltTabber : public kaleidoscope::Plugin {
 public:
  AltTabber(void) {}

  EventHandlerResult onKeyswitchEvent(Key& mapped_key, KeyAddr key_addr, uint8_t keyState);
  EventHandlerResult afterEachCycle();

private:
  bool bAltTabberLEDsActive = false;
};
}
}

extern kaleidoscope::plugin::AltTabber AltTabber;