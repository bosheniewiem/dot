## Alias 
gz() { tar cfvz $@ }
mp3yt() { 
    youtube-dl \
    --add-metadata \
    --extract-audio \
    --ignore-errors \
    --audio-format mp3 $1 &&
    notify-send "mp3yt" "Downloaded Music" || echo 'Usage: mp3yt <link>' 
}
alias ll='ls -lA'
alias rnb="toilet -f future"

## Nvim
alias neovim="nvim"
alias nano="nvim"
alias vi="nvim"
alias vim="nvim"
alias emacs="nvim"
alias edit="nvim"

## Prompt
PROMPT='%{[34m%}$(git_prompt_info)%{[37m%}Ͳ%{[00m%} '

UID() {
if [ ${UID} = '1000' ]; then
    echo "$"
else
    echo "#"
fi
}
#PROMPT="%{[44;30m%} $(UID) %{[00m%}%{[41;30m%} %c %{[00m%} "
ZSH_THEME_GIT_PROMPT_DIRTY=" ✗"
ZSH_THEME_GIT_PROMPT_CLEAN=" ✔"
#RPROMPT='%{[44;30m%} %D{%L:%M:%S %p} %{[00m%}'

unsetopt flowcontrol
setopt auto_cd

command_not_found_handler(){
    printf "\033[31m'"$1"' not found\n"
}

## Oh my zsh
 plugins=(git)
 source ~/.oh-my-zsh/oh-my-zsh.sh

## Discord hacks xD
sp()  { base64 <<< "$@" >> /dev/stderr | sed "s/./||&||/g" | xclip -sel clip; }
re()  { base64 -d <<<"$@"; }

## Tmux
alias tm='tmux -f "$XDG_CONFIG_HOME"/tmux/tmux.conf'
alias tma='tmux a -t -f "$XDG_CONFIG_HOME"/tmux/tmux.conf'
alias tmk='tmux kill-session -t'
alias tmks='tmux kill-server'

## Dots
alias dots='git --git-dir ~/.config/dot/ --work-tree ~'
