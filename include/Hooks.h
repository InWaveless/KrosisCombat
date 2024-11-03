#pragma once

namespace Hooks
{
    void Install() noexcept;

    class MeleeHit
    {
    public:
        static void Thunk(RE::Actor* target, RE::HitData& hitData);

        inline static REL::Relocation<decltype(&Thunk)> func;
    };
} // namespace Hooks
