// Copyright 2015-2017 Directive Games Limited - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "OnlineSessionInterface.h"

#include "DriftAPI.h"

#include "DriftUE4DemoGameInstance.generated.h"

UCLASS()
class DRIFTUE4DEMO_API UDriftUE4DemoGameInstance : public UPlatformGameInstance
{
    GENERATED_BODY()

public:
    void Init() override;
    void Shutdown() override;

private:
    void HandleConnectionStateChanged(EDriftConnectionState state);
    void HandleLoginComplete(int32 LocalUserNum, bool success, const FUniqueNetId& UniqueId, const FString& Error);
};
