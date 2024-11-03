#pragma once

class Utility : public Singleton<Utility>
{
public:
    class Actor : public Singleton<Actor>
    {
    public:
        static void RestoreAv(RE::Actor* actor, RE::ActorValue actorValue, float value);
    };
};
