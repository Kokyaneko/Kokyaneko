#!/bin/bash

set -euo pipefail

#set display
TARGET_RES="1024x576"
OUTPUT_NAME=$(xrandr | grep " connected" | awk '{print $1}' | head -n 1)

if [ -n "$OUTPUT_NAME" ]; then
    echo " ${TARGET_RES} "
    xrandr --output "$OUTPUT_NAME" --mode "$TARGET_RES"
else
    echo "Faild..."
fi

#set timezone
sudo timedatectl set-timezone Asia/Tokyo

#set Japanese environment
sudo apt update
sudo apt -y install neovim git gcc g++ w3m
sudo apt -y install fonts-noto-cjk language-pack-ja language-pack-gnome-ja
sudo apt -y install fcitx5 fcitx5-mozc fcitx5-configtool kde-config-fcitx5
im-config -n fcitx5
fcitx5 -d

echo "Finish startup!"
