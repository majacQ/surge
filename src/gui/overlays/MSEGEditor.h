/*
** Surge Synthesizer is Free and Open Source Software
**
** Surge is made available under the Gnu General Public License, v3.0
** https://www.gnu.org/licenses/gpl-3.0.en.html
**
** Copyright 2004-2020 by various individuals as described by the Git transaction log
**
** All source at: https://github.com/surge-synthesizer/surge.git
**
** Surge was a commercial product from 2004-2018, with Copyright and ownership
** in that period held by Claes Johanson at Vember Audio. Claes made Surge
** open source in September 2018.
*/

#pragma once
#include <JuceHeader.h>
#include "SurgeStorage.h"
#include "SkinSupport.h"
#include "RefreshableOverlay.h"

namespace Surge
{
namespace Overlays
{
struct MSEGControlRegion;
struct MSEGCanvas;

struct MSEGEditor : public juce::Component,
                    public Surge::GUI::SkinConsumingComponent,
                    public RefreshableOverlay
{
    /*
     * Because this is 'late' in the build (in the gui) there is a copy of this structure in
     * the DawExtraState. If you add something to this state, add it there too. Revisit that
     * decision in 1.9 perhaps but #3316 is very late in the 18 cycle, which is why we
     * needed the extra storage.
     */
    struct State
    {
        int timeEditMode = 0;
    };
    MSEGEditor(SurgeStorage *storage, LFOStorage *lfodata, MSEGStorage *ms, State *eds,
               Surge::GUI::Skin::ptr_t skin, std::shared_ptr<SurgeBitmaps> b);
    ~MSEGEditor();
    void forceRefresh() override;

    void resized() override;
    void paint(juce::Graphics &g) override;

    std::unique_ptr<MSEGControlRegion> controls;
    std::unique_ptr<MSEGCanvas> canvas;
};
} // namespace Overlays
} // namespace Surge
