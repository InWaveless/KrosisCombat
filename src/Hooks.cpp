#include "Hooks.h"

#include "Settings.h"
#include "Utility.h"

namespace Hooks
{
    void Install() noexcept
    {
        //stl::write_thunk_call<MainUpdate>();
        //logger::info("Installed main update hook");
        //logger::info("");

        stl::write_thunk_call<MeleeHit>();
        logger::info("installed on melee hit hook");
        logger::info("");
    }

    i32 MainUpdate::Thunk() noexcept { return func(); }

    void MeleeHit::Thunk(RE::Actor* target, RE::HitData& hitData)
    {
        if (hitData.aggressor.get() != nullptr) {
            logger::info("target:{}, hitData:{}, aggressor:{}", target->GetName(), hitData.weapon->GetName(), hitData.aggressor.get().get()->GetName());
        }
        MeleeHit::func(target, hitData);
    }

} // namespace Hooks
