#! /bin/bash
picom &
feh --bg-fill --randomize ~/.dwm/backgr/* &
#dwmblocks &
while true; do
        xsetroot -name " $(free -m | grep '^Mem' | awk '{print "  "$3"/"$2""}' | lolcat )   $(date +"  %I:%M     %d %b %Y")"
        sleep 2
done &

