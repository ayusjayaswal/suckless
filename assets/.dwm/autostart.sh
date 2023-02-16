#! /bin/bash
bgdir=(~/.wallpapers/*) &&
wallpaper=$(printf "%s\n" "${bgdir[RANDOM % ${#bgdir[@]}]}") &&
xwallpaper --zoom $wallpaper &&
picom &
sxhkd &
mpd &
slstatus

#dwmblocks &
# while true; do
#         xsetroot -name " $(free -m | grep '^Mem' | awk '{print "  "$3"/"$2""}' | lolcat )   $(date +"  %I:%M     %d %b %Y")"
#         sleep 2
# done &

