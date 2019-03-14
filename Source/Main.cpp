/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/
#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
int main (int argc, char* argv[])
{

	KnownPluginList plugList;
	OwnedArray<juce::PluginDescription> pluginDescriptions;
	juce::VSTPluginFormat format;


	String path("C:/VST/store/Tunefish4/Tunefish4.vst3");


	AudioPluginFormatManager pluginFormatManager;
	pluginFormatManager.addDefaultFormats();
	for (int i = 0; i < pluginFormatManager.getNumFormats(); ++i)
	{
		bool added = plugList.scanAndAddFile(path, true, pluginDescriptions,
			*pluginFormatManager.getFormat(i));

	}
	jassert(pluginDescriptions.size() > 0);

	if (pluginDescriptions.size() > 0) {

		std::cout << "Creating plugin...";
		String pluginLoadError ("An error occured loading plugin");
		AudioPluginInstance* pluginInstance = pluginFormatManager.createPluginInstance(*pluginDescriptions[0], 44100, 512, pluginLoadError);

		std::cout << "\nPlugin Identifier: ";
		std::cout << pluginInstance->getPluginDescription().fileOrIdentifier;
		std::cout << "\nPlugin Name: ";
		std::cout << pluginInstance->getPluginDescription().name;
		std::cout << "\nPlugin UID: ";
		std::cout << pluginInstance->getPluginDescription().uid;
		std::cout << "\nPlugin Version: ";
		std::cout << pluginInstance->getPluginDescription().version;
		std::cout << "\nPlugin Manufacturer Name: ";
		std::cout << pluginInstance->getPluginDescription().manufacturerName;


	}

	std::cout << "\nProgram execution complete.";
	std::cin.ignore();

    return 0;
}
