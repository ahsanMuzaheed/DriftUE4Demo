// Copyright 2015-2017 Directive Games Limited - All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class DriftUE4DemoEditorTarget : TargetRules
{
	public DriftUE4DemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "DriftUE4Demo" } );
	}
}
