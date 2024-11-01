#include "Hooks.h"

namespace Hooks
{
    void Install() noexcept
    {
        stl::write_thunk_call<MainUpdate>();
        logger::info("Installed main update hook");
        logger::info("");

        // Hook_OnMeleeHit::install();
        stl::write_thunk_call<MeleeHit>(MeleeHit::address + REL::Relocate(0x3C0, 0x4A8, 0x3C0));
        logger::info("installed on melee hit hook");
        logger::info("");
    }

    i32 MainUpdate::Thunk() noexcept { return func(); }

    void MeleeHit::Thunk(RE::Actor* target, RE::HitData& hitData)
    {
        logger::info("target:{}, hitData:{}", target->GetName(), hitData.weapon->GetName());
        MeleeHit::func(target, hitData);
    }
} // namespace Hooks
