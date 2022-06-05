// Copyright © Developed by Josh "db" Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#include "n00dSleeper.h"

#define LOCTEXT_NAMESPACE "Fn00dSleeperModule"


 // Default module functions

void Fn00dSleeperModule::StartupModule()
{
	RegisterSettings();
}

void Fn00dSleeperModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

// Overridden for settings

// Support for dynamic reloading
bool Fn00dSleeperModule::SupportsDynamicReloading()
{
	return true;
}

// Callback for when the settings were saved.
bool Fn00dSleeperModule::HandleSettingsSaved()
{

	UN00dSleeperSettings* Settings = GetMutableDefault<UN00dSleeperSettings>();
	bool ResaveSettings = false;

	// You can put any validation code in here and resave the settings in case an invalid
	// value has been entered

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	return true;
}
// Register the settings
void Fn00dSleeperModule::RegisterSettings()
{
	// Registering some settings is just a matter of exposing the default UObject of
	// your desired class, feel free to add here all those settings you want to expose
	// to your LDs or artists.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("n00d",
			LOCTEXT("RuntimeWDCategoryName", "n00d"),
			LOCTEXT("RuntimeWDCategoryDescription", "Configuration for n00d assets"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "n00d", "Sleeper",
			LOCTEXT("RuntimeGeneralSettingsName", "Sleeper"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "n00dSleeper Settings"),
			GetMutableDefault<UN00dSleeperSettings>()
		);

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &Fn00dSleeperModule::HandleSettingsSaved);
		}
	}

}
// Unregister the settings
void Fn00dSleeperModule::UnregisterSettings()
{
	// Ensure to unregister all of your registered settings here, hot-reload would
	// otherwise yield unexpected results.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "n00d", "Sleeper");
	}
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dSleeperModule, n00dSleeper)




