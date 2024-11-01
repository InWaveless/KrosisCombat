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

    // void Hook_OnMeleeHit::processHit(RE::Actor* victim, RE::HitData& hitData)
    //{
    //    using HITFLAG  = RE::HitData::Flag;
    //    auto aggressor = hitData.aggressor.get().get();
    //    if (!victim || !aggressor || victim->IsDead()) {
    //        _ProcessHit(victim, hitData);
    //        return;
    //    }
    //    logger::info("on melee hit hook");
    //    //hitProcessor::GetSingleton()->processHit(aggressor, victim, hitData);
    //    _ProcessHit(victim, hitData);
    //}
} // namespace Hooks
