#include "Utility.h"

void Utility::Actor::RestoreAv(RE::Actor* actor, RE::ActorValue actorValue, float value)
{
    if (value == 0) {
        return;
    }

    if (actor) {
        actor->AsActorValueOwner()->RestoreActorValue(RE::ACTOR_VALUE_MODIFIER::kDamage, actorValue, value);
    }
}
