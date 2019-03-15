/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/
#include <string>
#include <iostream>
#include <filesystem>
#include "../JuceLibraryCode/JuceHeader.h"


namespace fs = std::experimental::filesystem;



//==============================================================================
void displayPlugin(AudioPluginFormatManager& pluginFormatManager, std::string path) {

	KnownPluginList plugList;
	OwnedArray<juce::PluginDescription> pluginDescriptions;

	for (int i = 0; i < pluginFormatManager.getNumFormats(); ++i)
	{
		plugList.scanAndAddFile(path, true, pluginDescriptions,
			*pluginFormatManager.getFormat(i));
	}

	if (pluginDescriptions.size() > 0) {

		std::cout << "Creating plugin...";
		String pluginLoadError("An error occured loading plugin");
		AudioPluginInstance* pluginInstance = pluginFormatManager.createPluginInstance(*pluginDescriptions[0], 44100, 512, pluginLoadError);

		std::cout << "\n====> File: ";
		std::cout << path;
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
}


int main (int argc, char* argv[])
{

	if (argc != 2) {
		std::cout << "\nError: Wrong program argument number";
		std::cout << "\nYou must add VST directory path: ./explore /path/to/directory";
		std::cin.ignore();
		return 0;
	}

	AudioPluginFormatManager pluginFormatManager;
	pluginFormatManager.addDefaultFormats();

	std::string path = argv[1];
	std::cout << "\nExploring: ";
	std::cout << path;

	//TODO: Recursive directory scanning
	for (const auto & entry : fs::directory_iterator(path)) {
		displayPlugin(pluginFormatManager, entry.path().string());
	}

	std::cout << "\nProgram execution complete.";
	std::cin.ignore();

    return 0;
}


