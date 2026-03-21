// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyFirstGame : ModuleRules
{
	public MyFirstGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"MyFirstGame",
			"MyFirstGame/Variant_Platforming",
			"MyFirstGame/Variant_Platforming/Animation",
			"MyFirstGame/Variant_Combat",
			"MyFirstGame/Variant_Combat/AI",
			"MyFirstGame/Variant_Combat/Animation",
			"MyFirstGame/Variant_Combat/Gameplay",
			"MyFirstGame/Variant_Combat/Interfaces",
			"MyFirstGame/Variant_Combat/UI",
			"MyFirstGame/Variant_SideScrolling",
			"MyFirstGame/Variant_SideScrolling/AI",
			"MyFirstGame/Variant_SideScrolling/Gameplay",
			"MyFirstGame/Variant_SideScrolling/Interfaces",
			"MyFirstGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
