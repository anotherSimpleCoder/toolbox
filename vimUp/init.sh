#!/bin/sh

export VIM_HOME=$HOME/.vim
export VIM_PACK_HOME=$VIM_HOME/pack/local/start

if [ ! -d "$VIM_HOME" ]; then
	echo Creating vim directory
	mkdir -p $VIM_HOME
fi

if [ ! -d "$VIM_PACK_HOME" ]; then
	echo Creating Vim 8 plugin
	mkdir -p $VIM_PACK_HOME
fi

(
./install_packages.sh
)
