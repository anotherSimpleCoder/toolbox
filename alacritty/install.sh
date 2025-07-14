#!/usr/bin/bash

CONFIG_PATH=$HOME/.config/alacritty

if [ ! -f "$CONFIG_PATH/alacritty.toml" ]; then
	echo "Installing Alacritty config"
	mkdir -p $CONFIG_PATH
	cp ./alacritty.toml $CONFIG_PATH/alacritty.toml
	echo "Alacritty config installed!"
else
	rm $CONFIG_PATH/alacritty.toml
	cp ./alacritty.toml $CONFIG_PATH/alacritty.toml
	echo "Alacritty config updated!"
fi


