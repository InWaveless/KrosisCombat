#include "Hooks.h"

#include "Settings.h"
#include "Utility.h"

namespace Hooks
{
    void Install() noexcept
    {
        REL::Relocation target{ RELOCATION_ID(37673, 38627), REL::Relocate(0x3c0, 0x4a8, 0x0) };
        stl::write_thunk_call<MeleeHit>(target.address());
        logger::info("installed on melee hit hook");
        logger::info("");
    }

    void MeleeHit::Thunk(RE::Actor* target, RE::HitData& hitData)
    {
        if (hitData.aggressor.get() != nullptr) {
            logger::info("target:{}, hitData:{}, aggressor:{}", target->GetName(), hitData.weapon->GetName(), hitData.aggressor.get().get()->GetName());
        }
        MeleeHit::func(target, hitData);
    }

} // namespace Hooks
