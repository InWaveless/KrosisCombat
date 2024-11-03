#pragma once

class Settings : public Singleton<Settings>
{
public:
    static void LoadSettings() noexcept;

    inline static bool debug_logging{};

    inline static float fMeleeRewardLightHit_Percent = 0.2f;
};
