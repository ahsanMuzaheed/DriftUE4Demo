// Copyright 2015-2017 Directive Games Limited - All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class DriftUE4DemoTarget : TargetRules
{
	public DriftUE4DemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "DriftUE4Demo" } );
	}
}
