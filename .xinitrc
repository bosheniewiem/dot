#!/bin/sh
# xinitrc
xrdb "$XRESOURCES" 
sxhkd & 
dunst &
compton --config "$XDG_CONFIG_HOME/compositor/config" &
feh --no-fehbg --bg-tile "$WALLPAPERS/$(xrdb -q | awk '/wallpaper/ {print $2}')" &
xsetroot -cursor_name left_ptr &
start-pulseaudio-x11 &
setxkbmap pl &
xset b off &
xset r rate 200 25 &
#redshift -P -O 4700k &
mpd &
bar &
notify-send "Welcome $(whoami)!" &
#exec bspwm
#exec herbstluftwm
exec openbox
