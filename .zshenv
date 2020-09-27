export EDITOR="nvim"
export TERMINAL="urxvt"

# Cleanup
# XDG
export XDG_CONFIG_HOME="$HOME/.config"
export XDG_DATA_HOME="$HOME/.local/share"

# Others
export ZDOTDIR="$XDG_CONFIG_HOME/zsh"
export GNUPGHOME="$XDG_DATA_HOME"/gnupg
export PASSWORD_STORE_DIR="$XDG_DATA_HOME/passwords"
export XAUTHORITY="$XDG_RUNTIME_DIR/Xauthority"
export BIN="$HOME/.local/bin"
export PATH="$BIN:/sbin:$PATH"
export THEMES="$XDG_DATA_HOME/themes"
export WALLPAPERS="$XDG_DATA_HOME/wallpapers"
export LESSHISTFILE="-"
export HISTFILE="$ZDOTDIR/.history"
export CARGO_HOME="$XDG_DATA_HOME/cargo"
export MPLAYER_HOME="$XDG_CONFIG_HOME/mplayer"
export WGETRC="$XDG_CONFIG_HOME/wget/wgetrc"
export XRESOURCES="$XDG_CONFIG_HOME/x/Xresources"
export GIT_CONFIG="$XDG_CONFIG_HOME/git/config"
export GTK2_RC_FILES="$XDG_CONFIG_HOME/gtkrc-2.0"
export ICEAUTHORITY="$XDG_CACHE_HOME/ICEauthority"
