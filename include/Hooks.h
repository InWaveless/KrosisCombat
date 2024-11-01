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

        inline static const REL::RelocationID Hook{ 37673, 38627 };

        inline static const auto address{ Hook.address() };
    };
} // namespace Hooks
