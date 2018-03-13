#ifndef __GLOBAL_HEADER__
#define __GLOBAL_HEADER__

#include "pluginterfaces/base/fplatform.h"
#include "pluginterfaces/base/funknown.h"

namespace Igorski {
namespace SID {

    static const int   ID       = 0;
    static const char* NAME     = "VSTSID";
    static const char* VENDOR   = "igorski.nl";

    // set upon initialization, see vst.cpp
    static float SAMPLE_RATE = 44100.f;

    // filter ranges, also see https://www.waitingforfriday.com/?p=661
    // also see vstsid.xml to update the controls to match

    static const float FILTER_MIN_FREQ      = 30.0f;
    static const float FILTER_MAX_FREQ      = 10000.f;
    static const float FILTER_MIN_RESONANCE = 0.1f;
    static const float FILTER_MAX_RESONANCE = 0.7071067811865476f; //sqrt( 2.f ) / 2.f;

    // maximum and minimum rate of oscillation in Hz
    // also see vstsid.xml to update the controls to match

    static const float MAX_LFO_RATE() { return 10.f; }
    static const float MIN_LFO_RATE() { return .1f; }

    // sine waveform used for the oscillator
    static const float TABLE[ 128 ] = { 0, 0.0490677, 0.0980171, 0.14673, 0.19509, 0.24298, 0.290285, 0.33689, 0.382683, 0.427555, 0.471397, 0.514103, 0.55557, 0.595699, 0.634393, 0.671559, 0.707107, 0.740951, 0.77301, 0.803208, 0.83147, 0.857729, 0.881921, 0.903989, 0.92388, 0.941544, 0.95694, 0.970031, 0.980785, 0.989177, 0.995185, 0.998795, 1, 0.998795, 0.995185, 0.989177, 0.980785, 0.970031, 0.95694, 0.941544, 0.92388, 0.903989, 0.881921, 0.857729, 0.83147, 0.803208, 0.77301, 0.740951, 0.707107, 0.671559, 0.634393, 0.595699, 0.55557, 0.514103, 0.471397, 0.427555, 0.382683, 0.33689, 0.290285, 0.24298, 0.19509, 0.14673, 0.0980171, 0.0490677, 1.22465e-16, -0.0490677, -0.0980171, -0.14673, -0.19509, -0.24298, -0.290285, -0.33689, -0.382683, -0.427555, -0.471397, -0.514103, -0.55557, -0.595699, -0.634393, -0.671559, -0.707107, -0.740951, -0.77301, -0.803208, -0.83147, -0.857729, -0.881921, -0.903989, -0.92388, -0.941544, -0.95694, -0.970031, -0.980785, -0.989177, -0.995185, -0.998795, -1, -0.998795, -0.995185, -0.989177, -0.980785, -0.970031, -0.95694, -0.941544, -0.92388, -0.903989, -0.881921, -0.857729, -0.83147, -0.803208, -0.77301, -0.740951, -0.707107, -0.671559, -0.634393, -0.595699, -0.55557, -0.514103, -0.471397, -0.427555, -0.382683, -0.33689, -0.290285, -0.24298, -0.19509, -0.14673, -0.0980171, -0.0490677 };

}
}

namespace Steinberg {
namespace Vst {

    static const FUID VSTSIDProcessorUID( 0x84E8DE5F, 0x92554F53, 0x96FAE413, 0x3C935A18 );
    static const FUID VSTSIDWithSideChainProcessorUID( 0x41347FD6, 0xFED64094, 0xAFBB12B7, 0xDBA1D441);
    static const FUID VSTSIDControllerUID( 0xD39D5B65, 0xD7AF42FA, 0x843F4AC8, 0x41EB04F0 );

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg

#define MAJOR_VERSION_STR "1"
#define MAJOR_VERSION_INT 1

#define SUB_VERSION_STR "3"
#define SUB_VERSION_INT 3

#define RELEASE_NUMBER_STR "0"
#define RELEASE_NUMBER_INT 0

#define BUILD_NUMBER_STR "1" // Build number to be sure that each result could identified.
#define BUILD_NUMBER_INT 1

// Version with build number (example "1.0.3.342")
#define FULL_VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR "." BUILD_NUMBER_STR

// Version without build number (example "1.0.3")
#define VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR

#define stringOriginalFilename  "vstsid.vst3"
#if PLATFORM_64
#define stringFileDescription   "VSTSID VST3-SDK (64Bit)"
#else
#define stringFileDescription   "VSTSID VST3-SDK"
#endif
#define stringCompanyName       "igorski.nl\0"
#define stringLegalCopyright    "© 2018 igorski.nl"
#define stringLegalTrademarks   "VST is a trademark of Steinberg Media Technologies GmbH"

#endif
