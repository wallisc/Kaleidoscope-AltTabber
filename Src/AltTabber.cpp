// Kaleidoscope-AltTabber - A AltTabber plugin for Kaleidoscope.

#include "AltTabber.h"
#include "kaleidoscope.h"
#include "kaleidoscope/driver/hid/base/Keyboard.h"

namespace kaleidoscope {
namespace plugin {

bool IsAltTabberActive()
{
	return Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt);
}

bool ShouldRemapKeyToTab(const Key& mapped_key)
{
	return mapped_key == Key_F || mapped_key == Key_J;
}

bool ShouldRemapKeyToF4(const Key& mapped_key)
{
	return mapped_key == Key_4;
}

bool IsAltTabberKey(const Key& mapped_key)
{
	return ShouldRemapKeyToTab(mapped_key) || ShouldRemapKeyToF4(mapped_key);
}

EventHandlerResult AltTabber::onKeyswitchEvent(Key& mapped_key, KeyAddr key_addr, uint8_t keyState)
{
	if (IsAltTabberActive()) {
		if (ShouldRemapKeyToTab(mapped_key)) {
			mapped_key = Key_Tab;
		}
		else if (ShouldRemapKeyToF4(mapped_key)) {
			mapped_key = Key_F4;
		}
	}
	return EventHandlerResult::OK;
}

EventHandlerResult AltTabber::afterEachCycle() {
	if (IsAltTabberActive()) {
		bAltTabberLEDsActive = true;
		const cRGB altTabberColor = hsvToRgb(255, 155, 155);

		for (auto key_addr : KeyAddr::all()) {
			Key k = Layer.lookupOnActiveLayer(key_addr);

			if (IsAltTabberKey(k)) {
				::LEDControl.setCrgbAt(KeyAddr(key_addr), altTabberColor);
			}
		}
	}
	else if (bAltTabberLEDsActive)
	{
		::LEDControl.set_mode(::LEDControl.get_mode_index());
		bAltTabberLEDsActive = false;
	}
	return EventHandlerResult::OK;
}

}
}

kaleidoscope::plugin::AltTabber AltTabber;
