// Copyright 2015-2017 Directive Games Limited - All Rights Reserved

#include "DriftUE4DemoGameInstance.h"

#include "DriftAPI.h"
#include "DriftUtils.h"

#include "OnlineSubsystemUtils.h"


void UDriftUE4DemoGameInstance::Init()
{
    Super::Init();

    /**
     * Handle when the connection state changes
     */
    if (auto drift = FDriftWorldHelper(GetWorld()).GetInstance())
    {
        drift->OnConnectionStateChanged().AddUObject(this, &UDriftUE4DemoGameInstance::HandleConnectionStateChanged);
    }

    /**
     * Dedicated servers also login, but handle this elsewhere
     */
    if (IsRunningDedicatedServer())
    {
        return;
    }

    /**
     * Handle player login completion.
     */
    auto identityInterface = Online::GetIdentityInterface(GetWorld());
    if (identityInterface.IsValid())
    {
        identityInterface->OnLoginCompleteDelegates[0].AddUObject(this, &UDriftUE4DemoGameInstance::HandleLoginComplete);
    }
}


void UDriftUE4DemoGameInstance::Shutdown()
{
    /**
    * Unreal unfortunately offers no hook that we can use to let the plugin handle this automatically
    */
    if (auto drift = FDriftWorldHelper(GetWorld()).GetInstance())
    {
        drift->Shutdown();
    }

    Super::Shutdown();
}


void UDriftUE4DemoGameInstance::HandleConnectionStateChanged(EDriftConnectionState state)
{
    UE_LOG(LogDriftDemo, Log, TEXT("Connection State: %d"), (uint8)state);
}


void UDriftUE4DemoGameInstance::HandleLoginComplete(int32 LocalUserNum, bool success, const FUniqueNetId& UniqueId, const FString& Error)
{
    if (IsRunningDedicatedServer())
    {
        return;
    }

    if (success)
    {
        /**
        * The UniqueNetId is always from Drift, even if a secondary auth provider, like Steam, is used.
        *
        * The UniqueNetId must be cached on the local player and player state
        * for sessions to work. It's not clear why this is not done automatically
        * by the engine, except when called through blueprints. See ShowLoginUICallbackProxy.
        */
        if (auto localPlayer = GetLocalPlayerByIndex(LocalUserNum))
        {
            auto uniqueId = localPlayer->GetUniqueNetIdFromCachedControllerId();
            if (auto playerController = localPlayer->GetPlayerController(GetWorld()))
            {
                if (auto playerState = playerController->PlayerState)
                {
                    localPlayer->SetCachedUniqueNetId(uniqueId);
                    playerState->SetUniqueId(uniqueId);
                }
            }
        }
    }
}
