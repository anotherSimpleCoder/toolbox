#!/bin/sh
plugin_amount=$(cat ./plugins.yaml | yq -r ".plugins[].name" | wc -l)

for plugin_index in $(seq 0 $(($plugin_amount - 1))); do
	plugin_name=$(cat ./plugins.yaml | yq -r ".plugins[$plugin_index].name")

	plugin_destination=$VIM_PACK_HOME/$plugin_name
	plugin_path=$(cat ./plugins.yaml | yq -r ".plugins[$plugin_index].path")
	if [ ! -d $plugin_destination ]; then
		echo "Installing $plugin_name..."
		git clone --depth=1  $plugin_path $plugin_destination
	fi
done
