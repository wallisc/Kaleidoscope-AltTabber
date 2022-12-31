# Kaleidoscope-AltTabber
 
This plugin will overrides certain key functions when the left-alt is held. 

This is primarily to designed for ambidextrous fast alt-tabbing when the left-alt key is mapped to a thumb key.


The following keys are remapped:
 * The F/J keys are remapped to tab.
 * The 4 is remapped to F4. This is an added "bonus" as I found alt+f4 to be a pain to trigger on 60% keyboards

 ## Installation
 1. Find the plugin directory for the Kaleidoscope source. For the Dygma branch of Kaleidoscope it looks like: Arduino\hardware\dygma\samd\libraries\Kaleidoscope\src\kaleidoscope\plugin
 2. Copy the contents of the Src directory into the plugin folder using either git clone or just using the "Clone or download" button from GitHub
 3. Add the plugin to your sketch by adding the include and initializing the plugin.
````
#include "kaleidoscope/plugin/AltTabber.h"

KALEIDOSCOPE_INIT_PLUGINS(AltTabber);
````
