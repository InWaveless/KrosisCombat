#pragma once

namespace Hooks
{
    

    void Install() noexcept;

    class MainUpdate : public Singleton<MainUpdate>
    {
    public:
        static i32 Thunk() noexcept;

        inline static REL::Relocation<decltype(&Thunk)> func;

        inline static const REL::Relocation target{ RELOCATION_ID(35565, 36564), REL::Relocate(0x748, 0xc26, 0x7ee) };

        inline static const auto address{ target.address() };
    };
    
    class MeleeHit : public Singleton<MeleeHit>
    {
    public:
        static void Thunk(RE::Actor* target, RE::HitData& hitData);

        inline static REL::Relocation<decltype(Thunk)> func;

        inline static const REL::RelocationID Actor_DealDamage{ 37673, 38627 };

        inline static const auto address{ Actor_DealDamage.address() };
    };

    //class Hook_OnMeleeHit
    //{
    //public:
    //    static void install()
    //    {
    //        REL::Relocation<uintptr_t> hook{ RELOCATION_ID(37673, 38627) }; // 140628C20       14064E760
    //        auto&                      trampoline = SKSE::GetTrampoline();
    //        _ProcessHit                           = trampoline.write_call<5>(hook.address() + REL::VariantOffset(0x3C0, 0x4A8, 0).offset(), processHit);
    //        logger::info("hook:OnMeleeHit");
    //    }

    //private:
    //    static void                                         processHit(RE::Actor* victim, RE::HitData& hitData);
    //    inline static REL::Relocation<decltype(processHit)> _ProcessHit; // 140626400       14064BAB0
    //};
} // namespace Hooks
