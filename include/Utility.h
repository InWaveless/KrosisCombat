#pragma once

class Utility
{
public:
    class Actor : public Singleton<Actor>
    {
    public:
        void RestoreAv(RE::Actor* actor, RE::ActorValue actorValue, float value);
    };
};
