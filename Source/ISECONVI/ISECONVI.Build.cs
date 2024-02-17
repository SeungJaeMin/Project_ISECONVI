// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ISECONVI : ModuleRules
{
	public ISECONVI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
			new string[] {
			// Gameplay Abilites 
            "GameplayAbilities", 
			"GameplayTags", 
			"GameplayTasks",

			// Spine Plugin
			"SpinePlugin",
			
			// Default Setting 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"HeadMountedDisplay",
			"EnhancedInput"
			}
		);
		PublicIncludePaths.AddRange(
			new string[] {
				"ISECONVI",
				"ISECONVI/ISECONVI_BattleSequence"

			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
			}
		);

		// Generate compile errors if using DrawDebug functions in test/shipping builds.
		PublicDefinitions.Add("SHIPPING_DRAW_DEBUG_ERROR=1");
	}
}
